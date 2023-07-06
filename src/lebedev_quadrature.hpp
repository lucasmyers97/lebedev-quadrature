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

#include "make_generator_points.inl"



inline QuadraturePoints generate_quadrature_points(QuadratureOrder quad_order)
{
    std::vector<GeneratorPoint> generator_points;
    if (quad_order == QuadratureOrder::order_6   )
        generator_points = make_generator_points<QuadratureOrder::order_6>();
    else if (quad_order == QuadratureOrder::order_14  )
        generator_points = make_generator_points<QuadratureOrder::order_14>();
    else if (quad_order == QuadratureOrder::order_26  )
        generator_points = make_generator_points<QuadratureOrder::order_26>();
    else if (quad_order == QuadratureOrder::order_38  )
        generator_points = make_generator_points<QuadratureOrder::order_38>();
    else if (quad_order == QuadratureOrder::order_50  )
        generator_points = make_generator_points<QuadratureOrder::order_50>();
    else if (quad_order == QuadratureOrder::order_74  )
        generator_points = make_generator_points<QuadratureOrder::order_74>();
    else if (quad_order == QuadratureOrder::order_86  )
        generator_points = make_generator_points<QuadratureOrder::order_86>();
    else if (quad_order == QuadratureOrder::order_110 ) 
        generator_points = make_generator_points<QuadratureOrder::order_110>();
    else if (quad_order == QuadratureOrder::order_146 ) 
        generator_points = make_generator_points<QuadratureOrder::order_146>();
    else if (quad_order == QuadratureOrder::order_170 ) 
        generator_points = make_generator_points<QuadratureOrder::order_170>();
    else if (quad_order == QuadratureOrder::order_194 ) 
        generator_points = make_generator_points<QuadratureOrder::order_194>();
    else if (quad_order == QuadratureOrder::order_230 ) 
        generator_points = make_generator_points<QuadratureOrder::order_230>();
    else if (quad_order == QuadratureOrder::order_266 ) 
        generator_points = make_generator_points<QuadratureOrder::order_266>();
    else if (quad_order == QuadratureOrder::order_302 ) 
        generator_points = make_generator_points<QuadratureOrder::order_302>();
    else if (quad_order == QuadratureOrder::order_350 ) 
        generator_points = make_generator_points<QuadratureOrder::order_350>();
    else if (quad_order == QuadratureOrder::order_434 ) 
        generator_points = make_generator_points<QuadratureOrder::order_434>();
    else if (quad_order == QuadratureOrder::order_590 ) 
        generator_points = make_generator_points<QuadratureOrder::order_590>();
    else if (quad_order == QuadratureOrder::order_770 ) 
        generator_points = make_generator_points<QuadratureOrder::order_770>();
    else if (quad_order == QuadratureOrder::order_974 ) 
        generator_points = make_generator_points<QuadratureOrder::order_974>();
    else if (quad_order == QuadratureOrder::order_1202) 
        generator_points = make_generator_points<QuadratureOrder::order_1202>();
    else if (quad_order == QuadratureOrder::order_1454) 
        generator_points = make_generator_points<QuadratureOrder::order_1454>();
    else if (quad_order == QuadratureOrder::order_1730) 
        generator_points = make_generator_points<QuadratureOrder::order_1730>();
    else if (quad_order == QuadratureOrder::order_2030) 
        generator_points = make_generator_points<QuadratureOrder::order_2030>();
    else if (quad_order == QuadratureOrder::order_2354) 
        generator_points = make_generator_points<QuadratureOrder::order_2354>();
    else if (quad_order == QuadratureOrder::order_2702) 
        generator_points = make_generator_points<QuadratureOrder::order_2702>();
    else if (quad_order == QuadratureOrder::order_3074) 
        generator_points = make_generator_points<QuadratureOrder::order_3074>();
    else if (quad_order == QuadratureOrder::order_3470) 
        generator_points = make_generator_points<QuadratureOrder::order_3470>();
    else if (quad_order == QuadratureOrder::order_3890) 
        generator_points = make_generator_points<QuadratureOrder::order_3890>();
    else if (quad_order == QuadratureOrder::order_4334) 
        generator_points = make_generator_points<QuadratureOrder::order_4334>();
    else if (quad_order == QuadratureOrder::order_4802) 
        generator_points = make_generator_points<QuadratureOrder::order_4802>();
    else if (quad_order == QuadratureOrder::order_5294) 
        generator_points = make_generator_points<QuadratureOrder::order_5294>();
    else if (quad_order == QuadratureOrder::order_5810) 
        generator_points = make_generator_points<QuadratureOrder::order_5810>();
    else
        throw std::invalid_argument("Lebedev order not available");

    return generate_quadrature_points(generator_points);
}



} // namespace lebedev

#endif
