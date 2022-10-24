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
 
 int n, a[MAXN], b[MAXN], ans[MAXN], d[MAXN];
 bool used[MAXN];
 
 bool gen(int v) {
 	if (v == n) {
 		ford(i, n) {
 			d[i] = 1;
 			for(int j = i + 1; j < n; j++)
 				if (ans[j] < ans[i])
 					d[i] = max(d[i], d[j] + 1);
 
 			if (d[i] != b[i])
 				return false;
 		}
 
 		return true;
 	}
 
 	int maxv = n, minv = INF;
 	forn(i, v) {
 		if (a[i] >= a[v])
 			maxv = min(maxv, ans[i] - 1);
 
 		if (a[i] + 1 == a[v])
 			minv = min(minv, ans[i] + 1);
 	}
 
 	if (a[v] == 1)
 		minv = 1;
 
 	for(int i = minv; i <= maxv; i++)
 		if (!used[i]) {
 			ans[v] = i;
 			used[i] = true;
 			if (gen(v + 1)) return true;
 			used[i] = false;
 		}
 
 	return false;
 }
 
 void solve() {
 	n = nextInt();
 	forn(i, n)
 		a[i] = nextInt();
 
 	forn(i, n)
 		b[i] = nextInt();
 
 	memset(used, 0, sizeof used);
 	assert(gen(0));
 	forn(i, n)
 		cout << ans[i] << " ";
 	cout << endl;
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
