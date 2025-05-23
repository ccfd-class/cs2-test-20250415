#include <cmath>
#include <cstdio>
#include <cstdlib>

// -----------------------------------------------
// Code from labs
// -----------------------------------------------

// Lagrange interpolation
double lagrange(const double *x, const double *y, int n, double xx) {
  int i, j;
  double yint, ylag;

  yint = 0.0;
  for (i = 0; i < n; i++) {
    ylag = 1.0;
    for (j = 0; j < n; j++) {
      if (i == j)
        continue;

      ylag *= (xx - x[j]) / (x[i] - x[j]);
    }

    yint += y[i] * ylag;
  }

  return yint;
}

// Simpson's method for numerical integration
double simpson(double a, double b, double (*pf)(double), int n) {
  double x = a;
  double h = (b - a) / (2 * n);
  double h2 = h * 2;
  double x1 = a + h;

  double suma = pf(a) + 4. * pf(x1) + pf(b);

  for (int i = 0; i < n - 1; i += 1) {
    x += h2;
    suma += 2. * pf(x) + 4. * pf(x + h);
  }
  return suma * h / 3.;
}

// Bisection
double bisec(double xa, double xb, double (*pf)(double), double eps,
             int *i_iter) {
  int i;
  double fa, fb, xc, fc;

  fa = pf(xa);
  fb = pf(xb);

  if (fa * fb > 0.0) {
    *i_iter = -1;
    return 0;
  }

  for (i = 1; i <= 1000; i++) {
    xc = (xa + xb) / 2.;
    fc = pf(xc);

    if (fa * fc < 0.) {
      xb = xc;
      fb = fc;
    } else {
      xa = xc;
      fa = fc;
    }

    if (fabs(fc) < eps && fabs(xb - xa) < eps)
      break;
  }

  *i_iter = i;
  return xc;
}
// -----------------------------------------------

// These constants are given
const double Cd = .2491326;
const double rho = 1025.;
const double A = 80.;
const double vs = 10.;
const double W = 45'000'000.;
const double M = 40'500.;
const double eta = .25;
const int n = 11;
const double delta_x = 200'000.;
const double vw_measurements[] = {3.,  3.5, 3.6, 3.7, 3.,  2.,
                                  1.1, .3,  -.4, -1., -1.4};

// This function should return the solution: d such that Wh(d) = We
double solution() { return 0.; }

int main() {
  const double d = solution();
  printf("Computed distance: %.1lf\n", d);
}
