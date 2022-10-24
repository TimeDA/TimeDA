#include <cstdio>
 #include <algorithm>
 using namespace std;
 
 int tp[256];
 
 int vx[] = {1, 0, -1, 0};
 int vy[] = {0, 1, 0, -1};
 
 const int N = 105;
 char buf[N][N];
 
 void solve(int cs)
 {
     int n, m;
     scanf("%d %d ", &n, &m);
     for (int i = 0; i < n; i++)
         gets(buf[i]);
     
     int ans = 0;
     bool bad = false;
     for (int i = 0; i < n; i++)
     {
         for (int j = 0; j < m; j++)
         {
             if (buf[i][j] != '.')
             {
                 bool was[] = {false, false, false, false};
                 for (int v = 0; v < 4; v++)
                 {
                     int y = i, x = j;
                     while (y >= 0 && x >= 0 && y < n && x < m)
                     {
                         if (y != i || x != j)
                         {
                             if (buf[y][x] != '.')
                                 was[v] = true;
                         }
                         y += vy[v];
                         x += vx[v];   
                     }
                 }
                 int t = tp[buf[i][j]];
                 if (was[t])
                     continue;
                 else
                     ans++;
                 if (find(was, was + 4, true) == was + 4)
                     bad = true;
             }
         }
     }
     if (bad)
         printf("Case #%d: IMPOSSIBLE\n", cs);
     else
         printf("Case #%d: %d\n", cs, ans);
 }
 
 int main()
 {
     int T;
     scanf("%d", &T);
 
     tp['>'] = 0;
     tp['v'] = 1;
     tp['<'] = 2;
     tp['^'] = 3;
 
     for (int i = 0; i < T; i++)
         solve(i + 1);
 }
 
