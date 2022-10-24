
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <complex>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;
typedef complex<double> P;
const double PI = acos(-1);
const double R2 = sqrt(2);
const double R3 = sqrt(3);

int main(void) {
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase) {
    double target;
    scanf("%lf", &target);

    printf("Case #%d:\n", iCase+1);
    if(target <= R2) { // rotate z
      double left = 0;
      double right = PI / 4;
      REP(t, 100) {
        double mid = (left + right) / 2;
        P p(0.5, 0.5);
        p *= polar(1.0, -mid);
        if(abs(p.real())*2 < target) {
          left = mid;
        } else {
          right = mid;
        }
      }
      P rot = polar(1.0, -left);
      P p1 = P(0.5, 0) * rot;
      P p2 = P(0, 0.5) * rot;
      printf("%.10f %.10f 0\n", p1.real(), p1.imag());
      printf("%.10f %.10f 0\n", p2.real(), p2.imag());
      printf("0 0 0.5\n");
    } else { // z -> x. XXX
      const double phi = atan(R2);
      double left = 0;
      double right = 1.0472;
      REP(t, 100) {
        double mid = (left + right) / 2;
        double x1 = abs(R3*cos(PI-phi-mid));
        double x2 = abs(R3*cos(phi-mid));
        double area = R2*x1 + R2*(x2-x1)/2;
        if(area < target) {
          left = mid;
        } else {
          right = mid;
        }
      }
      P rot = polar(1.0, -left);
      P p1 = P(-R2/4, 0) * rot;
      P p2 = P(R2/4, 0) * rot;
      P p3 = P(0, 0.5) * rot;
      printf("%.10f %.10f %.10f\n", R2/4, p1.real(), p1.imag());
      printf("%.10f %.10f %.10f\n", R2/4, p2.real(), p2.imag());
      printf("%.10f %.10f %.10f\n", 0.0, p3.real(), p3.imag());
    }
    
  }
  return 0;
}
