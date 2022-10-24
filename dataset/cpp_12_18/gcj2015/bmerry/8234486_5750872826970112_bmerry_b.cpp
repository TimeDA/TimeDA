#include <bits/stdc++.h>
 #include <fcntl.h>
 #include <unistd.h>
 
 using namespace std;
 
 /*** START OF TEMPLATE CODE ***/
 
 typedef vector<int> vi;
 typedef vector<string> vs;
 typedef __int128 ll;
 typedef complex<ll> pnt;
 typedef pair<int, int> pii;
 
 #define RA(x) begin(x), end(x)
 #define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
 #define SZ(x) ((int) (x).size())
 
 template<class T>
 vector<T> splitstr(const string &s)
 {
     istringstream in(s);
     vector<T> out;
     copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
     return out;
 }
 
 template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
 
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
     cin.exceptions(ios::failbit | ios::badbit);
 }
 
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
             return c > 0;
         }
     }
 };
 
 /*** END OF TEMPLATE CODE ***/
 
 static ll fixup(double x)
 {
     return (ll) round(x * 10000.0);
 }
 
 static ll fetch()
 {
     double x;
     cin >> x;
     return fixup(x);
 }
 
 int main(int argc, const char **argv)
 {
     redirect(argc, argv);
 
     int cases;
     cin >> cases;
     cout << fixed << setprecision(9);
     for (int cas = 0; cas < cases; cas++)
     {
         cout << "Case #" << cas + 1 << ": ";
 
         int N;
         cin >> N;
         ll V = fetch();
         ll X = fetch() * V;
         pnt target(V, X);
         vector<pnt> pnts;
         for (int i = 0; i < N; i++)
         {
             ll R = fetch();
             ll C = fetch();
             pnts.emplace_back(R, R * C);
         }
         CompareAngle cmp(pnt(0.0, 0.0));
         sort(RA(pnts), cmp);
         vector<pnt> pnts2;
         for (const pnt &p : pnts)
         {
             if (!pnts2.empty() && !cmp(pnts2.back(), p))
                 pnts2.back() += p;
             else
                 pnts2.push_back(p);
         }
         pnts = move(pnts2);
 
         if (cmp(target, pnts[0]) || cmp(pnts.back(), target))
         {
             cout << "IMPOSSIBLE\n";
             continue;
         }
         N = SZ(pnts);
         vector<pnt> hull;
         pnt cur = 0;
         for (int i = 0; i < N; i++)
         {
             cur += pnts[i];
             hull.push_back(cur);
         }
         for (int i = 0; i < N - 1; i++)
         {
             cur -= pnts[i];
             hull.push_back(cur);
         }
 
         int i = 1;
         while (i < SZ(hull) && cmp(hull[i], target))
             i++;
         double ans;
         if (SZ(hull) == 1)
             ans = (double) target.real() / pnts[0].real();
         else
         {
             double num = cross(hull[i - 1], hull[i]);
             double den = cross(target, hull[i] - hull[i - 1]);
             ans = den / num;
             //cout << arg(hull[i - 1]) << ' ' << arg(hull[i]) << ' ' << arg(target) << '\n';
         }
         cout << ans << '\n';
     }
     return 0;
 }
