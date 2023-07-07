#include "quadrature_order.hpp"

#include <stdexcept>

namespace lebedev
{

constexpr unsigned int number_of_rules = 65;

constexpr unsigned int n_orders = 65;
constexpr std::array<bool, n_orders> rule_availability_table
    = {true,    true,    true,    true,    true,    true,    true,    true,    true,    true,
       true,    true,    true,    true,    true,    false,   true,    false,   false,   true, 
       false,   false,   true,    false,   false,   true,    false,   false,   true,    false,
       false,   true,    false,   false,   true,    false,   false,   true,    false,   false,
       true,    false,   false,   true,    false,   false,   true,    false,   false,   true,
       false,   false,   true,    false,   false,   true,    false,   false,   true,    false,
       false,   true,    false,   false,   true };



constexpr std::array<unsigned int, n_orders> rule_precision_table
    = {   3,   5,   7,   9,  11,  13,  15,  17,  19,  21,
         23,  25,  27,  29,  31,  33,  35,  37,  39,  41,
         43,  45,  47,  49,  51,  53,  55,  57,  59,  61,
         63,  65,  67,  69,  71,  73,  75,  77,  79,  81,
         83,  85,  87,  89,  91,  93,  95,  97,  99, 101,
        103, 105, 107, 109, 111, 113, 115, 117, 119, 121, 
        123, 125, 127, 129, 131 };



constexpr std::array<QuadratureOrder, n_orders> order_enum_table
    = { QuadratureOrder::order_6,
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



LEBEDEV_EXTERNAL_LINKAGE
QuadratureOrder get_rule_order(unsigned int rule_number)
{
    if (rule_number >= number_of_rules)
        throw std::invalid_argument("Requested order of a rule which exceeds number of rules");

    return order_enum_table[rule_number];
}



LEBEDEV_EXTERNAL_LINKAGE
bool get_rule_availability(unsigned int rule_number)
{
    if (rule_number >= number_of_rules)
        throw std::invalid_argument("Requested availability of a rule which exceeds number of rules");

    return rule_availability_table[rule_number];
}



LEBEDEV_EXTERNAL_LINKAGE
unsigned int get_rule_precision(unsigned int rule_number)
{
    if (rule_number >= number_of_rules)
        throw std::invalid_argument("Requested precision of a rule which exceeds number of rules");
    
    return rule_precision_table[rule_number];
}

} // namespace lebedev
