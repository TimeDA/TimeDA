/*
     Author: Nikolay Kuznetsov
     Dedicated to my Love, Kristina Dmitrashko
 */
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
 inline int64 nextInt64() { int64 x; if (scanf("%I64d", &x) != 1) throw; return x; }
 inline double nextDouble() { double x; if (scanf("%lf", &x) != 1) throw; return x; }
 
 const int INF = (int)1E9;
 const int64 INF64 = (int64)1E18;
 const long double EPS = 1E-9;
 const long double PI = 3.1415926535897932384626433832795;
 
 const int MAXN = 100100;
 
 int64 getBest(int n, int64 v) {
 	if (v + 1 == 1LL << n) return 1LL << n;
 	return getBest(n - 1, (v + 1) / 2);
 }
 
 int64 getWorst(int n, int64 v) {
 	if (v == 0) return 1;
 	return getWorst(n - 1, (v - 1) / 2) + (1LL << n)/2;
 }
 
 int n;
 int64 p;
 
 int64 stupid() {
 	return 0;
 }
 
 void solve() {
 	bool GENERATE_TEST = false;
 	if (!GENERATE_TEST) {
 		n = nextInt();
 		p = nextInt64();
 	} else {
 		// Generate test
 	}
 
 	int64 l = 0, r = (1LL << n) - 1;
 	while (r - l > 1) {
 		int64 mid = (l + r) >> 1;
 		if (getBest(n, mid) <= p)
 			l = mid;
 		else
 			r = mid;
 	}
 
 	int64 ans1 = -1;
 	for(int64 mid = l; mid <= r; mid++)
 		if (getBest(n, mid) <= p)
 			ans1 = mid;
 
 	l = 0, r = (1LL << n) - 1;
 	while (r - l > 1) {
 		int64 mid = (l + r) >> 1;
 		if (getWorst(n, mid) <= p)
 			l = mid;
 		else
 			r = mid;
 	}
 
 	int64 ans2 = -1;
 	for(int64 mid = l; mid <= r; mid++)
 		if (getWorst(n, mid) <= p)
 			ans2 = mid;
 
 	cout << ans2 << " " << ans1 << endl;	
 
 	//int64 ans = 0;
 	//cerr << "\tclever answer is '" << ans << "'" << endl;
 	//if (false) {
 	//	int64 stupidAnswer = stupid();
 	//	cerr << "\tstupid answer is '" << stupidAnswer << "'" << endl;
 	//	if (ans != stupidAnswer) {
 	//		cerr << "\tanswers aren't equal!" << endl;
 	//		throw;
 	//	}
 	//}
 }
 
 int main() {
 #ifdef NALP_PROJECT
 	freopen("input.txt", "rt", stdin);
 	freopen("output.txt", "wt", stdout);
 #else
 #endif
 
 	srand((unsigned int)time(0));
 	int tests = nextInt();
 	forn(test, tests) {
 		time_t start = clock();
 		cerr << "Case #" << test + 1 << endl;
 		cout << "Case #" << test + 1 << ": ";
 		solve();
 		cerr << "time is " << (0.0 + clock() - start) / CLOCKS_PER_SEC << endl;
 	}
 
 	return 0;
 }
