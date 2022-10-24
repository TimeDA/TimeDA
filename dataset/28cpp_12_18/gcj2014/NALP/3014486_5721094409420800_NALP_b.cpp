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
 
 #include <deque>
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
 
 inline int nextInt() { int x; if (scanf("%d", &x) != 1) throw; return x; }
 inline int64 nextInt64() { int64 x; if (scanf(LLD, &x) != 1) throw; return x; }
 inline double nextDouble() { double x; if (scanf("%lf", &x) != 1) throw; return x; }
 
 const int INF = (int)1E9;
 const int64 INF64 = (int64)1E18;
 const long double EPS = 1E-9;
 const long double PI = 3.1415926535897932384626433832795;
 
 const int MAXN = 1100;
 
 int n, a[MAXN], d[MAXN][MAXN], pos[MAXN], lf[MAXN], rg[MAXN];
 
 int solve(int l, int r) {
 	if (l > r) return 0;
 	int &ans = d[l][r];
 	if (ans != -1) return ans;
 
 	ans = INF;
 	int cur = n - (r - l + 1);
 	ans = min(ans, solve(l + 1, r) + lf[cur]);
 	ans = min(ans, solve(l, r - 1) + rg[cur]);
 	return ans;
 }
 
 int calc(vector<int> d) {
 	vector<int> p(d.size()), a(::a, ::a + n);
 	forn(i, n) p[d[i]] = i;
 	forn(i, n) a[i] = p[a[i]];
 
 	int ans = 0;
 	forn(i, a.size()) {
 		forn(j, i) {
 			if (a[j] > a[i]) {
 				ans++;
 			}
 		}
 	}
 
 	return ans;
 }
 
 int gen(deque<int> &a) {
 	if (int(a.size()) == n) {
 		return calc(vector<int>(all(a)));
 	}
 
 	int ans = INF;
 	int cur = n - 1 - int(a.size());
 	
 	a.push_back(cur);
 	ans = min(ans, gen(a));
 	a.pop_back();
 	
 	a.push_front(cur);
 	ans = min(ans, gen(a));
 	a.pop_front();
 
 	return ans;
 }
 
 int stupid() {
 	deque<int> a;
 	return gen(a); 
 }
 
 void solve(bool skipThisTest) {
     if (true) {
         cerr << "\tinput mode: read test." << endl;
         n = nextInt();
 		forn(i, n) {
 			a[i] = nextInt();
 		}
         if (skipThisTest) return;
     } else {
         cerr << "\tinput mode: generated test." << endl;
         // generate test.
     }
 
 	vector<int> X;
 	forn(i, n) {
 		X.pb(a[i]);
 	}
 
 	sort(all(X));
 	forn(i, n) {
 		a[i] = int(lower_bound(all(X), a[i]) - X.begin());
 		pos[a[i]] = i;
 	}
 
 	memset(lf, 0, sizeof lf);
 	memset(rg, 0, sizeof rg);
 	forn(i, n) {
 		forn(j, i) {
 			if (a[i] > a[j]) {
 				rg[a[j]]++;
 			} else {
 				lf[a[i]]++;
 			}
 		}
 	}
 
 	memset(d, 255, sizeof d);
 	int ans = solve(0, n - 1);
 	cout << ans << endl;
     cerr << "\tclever answer is '" << ans << "'." << endl;
     if (n <= 15) {
         int stupidAnswer = stupid();
         cerr << "\tstupid answer is '" << stupidAnswer << "'." << endl;
         assert(ans == stupidAnswer);
     }
 }
 
 int main(int argc, char * argv[]) {
 #ifdef NALP_PROJECT
     freopen("input.txt", "rt", stdin);
   freopen("output.txt", "wt", stdout);
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
