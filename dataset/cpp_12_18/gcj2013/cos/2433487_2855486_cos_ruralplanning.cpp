#include <stdio.h>
 #include <string.h>
 #include <algorithm>
 #include <iostream>
 #include <math.h>
 #include <assert.h>
 #include <vector>
 #include <queue>
 #include <string>
 #include <map>
 #include <set>
 
 using namespace std;
 typedef long long ll;
 typedef unsigned int uint;
 typedef unsigned long long ull;
 static const double EPS = 1e-9;
 static const double PI = acos(-1.0);
 
 #define REP(i, n) for (int i = 0; i < (int)(n); i++)
 #define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
 #define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
 #define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
 #define MEMSET(v, h) memset((v), h, sizeof(v))
 
 #include <complex>
 
 typedef complex<double> Point;
 typedef vector<Point> Polygon;
 
 static const double INF = 1e+10;
 
 #define CURR(P, i) (P[i])
 #define NEXT(P, i) (P[(i + 1) % P.size()])
 
 struct Line : public vector<Point> {
   Line() {;}
   Line(Point a, Point b) { push_back(a); push_back(b); }
 };
 
 struct Circle {
   Point p;
   double r;
   Circle() {;}
   Circle(Point p, double r) : p(p), r(r) {;}
 };
 
 namespace std {
   bool operator<(const Point &lhs, const Point &rhs) {
     return lhs.real() == rhs.real() ? lhs.imag() < rhs.imag() : lhs.real() < rhs.real();
   }
 }
 
 inline double cross(const Point &a, const Point &b) {
   return imag(conj(a) * b);
 }
 
 inline double dot(const Point &a, const Point &b) {
   return real(conj(a) * b);
 }
 
 inline int ccw(Point a, Point b, Point c) {
   b -= a;
   c -= a;
   if (cross(b, c) > 0) { return 1; }
   if (cross(b, c) < 0) { return -1; }
   if (dot(b, c) < 0) { return 2; }
   if (norm(b) < norm(c)) { return -2; }
   return 0;
 }
 
 bool intersectLL(const Line &l, const Line &m) {
   return abs(cross(l[1] - l[0], m[1] - m[0])) > EPS ||
          abs(cross(l[1] - l[0], m[0] - l[0])) < EPS;
 }
 
 bool intersectLS(const Line &l, const Line &s) {
   return cross(l[1] - l[0], s[0] - l[0]) *
          cross(l[1] - l[0], s[1] - l[0]) < EPS;
 }
 
 bool intersectLP(const Line &l, const Point &p) {
   return abs(cross(l[1] - p, l[0] - p)) < EPS;
 }
 
 bool intersectSS(const Line &s, const Line &t) {
   return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
     ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0;
 }
 
 bool intersectSP(const Line &s, const Point &p) {
   return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) < EPS;
 }
 
 double Area(const Polygon &p) {
   double ret = 0;
   for (int i = 0; i < (int)p.size(); i++) {
     ret += cross(CURR(p, i), NEXT(p, i));
   }
   return ret / 2.0;
 }
 
 Polygon ConvexHull(Polygon ps) {
   int n = ps.size();
   int k = 0;
   sort(ps.begin(), ps.end());
   vector<Point> ch(2 * n);
   for (int i = 0; i < n; ch[k++] = ps[i++])
     while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
   for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--])
     while (k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
   ch.resize(k - 1);
   return ch;
 }
 
 
 void solve();
 int main() {
   int test;
   scanf("%d", &test);
   char str[1000];
   fgets(str, 999, stdin);
   int test_case = 0;
   while (test--) {
     test_case++;
     printf("Case #%d: ", test_case);
     solve();
   }
 }
 
 int n;
 Point points[10000];
 double max_area = 0;
 
 double calc_area(vector<int> order) {
   vector<Line> ls;
   REP(i, n) {
     Line l(points[order[i]], points[order[(i + 1) % n]]);
     ls.push_back(l);
   }
   REP(i, ls.size()) {
     FOR(j, i + 2, ls.size()) {
       if (i == 0 && j == (int)ls.size() - 1) { continue; }
       if (intersectSS(ls[i], ls[j])) { return -1; }
     }
     Point p = (ls[i][0] + ls[i][1]) / 2.0;
     REP(j, ls.size()) {
       if (i == j) { continue; }
       if (intersectSP(ls[j], p)) { return -1; }
     }
   }
   Polygon poly;
   REP(i, n) { poly.push_back(points[order[i]]); }
   return fabs(Area(poly));
 }
 
 void solve() {
   scanf("%d", &n);
   REP(i, n) {
     double x, y;
     scanf("%lf %lf", &x, &y);
     points[i] = Point(x, y);
   }
   {
     max_area = 0;
     Polygon poly;
     REP(i, n) { poly.push_back(points[i]); }
     poly = ConvexHull(poly);
     max_area = Area(poly);
   }
   vector<int> order(n);
   REP(i, n) { order[i] = i; }
 
   do {
     double area = calc_area(order);
     //cout << area << " " << max_area << endl;
     if (area > max_area / 2.0 + EPS) { break; }
   } while (next_permutation(order.begin(), order.end()));
 
   REP(i, n) {
     if (i != 0) { putchar(' '); }
     printf("%d", order[i]);
   }
   puts("");
 }
