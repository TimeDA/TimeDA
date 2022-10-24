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
 
 int n, a[MAXN], l[MAXN], d[MAXN];
 vector<pair<int, int> > st;
 vector<int> g[MAXN];
 queue<int> q;
 
 bool check() {
 	forn(i, n - 1) {
 		if (l[i] == -1) continue;
 
 		int64 p = -1, q = -1;
 		int id = -1;
 		for(int j = i + 1; j < n; j++)
 			if (l[j] >= l[i]) {
 				int64 pp = l[j] - l[i], qq = j - i;
 				if (id == -1 || p*qq < pp*q) {
 					id = j;
 					p = pp;
 					q = qq;
 				}
 			}
 
 		if (id != a[i])
 			return false;
 	}
 
 	return true;
 }
 
 bool gen(int v) {
 	if (v == (int)st.size())
 		return true;
 
 	int pos = st[v].second;
 	for(l[pos] = INF - 1; l[pos] >= 0; l[pos]--)
 		if (check() && gen(v + 1))
 			return true;
 
 	return false;
 }
 
 void read() {
 	cin >> n;
 	forn(i, n - 1) {
 		cin >> a[i];
 		a[i]--;
 	}
 
 }
 
 void update(int v, int value) {
 	if (d[v] == -1) {
 		d[v] = value;
 		q.push(v);
 	}
 }
 
 void solve() {
 	forn(i, n)
 		g[i].clear();
 
 	forn(i, n - 1)
 		g[a[i]].pb(i);
 
 	forn(i, n - 1)
 		forn(j, n - 1)
 			if (i < j && j < a[i] && a[j] > a[i]) {
 				cout << "Impossible" << endl;
 				return;
 			}
 
 	memset(d, 255, sizeof d);
 	memset(l, 255, sizeof l);
 	{
 		int v = 0;
 		while (true) {
 			l[v] = INF;
 			update(v, 0);
 			if (v == n - 1) break;
 			v = a[v];
 		}
 	}
 
 	while (!q.empty()) {
 		int v = q.front(); q.pop();
 		forn(i, g[v].size())
 			update(g[v][i], d[v] + 1);
 	}
 
 	st.clear();
 	forn(i, n - 1)
 		if (d[i] != 0)
 			st.pb(mp(d[i], i));
 
 	sort(all(st));
 
 	gen(0);
 	forn(i, n)
 		cout << l[i] << " ";
 
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
