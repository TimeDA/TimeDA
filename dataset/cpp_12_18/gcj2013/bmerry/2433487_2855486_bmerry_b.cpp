#include <string>
 #include <vector>
 #include <map>
 #include <set>
 #include <queue>
 #include <stack>
 #include <cstdlib>
 #include <cstring>
 #include <cassert>
 #include <iostream>
 #include <sstream>
 #include <cstddef>
 #include <algorithm>
 #include <utility>
 #include <iterator>
 #include <numeric>
 #include <list>
 #include <complex>
 #include <cstdio>
 #include <climits>
 #include <fcntl.h>
 #include <unistd.h>
 
 using namespace std;
 
 typedef vector<int> vi;
 typedef vector<string> vs;
 typedef long long ll;
 typedef complex<ll> pnt;
 typedef pair<int, int> pii;
 
 #define RA(x) (x).begin(), (x).end()
 #define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
 #define SZ(x) ((int) (x).size())
 
 template<class T>
 void splitstr(const string &s, vector<T> &out)
 {
     istringstream in(s);
     out.clear();
     copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
 }
 
 template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
 
 // Geometry stuff
 
 #include <complex>
 #include <vector>
 #include <utility>
 #include <algorithm>
 
 static inline ll dot(const pnt &a, const pnt &b)
 {
     return real(conj(a) * b);
 }
 
 static inline ll cross(const pnt &a, const pnt &b)
 {
     return imag(conj(a) * b);
 }
 
 static inline ll cross(const pnt &a, const pnt &b, const pnt &c)
 {
     return cross(b - a, c - a);
 }
 
 // a-b and p-q contain their endpoints
 bool intersects_inclusive(const pnt &a, const pnt &b, const pnt &p, const pnt &q)
 {
     if (std::min(a.real(), b.real()) > std::max(p.real(), q.real()))
         return false;
     if (std::min(p.real(), q.real()) > std::max(a.real(), b.real()))
         return false;
     if (std::min(a.imag(), b.imag()) > std::max(p.imag(), q.imag()))
         return false;
     if (std::min(p.imag(), q.imag()) > std::max(a.imag(), b.imag()))
         return false;
 
     ll c1 = cross(a, b, p);
     ll c2 = cross(a, b, q);
     if ((c1 > 0 && c2 > 0) || (c1 < 0 && c2 < 0))
         return false;
 
     ll d1 = cross(p, q, a);
     ll d2 = cross(p, q, b);
     if ((d1 > 0 && d2 > 0) || (d1 < 0 && d2 < 0))
         return false;
 
     return true;
 }
 
 // a-b and p-q do not contain their endpoints
 bool intersects_exclusive(const pnt &a, const pnt &b, const pnt &p, const pnt &q)
 {
     // don't change these to >= - it will break for overlapping horizontal/vertical lines
     if (std::min(a.real(), b.real()) > std::max(p.real(), q.real()))
         return false;
     if (std::min(p.real(), q.real()) > std::max(a.real(), b.real()))
         return false;
     if (std::min(a.imag(), b.imag()) > std::max(p.imag(), q.imag()))
         return false;
     if (std::min(p.imag(), q.imag()) > std::max(a.imag(), b.imag()))
         return false;
 
     ll c1 = cross(a, b, p);
     ll c2 = cross(a, b, q);
     ll d1 = cross(p, q, a);
     ll d2 = cross(p, q, b);
 
     if (c1 == 0 && c2 == 0)
     {
         // collinear - either overlap or touch at the endpoints
         if (dot(p - a, b - a) <= 0 && dot(q - a, b - a) <= 0)
             return false;
         if (dot(p - b, a - b) <= 0 && dot(q - b, a - b) <= 0)
             return false;
         return true; // overlap
     }
     if ((c1 >= 0 && c2 >= 0) || (c1 <= 0 && c2 <= 0))
         return false;
     if ((d1 >= 0 && d2 >= 0) || (d1 <= 0 && d2 <= 0))
         return false;
 
     return true;
 }
 
 /* Sorts points by the angle they occupy relative to another point, starting at +X
  * and going ccw. Ties are broken by sorting with increasing distance from the base.
  * The base itself sorts to the front.
  */
 class CompareAngle
 {
 private:
     const pnt base;
 
 public:
     explicit CompareAngle(const pnt &base) : base(base) {}
 
     bool operator()(const pnt &a, const pnt &b) const
     {
         const pnt da = a - base;
         const pnt db = b - base;
         bool fa = da.imag() > 0 || (da.imag() == 0 && da.real() >= 0);
         bool fb = db.imag() > 0 || (db.imag() == 0 && db.real() >= 0);
         if (fa != fb)
             return fa;
         else
         {
             ll c = cross(da, db);
             if (c != 0)
                 return c > 0;
             else
                 return dot(da, da) < dot(db, db);
         }
     }
 };
 
 class CompareX
 {
 public:
     bool operator()(const pnt &a, const pnt &b) const
     {
         if (a.real() != b.real())
             return a.real() < b.real();
         else
             return a.imag() < b.imag();
     }
 };
 
 // Sort by Y then by X
 class CompareY
 {
 public:
     bool operator()(const pnt &a, const pnt &b) const
     {
         if (a.imag() != b.imag())
             return a.imag() < b.imag();
         else
             return a.real() < b.real();
     }
 };
 
 /* Convex hull which has all angles strictly less than pi. For a
  * collinear set, returns a 2-element hull with the extremities.
  *
  * NB: not tested with duplicates - eliminate them first
  */
 std::vector<pnt> convex_hull_exclusive(std::vector<pnt> pnts)
 {
     std::vector<pnt> hull;
     if (pnts.size() < 3)
     {
         std::sort(pnts.begin(), pnts.end(), CompareY());
         hull.swap(pnts);
         return hull;
     }
 
     std::vector<pnt>::iterator firstpos = std::min_element(RA(pnts), CompareY());
     std::swap(pnts[0], *firstpos);
     std::sort(pnts.begin() + 1, pnts.end(), CompareAngle(pnts[0]));
 
     hull.push_back(pnts[0]);
     for (int i = 1; i < SZ(pnts); i++)
     {
         while (SZ(hull) >= 2 && cross(hull[SZ(hull) - 2], hull.back(), pnts[i]) <= 0)
             hull.pop_back();
         hull.push_back(pnts[i]);
     }
     while (SZ(hull) >= 3 && cross(hull[SZ(hull) - 2], hull.back(), pnts[0]) <= 0)
         hull.pop_back();
     return hull;
 }
 
 /* Convex hull which has all angles at most pi, and includes all points
  * that lie on the boundary of the hull. For a collinear set, returns
  * points on the boundary TWICE.
  *
  * NB: not tested with duplicates - eliminate them first
  */
 std::vector<pnt> convex_hull_inclusive(std::vector<pnt> pnts)
 {
     std::vector<pnt> hull;
     if (pnts.size() < 3)
     {
         std::sort(pnts.begin(), pnts.end(), CompareY());
         hull.swap(pnts);
         return hull;
     }
 
     std::vector<pnt>::iterator firstpos = std::min_element(RA(pnts), CompareY());
     std::swap(pnts[0], *firstpos);
     std::sort(pnts.begin() + 1, pnts.end(), CompareAngle(pnts[0]));
 
     hull.push_back(pnts[0]);
     for (int i = 1; i < SZ(pnts); i++)
     {
         while (SZ(hull) >= 2 && cross(hull[SZ(hull) - 2], hull.back(), pnts[i]) < 0)
             hull.pop_back();
         hull.push_back(pnts[i]);
     }
     int i = SZ(pnts) - 2;
     while (i > 0 && cross(pnts[0], hull.back(), pnts[i]) == 0)
     {
         hull.push_back(pnts[i]);
         i--;
     }
     return hull;
 }
 
 // Returns DOUBLE the signed area of the polygon
 ll polygon_area2(const std::vector<pnt> &pnts)
 {
     ll ans = cross(pnts.back(), pnts[0]);
     for (size_t i = 1; i < pnts.size(); i++)
         ans += cross(pnts[i - 1], pnts[i]);
     return ans;
 }
 
 static void redirect(int argc, const char **argv)
 {
     if (argc > 1)
     {
         int fd = open(argv[1], O_RDONLY);
         if (fd == -1) { perror(argv[1]); exit(1); }
         if (-1 == dup2(fd, 0)) { perror(argv[1]); exit(1); }
         if (-1 == close(fd)) { perror(argv[1]); exit(1); }
     }
 
     if (argc > 2)
     {
         int fd = open(argv[2], O_WRONLY | O_CREAT, 0666);
         if (fd == -1) { perror(argv[2]); exit(1); }
         if (-1 == dup2(fd, 1)) { perror(argv[2]); exit(1); }
         if (-1 == close(fd)) { perror(argv[2]); exit(1); }
     }
 
     ios::sync_with_stdio(false);
 }
 
 static bool good_poly(const vector<pnt> &pnts)
 {
     int N = SZ(pnts);
     for (int i = 0; i < N; i++)
     {
         const pnt &a = pnts[i];
         const pnt &b = pnts[(i + 1) % N];
         for (int j = 2; j < N - 1; j++)
         {
             const pnt &p = pnts[(i + j) % N];
             const pnt &q = pnts[(i + j + 1) % N];
             if (intersects_inclusive(a, b, p, q))
                 return false;
         }
     }
     return true;
 }
 
 int main(int argc, const char **argv)
 {
     redirect(argc, argv);
 
     int cases;
     cin >> cases;
     for (int cas = 0; cas < cases; cas++)
     {
         int N;
         cin >> N;
         vector<pnt> pnts(N);
         for (int i = 0; i < N; i++)
         {
             int x, y;
             cin >> x >> y;
             pnts[i] = pnt(x, y);
         }
         vector<int> perm(N);
         for (int i = 0; i < N; i++)
             perm[i] = i;
 
         ll big = -1;
         vector<pnt> poly(N);
         vector<int> best;
         poly[0] = pnts[0];
         do
         {
             if (perm[1] < perm.back())
                 continue;
             for (int i = 1; i < N; i++)
                 poly[i] = pnts[perm[i]];
             ll a = llabs(polygon_area2(poly));
             if (a >= big && good_poly(poly))
             {
                 big = a;
                 best = perm;
             }
         } while (next_permutation(perm.begin() + 1, perm.end()));
 
         for (int i = 0; i < N; i++)
             poly[i] = pnts[best[i]];
         assert(good_poly(poly));
 
         poly.pop_back();
         vector<pnt> hull = convex_hull_exclusive(poly);
         ll limit = fabs(polygon_area2(hull));
         assert(big * 2 > limit);
 
         cout << "Case #" << cas + 1 << ":";
         for (int i = 0; i < N; i++)
             cout << ' ' << best[i];
         cout << '\n';
     }
     return 0;
 }
