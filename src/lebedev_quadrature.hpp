#ifndef LEBEDEV_QUADRATURE
#define LEBEDEV_QUADRATURE

#include "octahedral_generator.hpp"

#include <vector>
#include <cmath>
#include <stdexcept>

namespace lebedev {

using vec = std::vector<double>;
using OhPointGen = OctahedralPointGeneration;

enum QuadratureOrder 
{
    order_6 = 6,
    order_14 = 14,
    order_26 = 26,
    order_38 = 38,
    order_50 = 50,
    order_74 = 74,
    order_86 = 86,
    order_110 = 110,
    order_146 = 146,
    order_170 = 170,
    order_194 = 194,
    order_230 = 230,
    order_266 = 266,
    order_302 = 302,
    order_350 = 350,
    order_434 = 434,
    order_590 = 590,
    order_770 = 770,
    order_974 = 974,
    order_1202 = 1202,
    order_1454 = 1454,
    order_1730 = 1730,
    order_2030 = 2030,
    order_2354 = 2354,
    order_2702 = 2702,
    order_3074 = 3074,
    order_3470 = 3470,
    order_3890 = 3890,
    order_4334 = 4334,
    order_4802 = 4802,
    order_5294 = 4294,
    order_5810 = 5810
};



class GeneratorPoint
{
public:

    GeneratorPoint (double a, 
                    double b, 
                    double c, 
                    double weight, 
                    OhPointGen generating_rule)
        : a(a), b(b), c(c), weight(weight), generating_rule(generating_rule)
    {}

    void generate_quadrature_points(vec &x, vec &y, vec &z, vec &w) const
    {
        unsigned int n_points = 0;
        if (generating_rule == OhPointGen::points_6)
        {
            generate_oh_symmetric_points<OhPointGen::points_6> (a, b, c, x, y, z);
            n_points = 6;
        } else if (generating_rule == OhPointGen::points_12)
        {
            generate_oh_symmetric_points<OhPointGen::points_12> (a, b, c, x, y, z);
            n_points = 12;
        } else if (generating_rule == OhPointGen::points_8)
        {
            generate_oh_symmetric_points<OhPointGen::points_8> (a, b, c, x, y, z);
            n_points = 8;
        } else if (generating_rule == OhPointGen::points_24)
        {
            generate_oh_symmetric_points<OhPointGen::points_24> (a, b, c, x, y, z);
            n_points = 24;
        } else if (generating_rule == OhPointGen::points_24_axis)
        {
            generate_oh_symmetric_points<OhPointGen::points_24_axis> (a, b, c, x, y, z);
            n_points = 24;
        } else if (generating_rule == OhPointGen::points_48)
        {
            generate_oh_symmetric_points<OhPointGen::points_48> (a, b, c, x, y, z);
            n_points = 24;
        } else 
        {
            throw std::invalid_argument("Not a valid octahedral generating rule");
        }
        w.insert(w.end(), n_points, weight);
    }

private:
    double a = 1.0;
    double b = 0.0;
    double c = 0.0;
    double weight = 0.1666666666666667;
    
    OhPointGen generating_rule = OhPointGen::points_6;
};



struct QuadraturePoints 
{
    vec x;
    vec y;
    vec z;
    vec weights;
};



template <QuadratureOrder>
inline QuadraturePoints
generate_quadrature_points(const std::vector<GeneratorPoint> &generator_points)
{
    QuadraturePoints quad_points;
    for (const auto& generator_point : generator_points)
        generator_point.generate_quadrature_points(quad_points.x, 
                                                   quad_points.y, 
                                                   quad_points.z,
                                                   quad_points.weights);

    return quad_points;
}



template <QuadratureOrder quad_order>
std::vector<GeneratorPoint> make_generator_points();



template <QuadratureOrder quad_order>
inline QuadraturePoints
generate_quadrature_points()
{
    auto generator_points = make_generator_points<quad_order>();
    return generate_quadrature_points<quad_order>(generator_points);
}



#include "make_generator_points.inst"

} // namespace lebedev

#endif
