#include <iostream>
 #include <algorithm>
 #include <cmath>
 #include <cstring>
 #include <cstdlib>
 #include <string>
 #include <vector>
 #include <cstdio>
 #include <cassert>
 
 using namespace std;
 
 typedef long long ll;
 typedef long double ld;
 
 #ifdef WIN32
 #define LLD "%I64d"
 #else
 #define LLD "%lld"
 #endif
 
 const int maxn = 105;
 
 char p[maxn][maxn];
 int cnt[maxn][maxn];
 bool bad[maxn][maxn];
 int n, m;
 
 int main()
 {
     int NT = 0;
     scanf("%d", &NT);
     for (int T = 1; T <= NT; T++)
     {
         printf("Case #%d:", T);
         scanf("%d%d", &n, &m);
         for (int i = 0; i < n; i++)
         {
             for (int j = 0; j < m; j++) cnt[i][j] = 0, bad[i][j] = false;
         }
         for (int i = 0; i < n; i++)
         {
             scanf("%s", p[i]);
         }
         for (int i = 0; i < n; i++)
         {
             for (int j = 0; j < m; j++) if (p[i][j] != '.')
             {
                 cnt[i][j]++;
                 if (p[i][j] == '<') bad[i][j] = true;
                 break;
             }
         }
         for (int i = 0; i < n; i++)
         {
             for (int j = m - 1; j >= 0; j--) if (p[i][j] != '.')
             {
                 cnt[i][j]++;
                 if (p[i][j] == '>') bad[i][j] = true;
                 break;
             }
         }
         for (int j = 0; j < m; j++)
         {
             for (int i = 0; i < n; i++) if (p[i][j] != '.')
             {
                 cnt[i][j]++;
                 if (p[i][j] == '^') bad[i][j] = true;
                 break;
             }
         }
         for (int j = 0; j < m; j++)
         {
             for (int i = n - 1; i >= 0; i--) if (p[i][j] != '.')
             {
                 cnt[i][j]++;
                 if (p[i][j] == 'v') bad[i][j] = true;
                 break;
             }
         }
         bool ok = true;
         int answer = 0;
         for (int i = 0; i < n; i++)
         {
             for (int j = 0; j < m; j++) if (bad[i][j])
             {
 //                 cout << i << ' ' << j << ' ' << cnt[i][j] << endl;
                 if (cnt[i][j] == 4) ok = false;
                 answer++;
             }
         }
         if (ok) printf(" %d\n", answer);
         else printf(" IMPOSSIBLE\n");
 
         fprintf(stderr, "%d/%d cases done!\n", T, NT);
     }
     return 0;
 }
