#ifndef LEBEDEV_QUADRATURE
#define LEBEDEV_QUADRATURE

#include "octahedral_generator.hpp"

#include <vector>
#include <stdexcept>

namespace lebedev {

using vec = std::vector<double>;

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
    using OhPointGen = OctahedralPointGeneration;

    double a = 1.0;
    double b = 0.0;
    double c = 0.0;
    
    OhPointGen generating_rule = OhPointGen::points_6;

    void generate_quadrature_points(vec &x, vec &y, vec &z)
    {
        switch (generating_rule)
        {
            case OhPointGen::points_6:
                generate_oh_symmetric_points<OhPointGen::points_6> (a, b, c, x, y, z);
                break;
            case OhPointGen::points_12:
                generate_oh_symmetric_points<OhPointGen::points_12> (a, b, c, x, y, z);
                break;
            case OctahedralPointGeneration::points_8:
                generate_oh_symmetric_points<OhPointGen::points_8> (a, b, c, x, y, z);
                break;
            case OctahedralPointGeneration::points_24:
                generate_oh_symmetric_points<OhPointGen::points_24> (a, b, c, x, y, z);
                break;
            case OctahedralPointGeneration::points_24_axis:
                generate_oh_symmetric_points<OhPointGen::points_24_axis> (a, b, c, x, y, z);
                break;
            case OctahedralPointGeneration::points_48:
                generate_oh_symmetric_points<OhPointGen::points_48> (a, b, c, x, y, z);
                break;
            default:
                throw std::invalid_argument("Not a valid octahedral generating rule");
        }
    }
};



class QuadraturePoints 
{
public:
    vec x;
    vec y;
    vec z;
    vec weights;
};

} // namespace lebedev

#endif
