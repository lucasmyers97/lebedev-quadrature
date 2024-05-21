# Lebedev Quadrature

## Basic info


Lebedev quadrature is a scheme for numerically computing integrals around the unit sphere:
```math
\int_{S^2} f(x, y, z) \, d^3 x
=
\int_0^{2\pi} d\phi \int_0^\pi \sin\theta \, d\theta f(\theta, \phi)
\approx
4 \pi
\sum_k f(x_k, y_k, z_k) \, w_k
```

where $S^2$ is the regular $2D$ sphere, $(x_k, y_k, z_k)$ are the Lebedev quadrature points, and $w_k$ are the quadrature weights.

## Library features

* Pure C++ library for computing spherical integrals with Lebedev quadrature
* No dependencies -- only uses standard library
* Header only, with the option to compile a shared or static library to speed up compilation
* Can be included as a git submodule for easy inclusion in project

## Basic usage

Create a `lebedev::QuadraturePoints` by passing in a `lebedev::QuadratureOrder` enum (to see which orders are available, [see below](#available-quadrature-orders)):
```cpp
#include <lebedev_quadrature.hpp>

auto quad_order = lebedev::QuadratureOrder::order_590;
auto quad_points = lebedev::QuadraturePoints(quad_order);
```
From this, one can pass in a function which evaluates the integrand at a point and returns a value:
```cpp
// define a regular function
double xyz_squared(double x, double y, double z)
{
    return x*x * y*y * z*z;
}

// or a lambda function
auto lambda_func = [](double x, double y, double z) { return x*x * y*y * z*z; };

double quadrature_value = quad_points.evaluate_spherical_integral(xyz_squared);
double lambda_quadrature_value = quad_points.evaluate_spherical_integral(lambda_func);
```
or a function which takes all of the quadrature points and returns a vector that is the integrand evaluated at all the quadrature points:
```cpp
using vec = std::vector<double>;

// define a regular function
vec xyz_squared(const vec& x, const vec& y, const vec& z)
{
    vec return_vec(x.size());
    for (std::size_t i = 0; i < x.size(); ++i)
        return_vec[i] = x[i]*x[i] * y[i]*y[i] * z[i]*z[i];

    return return_vec;
}

// or a lambda function
auto lambda_func = [](const vec& x, const vec& y, const vec& z) { 
                        vec return_vec(x.size());
                        for (std::size_t i = 0; i < x.size(); ++i)
                            return_vec[i] = x[i]*x[i] * y[i]*y[i] * z[i]*z[i];

                        return return_vec;
                   };

auto quadrature_value = quad_points.evaluate_spherical_integral(xyz_squared);
auto lambda_quadrature_value = quad_points.evaluate_spherical_integral(lambda_func);
```
Alternatively, you can get directly get `const` references the quadrature points and weights (in case you need it for optimization purposes).
```cpp
auto qx = quad_points.get_x();
auto qy = quad_points.get_y();
auto qz = quad_points.get_z();
auto qw = quad_points.get_weights();

double quadrature_value = 0.0;
for (std::size_t i = 0; i < w.size(); ++i)
    quadrature_value += (x[i]*x[i] * y[i]*y[i] * z[i]*z[i]) * w[i];

quadrature_value *= 4 * M_PI;
```

## Library installation

### Header only

1. Clone the repository from GitHub
2. Add `lebedev/src` to your include paths
3. `#include <lebedev_quadrature.hpp>`

### Compiled library

If you include the headers from this library in a large number of compilation units it may slow down compilation time.
To bypass this, you must compile the library to a shared or static library within your project.

1. Write a global header in your project which includes `lebedev_quadrature`, and set the `LEBEDEV_HEADER_ONLY` macro to `0`.
```cpp
// lebedev_implementation.hpp
// this is a global header in your project which you will include in many 
// compilation units

#define LEBEDEV_HEADER_ONLY 0
#include <lebedev_quadrature.hpp>
```

2. Define `#LEBEDEV_IMPLEMENTATION` before including  `global_header.hpp`
```cpp
// lebedev_implementation.cpp

#define LEBEDEV_IMPLEMENTATION
#include "lebedev_implementation.hpp"
```

If you are using CMake for your project, you can create an internal library that you can link to:
```cmake
add_library(lebedev_implementation
    lebedev_implementation.cpp)
target_include_directories(lebedev_implementation
    PRIVATE
    path/to/lebedev_quadrature/src)
target_include_directories(lebedev_implementation
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR})
```

### Git Submodule

```
git submodule add --depth 1 https://github.com/lucasmyers97/lebedev-quadrature.git lebedev-quadrature
```

## Implementation details

For implementation details, see [here](src/README.md).

## Tests

Lebedev quadrature is designed to exactly integrate polynomials up to some degree which is dependent on the order of quadrature ([see below](#available-quadrature-orders) for details).
Hence, to test for bugs in this implementation we numerically integrate all monomials of the proper degree and compare that with analytic answers (indeed, there is a way to exactly integrate polynomials on the sphere).
See the [here](test/README.md).

## Sources

This is essentially a rewrite of [code by John Burkardt and Dmitri Laikov](https://people.sc.fsu.edu/~jburkardt/cpp_src/sphere_lebedev_rule/sphere_lebedev_rule.html).
It's lovely code and works perfectly, but it's basically just C.
I thought it might be nice to rewrite in (somewhat modern) C++ to use things like RAII and objects.
I also took the opportunity to try to make the intent of the code a little more explicit in the README files.
Finally, I included a function which will calculate the integral, given a `std::function` object and a `lebedev::QuadraturePoints` (for ease of operation). 

## Available quadrature orders {#available-quadrature-orders}

Below is a table which gives the rule number (this is just a way to enumerate the rules), whether it is available in this library, the precision (i.e. the degree of polynomial it can exactly integrate), and the order (i.e. the number of points in the quadrature scheme).
If you're interested in doing this programmatically, the `get_rule_order(unsigned int rule_number)`, `get_rule_availability(unsigned int rule_number)`, and `get_rule_precision(unsigned int rule_number)` functions all do what their names suggest.

| Rule number | Available | Precision | Order |
|-------------|-----------|-----------|-------|
| 0           | yes       | 3         | 6     | 
| 1           | yes       | 5         | 14    | 
| 2           | yes       | 7         | 26    | 
| 3           | yes       | 9         | 38    | 
| 4           | yes       | 11        | 50    | 
| 5           | yes       | 13        | 74    | 
| 6           | yes       | 15        | 86    | 
| 7           | yes       | 17        | 110   | 
| 8           | yes       | 19        | 146   | 
| 9           | yes       | 21        | 170   | 
| 10          | yes       | 23        | 194   | 
| 11          | yes       | 25        | 230   | 
| 12          | yes       | 27        | 266   | 
| 13          | yes       | 29        | 302   | 
| 14          | yes       | 31        | 350   | 
| 15          | no        | 33        | 386   | 
| 16          | yes       | 35        | 434   | 
| 17          | no        | 37        | 482   | 
| 18          | no        | 39        | 530   | 
| 19          | yes       | 41        | 590   | 
| 20          | no        | 43        | 650   | 
| 21          | no        | 45        | 698   | 
| 22          | yes       | 47        | 770   | 
| 23          | no        | 49        | 830   | 
| 24          | no        | 51        | 890   | 
| 25          | yes       | 53        | 974   | 
| 26          | no        | 55        | 1046  | 
| 27          | no        | 57        | 1118  | 
| 28          | yes       | 59        | 1202  | 
| 29          | no        | 61        | 1274  | 
| 30          | no        | 63        | 1358  | 
| 31          | yes       | 65        | 1454  | 
| 32          | no        | 67        | 1538  | 
| 33          | no        | 69        | 1622  | 
| 34          | yes       | 71        | 1730  | 
| 35          | no        | 73        | 1814  | 
| 36          | no        | 75        | 1910  | 
| 37          | yes       | 77        | 2030  | 
| 38          | no        | 79        | 2126  | 
| 39          | no        | 81        | 2222  | 
| 40          | yes       | 83        | 2354  | 
| 41          | no        | 85        | 2450  | 
| 42          | no        | 87        | 2558  | 
| 43          | yes       | 89        | 2702  | 
| 44          | no        | 91        | 2810  | 
| 45          | no        | 93        | 2930  | 
| 46          | yes       | 95        | 3074  | 
| 47          | no        | 97        | 3182  | 
| 48          | no        | 99        | 3314  | 
| 49          | yes       | 101       | 3470  | 
| 50          | no        | 103       | 3590  | 
| 51          | no        | 105       | 3722  | 
| 52          | yes       | 107       | 3890  | 
| 53          | no        | 109       | 4010  | 
| 54          | no        | 111       | 4154  | 
| 55          | yes       | 113       | 4334  | 
| 56          | no        | 115       | 4466  | 
| 57          | no        | 117       | 4610  | 
| 58          | yes       | 119       | 4802  | 
| 59          | no        | 121       | 4934  | 
| 60          | no        | 123       | 5090  | 
| 61          | yes       | 125       | 5294  | 
| 62          | no        | 127       | 5438  | 
| 63          | no        | 129       | 5606  | 
| 64          | yes       | 131       | 5810  | 
