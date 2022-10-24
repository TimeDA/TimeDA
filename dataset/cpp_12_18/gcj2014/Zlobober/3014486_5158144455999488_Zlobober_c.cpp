#include <cstdio>
 #include <memory.h>
 #include <algorithm>
 using namespace std;
 
 int vy[] = {1, 0, -1, 0}, vx[] = {0, 1, 0, -1};
 
 const int N = 550;
 bool bad[N][N];
 
 struct edge
 {
     int t, c, f, nxt;
     edge(int _t, int _c, int _f, int _nxt)
     {
         t = _t, c = _c, f = _f, nxt = _nxt;
     }
     edge(){}
 } E[N * N * 10];
 int ept;
 int first[N * N];
 
 void add_edge(int a, int b)
 {
     E[ept++] = edge(b, 1, 0, first[a]);
     E[ept++] = edge(a, 0, 0, first[b]);
     first[a] = ept - 2, first[b] = ept - 1;    
 }
 
 int was[N * N * 4];
 int iter = 1;
 
 int S, T;
 
 bool DFS(int x)
 {
     was[x] = iter;
     if (x == T)
         return true;
     for (int e = first[x]; e != -1; e = E[e].nxt)
     {
         if (E[e].c == E[e].f || was[E[e].t] == iter)
             continue;
         int y = E[e].t;
         if (DFS(y))
         {
             E[e].f++, E[e ^ 1].f--;
             return true;
         }
     }
     return false;
 }
 
 void solve(int cs)
 {
     int w, h, n;
     scanf("%d %d %d", &w, &h, &n);
     ept = 0;
     memset(bad, 0, sizeof(bad));
     memset(first, -1, sizeof(first));
     for (int i = 0; i < n; i++)
     {
         int x1, y1, x2, y2;
         scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
         for (int x = x1; x <= x2; x++)
             for (int y = y1; y <= y2; y++)
                 bad[y][x] = true;
     }
     for (int i = 0; i < h; i++)
         for (int j = 0; j < w; j++)
         {
             if (!bad[i][j])
             {
                 add_edge(2 * (i * w + j), 2 * (i * w + j) + 1);
                 for (int v = 0; v < 4; v++)
                 {
                     int ti = i + vy[v], tj = j + vx[v];
                     if (ti < 0 || ti >= h || tj < 0 || tj >= w || bad[ti][tj])
                         continue;
                     add_edge(2 * (i * w + j) + 1, 2 * (ti * w + tj));
                 }
             }
         }
     S = 2 * (w * h), T = 2 * (w * h) + 1;
     for (int j = 0; j < w; j++)
         add_edge(S, 2 * (0 * w + j)), add_edge(2 * ((h - 1) * w + j) + 1, T);
     ++iter;
     int ans = 0;
     while (DFS(S))
         ans++, iter++;
     printf("Case #%d: %d\n", cs, ans);
 }
 
 int main()
 {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++)
         solve(i + 1), fflush(stdout);
 }
 
