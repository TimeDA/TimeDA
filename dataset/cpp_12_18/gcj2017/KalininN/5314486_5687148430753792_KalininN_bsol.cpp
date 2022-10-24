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
 
 const int maxn = 1005;
 
 int cnt[maxn][maxn];
 int cntrow[maxn], cntcol[maxn];
 int n, m, C;
 
 bool can(int rides)
 {
     int have = 0;
     for (int i = 0; i < n; i++)
     {
         have += rides;
         have -= cntrow[i];
         if (have < 0) return false;
     }
     return true;
 }
 
 int main()
 {
     int NT = 0;
     scanf("%d", &NT);
     for (int T = 1; T <= NT; T++)
     {
         printf("Case #%d:", T);
         
         scanf("%d%d%d", &n, &C, &m);
         for (int i = 0; i < n; i++)
         {
             for (int j = 0; j < C; j++) cnt[i][j] = 0;
             cntrow[i] = 0;
         }
         for (int i = 0; i < C; i++) cntcol[i] = 0;
         for (int i = 0; i < m; i++)
         {
             int x, y;
             scanf("%d%d", &x, &y);
             x--, y--;
             cnt[x][y]++;
             cntcol[y]++;
             cntrow[x]++;
         }
         int l = *max_element(cntcol, cntcol + C) - 1;
         int r = m;
         while (r - l > 1)
         {
             int mid = (l + r) / 2;
             if (can(mid)) r = mid;
             else l = mid;
         }
         int answer = 0;
         for (int i = n - 1; i >= 0; i--)
         {
             answer += max(0, cntrow[i] - r);
         }
         printf(" %d %d\n", r, answer);
 
         fprintf(stderr, "%d/%d cases done!\n", T, NT);
     }
     return 0;
 }
