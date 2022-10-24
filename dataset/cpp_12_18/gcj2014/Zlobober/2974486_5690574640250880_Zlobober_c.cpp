#include <cstdio>
 #include <memory.h>
 using namespace std;
 
 const int N = 6;
 char F[N][N];
 
 int vx[] = {1, 1, 0, -1, -1, -1, 0, 1};
 int vy[] = {0, 1, 1, 1, 0, -1, -1, -1};
 
 int curit = 0;
 int was[N][N];
 
 int n, m, k;
 
 bool good(int y, int x)
 {
     for (int v = 0; v < 8; v++)
     {
         int ty = y + vy[v];
         int tx = x + vx[v];
         if (ty < 0 || ty >= n || tx < 0 || tx >= m)
             continue;
         if (F[ty][tx])
             return false;
     }
     return true;
 }
 
 int DFS(int y, int x)
 {
     was[y][x] = curit;
     if (!good(y, x))
         return 1;
     int ans = 1;
     for (int v = 0; v < 8; v++)
     {
         int ty = y + vy[v];
         int tx = x + vx[v];
         if (ty >= n || tx >= m || ty < 0 || tx < 0)
             continue;
         if (was[ty][tx] != curit)
             ans += DFS(ty, tx);
     }
     return ans;
 }
 
 bool check(int msk)
 {
     int f = n * m - __builtin_popcount(msk);
     for (int i = 0; i < n * m; i++)
         F[i / m][i % m] = (msk >> i) & 1;
     for (int i = 0; i < n * m; i++)
         if (!F[i / m][i % m])
         {
             ++curit;
             if (DFS(i / m, i % m) == f)
             {
                 for (int y = 0; y < n; y++)
                     for (int x = 0; x < m; x++)
                         if (y * m + x == i)
                             F[y][x] = 'c';
                         else if (F[y][x])
                             F[y][x] = '*';
                         else
                             F[y][x] = '.';
                 return true;
             }
         }
     return false;
 }
 
 void solve(int cs)
 {
     scanf("%d %d %d", &n, &m, &k);
     memset(F, 0, sizeof(F));
     for (int msk = 0; msk < (1 << (n * m)); msk++)
     {
         if (__builtin_popcount(msk) != k)
             continue;
         if (check(msk))
         {
             printf("Case #%d:\n", cs);
             for (int i = 0; i < n; i++)
                 puts(F[i]);
             return;
         }
     }
     printf("Case #%d:\n", cs);
     printf("Impossible\n");
 }
 
 int main()
 {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++)
         solve(i + 1);
 }
 
