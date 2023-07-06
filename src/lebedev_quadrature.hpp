#ifndef LEBEDEV_QUADRATURE_HPP
#define LEBEDEV_QUADRATURE_HPP
#include "octahedral_generator.hpp"
#include "quadrature_order.hpp"

#include <vector>
#include <array>
#include <cmath>
#include <stdexcept>

namespace lebedev {

using vec = std::vector<double>;

struct QuadraturePoints 
{
    vec x;
    vec y;
    vec z;
    vec weights;
};



inline QuadraturePoints generate_quadrature_points(QuadratureOrder quad_order);

} // namespace lebedev

#endif
