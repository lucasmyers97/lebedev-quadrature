#ifndef OCTAHEDRAL_GENERATOR
#define OCTAHEDRAL_GENERATOR

#include <vector>
#include <cassert>

namespace lebedev {

using vec = std::vector<double>;

enum OctahedralPointGeneration 
{
    points_6,
    points_12,
    points_8,
    points_24,
    points_24_axis,
    points_48
};



template <OctahedralPointGeneration>
void generate_oh_symmetric_points
(double a, double b, double c,vec &x, vec &y, vec &z);



template <>
inline void 
generate_oh_symmetric_points<OctahedralPointGeneration::points_6>
(double a, double b, double c, vec &x, vec &y, vec &z) 
{

    assert((a == 1) && (b == 0) && (c == 0) 
            && "6 point symmetry must have one nonzero component");

    x.insert(x.end(), { a, -a,  0,  0,  0,  0});
    y.insert(y.end(), { 0,  0,  a, -a,  0,  0});
    z.insert(z.end(), { 0,  0,  0,  0,  a, -a});
}



template <>
inline void 
generate_oh_symmetric_points<OctahedralPointGeneration::points_12>
(double a, double b, double c, vec &x, vec &y, vec &z)
{

    assert((b == 0) && (c == 0)
           && "12 point symmetry has two components which are the same");

    x.insert(x.end(), { 0,  0,  0,  0,  a, -a,  a, -a,  a, -a,  a, -a});
    y.insert(y.end(), { a, -a,  a, -a,  0,  0,  0,  0,  a,  a, -a, -a});
    z.insert(z.end(), { a,  a, -a, -a,  a,  a, -a, -a,  0,  0,  0,  0});
}



template <>
inline void 
generate_oh_symmetric_points<OctahedralPointGeneration::points_8>
(double a, double b, double c, vec &x, vec &y, vec &z)
{
    assert((b == 0) && (c == 0)
            && "8 point symmetry has all three components which are the same");

    x.insert(x.end(), { a, -a,  a, -a,  a, -a,  a, -a});
    y.insert(y.end(), { a,  a, -a, -a,  a,  a, -a, -a});
    z.insert(z.end(), { a,  a,  a,  a, -a, -a, -a, -a});
}



template <>
inline void 
generate_oh_symmetric_points<OctahedralPointGeneration::points_24>
(double a, double b, double c, vec &x, vec &y, vec &z)
{
    assert((c == 0)
            && "24 points symmetry has form (a, a, b), so c = 0");
    
    x.insert(x.end(), { a, -a,  a, -a,  a, -a,  a, -a,  a, -a,  a, -a});
    y.insert(y.end(), { a,  a, -a, -a,  a,  a, -a, -a,  b,  b, -b, -b});
    z.insert(z.end(), { b,  b,  b,  b, -b, -b, -b, -b,  a,  a,  a,  a});

    x.insert(x.end(), { a, -a,  a, -a,  b, -b,  b, -b,  b, -b,  b, -b});
    y.insert(y.end(), { b,  b, -b, -b,  a,  a, -a, -a,  a,  a, -a, -a});
    z.insert(z.end(), {-a, -a, -a, -a,  a,  a,  a,  a, -a, -a, -a, -a});
}



template <>
inline void 
generate_oh_symmetric_points<OctahedralPointGeneration::points_24_axis>
(double a, double b, double c, vec &x, vec &y, vec &z)
{
    assert((c == 0)
            && "24 points symmetry (axis) has form (a, b, 0), so c = 0");

    x.insert(x.end(), { a, -a,  a, -a,  b, -b,  b, -b,  a, -a,  a, -a});
    y.insert(y.end(), { b,  b, -b, -b,  a,  a, -a, -a,  0,  0,  0,  0});
    z.insert(z.end(), { 0,  0,  0,  0,  0,  0,  0,  0,  b,  b, -b, -b});

    x.insert(x.end(), { b, -b,  b, -b,  0,  0,  0,  0,  0,  0,  0,  0});
    y.insert(y.end(), { 0,  0,  0,  0,  a, -a,  a, -a,  b, -b,  b, -b});
    z.insert(z.end(), { a,  a, -a, -a,  b,  b, -b, -b,  a,  a, -a, -a});
}



template <>
inline void
generate_oh_symmetric_points<OctahedralPointGeneration::points_48>
(double a, double b, double c, vec &x, vec &y, vec &z)
{
    x.insert(x.end(), { a, -a,  a, -a,  a, -a,  a, -a,  a, -a,  a, -a});
    y.insert(y.end(), { b,  b, -b, -b,  b,  b, -b, -b,  c,  c, -c, -c});
    z.insert(z.end(), { c,  c,  c,  c, -c, -c, -c, -c,  b,  b,  b,  b});

    x.insert(x.end(), { a, -a,  a, -a,  b, -b,  b, -b,  b, -b,  b, -b});
    y.insert(y.end(), { c,  c, -c, -c,  a,  a, -a, -a,  a,  a, -a, -a});
    z.insert(z.end(), {-b, -b, -b, -b,  c,  c,  c,  c, -c, -c, -c, -c});

    x.insert(x.end(), { b, -b,  b, -b,  b, -b,  b, -b,  c, -c,  c, -c});
    y.insert(y.end(), { c,  c, -c, -c,  c,  c, -c, -c,  a,  a, -a, -a});
    z.insert(z.end(), { a,  a,  a,  a, -a, -a, -a, -a,  b,  b,  b,  b});

    x.insert(x.end(), { c, -c,  c, -c,  c, -c,  c, -c,  c, -c,  c, -c});
    y.insert(y.end(), { a,  a, -a, -a,  b,  b, -b, -b,  b,  b, -b, -b});
    z.insert(z.end(), {-b, -b, -b, -b,  a,  a,  a,  a, -a, -a, -a, -a});
}

} // namespace lebedev

#endif
