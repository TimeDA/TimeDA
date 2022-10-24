#include <cstdio>
 #include <algorithm>
 using namespace std;
 
 const int MAXN = 32;
 char mp[MAXN][MAXN];
 int n;
 int best = 1e9;
 int a[MAXN];
 int vis[MAXN];
 
 int check_perm(int cur) {
     if (cur == n) return 1;
     int flg = 0;
     // printf("cur:%d a[cur]:%d\n", cur, a[cur]);
     for (int i = 0 ; i < n ; ++i) {
         // printf("try i:%d vis: %d mp:%c\n", i, vis[i], mp[a[cur]][i]);
         if (vis[i] || mp[a[cur]][i] == '0') continue;
         vis[i] = 1;
         flg = 1;
         if (!check_perm(cur+1)) return 0;
         vis[i] = 0;
     }
     // printf("cur:%d flg:%d\n", cur, flg);
     return flg;
 }
 
 int check() {
     for (int i = 0 ; i < n ; ++i) a[i] = i;
     do {
         /*
         printf("checking: ");
         for (int i = 0 ; i < n; ++i)
             printf(" %d", a[i]);
         printf("\n");
         for (int i = 0 ; i < n ; ++i)
             printf("%s\n", mp[i]);
         printf("====\n");
         */
         for (int i = 0 ; i < n ; ++i) vis[i] = 0;
         if (!check_perm(0)) return 0;
     } while (next_permutation(a, a+n));
     return 1;
 }
 
 void solve(int pos, int cur) {
     if (pos == n*n) {
         if (check()) {
             if (cur < best) best = cur;
         }
         return;
     }
     int i = pos / n, j = pos % n;
     // printf("i:%d j:%d\n", i, j);
     if (mp[i][j] == '1') return solve(pos+1, cur);
     solve(pos+1, cur);
     mp[i][j] = '1';
     solve(pos+1, cur+1);
     mp[i][j] = '0';
 }
 
 int main() {
     int T, ca;
     scanf("%d",&T);
     for (int ca = 1 ; ca <= T ; ++ca) {
         memset(mp, 0, sizeof(mp));
         scanf("%d",&n);
         for (int i = 0 ; i < n ; ++i)
             scanf("%s", mp[i]);
 
         best = n * n + 1;
         solve(0, 0);
         printf("Case #%d: %d\n", ca, best);
     }
     return 0;
 }