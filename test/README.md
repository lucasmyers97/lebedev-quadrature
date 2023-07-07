# Test

## Introduction

Because Lebedev quadrature is specifically designed to integrate polynomials up to a particular order, we can check for bugs in this implementation by checking the quadrature results against analytic solutions to integrals of monomials around the sphere.
This is essentially what the test programs do, in addition to testing the `lebedev::QuadraturePoints` member function's ability to read in external functions to integrate.

## Analytic calculation of spherical integrals of monomials

To see why the test programs are written the way that they are, we consider the analytic solution of spherical integrals of monomials.
Details of the calculation are [here](https://www.jstor.org/stable/2695802) (or look it up on Sci-Hub if you don't have access).

In general, the solution for the integral of a monomial over the sphere is given by:
\begin{equation}
\int_{S^2} x^{a} y^{b} z^{c} \, dS
=
\begin{cases}
    2 B \left(\tfrac{a + 1}{2}, \tfrac{b + 1}{2}, \tfrac{c + 1}{2} \right)
    &a, b, c \text{ are all even } \\ 
    0
    &\text{otherwise}
\end{cases}
\end{equation}
where
\begin{equation*}
B(l, m, n)
=
\frac{\Gamma(l) \Gamma(m) \Gamma(n)}{\Gamma(l + m + n)}
\end{equation*}
We may write this in a more easily calculable way [by noting that](https://www.wikiwand.com/en/Particular_values_of_the_gamma_function#Integers_and_half-integers):
\begin{equation*}
\Gamma\left(\frac{n}{2}\right)
=
\sqrt{\pi} \frac{(n - 2)!!}{2^{\frac{n - 1}{2}}}
\end{equation*}
with
\begin{equation*}
n!!
=
\prod_{k = 0}^{\lceil \frac{n}{2} \rceil - 1} (n - 2k)
\end{equation*}
To write out $B(l, m, n)$ in a simpler way, we write:
\begin{equation*}
\begin{split}
    \Gamma\left( \frac{a + 1}{2} \right)
    &=
    \sqrt{\pi} \frac{(a - 1)!!}{2^{\frac{a}{2}}} \\
    &=
    \frac{\sqrt{\pi}}{2^{\frac{a}{2}}} 
    \prod_{k = 1}^{\frac{a}{2}} (2k - 1)
\end{split}
\end{equation*}
where the last line follows because $a$ is even for nonzero integral, so $a - 1$ is odd.
This applies for $b$ and $c$ as well. 
Finally:
\begin{equation*}
\begin{split}
    \Gamma\left( \frac{a + b + c + 3}{2} \right)
    &=
    \sqrt{\pi} \frac{(a + b + c + 1)!!}{2^{\frac{a + b + c + 2}{2}}} \\
    &=
    \frac{\sqrt{\pi}}{2^{\frac{a + b + c + 2}{2}}} 
    \prod_{k = 1}^{\frac{a + b + c + 2}{2}} (2k - 1)
\end{split}
\end{equation*}
With this we may calculate that:
\begin{equation}
    2 B \left(\tfrac{a + 1}{2}, \tfrac{b + 1}{2}, \tfrac{c + 1}{2} \right)
    =
    4 \pi \frac{P(a)P(b)P(c)}{P(a + b + c + 1)}
\end{equation}
where we have defined
\begin{equation}
    P(a)
    =
    \prod_{k = 1}^{\frac{a}{2}} (2k - 1)
\end{equation}
Hence, since the Lebedev quadrature scheme should be exact for this integrand we get:
\begin{equation}
    \frac{P(a)P(b)P(c)}{P(a + b + c + 1)}
    =
    \sum_k x_k^a \, y_k^b \, z_k^c \: w_k
\end{equation}
This is what we calculate in the tests.

## Explanation of tests

In `test_header_only.cpp` and `test_no_header_only.cpp`, we define a function `calc_2k_1_product` to aid in the analytic calculation of these integrals, and `calc_coord_multiples` to aid in the numerical calculation of these integrals.
`calc_2k_1_product` calculated a vector whose `i`th entry is given by:
$$
P(i) 
= 
\prod_0^i (2k - 1)
$$
for $i \leq n$.
Given a length-$m$ set of Lebedev quadrature points, `calc_coord_multiples` creates a tuple of three `std::vector<std::vector<double>>` objects of size $n \times m$ for which `x[i][j]` is given by:
$$
x(j)^{2i}
$$
with $x(j)$ being the $x$-coordinate of the $j$th Lebedev point.
This is similar for the $y$- and $z$-coordinates as well.
In the main function, we just use these to calculate the difference between the left and the right sides of eq. (4).


