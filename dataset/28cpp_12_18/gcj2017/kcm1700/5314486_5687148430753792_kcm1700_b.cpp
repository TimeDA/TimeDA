#include <cstdio>
 #include <algorithm>
 #include <cstdlib>
 #include <cmath>
 #include <climits>
 #include <cstring>
 #include <string>
 #include <vector>
 #include <queue>
 #include <numeric>
 #include <functional>
 #include <set>
 #include <map>
 
 using namespace std;
 
 struct MinCostFlow
 {
   typedef int cap_t;
   typedef int cost_t;
 
   bool iszerocap(cap_t cap) { return cap == 0; }
 
   struct edge {
     int target;
     cost_t cost;
     cap_t residual_capacity;
     cap_t orig_capacity;
     size_t revid;
   };
 
   int n;
   vector<vector<edge>> graph;
   vector<cost_t> pi;
   bool needNormalize, ranbefore;
   int lastStart;
 
   MinCostFlow(int n) : graph(n), n(n), pi(n, 0), needNormalize(false), ranbefore(false) {}
   void addEdge(int s, int e, cost_t cost, cap_t cap)
   {
     if (s == e) return;
     edge forward = { e, cost, cap, cap, graph[e].size() };
     edge backward = { s, -cost, 0, 0, graph[s].size() };
     if (cost < 0 || ranbefore) needNormalize = true;
     graph[s].emplace_back(forward);
     graph[e].emplace_back(backward);
   }
   bool normalize(int s) {
     auto infinite_cost = numeric_limits<cost_t>::max();
     vector<cost_t> dist(n, infinite_cost);
     dist[s] = 0;
     queue<int> q;
     vector<int> v(n), relax_count(n);
     v[s] = 1; q.push(s);
     while (!q.empty()) {
       int cur = q.front();
       v[cur] = 0; q.pop();
       if (++relax_count[cur] >= n) return false;
       for (const auto &e : graph[cur]) {
         if (iszerocap(e.residual_capacity)) continue;
         auto next = e.target;
         auto ncost = dist[cur] + e.cost;
         if (dist[next] > ncost) {
           dist[next] = ncost;
           if (v[next]) continue;
           v[next] = 1; q.push(next);
         }
       }
     }
     for (int i = 0; i < n; i++) pi[i] = dist[i];
     return true;
   }
 
   pair<cost_t, cap_t> AugmentShortest(int s, int e, cap_t flow_limit) {
     auto infinite_cost = numeric_limits<cost_t>::max();
     auto infinite_flow = numeric_limits<cap_t>::max();
     typedef pair<cost_t, int> pq_t;
     priority_queue<pq_t, vector<pq_t>, greater<pq_t>> pq;
     vector<pair<cost_t, cap_t>> dist(n, make_pair(infinite_cost, 0));
     vector<int> from(n, -1), v(n);
 
     if (needNormalize || (ranbefore && lastStart != s))
       normalize(s);
     ranbefore = true;
     lastStart = s;
 
     dist[s] = pair<cost_t, cap_t>(0, infinite_flow);
     pq.emplace(dist[s].first, s);
     while (!pq.empty()) {
       auto cur = pq.top().second; pq.pop();
       if (v[cur]) continue;
       v[cur] = 1;
       if (cur == e) continue;
       for (const auto &e : graph[cur]) {
         auto next = e.target;
         if (v[next]) continue;
         if (iszerocap(e.residual_capacity)) continue;
         auto ncost = dist[cur].first + e.cost - pi[next] + pi[cur];
         auto nflow = min(dist[cur].second, e.residual_capacity);
         if (dist[next].first <= ncost) continue;
         dist[next] = make_pair(ncost, nflow);
         from[next] = e.revid;
         pq.emplace(dist[next].first, next);
       }
     }
     /** augment the shortest path **/
     auto p = e;
     auto pathcost = dist[p].first + pi[p] - pi[s];
     auto flow = dist[p].second;
     if (iszerocap(flow) || (flow_limit <= 0 && pathcost >= 0)) return pair<cost_t, cap_t>(0, 0);
     if (flow_limit > 0) flow = min(flow, flow_limit);
     /* update potential */
     for (int i = 0; i < n; i++) {
       if (iszerocap(dist[i].second)) continue;
       pi[i] += dist[i].first;
     }
     while (from[p] != -1) {
       auto nedge = from[p];
       auto np = graph[p][nedge].target;
       auto fedge = graph[p][nedge].revid;
       graph[p][nedge].residual_capacity += flow;
       graph[np][fedge].residual_capacity -= flow;
       p = np;
     }
     return make_pair(pathcost * flow, flow);
   }
 
   pair<cost_t, cap_t> solve(int s, int e, cap_t flow_minimum = numeric_limits<cap_t>::max()) {
     cost_t total_cost = 0;
     cap_t total_flow = 0;
     for (;;) {
       auto res = AugmentShortest(s, e, flow_minimum - total_flow);
       if (res.second <= 0) break;
       total_cost += res.first;
       total_flow += res.second;
     }
     return make_pair(total_cost, total_flow);
   }
 };
 
 
 pair<int, int> check(int seats, int customers, vector<pair<int, int>> tickets) {
   vector<int> positions[2];
   for (int i = 0; i < 2; i++) positions[i].resize(seats);
   for (auto ticket : tickets) {
     positions[ticket.second][ticket.first]++;
   }
   MinCostFlow mcf(2 + 2 * seats);
   int source = 2 * seats;
   int sink = source + 1;
   for (int i = 0; i < seats; i++) {
     mcf.addEdge(source, i, 0, positions[0][i]);
     mcf.addEdge(seats + i, sink, 0, positions[1][i]);
     for (int j = 0; j < seats; j++) {
       if (i == j) {
         if (i > 0) {
           mcf.addEdge(i, seats + i, 1, 1000000);
         }
       }
       else {
         mcf.addEdge(i, seats + j, 0, 1000000);
       }
     }
   }
   auto res = mcf.solve(source, sink);
   int tot = tickets.size();
   int nomatch = tot - res.second * 2;
   int ans1 = nomatch + res.second;
   int ans2 = res.first;
   return make_pair(ans1, ans2);
 }
 
 int main() {
   int TT;
   scanf("%d", &TT);
   for (int testcase = 1; testcase <= TT; testcase++) {
     int n, c, m; // n: seat, c: customers
     scanf("%d%d%d", &n, &c, &m);
     vector<pair<int, int>> tickets;
     for (int i = 0; i < m; i++) {
       int b, p;
       scanf("%d%d", &p, &b);
       b--, p--;
       tickets.emplace_back(p, b);
     }
     sort(tickets.begin(), tickets.end());
 
     pair<int, int> sub = check(n, c, tickets);
     printf("Case #%d: %d %d\n", testcase, sub.first, sub.second);
   }
   return 0;
 }