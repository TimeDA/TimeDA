#ifdef _MSC_VER
 #define _CRT_SECURE_NO_DEPRECATE
 #pragma comment(linker, "/STACK:66777216")
 #else
 #pragma GCC optimize("O3")
 #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,pclmul")
 #endif
 #include <algorithm>
 #include <string>
 #include <set>
 #include <map>
 #include <vector>
 #include <queue>
 #include <iostream>
 #include <iterator>
 #include <cmath>
 #include <cstdio>
 #include <cstdlib>
 #include <sstream>
 #include <fstream>
 #include <ctime>
 #include <cstring>
 #include <chrono>
 using namespace std;
 #define pb push_back
 #define ppb pop_back
 #define pi 3.1415926535897932384626433832795028841971
 #define mp make_pair
 #define x first
 #define y second
 #define pii pair<int,int>
 #define pdd pair<double,double>
 #define INF 1000000000
 #define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
 #define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
 #define all(c) (c).begin(), (c).end()
 #define SORT(c) sort(all(c))
 #define rep(i,n) FOR(i,1,(n))
 #define rept(i,n) FOR(i,0,(n)-1)
 #define L(s) (int)((s).size())
 #define C(a) memset((a),0,sizeof(a))
 #define VI vector <int>
 #define ll long long
 #define pss pair<short, short>
 
 vector<pss> f[13];
 pair<pss, pss> pr[13][(1 << 11) + 1][(1 << 11) + 1];
 int num[13][(1 << 11) + 1][(1 << 11) + 1];
 int can[13][(1 << 11) + 1][(1 << 11) + 1];
 int comb[8][8];
 
 inline void sr(int v) {
 	int n = 1 << v;
 	if (!v) {
 		sort(f[v].begin(), f[v].end(), [&](const pss &a, const pss &b) {
 			if (a.x != b.x) return a.x > b.x;
 			if (a.y != b.y) return a.y > b.y;
 			return false;
 		});
 	}
 	else {
 		sort(f[v].begin(), f[v].end(), [&](const pss &a, const pss &b) {
 			return num[v - 1][a.x][a.y] < num[v - 1][b.x][b.y];
 		});
 	}
 	rept(i, L(f[v])) {
 		num[v][f[v][i].x][f[v][i].y] = i;
 	}
 }
 
 int kolt, n, a, b, c;
 void build(int v, int x, int y, string& s) {
 	if (v == 0) {
 		if (x) s += 'P'; else
 			if (y) s += 'R'; else
 				s += 'S';
 		return;
 	}
 	auto t1 = pr[v][x][y].x, t2 = pr[v][x][y].y;
 	build(v - 1, t1.x, t1.y, s);
 	build(v - 1, t2.x, t2.y, s);
 }
 
 inline int gt(int a, int b) {
 	if (a > b) swap(a, b);
 	if (a == 0 && b == 1) return 1;
 	if (a == 0 && b == 2) return 0;
 	if (a == 1 && b == 2) return 2;
 }
 int main() {
 	freopen("A-small-attempt1.in", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	memset(pr, -1, sizeof(pr));
 	memset(num, -1, sizeof(num));
 	f[0].pb(mp(0, 0));
 	f[0].pb(mp(0, 1));
 	f[0].pb(mp(1, 0));
 	sr(0);
 	pr[0][0][0] = mp(mp(0, 0), mp(0, 0));
 	pr[0][0][1] = mp(mp(0, 0), mp(0, 0));
 	pr[0][1][0] = mp(mp(0, 0), mp(0, 0));
 	can[0][0][0] = 1 << 2;
 	can[0][0][1] = 1 << 1;
 	can[0][1][0] = 1 << 0;
 
 	rept(i1, 8) {
 		rept(i2, 8) {
 			if (!i1 || !i2) continue;
 			int c = 0;
 			rept(j1, 3) {
 				if (~i1 & 1 << j1) continue;
 				rept(j2, 3) {
 					if (~i2 & 1 << j2) continue;
 					if (j1 == j2) continue;
 					c |= 1 << gt(j1, j2);
 				}
 			}
 			comb[i1][i2] = c;
 		}
 	}
 
 	rep(h, 12) {
 		cerr << h << " " << L(f[h - 1]) << endl;
 		int u = 1 << h;
 		int pu = u / 2;
 		rept(i, u + 1) {
 			if (i * 2 > u) break;
 			rept(j, u + 1) {
 				if (j * 2 > u) break;
 				if (i + j > u) break;
 				int z = u - i - j;
 				if (z * 2 > u) continue;
 				bool found = 0;
 				rept(o, L(f[h - 1])) {
 					auto t = f[h - 1][o];
 					if (t.x <= i && t.y <= j && pu - t.x - t.y <= z) {
 						int a = i - t.x, b = j - t.y;
 						if (h == 1 || (a * 2 <= pu && b * 2 <= pu)) {
 							if (num[h - 1][a][b] != -1) {
 								if (comb[can[h - 1][t.x][t.y]][can[h - 1][a][b]] != 0) {
 									if (!found) {
 										pr[h][i][j] = mp(mp(t.x, t.y), mp(a, b));
 										f[h].pb(mp(i, j));
 										found = 1;
 									}
 									can[h][i][j] |= comb[can[h - 1][t.x][t.y]][can[h - 1][a][b]];
 									if (can[h][i][j] == 7 && found)	break;
 								}
 							}
 						}
 					}
 				}
 			}
 		}
 		sr(h);
 	}
 
 	scanf("%d", &kolt);
 	rep(hod, kolt) {
 		int t;
 		scanf("%d%d%d%d", &t, &a, &b, &c);
 		int n = 1 << t;
 		printf("Case #%d: ", hod);
 		if (a * 2 > n || b * 2 > n || c * 2 > n) {
 			printf("IMPOSSIBLE\n");
 			continue;
 		}
 		
 		int s0 = b, s1 = a;
 		if (num[t][s0][s1] == -1) {
 			printf("IMPOSSIBLE\n");
 			continue;
 		}
 		string s = "";
 		build(t, s0, s1, s);
 		printf("%s\n", s.c_str());
 	}
 }
