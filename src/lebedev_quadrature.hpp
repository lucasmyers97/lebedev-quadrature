#ifndef LEBEDEV_QUADRATURE
#define LEBEDEV_QUADRATURE

#include <vector>

namespace lebedev {

enum QuadratureOrder {
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



enum OctahedralPointGeneration {
    points_6,
    points_12,
    points_8,
    points_24,
    points_24_axis,
    points_48
};



class QuadraturePoints {
public:
    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> z;
    std::vector<double> weights;
};

} // namespace lebedev

#endif
