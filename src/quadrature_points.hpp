#ifndef QUADRATURE_POINTS_HPP
#define QUADRATURE_POINTS_HPP

#include "preprocessor.hpp"
#include "quadrature_order.hpp"

#include <vector>
#include <functional>

namespace lebedev {

using vec = std::vector<double>;

class QuadraturePoints 
{
using vec = std::vector<double>;
using scalar_function = std::function<double(double, double, double)>;
using vector_function = std::function<vec(vec, vec, vec)>;

public:
    LEBEDEV_EXTERNAL_LINKAGE
    QuadraturePoints(QuadratureOrder quad_order);

    LEBEDEV_EXTERNAL_LINKAGE
    double 
    evaluate_spherical_integral(const scalar_function& integrand_at_point) const;

    LEBEDEV_EXTERNAL_LINKAGE
    double 
    evaluate_spherical_integral(const vector_function& integrand_at_points) const;

    LEBEDEV_EXTERNAL_LINKAGE const vec& get_x() const;
    LEBEDEV_EXTERNAL_LINKAGE const vec& get_y() const;
    LEBEDEV_EXTERNAL_LINKAGE const vec& get_z() const;
    LEBEDEV_EXTERNAL_LINKAGE const vec& get_weights() const;

private:

    vec x;
    vec y;
    vec z;
    vec weights;
};

} // namespace lebedev

#endif
