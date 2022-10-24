#ifdef NALP_PROJECT
 #pragma hdrstop
 #else
 #define _SECURE_SCL 0
 #endif
 
 #define _CRT_SECURE_NO_DEPRECATE
 #pragma comment(linker, "/STACK:64000000")
 
 #include <cstdio>
 #include <cstdlib>
 #include <ctime>
 #include <cctype>
 #include <cmath>
 #include <algorithm>
 #include <utility>
 
 #include <set>
 #include <map>
 #include <vector>
 #include <string>
 #include <queue>
 #include <memory.h>
 
 #include <iostream>
 #include <sstream>
 
 using namespace std;
 
 typedef long long int64;
 
 #define forn(i, n) for(int i = 0; i < (int)(n); i++)
 #define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
 #define pb push_back
 #define mp make_pair
 #define X first
 #define Y second
 #define y1 YYYYYYYYYYYY1
 #define all(a) (a).begin(), (a).end()
 #define rall(a) (a).rbegin(), (a).rend()
 #define Abs(x) (((x) >= 0) ? (x) : (-(x)))
 
 const int INF = (int)1E9;
 const int64 INF64 = (int64)1E18;
 const long double EPS = 1E-9;
 const long double PI = 3.1415926535897932384626433832795;
 
 const int MAXN = 100100;
 
 int n, w, l, T;
 pair<int, int> a[MAXN];
 int x[MAXN], y[MAXN];
 int ax[MAXN], ay[MAXN];
 
 void read() {
 	cin >> n >> w >> l;
 	forn(i, n)
 		cin >> a[i].first;
 }
 
 int rnd() {
 	return abs(rand() * rand());
 }
 
 bool check(int v, int xx, int yy) {
 	forn(i, v) {
 		int64 d = (0LL + xx - x[i])*(0LL + xx - x[i]) + (0LL + yy - y[i])*(0LL + yy - y[i]);
 		if (d < (0LL + a[i].first + a[v].first)*(0LL + a[i].first + a[v].first))
 			return false;
 	}
 
 	return true;
 }
 
 bool gen2(int v) {
 	if (v == n)
 		return true;
 
 	if (clock() - T > 10000)
 		return false;
 
 	while (true) {
 		int xx = rnd() % (w + 1);
 		int yy = rnd() % (l + 1);
 
 		if (check(v, xx, yy)) {
 			x[v] = xx;
 			y[v] = yy;
 			if (gen2(v + 1)) return true;
 		}				
 
 		if (clock() - T > 10000)
 			return false;
 	}	
 
 	return false;
 }
 
 bool gen1(int v) {
 	if (v == n)
 		return true;
 
 	if (clock() - T > 10000)
 		return false;
 
 	for(int xx = 0; xx <= w; xx++) {
 		if (clock() - T > 10000)
 			return false;
 
 		if (check(v, xx, 0)) {
 			x[v] = xx;
 			y[v] = 0;
 			if (gen1(v + 1)) return true;
 			break;
 		}
 
 		if (check(v, xx, l)) {
 			x[v] = xx;
 			y[v] = l;
 			if (gen1(v + 1)) return true;
 			break;
 		}
 	}
 
 	for(int yy = 0; yy <= l; yy++) {
 		if (clock() - T > 10000)
 			return false;
 
 		if (check(v, 0, yy)) {
 			x[v] = 0;
 			y[v] = yy;
 			if (gen1(v + 1)) return true;
 			break;
 		}
 
 		if (check(v, w, yy)) {
 			x[v] = w;
 			y[v] = yy;
 			if (gen1(v + 1)) return true;
 			break;
 		}
 	}
 
 	for(int yy = 0; yy <= l; yy += a[v].first) {
 		if (clock() - T > 10000)
 			return false;
 
 		for(int xx = 0; xx <= w; xx += a[v].first) {
 			if (clock() - T > 10000)
 				return false;
 
 			if (check(v, xx, yy)) {
 				x[v] = xx;
 				y[v] = yy;
 				if (gen1(v + 1)) return true;
 			}
 		}
 	}
 
 	while (true) {
 		int xx = rnd() % (w + 1);
 		int yy = rnd() % (l + 1);
 
 		if (clock() - T > 10000)
 			return false;
 
 		if (check(v, xx, yy)) {
 			x[v] = xx;
 			y[v] = yy;
 			if (gen1(v + 1)) return true;
 		}				
 	}	
 
 	return false;
 }
 
 void solve() {
 	forn(i, n) a[i].second = i;
 
 	bool ans = false;
 	while (true) {
 		T = clock();
 		if (!ans) ans = gen2(0);
 
 		T = clock();
 		if (!ans) ans = gen1(0);
 
 		if (ans) break;
 		random_shuffle(a, a + n);
 	}
 	
 	forn(i, n) {
 		ax[a[i].second] = x[i];
 		ay[a[i].second] = y[i];
 	}
 
 	forn(i, n)
 		cout << ax[i] << " " << ay[i] << " ";
 
 	cout << endl;
 }
 
 int main() {
 #ifdef NALP_PROJECT
 	freopen("input.txt", "rt", stdin);
 	freopen("output.txt", "wt", stdout);
 #else
 #endif
 
 	cout.precision(9);
 	cout.setf(ios::fixed);
 
 	cerr.precision(3);
 	cerr.setf(ios::fixed);
 
 	int tests;
 	cin >> tests;
 	forn(i, tests) {
 		cerr << "Test #" << i + 1 << endl;
 		time_t curTime = clock();
 
 		cout << "Case #" << i + 1 << ": ";
 		read();
 		solve();
 
 		cerr << "calced : " << (clock() - curTime + 0.0) / CLOCKS_PER_SEC << endl << endl;
 	}
 	
 	return 0;
 }
