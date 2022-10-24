#include <cstdio>
 #include <algorithm>
 #include <cassert>
 using namespace std;
 
 const int N = 105;
 const int INF = N * (1000 * 1000 + 42);
 const int MX = 1050;
 
 int D[N][2 * MX];
 
 int H[N], G[N];
 
 void solve(int cs)
 {
     int p, q, n;
     scanf("%d %d %d", &p, &q, &n);
     for (int i = 0; i < n; i++)
     {
         scanf("%d %d", &H[i], &G[i]);
     }
     for (int i = 0; i < N; i++)
         for (int j = 0; j < 2 * MX; j++)
             D[i][j] = -INF;
     D[0][1] = 0;
     for (int i = 0; i < n; i++)
     {
         for (int a = 0; a <= MX; a++)
         {
             if (D[i][a] < 0)
                 continue;
             if (a * p >= H[i])
             {
                 int nd = (H[i] + p - 1) / p;
                 assert(nd <= a);
                 D[i + 1][a - nd] = max(D[i + 1][a - nd], D[i][a] + G[i]);
             }
             for (int w = 0; (w - 1) * p < H[i]; w++)
             {
                 int rr = H[i] - w * p;
                 int ms = w;
                 if (ms > a)
                     continue;
                 if (rr < 0)
                     continue;
                 for (int b = 0; (b - 1) * q < rr; b++)
                 {
                     int r = rr - b * q;
                     int pl = b;
                     int kill = -1;
                     while (r > 0)
                     {
                         r -= q;
                         if (r <= 0)
                         {
                             kill = 1;
                             break;
                         }
                         r -= p;
                         if (r <= 0)
                         {
                             kill = 0;
                             break;
                         }
                     }
                     if (kill == 0)
                         D[i + 1][a + pl - ms] = max(D[i + 1][a + pl - ms], D[i][a] + G[i]);
                     else
                         D[i + 1][a + pl - ms] = max(D[i + 1][a + pl - ms], D[i][a]);
                 }
             }
         }
     }
     int mx = 0;
     for (int a = 0; a < MX; a++)
         mx = max(mx, D[n][a]);
     printf("Case #%d: %d\n", cs, mx);
 }
 
 int main()
 {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++)
     {
         solve(i + 1);
         fflush(stdout);
     }
 }
