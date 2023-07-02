#include <iostream>

#include "lebedev_quadrature.hpp"

int main()
{
    constexpr auto order = lebedev::QuadratureOrder::order_590;
    auto quad_points = lebedev::generate_quadrature_points<order>();

    for (std::size_t i = 0; i < quad_points.x.size(); ++i)
        std::cout << "[" 
            << quad_points.x[i] << ", " 
            << quad_points.y[i] << ", " 
            << quad_points.z[i] << "],\n";

    return 0;
}
