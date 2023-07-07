#ifndef QUADRATURE_POINTS_HPP
#define QUADRATURE_POINTS_HPP

#include "quadrature_order.hpp"

#include <vector>
#include <functional>

namespace lebedev {

using vec = std::vector<double>;

class QuadraturePoints 
{
using vec = std::vector<double>;
using scalar_function = std::function<double(double, double, double)>;
using vector_function = std::function<vec(vec, vec, vec, vec)>;

public:
    inline QuadraturePoints(QuadratureOrder quad_order);

    double evaluate_spherical_integral(scalar_function integrand_at_point);
    double evaluate_spherical_integral(vector_function integrand_at_points);

    const vec& get_x() const;
    const vec& get_y() const;
    const vec& get_z() const;
    const vec& get_weights() const;

private:

    vec x;
    vec y;
    vec z;
    vec weights;
};

} // namespace lebedev

#endif
