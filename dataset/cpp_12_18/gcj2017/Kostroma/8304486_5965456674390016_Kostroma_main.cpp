#pragma comment(linker, "/STACK:512000000")
 #define _CRT_SECURE_NO_WARNINGS
 //#include "testlib.h"
 #include <bits/stdc++.h>
 using namespace std;
 
 #define all(a) a.begin(), a.end()
 typedef long long li;
 typedef long double ld;
 void solve(bool);
 void precalc();
 clock_t start;
 int main() {
 #ifdef AIM
   freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
   freopen("/home/alexandero/ClionProjects/ACM/output.txt", "w", stdout);
   //freopen("out.txt", "w", stdout);
 #else
   //freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
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
     cout << "Case #" << testNum++ << ": ";
     //cerr << testNum << endl;
     solve(true);
     //cerr << testNum - 1 << endl;
   }
   cout.flush();
 #ifdef AIM1
   while (true) {
       solve(false);
   }
 #endif
 
 #ifdef AIM
   cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
 #endif
 
   return 0;
 }
 
 //BE CAREFUL: IS INT REALLY INT?
 
 template<typename T>
 T binpow(T q, T w, T mod) {
   if (!w)
     return 1 % mod;
   if (w & 1)
     return q * 1LL * binpow(q, w - 1, mod) % mod;
   return binpow(q * 1LL * q % mod, w / 2, mod);
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
 
 void precalc() {
 
 }
 
 template<typename T>
 void relax_min(T& cur, T val) {
   cur = min(cur, val);
 }
 
 template<typename T>
 void relax_max(T& cur, T val) {
   cur = max(cur, val);
 }
 
 //#define int li
 //const int mod = 1000000007;
 
 vector<int> dsu;
 
 void init(int n) {
   dsu.resize(n);
   for (int i = 0; i < n; ++i) {
     dsu[i] = i;
   }
 }
 
 int find_set(int v) {
   if (dsu[v] == v) {
     return v;
   }
   return dsu[v] = find_set(dsu[v]);
 }
 
 bool merge(int q, int w) {
   q = find_set(q);
   w = find_set(w);
   if (q == w) {
     return false;
   }
   dsu[w] = q;
   return true;
 }
 
 struct State {
   int mask;
   int city;
   bool operator < (const State& ot) const {
     return make_pair(mask, city) < make_pair(ot.mask, ot.city);
   }
 };
 
 void solve(bool read) {
   int n;
   cin >> n;
   vector<int> fin(2 * n), start(2 * n), len(2 * n);
   for (int i = 0; i < 2 * n; ++i) {
     cin >> fin[i] >> start[i] >> len[i];
     --fin[i];
   }
 
   vector<int> powers(n + 1, 1);
   const int SIZE = 4;
   for (int i = 1; i < powers.size(); ++i) {
     powers[i] = powers[i - 1] * 4;
   }
 
   State start_state = {0, 0};
   map<State, int> dist;
   set<pair<int, State>> a;
   a.insert({0, start_state});
   dist[start_state] = 0;
   while (!a.empty()) {
     auto state = a.begin()->second;
     a.erase(a.begin());
     int id = state.city;
     int cur = state.mask / powers[id] % SIZE;
     for (int j = 0; j < 2; ++j) {
       if (cur & (1 << j)) {
         continue;
       }
       int next_id = fin[2 * id + j];
       int new_dist = dist[state];
       if (new_dist % 24 > start[2 * id + j]) {
         new_dist += 24 - (new_dist % 24 - start[2 * id + j]);
       } else {
         new_dist += start[2 * id + j] - new_dist % 24;
       }
       new_dist += len[2 * id + j];
       State next_state = {state.mask + powers[id] * (1 << j), next_id};
       if (!dist.count(next_state) || dist[next_state] > new_dist) {
         a.erase({dist[next_state], next_state});
         dist[next_state] = new_dist;
         a.insert({dist[next_state], next_state});
       }
     }
   }
 
   int finish_mask = 0;
   for (int i = 0; i < n; ++i) {
     finish_mask += powers[i] * 3;
   }
 
   cout << dist[State{finish_mask, 0}] << endl;
 
 
 
 }
