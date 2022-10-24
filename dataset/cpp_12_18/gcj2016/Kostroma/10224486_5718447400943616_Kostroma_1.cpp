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
 
 vector<bool> used;
 
 bool can_bad(int n, const vector<vector<int>>& matrix, const vector<int>& p, int pos) {
 	if (pos == n) {
 		return false;
 	}
 	bool res = false;
 	bool have = false;
 	for (int can = 0; can < n; ++can) {
 		if (matrix[p[pos]][can] && !used[can]) {
 			have = true;
 			used[can] = true;
 			res |= can_bad(n, matrix, p, pos + 1);
 			used[can] = false;
 		}
 	}
 	if (!have) {
 		return true;
 	}
 	return res;
 }
 
 void solve() {
 	int n;
 	cin >> n;
 	vector<vector<int>> matrix(n, vector<int>(n));
 	for (int i = 0; i < n; ++i) {
 		string s; 
 		cin >> s;
 		for (int j = 0; j < n; ++j) {
 			matrix[i][j] = s[j] - '0';
 		}
 	}
 	int ans = n * n;
 	for (int mask = 0; mask < (1 << (n * n)); ++mask) {
 		auto cur = matrix;
 		int cnt = 0;
 		int res = 0;
 		for (int i = 0; i < n; ++i) {
 			for (int j = 0; j < n; ++j) {
 				if (mask & (1 << cnt)) {
 					if (!matrix[i][j]) {
 						cur[i][j] = 1;
 						++res;
 					}
 				}
 				cnt++;
 			}
 		}
 		vector<int> p(n);
 		for (int i = 0; i < n; ++i) {
 			p[i] = i;
 		}
 		bool good = true;
 		do {
 			used.assign(n, false);
 			if (can_bad(n, cur, p, 0)) {
 				good = false;
 				break;
 			}
 		} while (next_permutation(all(p)));
 
 		if (good) {
 			ans = min(ans, res);
 		}
 	}
 	cout << ans << "\n";
 
 	/*int n, k;
 	cin >> n >> k;
 	vector<ld> p(n);
 	for (int i = 0; i < n; ++i) {
 		cin >> p[i];
 	}
 
 	vector<int> q(n);
 	for (int i = n - k; i < n; ++i) {
 		q[i] = 1;
 	}
 	ld rres = 0;
 	do {
 		vector<ld> z;
 		for (int i = 0; i < n; ++i) {
 			if (q[i]) {
 				z.push_back(p[i]);
 			}
 		}
 		vector<vector<ld>> dp(k + 1, vector<ld>(k + 1, 0));
 		dp[0][0] = 1;
 		for (int i = 0; i < k; ++i) {
 			for (int win = 0; win <= i; ++win) {
 				dp[i + 1][win] += (1 - z[i]) * dp[i][win];
 				dp[i + 1][win + 1] += z[i] * dp[i][win];
 			}
 		}
 		rres = max(rres, dp[k][k / 2]);
 
 	} while (next_permutation(q.begin(), q.end()));
 
 	cout << rres << " ";
 
 	vector<vector<ld>> dp_pref(n + 1, vector<ld>(n + 1, 0));
 	dp_pref[0][0] = 1;
 	for (int i = 0; i < n; ++i) {
 		for (int win = 0; win <= i; ++win) {
 			dp_pref[i + 1][win] += (1 - p[i]) * dp_pref[i][win];
 			dp_pref[i + 1][win + 1] += p[i] * dp_pref[i][win];
 		}
 	}
 	vector<vector<ld>> dp_suf(n + 1, vector<ld>(n + 1, 0));
 	dp_suf[n][0] = 1;
 	for (int i = n - 1; i >= 0; --i) {
 		for (int win = 0; win <= n - i - 1; ++win) {
 			dp_suf[i][win] += (1 - p[i]) * dp_suf[i + 1][win];
 			dp_suf[i][win + 1] += p[i] * dp_suf[i + 1][win];
 		}
 	}
 
 	ld res = 0;
 	for (int pref = 0; pref <= k; ++pref) {
 		int suf = k - pref;
 		ld cur_res = 0;
 		for (int win_pref = 0; win_pref <= pref; ++win_pref) {
 			int win_suf = k / 2 - win_pref;
 			if (win_suf < 0) {
 				continue;
 			}
 			cur_res += dp_pref[pref][win_pref] * dp_suf[n - suf][win_suf];
 		}
 		res = max(res, cur_res);
 	}
 
 	for (int start = 0; start + k <= n; ++start) {
 		vector<vector<ld>> dp(k + 1, vector<ld>(k + 1, 0));
 		dp[0][0] = 1;
 		for (int i = 0; i < k; ++i) {
 			for (int win = 0; win <= i; ++win) {
 				dp[i + 1][win] += (1 - p[i + start]) * dp[i][win];
 				dp[i + 1][win + 1] += p[i + start] * dp[i][win];
 			}
 		}
 		res = max(res, dp[k][k / 2]);
 	}
 
 	cout << res << " ";
 
 	ld mx = 0, mn = 1;
 	for (int i = 0; i < n; ++i) {
 		mx = max(mx, p[i]);
 		mn = min(mn, p[i]);
 	}
 
 	cout << mn << ' ' << mx << "\n";*/
 
 }
 
 
 
