#include <cstdio>
 #include <algorithm>
 using namespace std;
 
 const int MAXN = 55;
 const int MAXP = 55;
 int q[MAXN][MAXP];
 int r[MAXN];
 int n, p;
 int len[MAXN], prv[MAXN];
 int pos[MAXN][MAXP];
 int vis[MAXN][MAXP];
 
 inline bool is_valid(int real, int ideal, int cnt) {
     double real_cnt = 1.0 * real / ideal;
     return real_cnt >= cnt * 0.9 && real_cnt <= cnt * 1.1;
 }
 
 int main() {
     int T;
     scanf("%d",&T);
     for (int ca = 1 ; ca <= T ; ++ca) {
         memset(vis, 0, sizeof(vis));
 
         scanf("%d%d",&n,&p);
         for (int i = 0 ; i < n ; ++i)
             scanf("%d",&r[i]);
         for (int i = 0 ; i < n ; ++i)
             for (int j = 0 ; j < p ; ++j)
                 scanf("%d",&q[i][j]);
          
         int max_cnt = 0;   
         for (int i = 0 ; i < n ; ++i) {
             sort(&q[i][0], &q[i][p]);
             int tmp_cnt = (q[i][p-1] * 1.0 / r[i]) * 1.1 + 1;
             if (tmp_cnt > max_cnt) max_cnt = tmp_cnt;
         }
 
         for (int i = 0 ; i < n ; ++i)
             prv[i] = 0;
 
         int ans = 0;
         for (int cnt = 1 ; cnt <= max_cnt ; ++cnt) {
             memset(len, 0, sizeof(len));
             for (int i = 0 ; i < n ; ++i)
                 for (int j = prv[i] ; j < p ; ++j)
                     if (!vis[i][j] && is_valid(q[i][j], r[i], cnt)) {
                         pos[i][len[i]++] = j;
                     }
             int minv = 1e9;
             for (int i = 0 ; i < n ; ++i)
                 if (len[i] < minv) minv = len[i];
             ans += minv;
 
             for (int i = 0 ; i < n ; ++i)
                 for (int j = 0 ; j < len[i] && j < minv ; ++j) {
                     vis[i][pos[i][j]] = 1;
                     prv[i] = pos[i][j] + 1;
                 }
         }
         printf("Case #%d: %d\n", ca, ans);
     }
     return 0;
 }
 
