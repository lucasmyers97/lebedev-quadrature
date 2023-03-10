# Lebedev Quadrature

## Basic info

* Pure C++ library for computing spherical integrals with Lebedev quadrature
* No dependencies -- only uses standard library
* Header only
* Integrates CMake for use as a package in another CMake project, or you can just copy the header files into your includes

## Sources

This is essentially a rewrite of [code by John Burkardt and Dmitri Laikov](https://people.sc.fsu.edu/~jburkardt/cpp_src/sphere_lebedev_rule/sphere_lebedev_rule.html).
It's lovely code and works perfectly, but it's basically just C.
I thought it might be nice to rewrite in (somewhat modern) C++ to use things like RAII and objects.
I also took the opportunity to try to make the intent of the code a little more explicit, and document with Doxygen friendly comments.
Finally, I included a function which will calculate the integral, given a `std::function` object and a `lebedev::QuadraturePoints` (for ease of operation). 
