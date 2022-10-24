
#include <cstdlib>
#include <complex>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <cassert>
#include <iostream>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
using namespace std;
typedef complex<double> P;
struct L { P pos, dir; };

inline double inp(const P& a, const P& b) {
    return (conj(a)*b).real();
}
inline double outp(const P& a, const P& b) {
    return (conj(a)*b).imag();
}
inline P proj(const P& p, const P& b) {
    return b*inp(p,b)/norm(b);
}
inline P perf(const L& l, const P& p) {
    L m = {l.pos - p, l.dir};
    return (p + (m.pos - proj(m.pos, m.dir)));
}
inline L proj(const L& s, const L& b) {
     return (L){perf(b, s.pos), proj(s.dir, b.dir)};
}

struct P3 {
  P p;
  double z;
};

const double EPS = 1e-4;
bool isOK2(const P3& p, const P3& p1, const P3& p2, const P3& p3) {
  P a = p.p - p1.p;
  P a2 = p2.p - p1.p;
  P b2 = proj(a, a2);
  double c2 = b2 / a2;

  P a3 = p3.p - p1.p;
  P b3 = proj(a, a3);
  double c3 = b3 / a3;

  double h = p1.z + (p2.z-p1.z)*c2 + (p3.z-p1.z)*c3;
  return h >= p.z - EPS;
}

int n;

P3 ps[1010];
int perm[1010];


bool isOK(void) {
  for(int i3 = 3; i3 < n; ++i3) {
    int i1 = i3-2;
    int i2 = i3-1;
    REP(i, i1) {
      if(!isOK2(ps[perm[i]], ps[perm[i1]], ps[perm[i2]], ps[perm[i3]])) {
        return false;
      }
    }
  }
  return true;
}

int main(void) {
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase) {
    scanf("%d", &n);
    REP(i, n) {
      double x, y, z;
      scanf("%lf%lf%lf", &x, &y, &z);
      ps[i].p = P(x, y);
      ps[i].z = z;
      perm[i] = i;
    }
    do {
      if(isOK()) {
        printf("Case #%d:", iCase+1);
        REP(i, n) {
          printf(" %d", perm[i]+1);
        }
        printf("\n");
        break;
      }
    } while(next_permutation(perm, perm+n));
  }
  return 0;
}
