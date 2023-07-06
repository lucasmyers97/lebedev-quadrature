#ifndef QUADRATURE_ORDER
#define QUADRATURE_ORDER

#include <array>

namespace lebedev {

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

} // namespace lebedev

#endif
