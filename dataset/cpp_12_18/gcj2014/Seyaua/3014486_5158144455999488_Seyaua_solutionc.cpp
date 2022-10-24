#include <iostream>
 #include <cstdio>
 #include <string>
 #include <cstring>
 #include <set>
 #include <map>
 #include <vector>
 #include <bitset>
 #include <algorithm>
 #include <cmath>
 #include <queue>
 #include <ctime>
 #pragma comment(linker, "/STACK:256000000")
 
 using namespace std;
 
 const long long INF = 1000000000000000LL;
 
 class MaximumFlow {
   int s, f;
 public:
   struct edge {
     int u, v;
     long long capacity, flow;
     edge() { u = v = capacity = flow = 0;}
     edge(int u_, int v_, long long capacity_, long long flow_) :
       u(u_), v(v_), capacity(capacity_), flow(flow_) {}
   };
   vector <edge> edges;
   vector <vector <int> > graph;
   vector <int> ptr, level;
   queue <int> q;
   int n;
   MaximumFlow() {}
   MaximumFlow(int number) {
     n = number;
     graph.resize(n);
     ptr.assign(n, 0);
     level.resize(n);
   }
   void addEdge(int u, int v, long long capacity) {
     int sz = (int)(edges.size());
     edges.push_back(edge(u, v, capacity, 0));
     edges.push_back(edge(v, u, 0, 0));
     graph[u].push_back(sz);
     graph[v].push_back(sz + 1);
   }
   void updateLevels() {
     level.assign(n, -1);
     q.push(s);
     level[s] = 0;
     while (!q.empty()) {
       int topq = q.front();
       q.pop();
       for (int index = 0; index < graph[topq].size(); ++index) {
         int i = graph[topq][index];
         int to = edges[i].v;
         if (edges[i].capacity - edges[i].flow == 0) {
           continue;
         }
         if (level[to] == -1) {
           level[to] = level[topq] + 1;
           q.push(to);
         }
       }
     }
   }
   long long pushFlow(int v, long long flow) {
     if (v == f || flow == 0) {
       return flow;
     }
     for (; ptr[v] < graph[v].size(); ++ptr[v]) {
       int index = graph[v][ptr[v]];
       int to = edges[index].v;
       if (level[v] + 1 == level[to]) {
         int pushed = pushFlow(to, min(flow, edges[index].capacity - edges[index].flow));
         if (pushed > 0) {
           edges[index].flow += pushed;
           edges[index ^ 1].flow -= pushed;
           return pushed;
         }
       }
     }
     return 0;
   }
   long long dinicFlow(int start, int finish) {
     s = start, f = finish;
     long long result = 0;
     while (true) {
       updateLevels();
       if (level[f] == -1) {
         break;
       }
       while (true) {
         long long pushed = pushFlow(start, INF);
         if (pushed == 0) {
           break;
         }
         result += pushed;
       }
       ptr.assign(n, 0);
     }
     return result;
   }
 };
 
 const int maxN = 510;
 int w, h, b;
 int a[maxN][maxN];
 
 int dx[] = {1, -1, 0, 0};
 int dy[] = {0, 0, 1, -1};
 
 bool is_in(int x, int y) {
   return x >= 0 && x < w && y >= 0 && y < h && a[x][y] == 0;
 }
 
 void solve(int tcase) {
   printf("Case #%d: ", tcase);
 
   scanf("%d%d%d", &w, &h, &b);
   memset(a, 0, sizeof(a));
 
   for (int i = 0; i < b; ++i) {
     int x1, y1, x2, y2;
     scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
 
     for (int j = x1; j <= x2; ++j) {
       for (int k = y1; k <= y2; ++k) {
         a[j][k] = 1;
       }
     }
   }
 
   MaximumFlow mf(2 * w * h + 2);
   int s = 2 * w * h;
   int t = 2 * w * h + 1;
 
   for (int i = 0; i < w; ++i) {
     if (a[i][0] == 0) {
       mf.addEdge(s, i, 1);
     }
   }
   for (int i = 0; i < w; ++i) {
     if (a[i][h - 1] == 0) {
       mf.addEdge((h - 1) * w + i + w * h, t, 1);
     }
   }
 
   for (int i = 0; i < w; ++i) {
     for (int j = 0; j < h; ++j) {
       for (int k = 0; k < 4; ++k) {
         if (is_in(i, j) && is_in(i + dx[k], j + dy[k])) {
           mf.addEdge(i + j * w + w * h, i + dx[k] + (j + dy[k]) * w, 1);
         }
       }
       if (is_in(i, j)) {
         mf.addEdge(i + j * w, i + j * w + w * h, 1);
       }
     }
   }
 
   cout << mf.dinicFlow(s, t) << endl;
 }
 
 int main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
 
   int t;
   scanf("%d", &t);
 
   for (int i = 0; i < t; ++i) {
     solve(i + 1);
     cerr << i << endl;
   }
 
   return 0;
 }
