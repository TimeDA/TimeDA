#pragma comment(linker, "/STACK:512000000")
 #define _CRT_SECURE_NO_WARNINGS
 //#include "testlib.h"
 #include <cstdio>
 #include <cassert>
 #include <algorithm>
 #include <iostream>
 #include <memory.h>
 #include <string>
 #include <vector>
 #include <set>
 #include <map>
 #include <cmath>
 #include <bitset>
 #include <deque>
 #include <ctime>
 #include <stack>
 #include <queue>
 #include <fstream>
 #include <sstream>
 //#include <unordered_map>
 using namespace std;
 //#define FILENAME ""
 #define mp make_pair
 #define all(a) a.begin(), a.end()
 typedef long long li;
 typedef long double ld;
 void solve();
 void precalc();
 clock_t start;
 //int timer = 1;
 
 int testNumber = 1;
 
 bool todo = true;
 
 int main() {
 #ifdef room111
 	freopen("in.txt", "r", stdin);
 	freopen("out.txt", "w", stdout);
 #else
 	//freopen("input.txt", "r", stdin);
 	//freopen("output.txt", "w", stdout);
 	//freopen(FILENAME".in", "r", stdin);
 	//freopen(FILENAME ".out", "w", stdout);
 #endif
 	start = clock();
 	int t = 1;
 	cout.sync_with_stdio(0);
 	cin.tie(0);
 	precalc();
 	cout.precision(10);
 	cout << fixed;
 	cin >> t;
 	int testNum = 1;
 	while (t--) {
 		//cerr << testNum << endl;
 		cout << "Case #" << testNum++ << ": ";
 		solve();
 		++testNumber;
 		//++timer;
 	}
 
 #ifdef room111
 	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
 #endif
 
 	return 0;
 }
 
 //BE CAREFUL: IS INT REALLY INT?
 
 //#define int li
 
 /*int pr[] = { 97, 2011 };
 int mods[] = { 1000000007, 1000000009 };
 
 const int C = 300500;
 int powers[2][C];*/
 
 //int MOD = 1000000007;
 
 //int c[5010][5010];
 
 template<typename T>
 T binpow(T q, T w, T mod) {
 	if (!w)
 		return 1 % mod;
 	if (w & 1)
 		return q * 1LL * binpow(q, w - 1, mod) % mod;
 	return binpow(q * 1LL * q % mod, w / 2, mod);
 }
 
 /*int curMod = 1000000009;
 
 int fact[100500], revfact[100500];
 
 int getC(int n, int k) {
 int res = fact[n] * revfact[n - k] % curMod * revfact[k] % curMod;
 return res;
 }*/
 
 /*const int C = 7000500;
 
 int least_prime[C];*/
 
 void precalc() {
 	
 	/*for (int i = 2; i < C; ++i) {
 	if (!least_prime[i]) {
 	least_prime[i] = i;
 	for (li j = i * 1LL * i; j < C; j += i) {
 	least_prime[j] = i;
 	}
 	}
 	}*/
 
 	/*fact[0] = revfact[0] = 1;
 	for (int i = 1; i < 100500; ++i) {
 	fact[i] = fact[i - 1] * i % curMod;
 	revfact[i] = binpow(fact[i], curMod - 2, curMod);
 	}*/
 
 	/*for (int w = 0; w < 2; ++w) {
 	powers[w][0] = 1;
 	for (int j = 1; j < C; ++j) {
 	powers[w][j] = (powers[w][j - 1] * 1LL * pr[w]) % mods[w];
 	}
 	}*/
 	/*for (int i = 0; i < 5010; ++i) {
 	c[i][i] = c[i][0] = 1;
 	for (int j = 1; j < i; ++j) {
 	c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
 	}
 	}*/
 }
 
 template<typename T>
 T gcd(T q, T w) {
 	while (w) {
 		q %= w;
 		swap(q, w);
 	}
 	return q;
 }
 template<typename T>
 T lcm(T q, T w) {
 	return q / gcd(q, w) * w;
 }
 
 //#define int li
 
 //const int mod = 1000000007;
 
 pair<int, int> get_pos(int n, int m, int x) {
 	if (x < m) {
 		return{ 0, x + 1 };
 	}
 	x -= m;
 	if (x < n) {
 		return{ x + 1, m + 1 };
 	}
 	x -= n;
 	if (x < m) {
 		return{ n + 1, m - x };
 	}
 	x -= m;
 	if (x < n) {
 		return{ n - x, 0 };
 	}
 	assert(false);
 }
 
 vector<int> dsu;
 
 void init(int n) {
 	dsu.resize(n);
 	for (int i = 0; i < n; ++i) {
 		dsu[i] = i;
 	}
 }
 
 int n, m;
 
 int get_num(int x, int y, int type) {
 	return x * 2 * m + y * 2 + type;
 }
 
 int find_set(int v) {
 	if (dsu[v] == v) {
 		return v;
 	}
 	return dsu[v] = find_set(dsu[v]);
 }
 
 void merge(int q, int w) {
 	q = find_set(q);
 	w = find_set(w);
 	if (q == w) {
 		return;
 	}
 	dsu[w] = q;
 }
 
 void solve() {
 	cout << "\n";
 	cin >> n >> m;
 	vector<vector<pair<int, int>>> pairs;
 	for (int i = 0; i < (n + m); ++i) {
 		int a[2];
 		cin >> a[0] >> a[1];
 		--a[0];
 		--a[1];
 		pairs.push_back({ get_pos(n, m, a[0]), get_pos(n, m, a[1]) });
 	}
 
 	for (int mask = 0; mask < (1 << (n * m)); ++mask) {
 		vector<vector<int>> type(n, vector<int>(m));
 		int cnt = 0;
 		for (int i = 0; i < n; ++i) {
 			for (int j = 0; j < m; ++j) {
 				if (mask & (1 << cnt)) {
 					type[i][j] = 1;
 				}
 				++cnt;
 			}
 		}
 
 		init(2 * n * m);
 		for (int i = 0; i < n; ++i) {
 			for (int j = 0; j < m; ++j) {
 				if (type[i][j]) {
 					if (i > 0) {
 						merge(get_num(i, j, 0), get_num(i - 1, j, type[i - 1][j]));
 					}
 					if (j > 0) {
 						merge(get_num(i, j, 0), get_num(i, j - 1, 1));
 					}
 					if (i + 1 < n) {
 						merge(get_num(i, j, 1), get_num(i + 1, j, type[i + 1][j] ^ 1));
 					}
 					if (j + 1 < m) {
 						merge(get_num(i, j, 1), get_num(i, j + 1, 0));
 					}
 				}
 				else {
 					if (i > 0) {
 						merge(get_num(i, j, 1), get_num(i - 1, j, type[i - 1][j]));
 					}
 					if (j > 0) {
 						merge(get_num(i, j, 0), get_num(i, j - 1, 1));
 					}
 					if (i + 1 < n) {
 						merge(get_num(i, j, 0), get_num(i + 1, j, type[i + 1][j] ^ 1));
 					}
 					if (j + 1 < m) {
 						merge(get_num(i, j, 1), get_num(i, j + 1, 0));
 					}
 				}
 			}
 		}
 		set<int> comps;
 		bool flag = true;
 		for (auto need : pairs) {
 			vector<int> sos;
 			for (auto cur : need) {
 				auto nex = cur;
 				int need_type = 0;
 				if (cur.first == 0) {
 					++nex.first;
 					if (type[nex.first - 1][nex.second - 1] == 0) {
 						need_type = 1;
 					}
 				}
 				else if (cur.first == n + 1) {
 					--nex.first;
 					if (type[nex.first - 1][nex.second - 1] == 1) {
 						need_type = 1;
 					}
 				}
 				else if (cur.second == 0) {
 					++nex.second;
 				}
 				else if (cur.second == m + 1) {
 					--nex.second;
 					need_type = 1;
 				}
 				//cerr << cur.first << ' ' << cur.second << ' ' << nex.first << ' ' << nex.second << ' ' << need_type << "\n";
 				sos.push_back(find_set(get_num(nex.first - 1, nex.second - 1, need_type)));
 			}
 			if (sos[0] != sos[1]) {
 				flag = false;
 				break;
 			}
 			comps.insert(sos[0]);
 		}
 
 		if (!flag) {
 			continue;
 		}
 		
 		if (comps.size() != pairs.size()) {
 			continue;
 		}
 
 		for (int i = 0; i < n; ++i) {
 			for (int j = 0; j < m; ++j) {
 				if (type[i][j]) {
 					cout << "/";
 				}
 				else {
 					cout << "\\";
 				}
 			}
 			cout << "\n";
 		}
 		return;
 	}
 
 	cout << "IMPOSSIBLE\n";
 
 }
 
 
 
