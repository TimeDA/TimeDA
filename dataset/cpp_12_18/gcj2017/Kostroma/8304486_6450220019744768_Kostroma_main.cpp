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
 
 void solve(bool read) {
   int n, m;
   cin >> n >> m;
   vector<pair<int, int>> edges;
   for (int i = 0; i < m; ++i) {
     int a, b;
     cin >> a >> b;
     --a; --b;
     edges.push_back({a, b});
   }
   /*cout << n << " " << m << endl;
   for (auto e : edges) {
     cout << e.first << " " << e.second << endl;
   }*/
   init(n);
   vector<int> tree, rem;
   for (int i = 0; i < m; ++i) {
     int a = edges[i].first, b = edges[i].second;
     if (merge(a, b)) {
       tree.push_back(i);
     } else {
       rem.push_back(i);
     }
   }
 
   vector<vector<int>> g(n);
   for (int i : tree) {
     g[edges[i].first].push_back(i);
     g[edges[i].second].push_back(i);
   }
 
   vector<vector<pair<int, int>>> expr(m);
   for (int ex : rem) {
     expr[ex].push_back({ex, 1});
     int start = edges[ex].second, finish = edges[ex].first;
     queue<int> q;
     q.push(start);
     vector<int> par(n, -1);
     while (!q.empty()) {
       int v = q.front();
       q.pop();
       if (v == finish) {
         break;
       }
       for (int e : g[v]) {
         int to = edges[e].second;
         if (to == v) {
           to = edges[e].first;
         }
         if (par[to] == -1) {
           par[to] = e;
           q.push(to);
         }
       }
     }
 
     if (par[finish] == -1) {
       cout << "IMPOSSIBLE\n";
       return;
     }
     int v = finish;
     while (v != start) {
       auto e = par[v];
       int to = edges[e].first;
       int coef = 1;
       if (to == v) {
         coef = -1;
         to = edges[e].second;
       }
       expr[e].push_back({ex, coef});
       v = to;
     }
   }
 
   for (int i : tree) {
     if (expr[i].empty()) {
       cout << "IMPOSSIBLE\n";
       return;
     }
   }
 
   vector<int> colors(m);
   int border = 1;
   while (true) {
     for (int it = 0; it < 50; ++it) {
       for (int i : rem) {
         colors[i] = rand() % border + 1;
         if (rand() & 1) {
           colors[i] = -colors[i];
         }
       }
       bool flag = true;
       for (int i : tree) {
         colors[i] = 0;
         for (auto item : expr[i]) {
           colors[i] += colors[item.first] * item.second;
         }
         if (colors[i] == 0) {
           flag = false;
           break;
         }
       }
 
       if (flag) {
         for (int i = 0; i < m; ++i) {
           assert(abs(colors[i]) <= n * n && colors[i] != 0);
           cout << colors[i] << " ";
         }
         cout << endl;
         return;
       }
     }
     if (border >= n) {
       border += 2;
     } else if (border + 5 >= n) {
       ++border;
     } else {
       border *= 2;
       if (border + 5 >= n) {
         border = n - 5;
       }
     }
   }
 
 
 
 }
