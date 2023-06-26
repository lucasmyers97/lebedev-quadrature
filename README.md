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

## Math background

Lebedev quadrature is a method for approximating integrals on the surface of the unit sphere.
This is done by generating sets of points which are invariant under the action of the octahedral rotation group $O$.
These sets of points are assigned weights which are tabulated so as to produce exact integrations for 3D polynomials up to some degree.
In general, the solution for the integral of a monomial over the sphere is given by:
\begin{equation}
\int_{S^2} x^{a} y^{b} z^{c} \, dS
=
\begin{cases}
    2 B \left(\tfrac{a + 1}{2}, \tfrac{b + 1}{2}, \tfrac{c + 1}{2} \right)
    &a, b, c \text{ are even } \\ 
    0
    &\text{otherwise}
\end{cases}
\end{equation}
where
\begin{equation}
B(l, m, n)
=
\frac{\Gamma(l) \Gamma(m) \Gamma(n)}{\Gamma(l + m + n)}
\end{equation}
We may write this in a more easily calculable way [by noting that](https://www.wikiwand.com/en/Particular_values_of_the_gamma_function#Integers_and_half-integers):
\begin{equation}
\Gamma\left(\frac{n}{2}\right)
=
\sqrt{\pi} \frac{(n - 2)!!}{2^{\frac{n - 1}{2}}}
\end{equation}
with
\begin{equation}
n!!
=
\prod_{k = 0}^{\lceil \frac{n}{2} \rceil - 1} (n - 2k)
\end{equation}
Now we seek:
\begin{equation}
\begin{split}
    \Gamma\left( \frac{a + 1}{2} \right)
    &=
    \sqrt{\pi} \frac{(a - 1)!!}{2^{\frac{a}{2}}} \\
    &=
    \frac{\sqrt{\pi}}{2^{\frac{a}{2}}} 
    \prod_{k = 1}^{\frac{a}{2}} (2k - 1)
\end{split}
\end{equation}
where the last line follows because $a$ is even for nonzero integral, so $a - 1$ is odd.
This applies for $b$ and $c$ as well. 
Finally:
\begin{equation}
\begin{split}
    \Gamma\left( \frac{a + b + c + 3}{2} \right)
    &=
    \sqrt{\pi} \frac{(a + b + c + 1)!!}{2^{\frac{a + b + c + 2}{2}}} \\
    &=
    \frac{\sqrt{\pi}}{2^{\frac{a + b + c + 2}{2}}} 
    \prod_{k = 1}^{\frac{a + b + c + 2}{2}} (2k - 1)
\end{split}
\end{equation}
With this we may calculate that:
\begin{equation}
    2 B \left(\tfrac{a + 1}{2}, \tfrac{b + 1}{2}, \tfrac{c + 1}{2} \right)
    =
    4 \pi \frac{P(a)P(b)P(c)}{P(a + b + c + 2)}
\end{equation}
where we have defined
\begin{equation}
    P(a)
    =
    \prod_{k = 1}^{\frac{a}{2}} (2k - 1)
\end{equation}
For an example to check, consider $a = 2$ so that the monomial is $x^2$.
Then we get:
\begin{equation}
\begin{split}
    \int_{S^2} x^2 \, dS
    &=
    \int_0^{\pi} d\theta \sin^3 \theta \int_{0}^{2\pi} d\phi \cos^2\phi \\
    &=
    \frac{4 \pi}{3}
\end{split}
\end{equation}
But from our formula we get:
\begin{equation}
    2B \left( \tfrac{3}{2}, 0, 0 \right)
    =
    4 \pi \frac{P(2) P(0) P(0)}{P(4)}
    =
    4 \pi \frac{1}{3}
\end{equation}
Seems like it works.
