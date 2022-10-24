#include <bits/stdc++.h>
 
 using namespace std;
 
 using ll = long long;
 using ld = long double;
 using D = double;
 using uint = unsigned int;
 template<typename T>
 using pair2 = pair<T, T>;
 
 #ifdef WIN32
     #define LLD "%I64d"
 #else
     #define LLD "%lld"
 #endif
 
 #define pb push_back
 #define mp make_pair
 #define all(x) (x).begin(),(x).end()
 #define fi first
 #define se second
 
 const ll inf = 1e18;
 
 const int maxn = 105;
 
 ld d[maxn];
 ll gr[maxn][maxn];
 int n, nq;
 int maxd[maxn], speed[maxn];
 bool was[maxn];
 
 int main()
 {
     int NT = 0;
     scanf("%d", &NT);
     for (int T = 1; T <= NT; T++)
     {
         printf("Case #%d:", T);
         
         scanf("%d%d", &n, &nq);
         for (int i = 0; i < n; i++) scanf("%d%d", &maxd[i], &speed[i]);
         for (int i = 0; i < n; i++)
         {
             for (int j = 0; j < n; j++)
             {
                 scanf("%lld", &gr[i][j]);
                 if (gr[i][j] == -1) gr[i][j] = inf;
             }
             gr[i][i] = 0;
         }
         for (int k = 0; k < n; k++)
         {
             for (int i = 0; i < n; i++)
             {
                 for (int j = 0; j < n; j++) gr[i][j] = min(gr[i][j], gr[i][k] + gr[k][j]);
             }
         }
 //         for (int i = 0; i < n; i++)
 //         {
 //             for (int j = 0; j < n; j++) printf("%lld ", gr[i][j]);
 //             printf("\n");
 //         }
         for (int q = 0; q < nq; q++)
         {
             int s, t;
             scanf("%d%d", &s, &t);
             s--, t--;
             for (int i = 0; i < n; i++) d[i] = inf, was[i] = false;
             d[s] = 0;
             for (int step = 0; step < n; step++)
             {
                 int cur = -1;
                 ll curd = inf;
                 for (int i = 0; i < n; i++) if (!was[i] && d[i] < curd)
                 {
                     curd = d[i];
                     cur = i;
                 }
 //                 cout << cur << ' ' << curd << endl;
                 if (cur == -1) break;
                 was[cur] = true;
                 for (int i = 0; i < n; i++) if (gr[cur][i] <= maxd[cur]) d[i] = min(d[i], d[cur] + (ld)gr[cur][i] / speed[cur]);
             }
             printf(" %.20f", (double)d[t]);
         }
         printf("\n");
 
         fprintf(stderr, "%d/%d cases done!\n", T, NT);
     }
     return 0;
 }
