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
 #define Cerr cerr
 #define Endl endl
 
 template<typename T> inline T Abs(T x) { return (x >= 0) ? x : -x; }
 template<typename T> inline T Sqr(T x) { return x * x; }
 template<typename T> inline string ToString(T x) { stringstream st; st << x; string s; st >> s; return s; }
 template<typename T> inline int Bit(T mask, int b) { return (b >= 0 && (mask & (T(1) << b)) != 0) ? 1 : 0; }
 template<typename T1, typename T2> std::ostream& operator<<(std::ostream &out, const pair<T1, T2>& a) { out << "(" << a.first << ", " << a.second << ")"; return out; }
 template<typename T> std::ostream& operator<<(std::ostream &out, const vector<T>& a) { out << "[" << a.size() << "]{ "; forn(i, a.size()) { out << a[i] << " "; } out << "}"; return out; }
 
 inline int NextInt() { int x; if (scanf("%d", &x) != 1) throw; return x; }
 inline int64 NextInt64() { int64 x; if (scanf(LLD, &x) != 1) throw; return x; }
 inline double NextDouble() { double x; if (scanf("%lf", &x) != 1) throw; return x; }
 
 const int INF = (int)1E9;
 const int64 INF64 = (int64)1E18;
 const long double EPS = 1E-9;
 const long double PI = 3.1415926535897932384626433832795;
 
 const int MAXN = 100100;
 
 int n, p, a[MAXN], s[MAXN];
 
 int StupidSolution() {
     return 0;
 }
 
 int Solve2() {
     return s[0] + 1 + s[1] / 2;
 }
 
 int Solve3() {
     const int m12 = min(s[1], s[2]);
     return s[0] + 1 + m12 + (s[1] + s[2] - 2*m12) / 3;
 }
 
 void Solve(bool skipThisTest) {
     if (true) {
         cerr << "\tinput mode: read test." << endl;
         n = NextInt();
         p = NextInt();
         forn(i, n) {
             a[i] = NextInt();
         }
         if (skipThisTest) return;
     } else {
         cerr << "\tinput mode: generated test." << endl;
         // generate test.
     }
 
     int sum = 0;
     memset(s, 0, sizeof s);
     forn(i, n) {
         ++s[a[i] % p];
         sum += a[i];
     }
 
     int ans = 0;
     if (p == 2) {
         ans = Solve2();
     } else if (p == 3) {
         ans = Solve3();
     } else {
         throw;
     }
 
     if (sum % p == 0) {
         --ans;
     }
 
     cout << ans << endl;
 
     cerr << "\tclever answer is '" << ans << "'." << endl;
     if (n <= 0) {
         const int stupidAnswer = StupidSolution();
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
     const int tests = NextInt();
     clock_t totalStartTime = clock();
     for (int test = 1; test <= tests; test++) {
         clock_t startTime = clock();
         cerr << "Case #" << test << endl;
         const bool skipThisTest = (test < minTest || test > maxTest);
         if (!skipThisTest) cout << "Case #" << test << ": ";
         Solve(skipThisTest);
 
         char formattedTime[100];
         const clock_t time = clock() - startTime;
         sprintf(formattedTime, "%d.%03d", int(time / CLOCKS_PER_SEC), int(time % CLOCKS_PER_SEC));
         cerr << "time for test is " << formattedTime << " s." << endl << endl;
     }
 
     char formattedTime[100];
     const clock_t totalTime = clock() - totalStartTime;
     sprintf(formattedTime, "%d.%03d", int(totalTime / CLOCKS_PER_SEC), int(totalTime % CLOCKS_PER_SEC));
     cerr << string(20, '=') << endl;
     cerr << "TOTAL TIME IS " << formattedTime << " s." << endl;
 
     return 0;
 }
