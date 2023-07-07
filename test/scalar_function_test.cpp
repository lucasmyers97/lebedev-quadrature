#include "lebedev_quadrature.hpp"

#include <iostream>

double xyz_squared(double x, double y, double z)
{
    return x*x * y*y * z*z;
}

int main()
{
    auto lambda_func = [](double x, double y, double z) { return x*x * y*y * z*z; };

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
