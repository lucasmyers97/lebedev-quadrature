#ifndef LEBEDEV_QUADRATURE
#define LEBEDEV_QUADRATURE

#include "octahedral_generator.hpp"

#include <vector>
#include <array>
#include <cmath>
#include <stdexcept>

namespace lebedev {

using vec = std::vector<double>;
using OhPointGen = OctahedralPointGeneration;

constexpr unsigned int n_orders = 65;
constexpr std::array<bool, n_orders> order_available
    = {true,    true,    true,    true,    true,    true,    true,    true,    true,    true,
       true,    true,    true,    true,    true,    false,   true,    false,   false,   true, 
       false,   false,   true,    false,   false,   true,    false,   false,   true,    false,
       false,   true,    false,   false,   true,    false,   false,   true,    false,   false,
       true,    false,   false,   true,    false,   false,   true,    false,   false,   true,
       false,   false,   true,    false,   false,   true,    false,   false,   true,    false,
       false,   true,    false,   false,   true };

constexpr std::array<unsigned int, n_orders> precision_table
    = {   3,   5,   7,   9,  11,  13,  15,  17,  19,  21,
         23,  25,  27,  29,  31,  33,  35,  37,  39,  41,
         43,  45,  47,  49,  51,  53,  55,  57,  59,  61,
         63,  65,  67,  69,  71,  73,  75,  77,  79,  81,
         83,  85,  87,  89,  91,  93,  95,  97,  99, 101,
        103, 105, 107, 109, 111, 113, 115, 117, 119, 121, 
        123, 125, 127, 129, 131 };

constexpr std::array<unsigned int, n_orders> order_table
    = {    6,   14,   26,   38,   50,   74,   86,  110,  146,  170,
         194,  230,  266,  302,  350,  386,  434,  482,  530,  590, 
         650,  698,  770,  830,  890,  974, 1046, 1118, 1202, 1274,
        1358, 1454, 1538, 1622, 1730, 1814, 1910, 2030, 2126, 2222,
        2354, 2450, 2558, 2702, 2810, 2930, 3074, 3182, 3314, 3470,
        3590, 3722, 3890, 4010, 4154, 4334, 4466, 4610, 4802, 4934,
        5090, 5294, 5438, 5606, 5810 };

enum class QuadratureOrder 
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
    order_386 = 386,
    order_434 = 434,
    order_482 = 482,
    order_530 = 530,
    order_590 = 590,
    order_650 = 650,
    order_698 = 698,
    order_770 = 770,
    order_830 = 830,
    order_890 = 890,
    order_974 = 974,
    order_1046 = 1046,
    order_1118 = 1118,
    order_1202 = 1202,
    order_1274 = 1274,
    order_1358 = 1358,
    order_1454 = 1454,
    order_1538 = 1538,
    order_1622 = 1622,
    order_1730 = 1730,
    order_1814 = 1814,
    order_1910 = 1910,
    order_2030 = 2030,
    order_2126 = 2126,
    order_2222 = 2222,
    order_2354 = 2354,
    order_2450 = 2450,
    order_2558 = 2558,
    order_2702 = 2702,
    order_2810 = 2810,
    order_2930 = 2930,
    order_3074 = 3074,
    order_3182 = 3182,
    order_3314 = 3314,
    order_3470 = 3470,
    order_3590 = 3590,
    order_3722 = 3722,
    order_3890 = 3890,
    order_4010 = 4010,
    order_4154 = 4154,
    order_4334 = 4334,
    order_4466 = 4466,
    order_4610 = 4610,
    order_4802 = 4802,
    order_4934 = 4934,
    order_5090 = 5090,
    order_5294 = 5294,
    order_5438 = 5438,
    order_5606 = 5606,
    order_5810 = 5810 
};

constexpr std::array<QuadratureOrder, n_orders> order_enum_table
    = {
    QuadratureOrder::order_6,
    QuadratureOrder::order_14,
    QuadratureOrder::order_26,
    QuadratureOrder::order_38,
    QuadratureOrder::order_50,
    QuadratureOrder::order_74,
    QuadratureOrder::order_86,
    QuadratureOrder::order_110,
    QuadratureOrder::order_146,
    QuadratureOrder::order_170,
    QuadratureOrder::order_194,
    QuadratureOrder::order_230,
    QuadratureOrder::order_266,
    QuadratureOrder::order_302,
    QuadratureOrder::order_350,
    QuadratureOrder::order_386,
    QuadratureOrder::order_434,
    QuadratureOrder::order_482,
    QuadratureOrder::order_530,
    QuadratureOrder::order_590,
    QuadratureOrder::order_650,
    QuadratureOrder::order_698,
    QuadratureOrder::order_770,
    QuadratureOrder::order_830,
    QuadratureOrder::order_890,
    QuadratureOrder::order_974,
    QuadratureOrder::order_1046,
    QuadratureOrder::order_1118,
    QuadratureOrder::order_1202,
    QuadratureOrder::order_1274,
    QuadratureOrder::order_1358,
    QuadratureOrder::order_1454,
    QuadratureOrder::order_1538,
    QuadratureOrder::order_1622,
    QuadratureOrder::order_1730,
    QuadratureOrder::order_1814,
    QuadratureOrder::order_1910,
    QuadratureOrder::order_2030,
    QuadratureOrder::order_2126,
    QuadratureOrder::order_2222,
    QuadratureOrder::order_2354,
    QuadratureOrder::order_2450,
    QuadratureOrder::order_2558,
    QuadratureOrder::order_2702,
    QuadratureOrder::order_2810,
    QuadratureOrder::order_2930,
    QuadratureOrder::order_3074,
    QuadratureOrder::order_3182,
    QuadratureOrder::order_3314,
    QuadratureOrder::order_3470,
    QuadratureOrder::order_3590,
    QuadratureOrder::order_3722,
    QuadratureOrder::order_3890,
    QuadratureOrder::order_4010,
    QuadratureOrder::order_4154,
    QuadratureOrder::order_4334,
    QuadratureOrder::order_4466,
    QuadratureOrder::order_4610,
    QuadratureOrder::order_4802,
    QuadratureOrder::order_4934,
    QuadratureOrder::order_5090,
    QuadratureOrder::order_5294,
    QuadratureOrder::order_5438,
    QuadratureOrder::order_5606,
    QuadratureOrder::order_5810 
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
            n_points = 48;
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



inline QuadraturePoints generate_quadrature_points(QuadratureOrder quad_order)
{
    QuadraturePoints quad_points;
    if (quad_order == QuadratureOrder::order_6   )
        quad_points = generate_quadrature_points<QuadratureOrder::order_6>();
    else if (quad_order == QuadratureOrder::order_14  )
        quad_points = generate_quadrature_points<QuadratureOrder::order_14>();
    else if (quad_order == QuadratureOrder::order_26  )
        quad_points = generate_quadrature_points<QuadratureOrder::order_26>();
    else if (quad_order == QuadratureOrder::order_38  )
        quad_points = generate_quadrature_points<QuadratureOrder::order_38>();
    else if (quad_order == QuadratureOrder::order_50  )
        quad_points = generate_quadrature_points<QuadratureOrder::order_50>();
    else if (quad_order == QuadratureOrder::order_74  )
        quad_points = generate_quadrature_points<QuadratureOrder::order_74>();
    else if (quad_order == QuadratureOrder::order_86  )
        quad_points = generate_quadrature_points<QuadratureOrder::order_86>();
    else if (quad_order == QuadratureOrder::order_110 ) 
        quad_points = generate_quadrature_points<QuadratureOrder::order_110>();
    else if (quad_order == QuadratureOrder::order_146 ) 
        quad_points = generate_quadrature_points<QuadratureOrder::order_146>();
    else if (quad_order == QuadratureOrder::order_170 ) 
        quad_points = generate_quadrature_points<QuadratureOrder::order_170>();
    else if (quad_order == QuadratureOrder::order_194 ) 
        quad_points = generate_quadrature_points<QuadratureOrder::order_194>();
    else if (quad_order == QuadratureOrder::order_230 ) 
        quad_points = generate_quadrature_points<QuadratureOrder::order_230>();
    else if (quad_order == QuadratureOrder::order_266 ) 
        quad_points = generate_quadrature_points<QuadratureOrder::order_266>();
    else if (quad_order == QuadratureOrder::order_302 ) 
        quad_points = generate_quadrature_points<QuadratureOrder::order_302>();
    else if (quad_order == QuadratureOrder::order_350 ) 
        quad_points = generate_quadrature_points<QuadratureOrder::order_350>();
    else if (quad_order == QuadratureOrder::order_434 ) 
        quad_points = generate_quadrature_points<QuadratureOrder::order_434>();
    else if (quad_order == QuadratureOrder::order_590 ) 
        quad_points = generate_quadrature_points<QuadratureOrder::order_590>();
    else if (quad_order == QuadratureOrder::order_770 ) 
        quad_points = generate_quadrature_points<QuadratureOrder::order_770>();
    else if (quad_order == QuadratureOrder::order_974 ) 
        quad_points = generate_quadrature_points<QuadratureOrder::order_974>();
    else if (quad_order == QuadratureOrder::order_1202) 
        quad_points = generate_quadrature_points<QuadratureOrder::order_1202>();
    else if (quad_order == QuadratureOrder::order_1454) 
        quad_points = generate_quadrature_points<QuadratureOrder::order_1454>();
    else if (quad_order == QuadratureOrder::order_1730) 
        quad_points = generate_quadrature_points<QuadratureOrder::order_1730>();
    else if (quad_order == QuadratureOrder::order_2030) 
        quad_points = generate_quadrature_points<QuadratureOrder::order_2030>();
    else if (quad_order == QuadratureOrder::order_2354) 
        quad_points = generate_quadrature_points<QuadratureOrder::order_2354>();
    else if (quad_order == QuadratureOrder::order_2702) 
        quad_points = generate_quadrature_points<QuadratureOrder::order_2702>();
    else if (quad_order == QuadratureOrder::order_3074) 
        quad_points = generate_quadrature_points<QuadratureOrder::order_3074>();
    else if (quad_order == QuadratureOrder::order_3470) 
        quad_points = generate_quadrature_points<QuadratureOrder::order_3470>();
    else if (quad_order == QuadratureOrder::order_3890) 
        quad_points = generate_quadrature_points<QuadratureOrder::order_3890>();
    else if (quad_order == QuadratureOrder::order_4334) 
        quad_points = generate_quadrature_points<QuadratureOrder::order_4334>();
    else if (quad_order == QuadratureOrder::order_4802) 
        quad_points = generate_quadrature_points<QuadratureOrder::order_4802>();
    else if (quad_order == QuadratureOrder::order_5294) 
        quad_points = generate_quadrature_points<QuadratureOrder::order_5294>();
    else if (quad_order == QuadratureOrder::order_5810) 
        quad_points = generate_quadrature_points<QuadratureOrder::order_5810>();
    else
        throw std::invalid_argument("Lebedev order not available");

    return quad_points;
}



#include "make_generator_points.inst"

} // namespace lebedev

#endif
