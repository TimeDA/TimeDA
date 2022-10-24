#ifdef DBG1
  #define LOCAL
#endif

#ifdef LOCAL
  #define _GLIBCXX_DEBUG
#endif

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>

#ifdef DBG1
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

//using namespace std;

using std::vector;
using std::sort;
using std::pair;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;

const double pi = acos(-1.0);
const double eps = 1e-9;

template<class T>
void rotate(T &x, T &y, double ang) {
  T x0 = x;
  T y0 = y;
  x = x0 * cos(ang) + y0 * sin(ang);
  y = y0 * cos(ang) - x0 * sin(ang);
}

struct Point {
  double x, y, z;

  Point() {
    x = y = z = 0.0;
  }
  Point(double x, double y, double z) : x(x), y(y), z(z) {}

  Point operator * (double k) const {
    return Point(x * k, y * k, z * k);
  }

  Point operator + (const Point & p) const {
    return Point(x + p.x, y + p.y, z + p.z);
  }

  Point operator - (const Point & p) const {
    return Point(x - p.x, y - p.y, z - p.z);
  }

  Point& operator += (const Point & p) {
    return *this = *this + p;
  }

  Point& operator -= (const Point & p) {
    return *this = *this - p;
  }

  Point projectXY() const {
    return Point(x, y, 0);
  }

  double vectorProdZ(const Point & p) const {
    return x * p.y - y * p.x;
  }

  bool operator < (const Point & p) const {
    double vmul = vectorProdZ(p);
    if (fabs(vmul) > eps) {
      return vmul > 0;
    }
    return sqrAbs() < p.sqrAbs();
  }

  double sqrAbs() const {
    return x * x + y * y + z * z;
  }

  void dbgPrint() const {
    dbg("%.5lf %.5lf %.5lf\n", x, y, z);
  }
};

vector<Point> rotate_cube(const vector<double> & rots) {
  vector<Point> v({Point(0.5, 0, 0), Point(0, 0.5, 0), Point(0, 0, 0.5)});
  rotate(v[0], v[2], rots[0]);
  rotate(v[1], v[2], rots[1]);
  return v;
}

double get_square(const vector<double> & rots, bool debug = false) {
  auto v = rotate_cube(rots);
 
  if (debug) {
    for (int i = 0; i < 3; ++i) {
      v[i].dbgPrint();
    }
  }

  vector <Point> pp;
  for (int i = 0; i < 8; ++i) {
    Point p;
    for (int j = 0; j < 3; ++j) {
      if ((i >> j) & 1) {
        p += v[j];
      } else {
        p -= v[j];
      }
    }
    pp.push_back(p.projectXY());
  }

  int best = 0;
  for (int i = 1; i < 8; ++i) {
    if (pp[i].y < pp[best].y - eps || (fabs(pp[i].y - pp[best].y) < eps && pp[i].x < pp[best].x)) {
      best = i;
    }
  }
  vector <Point> st;
  st.push_back(pp[best]);
  pp.erase(pp.begin() + best);
  for (auto & p : pp) {
    p -= st[0];
  }
  st[0] = Point();
  sort(pp.begin(), pp.end());
  for (auto p : pp) {
    while (int(st.size()) >= 2 && (st.back() - st[st.size() - 2]).vectorProdZ(p - st.back()) < eps) {
      st.pop_back();
    }
    st.push_back(p);
  }

  st.push_back(st[0]);
  double s = 0.0;
  for (int i = 1; i < int(st.size()); ++i) {
    if (debug) {
      st[i].dbgPrint();
    }
    s += st[i - 1].vectorProdZ(st[i]);
  }
  if (debug) {
    dbg("rot1 %.10lf rot2 %.10lf s %.10lf\n", rots[0], rots[1], s / 2.0);
  }
  return s / 2.0;
}

void binary_search(double L, double R, vector<double> &rots, double A) {
  rots.push_back(0.0);
  for (int i = 0; i < 50; ++i) {
    double M = (L + R) / 2.0;
    rots.back() = M;
    if (get_square(rots) > A) {
      R = M;
    } else {
      L = M;
    }
  }
  rots.back() = (L + R) / 2.0;
}

void solve() {
  double A;
  scanf("%lf", &A);
  vector<double> rots(1, (A < sqrt(2.0) ? 0.0 : 0.6154797150));
  binary_search(0.0, pi / 2.0, rots, A);
  dbg("rot1 %.20lf rot2 %.20lf\n", rots[0], rots[1]);
  auto v = rotate_cube(rots);
  get_square(rots, true);
  for (auto p : v) {
    printf("%.20lf %.20lf %.20lf\n", p.x, p.z, p.y);
  }
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int ii = 1; ii <= tt; ++ii) {
    printf("Case #%d:\n", ii);
    solve();
  }
  return 0;
}
