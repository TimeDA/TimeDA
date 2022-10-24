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
         solve(true);
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
 
 //const int mod = 1000000007;
 
 //#define int li
 
 const int INF = (int)1e9;
 int NEED_FLOW = 10000;
 #define mp make_pair
 typedef int int_e;
 
 struct edge {
   int from, to;
   int cap;
   int_e cost;
   int flow;
 };
 
 vector<edge> edges;
 vector<vector<int>> g;
 
 void add_edge(int from, int to, int_e cost, int cap) {
   //cout << from << ' ' << to << ' ' << cost <<  ' ' << cap << "\n";
   edge e = {from, to, cap, cost, 0};
   g[from].push_back(edges.size());
   edges.push_back(e);
   edge e2 = {to, from, 0, -cost, 0};
   g[to].push_back(edges.size());
   edges.push_back(e2);
 }
 
 pair<int, int_e> mincost(int n, int s, int t) {
   int_e cost = 0;
   int flow = 0;
   vector<int_e> potential;
   {
     vector<int> p(n, -1);
     vector<int_e> d(n);
     d[s] = 0;
     p[s] = s;
     bool changed = true;
     while(changed) {
       changed = false;
       for(size_t i = 0; i < edges.size(); ++i) {
         edge& e = edges[i];
         if(e.cap == e.flow || p[e.from] == -1)
           continue;
         if(p[e.to] == -1 || d[e.to] > d[e.from] + e.cost) {
           d[e.to] = d[e.from] + e.cost;
           p[e.to] = i;
           changed = true;
         }
       }
     }
     potential = std::move(d);
   }
   while(flow < NEED_FLOW) {
 
     //if(d[t] >= 0) { // only for mincost, not mincostmaxflow
     //	break;
     //}
 
     vector<int_e> d(n);
     vector<int> p(n, -1);
 
     typedef pair<int_e, int> queue_type;
     priority_queue<queue_type, vector<queue_type>, greater<queue_type>> q;
 
     q.push(mp(0, s));
 
     while(!q.empty()) {
       int v = q.top().second;
       int_e oldD = q.top().first;
       q.pop();
       if(oldD != d[v])
         continue;
       for(int id: g[v]) {
         edge& e = edges[id];
         if (e.to == s)
           continue;
         if(e.cap > e.flow) {
           int_e newd = d[v] + e.cost + potential[e.from] - potential[e.to];
           if(p[e.to] == -1 || d[e.to] > newd) {
             d[e.to] = newd;
             p[e.to] = id;
             q.push(mp(d[e.to], e.to));
           }
         }
       }
     }
 
     if(p[t] == -1)
       break;
 
     //if(d[t] >= 0) { // only for mincost, not mincostmaxflow
     //	break;
     //}
 
     int cur = t;
     int maxAdd = NEED_FLOW - flow;
     while(cur != s) {
       edge& e = edges[p[cur]];
       cur = e.from;
       maxAdd = min(maxAdd, e.cap - e.flow);
     }
 
     flow += maxAdd;
     cost += (potential[t] + d[t]) * maxAdd;
     cur = t;
     while(cur != s) {
       int id = p[cur];
       edges[id].flow += maxAdd;
       edges[id ^ 1].flow -= maxAdd;
       cur = edges[id].from;
     }
 
     for (int i = 0; i < n; ++i) {
       if (i != s && p[i] == -1) {
         potential[i] = INF;
       }
       else
         potential[i] = min(potential[i] + d[i], INF);
     }
   }
 
   // cost and flow are final here
   return make_pair(flow, cost);
 }
 
 vector<int> pos, buyer;
 int n, c, m;
 
 void build(int S, int T, int M) {
   edges.clear();
   g.clear();
   g.resize(T + 1);
   for (int i = 0; i < c; ++i) {
     add_edge(S, i, 0, INF);
   }
   for (int i = 0; i < n; ++i) {
     add_edge(i + c, T, 0, M);
   }
   for (int i = 0; i < m; ++i) {
     add_edge(buyer[i], pos[i] + c, 0, 1);
   }
   for (int i = 0; i + 1 < n; ++i) {
     add_edge(n + c + i + 1, n + c + i, 0, INF);
   }
   for (int i = 0; i < n; ++i) {
     add_edge(n + c + i, c + i, 0, INF);
     add_edge(c + i, n + c + i, 1, INF);
   }
 }
 
 void solve(bool read) {
   cin >> n >> c >> m;
   pos.resize(m);
   buyer.resize(m);
   vector<int> bought(c);
   for (int i = 0; i < m; ++i) {
     cin >> pos[i] >> buyer[i];
     --pos[i];
     --buyer[i];
     ++bought[buyer[i]];
   }
 
   int S = c + n + n;
   int T = S + 1;
 
   int L = 0;
   for (int i = 0; i < c; ++i) {
     L = max(L, bought[i]);
   }
   --L;
   int R = m + 5;
   while (L + 1 < R) {
     int M = (L + R) / 2;
     build(S, T, M);
     auto res = mincost(T + 1, S, T);
     //cout << M << " " << res.first << " " << res.second << endl;
     if (res.first == m) {
       R = M;
     } else {
       L = M;
     }
   }
 
   build(S, T, R);
 
   cout << R << " " << mincost(T + 1, S, T).second << endl;
 
 
 }