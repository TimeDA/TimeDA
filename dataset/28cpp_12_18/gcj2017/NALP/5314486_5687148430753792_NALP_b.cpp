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
 
 const int MAXN = 10000;
 
 int seats, customers, tickets;
 int pos[MAXN], customer[MAXN];
 
 
 struct edge {
     int v, u, c, cost, f;
     edge(int v, int u, int c, int cost) : v(v), u(u), c(c), cost(cost), f(0) {}
 };
 
 int d[MAXN], pr[MAXN];
 vector<vector<int>> g;
 bool used[MAXN];
 vector<edge> e;
 queue<int> q;
 
 void AddEdge(int v, int u, int c, int cost) {
     if (max(v, u) + 1 > g.size()) {
         g.resize(max(v, u) + 1);
     }
 
     g[v].pb ((int)e.size());
     e.pb(edge(v, u, c, +cost));
 
     g[u].pb ((int)e.size());
     e.pb(edge(u, v, 0, -cost));
 }
 
 void Update(int v, int value, int prev) {
     if (d[v] > value) {
         if (!used[v]) q.push(v);
         used[v] = true;
         pr[v] = prev;
         d[v] = value;
     }
 }
 
 int Flow(int &ansCost, int S, int T) {
     memset(d, 60, sizeof d);
     memset(used, 0, sizeof used);
 
     Update(S, 0, -1);
     while (!q.empty()) {
         int v = q.front(); q.pop();
         used[v] = false;
 
         forn(i, g[v].size()) {
             int id = g[v][i], u = e[id].u;
             if (e[id].c > e[id].f) {
                 Update(u, d[v] + e[id].cost, id);
             }
         }
     }
 
     if (d[T] > INF/2) return 0;
 
     int cflow = INF;
     for(int v = T; v != S; ) {
         int id = pr[v];
         cflow = min (cflow, e[id].c - e[id].f);
         v = e[id].v;
     }
 
     for(int v = T; v != S; ) {
         int id = pr[v];
         ansCost += e[id].cost * cflow;
         e[id^0].f += cflow;
         e[id^1].f -= cflow;
         v = e[id].v;
     }
 
     return cflow;
 }
 
 int StupidSolution() {
     return 0;
 }
 
 pair<int, int> Range(const pair<int, int>& p) {
     pair<int, int> ans(p.first, p.first);
     if (p.second == 1) ans.first = 0;
     return ans;
 }
 
 void Solve(bool skipThisTest) {
     if (true) {
         cerr << "\tinput mode: read test." << endl;
         seats = NextInt();
         customers = NextInt();
         tickets = NextInt();
         forn(i, tickets) {
             pos[i] = NextInt() - 1;
             customer[i] = NextInt() - 1;
         }
 
         if (skipThisTest) return;
     } else {
         cerr << "\tinput mode: generated test." << endl;
         // generate test.
     }
 
     g.clear();
     e.clear();
 
     if (customers != 2) {
         throw;
     }
 
     const int S = 8 * tickets + 100;
     const int T = 8 * tickets + 101;
     const int SHIFT1 = 2 * tickets;
     const int SHIFT2 = 4 * tickets;
     const int SHIFT3 = 6 * tickets;
 
     vector<pair<int, pair<int, int>>> t0, t1;
     forn(i, tickets) {
         vector<pair<int, pair<int, int>>>& r = customer[i] == 0 ? t0 : t1;
         r.push_back(mp(i, mp(pos[i], 0)));
         if (pos[i] > 0) {
             r.push_back(mp(i, mp(pos[i] - 1, 1)));
         }
 
         AddEdge(S, i + SHIFT1, 1, 0);
         AddEdge(i + SHIFT3, T, 1, 0);
     }
 
 //    cerr << t0 << endl << t1 << endl;
 
     forn(i, t0.size()) {
         AddEdge(t0[i].first + SHIFT1, i, 1, t0[i].second.second);
     }
 
     forn(i, t1.size()) {
         AddEdge(i + SHIFT2, t1[i].first + SHIFT3, 1, t1[i].second.second);
     }
 
     forn(i0, t0.size()) {
         forn(i1, t1.size()) {
             const pair<int, int> r0 = Range(t0[i0].second);
             const pair<int, int> r1 = Range(t1[i1].second);
             if (r0.first == r0.second && r0.first == r1.first && r0.first == r1.second) {
                 continue;
             }
 
             AddEdge(i0, i1 + SHIFT2, 1, 0);
         }
     }
 
     int flow = 0, cost = 0, cflow = 1;
     while (cflow > 0) {
         cflow = Flow(cost, S, T);
         flow += cflow;
     }
 
 //    cerr << flow << endl;;
     const int ans = tickets - flow;
     cout << ans << " " << cost << endl;
 
     cerr << "\tclever answer is '" << ans << "'." << endl;
     if (tickets <= 0) {
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
