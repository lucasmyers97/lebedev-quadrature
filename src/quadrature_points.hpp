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
using vector_function = std::function<vec(const vec&, const vec&, const vec&)>;

public:
    QuadraturePoints(QuadratureOrder quad_order);

    double 
    evaluate_spherical_integral(const scalar_function& integrand_at_point) const;

    double 
    evaluate_spherical_integral(const vector_function& integrand_at_points) const;

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
