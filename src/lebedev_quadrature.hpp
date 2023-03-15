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
std::vector<GeneratorPoint> make_generator_points();



template <>
inline std::vector<GeneratorPoint> 
make_generator_points<QuadratureOrder::order_6>()
{
    return {
        {1.0, 0.0, 0.0, 0.1666666666666667, OhPointGen::points_6}
    };
}



template <>
inline std::vector<GeneratorPoint> 
make_generator_points<QuadratureOrder::order_14>()
{
    return {
        {1.0,     0.0, 0.0, 0.6666666666666667e-1, OhPointGen::points_6},
        {1.0/3.0, 0.0, 0.0, 0.7500000000000000e-1, OhPointGen::points_8}
    };
}



template <>
inline std::vector<GeneratorPoint> 
make_generator_points<QuadratureOrder::order_26>()
{
    return {
        {1.0,       0.0, 0.0, 0.4761904761904762e-1, OhPointGen::points_6},
        {sqrt(0.5), 0.0, 0.0, 0.3809523809523810e-1, OhPointGen::points_12},
        {1.0/3.0,   0.0, 0.0, 0.3214285714285714e-1, OhPointGen::points_8}
    };
}



template <>
inline std::vector<GeneratorPoint> 
make_generator_points<QuadratureOrder::order_38>()
{
    double a = 0.4597008433809831;
    return {
        {1.0,       0.0, 0.0, 0.9523809523809524e-2, OhPointGen::points_6},
        {1.0/3.0,   0.0, 0.0, 0.3214285714285714e-1, OhPointGen::points_8},
        {a, sqrt(1.0 - a * a), 0.0, 0.2857142857142857e-1, OhPointGen::points_24_axis}
    };
}



template <>
inline std::vector<GeneratorPoint> 
make_generator_points<QuadratureOrder::order_50>()
{
    double a = 0.3015113445777636;
    return {
        {1.0,       0.0, 0.0, 0.1269841269841270e-1, OhPointGen::points_6},
        {sqrt(0.5), 0.0, 0.0, 0.2257495590828924e-1, OhPointGen::points_12},
        {1.0/3.0,   0.0, 0.0, 0.2109375000000000e-1, OhPointGen::points_8},
        {a, sqrt(1.0 - 2.0 * a * a), 0.0, 0.2017333553791887e-1, OhPointGen::points_24}
    };
}




template <>
inline std::vector<GeneratorPoint> 
make_generator_points<QuadratureOrder::order_74>()
{
    double a1 = 0.4803844614152614;
    double a2 = 0.3207726489807764;
    return {
        {1.0,       0.0, 0.0, 0.5130671797338464e-3, OhPointGen::points_6},
        {sqrt(0.5), 0.0, 0.0, 0.1660406956574204e-1, OhPointGen::points_12},
        {1.0/3.0,   0.0, 0.0, -0.2958603896103896e-1, OhPointGen::points_8},
        {a1, sqrt(1.0 - 2.0 * a1 * a1), 0.0, 0.2657620708215946e-1, OhPointGen::points_24},
        {a2, sqrt(1.0 - a2 * a2), 0.0, 0.1652217099371571e-1, OhPointGen::points_24_axis}
    };
}



template <>
inline std::vector<GeneratorPoint> 
make_generator_points<QuadratureOrder::order_86>()
{
    double a1 = 0.3696028464541502;
    double a2 = 0.6943540066026664;
    double a3 = 0.3742430390903412;
    return {
        {1.0,       0.0, 0.0, 0.1154401154401154e-1, OhPointGen::points_6},
        {1.0/3.0,   0.0, 0.0, 0.1194390908585628e-1, OhPointGen::points_8},
        {a1, sqrt(1.0 - 2.0 * a1 * a1), 0.0, 0.1111055571060340e-1, OhPointGen::points_24},
        {a2, sqrt(1.0 - 2.0 * a2 * a2), 0.0, 0.1187650129453714e-1, OhPointGen::points_24},
        {a3, sqrt(1.0 - a3 * a3), 0.0, 0.1181230374690448e-1, OhPointGen::points_24_axis}
    };
}



template <>
inline std::vector<GeneratorPoint> 
make_generator_points<QuadratureOrder::order_110>()
{
    double a1 = 0.1851156353447362;
    double a2 = 0.6904210483822922;
    double a3 = 0.3956894730559419;
    double a4 = 0.4783690288121502;
    return {
        {1.0,       0.0, 0.0, 0.3828270494937162e-2, OhPointGen::points_6},
        {1.0/3.0,   0.0, 0.0, 0.9793737512487512e-2, OhPointGen::points_8},
        {a1, sqrt(1.0 - 2.0 * a1 * a1), 0.0, 0.8211737283191111e-2, OhPointGen::points_24},
        {a2, sqrt(1.0 - 2.0 * a2 * a2), 0.0, 0.9942814891178103e-2, OhPointGen::points_24},
        {a3, sqrt(1.0 - 2.0 * a3 * a3), 0.0, 0.9595471336070963e-2, OhPointGen::points_24},
        {a4, sqrt(1.0 - a4 * a4), 0.0, 0.9694996361663028e-2, OhPointGen::points_24_axis}
    };
}



template <>
inline std::vector<GeneratorPoint> 
make_generator_points<QuadratureOrder::order_146>()
{
    double a1 = 0.6764410400114264;
    double a2 = 0.4174961227965453;
    double a3 = 0.1574676672039082;
    double a4 = 0.1403553811713183;
    double b4 = 0.4493328323269557;
    return {
        {1.0,       0.0, 0.0, 0.5996313688621381e-3, OhPointGen::points_6},
        {sqrt(0.5),   0.0, 0.0, 0.7372999718620756e-2, OhPointGen::points_12},
        {1.0/3.0,   0.0, 0.0, 0.7210515360144488e-2, OhPointGen::points_8},
        {a1, sqrt(1.0 - 2.0 * a1 * a1), 0.0, 0.7116355493117555e-2, OhPointGen::points_24},
        {a2, sqrt(1.0 - 2.0 * a2 * a2), 0.0, 0.6753829486314477e-2, OhPointGen::points_24},
        {a3, sqrt(1.0 - 2.0 * a3 * a3), 0.0, 0.7574394159054034e-2, OhPointGen::points_24},
        {a4, b4, sqrt (1.0 - a4 * a4 - b4 * b4), 0.6991087353303262e-2, OhPointGen::points_48}
    };
}



template <>
inline std::vector<GeneratorPoint>
make_generator_points<QuadratureOrder::order_170>()
{
    double a1 = 0.2551252621114134;
    double a2 = 0.6743601460362766;
    double a3 = 0.4318910696719410;
    double a4 = 0.2613931360335988;
    double a5 = 0.4990453161796037;
    double b5 = 0.1446630744325115;

    return {
        {1.0,       0.0, 0.0, 0.5544842902037365e-2, OhPointGen::points_6},
        {sqrt(0.5),   0.0, 0.0, 0.6071332770670752e-2, OhPointGen::points_12},
        {1.0/3.0,   0.0, 0.0, 0.6383674773515093e-2, OhPointGen::points_8},
        {a1, sqrt(1.0 - 2.0 * a1 * a1), 0.0, 0.5183387587747790e-2, OhPointGen::points_24},
        {a2, sqrt(1.0 - 2.0 * a2 * a2), 0.0, 0.6317929009813725e-2, OhPointGen::points_24},
        {a3, sqrt(1.0 - 2.0 * a3 * a3), 0.0, 0.6201670006589077e-2, OhPointGen::points_24},
        {a4, sqrt(1.0 - a4 * a4), 0.0, 0.5477143385137348e-2, OhPointGen::points_24_axis},
        {a5, b5, sqrt (1.0 - a5 * a5 - b5 * b5), 0.5968383987681156e-2, OhPointGen::points_48}
    };
}



template <>
inline std::vector<GeneratorPoint>
make_generator_points<QuadratureOrder::order_194>()
{
    double a1 = 0.6712973442695226;
    double a2 = 0.2892465627575439;
    double a3 = 0.4446933178717437;
    double a4 = 0.1299335447650067;
    double a5 = 0.3457702197611283;
    double a6 = 0.1590417105383530;
    double b6 = 0.8360360154824589;
    return {
        {1.0,       0.0, 0.0, 0.1782340447244611e-2, OhPointGen::points_6},
        {sqrt(0.5),   0.0, 0.0, 0.5716905949977102e-2, OhPointGen::points_12},
        {1.0/3.0,   0.0, 0.0, 0.5573383178848738e-2, OhPointGen::points_8},
        {a1, sqrt(1.0 - 2.0 * a1 * a1), 0.0, 0.5608704082587997e-2, OhPointGen::points_24},
        {a2, sqrt(1.0 - 2.0 * a2 * a2), 0.0, 0.5518771467273614e-2, OhPointGen::points_24},
        {a3, sqrt(1.0 - 2.0 * a3 * a3), 0.0, 0.6201670006589077e-2, OhPointGen::points_24},
        {a4, sqrt(1.0 - 2.0 * a4 * a4), 0.0, 0.4106777028169394e-2, OhPointGen::points_24},
        {a5, sqrt(1.0 - a5 * a5), 0.0, 0.5051846064614808e-2, OhPointGen::points_24_axis},
        {a6, b6, sqrt (1.0 - a6 * a6 - b6 * b6), 0.5530248916233094e-2, OhPointGen::points_48}
    };
}




template <>
inline std::vector<GeneratorPoint>
make_generator_points<QuadratureOrder::order_230>()
{
    double a1 = 0.4492044687397611;
    double a2 = 0.2520419490210201;
    double a3 = 0.6981906658447242;
    double a4 = 0.6587405243460960;
    double a5 = 0.4038544050097660e-1;
    double a6 = 0.5823842309715585;
    double a7 = 0.3545877390518688;
    double a8 = 0.2272181808998187;
    double b8 = 0.4864661535886647;
    return {
        {1.0,       0.0, 0.0, -0.5522639919727325e-1, OhPointGen::points_6},
        {1.0/3.0,   0.0, 0.0, 0.4450274607445226e-2, OhPointGen::points_8},
        {a1, sqrt(1.0 - 2.0 * a1 * a1), 0.0, 0.4496841067921404e-2, OhPointGen::points_24},
        {a2, sqrt(1.0 - 2.0 * a2 * a2), 0.0, 0.5049153450478750e-2, OhPointGen::points_24},
        {a3, sqrt(1.0 - 2.0 * a3 * a3), 0.0, 0.3976408018051883e-2, OhPointGen::points_24},
        {a4, sqrt(1.0 - 2.0 * a4 * a4), 0.0, 0.4401400650381014e-2, OhPointGen::points_24},
        {a5, sqrt(1.0 - 2.0 * a5 * a5), 0.0, 0.1724544350544401e-1, OhPointGen::points_24},
        {a6, sqrt(1.0 - a6 * a6), 0.0, 0.4231083095357343e-2, OhPointGen::points_24_axis},
        {a7, sqrt(1.0 - a7 * a7), 0.0, 0.5198069864064399e-2, OhPointGen::points_24_axis},
        {a8, b8, sqrt (1.0 - a8 * a8 - b8 * b8), 0.4695720972568883e-2, OhPointGen::points_48}
    };
}



template <>
inline std::vector<GeneratorPoint>
make_generator_points<QuadratureOrder::order_266>()
{  
    double a1 = 0.7039373391585475;
    double a2 = 0.1012526248572414;
    double a3 = 0.4647448726420539;
    double a4 = 0.3277420654971629;
    double a5 = 0.6620338663699974;
    double a6 = 0.8506508083520399;
    double a7 = 0.3233484542692899;
    double b7 = 0.1153112011009701;
    double a8 = 0.2314790158712601;
    double b8 = 0.5244939240922365;
    return {
        {1.0,       0.0, 0.0, -0.1313769127326952e-2, OhPointGen::points_6},
        {sqrt(0.5),   0.0, 0.0, -0.2522728704859336e-2, OhPointGen::points_12},
        {1.0/3.0,   0.0, 0.0, 0.4186853881700583e-2, OhPointGen::points_8},
        {a1, sqrt(1.0 - 2.0 * a1 * a1), 0.0, 0.5315167977810885e-2, OhPointGen::points_24},
        {a2, sqrt(1.0 - 2.0 * a2 * a2), 0.0, 0.4047142377086219e-2, OhPointGen::points_24},
        {a3, sqrt(1.0 - 2.0 * a3 * a3), 0.0, 0.4112482394406990e-2, OhPointGen::points_24},
        {a4, sqrt(1.0 - 2.0 * a4 * a4), 0.0, 0.3595584899758782e-2, OhPointGen::points_24},
        {a5, sqrt(1.0 - 2.0 * a5 * a5), 0.0, 0.4256131351428158e-2, OhPointGen::points_24},
        {a6, sqrt(1.0 - a6 * a6), 0.0, 0.4229582700647240e-2, OhPointGen::points_24_axis},
        {a7, b7, sqrt (1.0 - a7 * a7 - b7 * b7), 0.4080914225780505e-2, OhPointGen::points_48},
        {a8, b8, sqrt (1.0 - a8 * a8 - b8 * b8), 0.4071467593830964e-2, OhPointGen::points_48}
    };
}



template <>
inline std::vector<GeneratorPoint>
make_generator_points<QuadratureOrder::order_302>()
{  
    double a1 = 0.3515640345570105;
    double a2 = 0.6566329410219612;
    double a3 = 0.4729054132581005;
    double a4 = 0.9618308522614784e-1;
    double a5 = 0.2219645236294178;
    double a6 = 0.7011766416089545;
    double a7 = 0.2644152887060663;
    double a8 = 0.5718955891878961;
    double a9 = 0.2510034751770465;
    double b9 = 0.8000727494073952;
    double a10 = 0.1233548532583327;
    double b10 = 0.4127724083168531;
    return {
        {1.0,       0.0, 0.0, 0.8545911725128148e-3, OhPointGen::points_6},
        {1.0/3.0,   0.0, 0.0, 0.3599119285025571e-2, OhPointGen::points_8},
        {a1, sqrt(1.0 - 2.0 * a1 * a1), 0.0, 0.3449788424305883e-2, OhPointGen::points_24},
        {a2, sqrt(1.0 - 2.0 * a2 * a2), 0.0, 0.3604822601419882e-2, OhPointGen::points_24},
        {a3, sqrt(1.0 - 2.0 * a3 * a3), 0.0, 0.3576729661743367e-2, OhPointGen::points_24},
        {a4, sqrt(1.0 - 2.0 * a4 * a4), 0.0, 0.2352101413689164e-2, OhPointGen::points_24},
        {a5, sqrt(1.0 - 2.0 * a5 * a5), 0.0, 0.3108953122413675e-2, OhPointGen::points_24},
        {a6, sqrt(1.0 - 2.0 * a6 * a6), 0.0, 0.3650045807677255e-2, OhPointGen::points_24},
        {a7, sqrt(1.0 - a7 * a7), 0.0, 0.2982344963171804e-2, OhPointGen::points_24_axis},
        {a8, sqrt(1.0 - a8 * a8), 0.0, 0.3600820932216460e-2, OhPointGen::points_24_axis},
        {a9, b9, sqrt (1.0 - a9 * a9 - b9 * b9), 0.3571540554273387e-2, OhPointGen::points_48},
        {a10, b10, sqrt (1.0 - a10 * a10 - b10 * b10), 0.3392312205006170e-2, OhPointGen::points_48}
    };
}



template <>
inline std::vector<GeneratorPoint>
make_generator_points<QuadratureOrder::order_350>()
{  
    double a1 = 0.7068965463912316;
    double a2 = 0.4794682625712025;
    double a3 = 0.1927533154878019;
    double a4 = 0.6930357961327123;
    double a5 = 0.3608302115520091;
    double a6 = 0.6498486161496169;
    double a7 = 0.1932945013230339;
    double a8 = 0.3800494919899303;
    double a9 = 0.2899558825499574;
    double b9 = 0.7934537856582316;
    double a10 = 0.9684121455103957e-1;
    double b10 = 0.8280801506686862;
    double a11 = 0.1833434647041659;
    double b11 = 0.9074658265305127;
    return {
        {1.0,       0.0, 0.0, 0.3006796749453936e-2, OhPointGen::points_6},
        {1.0/3.0,   0.0, 0.0, 0.3050627745650771e-2, OhPointGen::points_8},
        {a1, sqrt(1.0 - 2.0 * a1 * a1), 0.0, 0.1621104600288991e-2, OhPointGen::points_24},
        {a2, sqrt(1.0 - 2.0 * a2 * a2), 0.0, 0.3005701484901752e-2, OhPointGen::points_24},
        {a3, sqrt(1.0 - 2.0 * a3 * a3), 0.0, 0.2990992529653774e-2, OhPointGen::points_24},
        {a4, sqrt(1.0 - 2.0 * a4 * a4), 0.0, 0.2982170644107595e-2, OhPointGen::points_24},
        {a5, sqrt(1.0 - 2.0 * a5 * a5), 0.0, 0.2721564237310992e-2, OhPointGen::points_24},
        {a6, sqrt(1.0 - 2.0 * a6 * a6), 0.0, 0.3033513795811141e-2, OhPointGen::points_24},
        {a7, sqrt(1.0 - a7 * a7), 0.0, 0.3007949555218533e-2, OhPointGen::points_24_axis},
        {a8, sqrt(1.0 - a8 * a8), 0.0, 0.2881964603055307e-2, OhPointGen::points_24_axis},
        {a9, b9, sqrt (1.0 - a9 * a9 - b9 * b9), 0.2958357626535696e-2, OhPointGen::points_48},
        {a10, b10, sqrt (1.0 - a10 * a10 - b10 * b10), 0.3036020026407088e-2, OhPointGen::points_48},
        {a11, b11, sqrt (1.0 - a11 * a11 - b11 * b11), 0.2832187403926303e-2, OhPointGen::points_48}
    };
}



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

} // namespace lebedev

#endif
