#include <iostream>
#include <vector>
#include <tuple>

#include "lebedev_implementation.hpp"

using vec = std::vector<double>;
using mat = std::vector<vec>;


/**
 * Calculates length-n vector whose ith component is \prod_0^i (2k - 1)
 */
std::vector<double> calc_2k_1_product(unsigned int n)
{
    std::vector<double> product_vector(n + 1);

    product_vector[0] = 1;
    for (std::size_t k = 1; k <= n; ++k)
        product_vector[k] = (2*k - 1) * product_vector[k - 1];

    return product_vector;
}


/**
 * Calculates three (degree + 1) x n vector of vectors whose columns are the
 * coordinates of each Lebedev point raised to the 2i'th power.
 */
std::tuple<mat, mat, mat>
calc_coord_multiples(const lebedev::QuadraturePoints quad_points, unsigned int degree)
{
    const auto n_pts = quad_points.get_weights().size();

    auto qx = quad_points.get_x();
    auto qy = quad_points.get_y();
    auto qz = quad_points.get_z();

    mat x(degree + 1, vec(n_pts));
    mat y(degree + 1, vec(n_pts));
    mat z(degree + 1, vec(n_pts));

    for (std::size_t j = 0; j < n_pts; ++j)
    {
        x[0][j] = 1.0;
        y[0][j] = 1.0;
        z[0][j] = 1.0;
    }

    for (std::size_t i = 1; i <= degree; ++i)
        for (std::size_t j = 0; j < n_pts; ++j)
        {
            x[i][j] = x[i - 1][j] * qx[j] * qx[j];
            y[i][j] = y[i - 1][j] * qy[j] * qy[j];
            z[i][j] = z[i - 1][j] * qz[j] * qz[j];
        }

    return std::make_tuple(x, y, z);
}



int main()
{
    constexpr unsigned int n_max = 64;

    for (std::size_t n = 0; n <= n_max; ++n)
    {
        if (!lebedev::get_rule_availability(n))
            continue;

        auto order = lebedev::get_rule_order(n);
        std::cout << "Order is: " << static_cast<unsigned int>(order) << "\n";
        auto quad_points = lebedev::QuadraturePoints(order);

        auto degree = lebedev::get_rule_precision(n);
        mat x, y, z;
        std::tie(x, y, z) = calc_coord_multiples(quad_points, degree);

        auto P = calc_2k_1_product(n + 1);

        double error = 0;
        for (std::size_t i = 0; i <= n; ++i)
            for (std::size_t j = 0; j <= n - i; ++j)
            {
                const std::size_t k = n - i - j;

                const double integral = P[i] * P[j] * P[k] / P[i + j + k + 1];

                auto w = quad_points.get_weights();
                double quad = 0;
                for (std::size_t l = 0; l < w.size(); ++l)
                    quad += x[i][l] * y[j][l] * z[k][l] * w[l];

                error += std::abs(quad - integral);
            }

        std::cout << "Error is: " << error << "\n";

        std::cout << n << "\n";
    }

    return 0;
}
