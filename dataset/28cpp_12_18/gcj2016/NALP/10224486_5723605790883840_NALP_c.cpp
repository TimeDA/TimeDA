#ifdef NALP_PROJECT
 #pragma hdrstop
 #else
 #define _SECURE_SCL 0
 #endif
 
 #define _CRT_SECURE_NO_DEPRECATE
 #pragma comment(linker, "/STACK:200000000")
 
 #include <cstdio>
 #include <cstdlib>
 #include <ctime>
 #include <cctype>
 #include <cmath>
 #include <algorithm>
 #include <utility>
 #include <cassert>
 
 #include <set>
 #include <map>
 #include <vector>
 #include <string>
 #include <queue>
 #include <bitset>
 #include <memory.h>
 
 #include <iostream>
 #include <fstream>
 #include <sstream>
 
 #ifdef _WIN32
     #define LLD "%I64d"
 #else
     #define LLD "%lld"
 #endif
 
 using namespace std;
 
 typedef long long int64;
 
 #define forn(i, n) for(int i = 0; i < (int)(n); i++)
 #define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
 #define pb push_back
 #define mp make_pair
 #define y1 YYY1
 #define all(a) (a).begin(), (a).end()
 #define rall(a) (a).rbegin(), (a).rend()
 
 template<typename T> inline T Abs(T x) { return (x >= 0) ? x : -x; }
 template<typename T> inline T sqr(T x) { return x * x; }
 template<typename T> inline string toStr(T x) { stringstream st; st << x; string s; st >> s; return s; }
 template<typename T> inline int bit(T mask, int b) { return (b >= 0 && (mask & (T(1) << b)) != 0) ? 1 : 0; }
 template<typename T1, typename T2> std::ostream& operator<<(std::ostream &out, const pair<T1, T2>& a) { out << "(" << a.first << ", " << a.second << ")"; return out; }
 template<typename T> std::ostream& operator<<(std::ostream &out, const vector<T>& a) { out << "[" << a.size() << "]{ "; forn(i, a.size()) { out << a[i] << " "; } out << "}"; return out; }
 
 inline int nextInt() { int x; if (scanf("%d", &x) != 1) throw; return x; }
 inline int64 nextInt64() { int64 x; if (scanf(LLD, &x) != 1) throw; return x; }
 inline double nextDouble() { double x; if (scanf("%lf", &x) != 1) throw; return x; }
 
 const int INF = (int)1E9;
 const int64 INF64 = (int64)1E18;
 const long double EPS = 1E-9;
 const long double PI = 3.1415926535897932384626433832795;
 
 const int MAXN = 510;
 
 int n, m, C, a[MAXN];
 bool g[MAXN][MAXN];
 
 int getv(int x, int y, int c) {
     if (0 <= x && x < n && 0 <= y && y < m) {
         return (x * m + y) * 4 + c;
     } else {
         return -1;
     }
 }
 
 void add(int v, int u) {
     if (v != -1 && u != -1) {
         g[v][u] = g[u][v] = true;
     }
 }
 
 void clearg() {
     const int N = n * m * 4;
     forn(i, N) {
         forn(j, N) {
             g[i][j] = g[j][i] = (i == j);
         }
     }
 }
 
 void fl() {
     const int N = n * m * 4;
     forn(k, N) {
         forn(i, N) {
             forn(j, N) {
                 g[i][j] = g[i][j] || (g[i][k] && g[k][j]);
             }
         }
     }
 //    forn(i, N) {
 //        forn(j, N) {
 //            cerr << g[i][j];
 //        }
 //        cerr << endl;
 //    }
 //    cerr << endl;
 }
 
 bool check(int v, int u, const vector<int>& rb) {
     int cnt = 0;
     forn(i, rb.size()) {
         cnt += g[v][rb[i]];
     }
 //    cerr << "check " << v << " " << u << " " << cnt << " " << g[v][u] << endl;
     return cnt == 2 && g[v][u];
 }
 
 bool good(const vector<string>& f) {
     clearg();
     forn(x, n) {
         forn(y, m) {
             add(getv(x, y, 0), getv(x, y - 1, 2));
             add(getv(x, y, 1), getv(x - 1, y, 3));
             add(getv(x, y, 2), getv(x, y + 1, 0));
             add(getv(x, y, 3), getv(x + 1, y, 1));
             if (f[x][y] == '/') {
                 add(getv(x, y, 0), getv(x, y, 1));
                 add(getv(x, y, 2), getv(x, y, 3));
             } else {
                 add(getv(x, y, 0), getv(x, y, 3));
                 add(getv(x, y, 1), getv(x, y, 2));
             }
         }
     }
 
     vector<int> rb;
     forn(y, m) {
         rb.pb(getv(0, y, 1));
     }
     forn(x, n) {
         rb.pb(getv(x, m - 1, 2));
     }
     ford(y, m) {
         rb.pb(getv(n - 1, y, 3));
     }
     ford(x, n) {
         rb.pb(getv(x, 0, 0));
     }
 //    cerr << 1 << endl;
     assert(rb.size() == C);
 
     fl();
 
     forn(i, C / 2) {
         const int v = a[2*i], u = a[2*i + 1];
         if (!check(rb[v], rb[u], rb)) {
             return false;
         }
     }
 
     return true;
 }
 
 vector<string> stupid() {
     forn(mask, 1 << (n * m)) {
         vector<string> f(n, string(m, '.'));
         forn(i, n * m) {
             const int x = i / m, y = i % m;
             f[x][y] = bit(mask, i) ? '/' : '\\';
         }
 
 //        cerr << f << endl;
         if (good(f)) {
             return f;
         }
     }
     return {"IMPOSSIBLE"};
 }
 
 void solve(bool skipThisTest) {
     if (true) {
         cerr << "\tinput mode: read test." << endl;
         n = nextInt();
         m = nextInt();
         C = 2 * (n + m);
         forn(i, C) {
             a[i] = nextInt() - 1;
         }
         if (skipThisTest) return;
     } else {
         cerr << "\tinput mode: generated test." << endl;
         // generate test.
     }
 
     vector<string> ans = stupid();
     for (const auto& row : ans) {
         cout << endl << row;
     }
     cout << endl;
 
     cerr << "\tclever answer is '" << ans << "'." << endl;
     if (n <= 16) {
         vector<string> stupidAnswer = stupid();
         cerr << "\tstupid answer is '" << stupidAnswer << "'." << endl;
         assert(ans == stupidAnswer);
     }
 }
 
 int main(int argc, char * argv[]) {
 #ifdef NALP_PROJECT
     freopen("input.txt", "rt", stdin);
 //  freopen("output.txt", "wt", stdout);
 #else
 #endif
 
     int minTest = 1, maxTest = INF;
     if (argc == 3) {
         minTest = atoi(argv[1]);
         maxTest = atoi(argv[2]);
     }
 
     cout.precision(10);
     cout.setf(ios::fixed);
 
     cerr.precision(10);
     cerr.setf(ios::fixed);
 
     srand((unsigned int)time(0));
     int tests = nextInt();
     clock_t totalStartTime = clock();
     for(int test = 1; test <= tests; test++) {
         clock_t startTime = clock();
         cerr << "Case #" << test << endl;
         bool skipThisTest = (test < minTest || test > maxTest);
         if (!skipThisTest) cout << "Case #" << test << ": ";
         solve(skipThisTest);
 
         char formattedTime[100];
         clock_t time = clock() - startTime;
         sprintf(formattedTime, "%d.%03d", int(time / CLOCKS_PER_SEC), int(time % CLOCKS_PER_SEC));
         cerr << "time for test is " << formattedTime << " s." << endl << endl;
     }
 
     char formattedTime[100];
     clock_t totalTime = clock() - totalStartTime;
     sprintf(formattedTime, "%d.%03d", int(totalTime / CLOCKS_PER_SEC), int(totalTime % CLOCKS_PER_SEC));
     cerr << string(20, '=') << endl;
     cerr << "TOTAL TIME IS " << formattedTime << " s." << endl;
 
     return 0;
 }
