#include "lebedev_quadrature.hpp"

#include <iostream>
#include <vector>

using vec = std::vector<double>;

vec xyz_squared(const vec& x, const vec& y, const vec& z)
{
    vec return_vec(x.size());
    for (std::size_t i = 0; i < x.size(); ++i)
        return_vec[i] = x[i]*x[i] * y[i]*y[i] * z[i]*z[i];

    return return_vec;
}

int main()
{
    auto lambda_func = [](const vec& x, const vec& y, const vec& z) { 
                            vec return_vec(x.size());
                            for (std::size_t i = 0; i < x.size(); ++i)
                                return_vec[i] = x[i]*x[i] * y[i]*y[i] * z[i]*z[i];

                            return return_vec;
                       };

    auto quad_order = lebedev::QuadratureOrder::order_590;
    auto quad_points = lebedev::QuadraturePoints(quad_order);

    auto quadrature_value = quad_points.evaluate_spherical_integral(xyz_squared);
    auto lambda_quadrature_value = quad_points.evaluate_spherical_integral(lambda_func);
    auto integral_value = 4.0 * M_PI / 105.0;

    std::cout << "Numerical integration is: " 
              << quadrature_value
              << "\n";

    std::cout << "Lambda integration is: " 
              << lambda_quadrature_value
              << "\n";

    std::cout << "Actual integral value is: "
              << integral_value
              << "\n";

    std::cout << "Difference with numerical integration is: " 
              << quadrature_value - integral_value
              << "\n";
    std::cout << "Difference with lambda integration is: " 
              << lambda_quadrature_value - integral_value
              << "\n";

    return 0;
}
