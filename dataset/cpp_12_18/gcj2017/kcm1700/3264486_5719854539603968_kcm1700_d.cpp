#include <vector>
 #include <map>
 #include <climits>
 #include <algorithm>
 #include <cstdio>
 #include <cstring>
 #include <limits>
 #include <queue>
 
 using namespace std;
 struct MaxFlowDinic
 {
   typedef long long flow_t;
 
   struct Edge
   {
     int next;
     int inv; /* inverse edge index */
     flow_t res; /* residual */
   };
 
   int n;
   vector<vector<Edge>> graph;
 
   vector<unsigned> q, l, start;
 
   void Init(int _n) {
     n = _n;
     graph.resize(n);
     for (int i = 0; i < n; i++) graph[i].clear();
   }
   void AddNodes(int count) {
     n += count;
     graph.resize(n);
   }
   void AddEdge(int s, int e, flow_t cap, flow_t caprev = 0) {
     Edge forward = { e, graph[e].size(), cap };
     Edge reverse = { s, graph[s].size(), caprev };
     graph[s].push_back(forward);
     graph[e].push_back(reverse);
   }
 
   bool AssignLevel(int source, int sink) {
     int t = 0;
     memset(&l[0], 0, sizeof(l[0]) * l.size());
     l[source] = 1;
     q[t++] = source;
     for (int h = 0; h < t && !l[sink]; h++) {
       int cur = q[h];
       for (unsigned i = 0; i < graph[cur].size(); i++) {
         int next = graph[cur][i].next;
         if (l[next]) continue;
         if (graph[cur][i].res > 0) {
           l[next] = l[cur] + 1;
           q[t++] = next;
         }
       }
     }
     return l[sink] != 0;
   }
 
   flow_t BlockFlow(int cur, int sink, flow_t currentFlow) {
     if (cur == sink) return currentFlow;
     for (unsigned &i = start[cur]; i < graph[cur].size(); i++) {
       int next = graph[cur][i].next;
       if (graph[cur][i].res == 0 || l[next] != l[cur] + 1)
         continue;
       if (flow_t res = BlockFlow(next, sink, min(graph[cur][i].res, currentFlow))) {
         int inv = graph[cur][i].inv;
         graph[cur][i].res -= res;
         graph[next][inv].res += res;
         return res;
       }
     }
     return 0;
   }
 
   flow_t Solve(int source, int sink)
   {
     q.resize(n);
     l.resize(n);
     start.resize(n);
     flow_t ans = 0;
     while (AssignLevel(source, sink)) {
       memset(&start[0], 0, sizeof(start[0])*n);
       while (flow_t flow = BlockFlow(source, sink, numeric_limits<flow_t>::max())) {
         ans += flow;
       }
     }
     return ans;
   }
 };
 
 void solve(int n, vector<int> prerow, vector<int> precol, vector<int> prestyle) {
   MaxFlowDinic mf;
   int rowBase = 0;
   int colBase = rowBase + n;
   int diagBase = colBase + n;
   int diag2Base = diagBase + (2 * n - 1);
   int source = diag2Base + (2 * n - 1);
   int sink = source + 1;
   mf.Init(sink + 1);
   vector<int> cancel(sink+1);
   map<pair<int, int>, int> board;
   int basescore = 0;
   for (int i = 0; i < prestyle.size(); i++) {
     board[make_pair(prerow[i], precol[i])] = 1 + prestyle[i];
     if (prestyle[i] == 0 || prestyle[i] == 2) {
       int d1 = prerow[i] + precol[i];
       int d2 = prerow[i] - precol[i] + (n - 1);
       cancel[diagBase + d1] = 1;
       cancel[diag2Base + d2] = 1;
       basescore++;
     }
     if (prestyle[i] == 1 || prestyle[i] == 2) {
       int r = prerow[i];
       int c = precol[i];
       cancel[rowBase + r] = 1;
       cancel[colBase + c] = 1;
       basescore++;
     }
   }
   for (int r = 0; r < n; r++) {
     if (cancel[rowBase + r]) continue;
     mf.AddEdge(source, rowBase + r, 1);
   }
   for (int c = 0; c < n; c++) {
     if (cancel[colBase + c]) continue;
     mf.AddEdge(colBase + c, sink, 1);
   }
   for (int d1 = 0; d1 < 2 * n - 1; d1++) {
     if (cancel[diagBase + d1]) continue;
     mf.AddEdge(source, diagBase + d1, 1);
   }
   for (int d2 = 0; d2 < 2 * n - 1; d2++) {
     if (cancel[diag2Base + d2]) continue;
     mf.AddEdge(diag2Base + d2, sink, 1);
   }
   for (int r = 0; r < n; r++) {
     for (int c = 0; c < n; c++) {
       mf.AddEdge(rowBase + r, colBase + c, 1);
       int d1 = r + c;
       int d2 = r - c + (n - 1);
       mf.AddEdge(diagBase + d1, diag2Base + d2, 1);
     }
   }
   auto addflow = mf.Solve(source, sink);
   map<pair<int, int>, int> board2;
   for (int r = 0; r < n; r++) {
     for (auto edge : mf.graph[rowBase + r]) {
       if (edge.next >= colBase && edge.next < colBase + n) {
         if (edge.res == 0) {
           board2[make_pair(r, edge.next - colBase)] |= 2;
         }
       }
     }
   }
   for (int d1 = 0; d1 < 2*n-1; d1++) {
     for (auto edge : mf.graph[diagBase + d1]) {
       if (edge.next >= diag2Base && edge.next < diag2Base + 2 * n - 1) {
         int d2 = edge.next - diag2Base;
         if (edge.res == 0) {
           // r+c == d1
           // r-c+(n-1) == d2
           int r = (d1+d2-(n-1)) / 2;
           int c = d1 - r;
           board2[make_pair(r, c)] |= 1;
         }
       }
     }
   }
   vector<int> ar, ac, as;
   for (int r = 0; r < n; r++) {
     for (int c = 0; c < n; c++) {
       int opos = board[make_pair(r, c)];
       int fpos = opos | board2[make_pair(r, c)];
       if (opos != fpos) {
         ar.push_back(r);
         ac.push_back(c);
         as.push_back(fpos - 1);
       }
     }
   }
   printf("%d %d\n", basescore + addflow, (int)as.size());
   for (int i = 0; i < as.size(); i++) {
     printf("%c %d %d\n", "+xo"[as[i]], ar[i] + 1, ac[i] + 1);
   }
 }
 
 int main() {
   int T;
   scanf("%d", &T);
   for (int testcase = 1; testcase <= T; testcase++) {
     int n, m;
     scanf("%d%d", &n, &m);
     vector<int> row, col, style;
     for (int i = 0; i < m; i++) {
       char kind[3];
       int r, c;
       scanf("%s%d%d", kind, &r, &c);
       r--, c--;
       row.push_back(r);
       col.push_back(c);
       if (kind[0] == '+') {
         style.push_back(0);
       }
       else if (kind[0] == 'x') {
         style.push_back(1);
       }
       else if (kind[0] == 'o') {
         style.push_back(2);
       }
     }
     printf("Case #%d: ", testcase);
     solve(n, row, col, style);
   }
   return 0;
 }