#pragma comment(linker, "/STACK:512000000")
 #define _CRT_SECURE_NO_WARNINGS
 #include "testlib.h"
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
 
 const int ITERS = 10000;
 const int BUCKETS = 10;
 
 vector<vector<int>> g;
 
 vector<int> sum;
 
 void dfs(int v) {
 	sum[v] = 1;
 	for (int to : g[v]) {
 		dfs(to);
 		sum[v] += sum[to];
 	}
 }
 
 void solve() {
 	int n;
 	cin >> n;
 	g.clear();
 	g.resize(n);
 	vector<int> all_roots;
 	for (int i = 0; i < n; ++i) {
 		int p;
 		cin >> p;
 		--p;
 		if (p != -1) {
 			g[p].push_back(i);
 		}
 		else {
 			all_roots.push_back(i);
 		}
 	}
 	sum.clear();
 	sum.resize(n);
 	for (int v : all_roots) {
 		dfs(v);
 	}
 	string s;
 	cin >> s;
 	
 	int m;
 	cin >> m;
 	vector<string> good(m);
 	for (int i = 0; i < m; ++i) {
 		cin >> good[i];
 	}
 
 	vector<vector<int>> roots(BUCKETS);
 	vector<int> roots_sum(BUCKETS);
 
 	int sum_sizes = 0;
 	for (int v : all_roots) {
 		int id = rnd.next(BUCKETS);
 		roots[id].push_back(v);
 		roots_sum[id] += sum[v];
 		sum_sizes += sum[v];
 	}
 
 	vector<vector<int>> cur_roots;
 	vector<int> cur_roots_sum;
 	vector<int> good_iters(m, 0), iters(m, 0);
 
 	map<string, int> mapa;
 	for (int it = 0; it < ITERS; ++it) {
 		cur_roots = roots;
 		cur_roots_sum = roots_sum;
 		int cnt = 0;
 		int into = sum_sizes;
 		string can;
 		while (cnt < n) {
 			int id = rnd.next(into);
 			for (int i = 0; i < BUCKETS; ++i) {
 				if (cur_roots_sum[i] > id) {
 					for (int j = 0; j < cur_roots[i].size(); ++j) {
 						if (sum[cur_roots[i][j]] > id) {
 							int now = cur_roots[i][j];
 							cur_roots[i].erase(cur_roots[i].begin() + j);
 							cur_roots_sum[i] -= sum[now];
 							into -= sum[now];
 							can += s[now];
 							++cnt;
 							for (int nex : g[now]) {
 								int new_bucket = rnd.next(BUCKETS);
 								cur_roots[new_bucket].push_back(nex);
 								cur_roots_sum[new_bucket] += sum[nex];
 								into += sum[nex];
 							}
 							break;
 						}
 						id -= sum[cur_roots[i][j]];
 					}
 					break;
 				}
 				id -= cur_roots_sum[i];
 			}
 		}
 		//++mapa[can];
 		for (int i = 0; i < m; ++i) {
 			bool have = false;
 			for (int pos = 0; pos + good[i].length() <= can.length(); ++pos) {
 				bool f = true;
 				for (int j = 0; j < good[i].length(); ++j) {
 					if (good[i][j] != can[pos + j]) {
 						f = false;
 						break;
 					}
 				}
 				if (f) {
 					have = true;
 					break;
 				}
 			}
 			++iters[i];
 			if (have) {
 				++good_iters[i];
 			}
 		}
 	}
 	for (auto item : mapa) {
 		//cerr << item.first << ' ' << item.second << "\n";
 	}
 
 	for (int i = 0; i < m; ++i) {
 		cout << (good_iters[i] / 1.0 / iters[i]) << ' ';
 	}
 	cout << "\n";
 
 }
 
 
 
