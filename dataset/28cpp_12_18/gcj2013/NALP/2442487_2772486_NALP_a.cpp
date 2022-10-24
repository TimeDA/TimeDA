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
 const int64 MOD = 1000002013;
 
 struct event {
 	int64 x, type, num;
 
 	event(int64 x = 0, int64 type = 0, int64 num = 0) : x(x), type(type), num(num) {}
 
 	bool operator < (const event &e) const {
 		if (x != e.x) return x < e.x;
 		if (type != e.type) return type < e.type;
 		return num < e.num;
 	}
 };
 
 int64 s[MAXN], t[MAXN], p[MAXN];
 int m;
 
 void solve() {
 	bool GENERATE_TEST = false;
 	if (!GENERATE_TEST) {
 		int n = nextInt();
 		m = nextInt();
 		forn(i, m) {
 			s[i] = nextInt() - 1;
 			t[i] = nextInt() - 1;
 			assert(s[i] < t[i]);
 			p[i] = nextInt();
 		}
 	} else {
 		// Generate test
 	}
 
 	vector<event> e;
 	forn(i, m) {
 		e.pb(event(s[i], -1, p[i]));
 		e.pb(event(t[i], +1, p[i]));
 	}
 
 	int64 ans = 0;
 	sort(all(e));
 	int64 inE = 0, outE = 0;
 	multiset<pair<int64, int64> > st;
 	forn(i, e.size()) {
 		event cur = e[i];
 		if (cur.type == -1) {
 			inE += cur.num;
 			st.insert(mp(cur.x, cur.num));
 		} else {
 			int64 need = cur.num;
 			outE += need;
 			while (need > 0) {
 				pair<int64, int64> last = *st.rbegin();
 				st.erase(st.find(last));
 
 				int64 cnt = min(need, last.second);
 				last.second -= cnt;
 				need -= cnt;
 				if (last.second > 0) st.insert(last);
 
 				int64 dist = Abs(e[i].x - last.first);
 				int64 cost = (dist * (dist - 1) / 2) % MOD;
 				ans = (ans + cnt*cost) % MOD;
 			}
 		}
 	}
 
 	forn(i, m) {
 		int64 dist = Abs(t[i] - s[i]);
 		int64 cost = (dist * (dist - 1) / 2) % MOD;
 		int64 cur = (p[i] * cost) % MOD;
 		ans = (ans - cur + MOD) % MOD;
 	}
 
 	cout << ans << endl;
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
