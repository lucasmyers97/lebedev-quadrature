#ifndef LEBEDEV_HPP
#define LEBEDEV_HPP

#ifndef LEBEDEV_HEADER_ONLY
#define LEBEDEV_HEADER_ONLY 1
#endif

#include "lebedev_quadrature.hpp"
#include "quadrature_order.hpp"
#include "generator_point.hpp"

#if LEBEDEV_HEADER_ONLY || LEBEDEV_IMPLEMENTATION

#include "lebedev_quadrature.inl"
#include "quadrature_order.inl"
#include "generator_point.inl"

#endif

#endif
