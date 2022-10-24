#include <cstdio>
 #include <string>
 #include <cstring>
 #include <cstdlib>
 using namespace std;
 
 const int MAXN = 10010;
 int vis[MAXN];
 int q[MAXN];
 int inq[MAXN];
 int qh, qt;
 int d[MAXN], len[MAXN];
 
 int main() {
     freopen("A-small-attempt1.in","r",stdin);
     freopen("A-small-attempt1.out","w",stdout);
     int T, ca, i, n, D;
     scanf("%d",&T);
     for (ca = 1 ; ca <= T ; ++ca) {
         printf("Case #%d: ",ca);
         scanf("%d",&n);
         for (i = 0 ; i < n ; i++)
             scanf("%d%d",&d[i],&len[i]);
         scanf("%d",&D);
         memset(vis, 0, sizeof(vis));
         memset(inq, 0, sizeof(inq));
         int flg = 0;
         q[0] = 0;
         inq[0] = 1; vis[0] = d[0];
         for (qh = 0, qt = 1 ; qh != qt ; ) {
             int from = q[qh];
                 if (d[from] + vis[from] >= D) {
                     flg = 1;
                     break;
                 }
             for (i = 0 ; i < n ; i++) {
                 if (i == from) continue;
                 if (abs(d[i] - d[from]) > vis[from]) continue;
                 int tmp = min(abs(d[i] - d[from]), len[i]);
                 if (tmp > vis[i]) {
                     vis[i] = tmp;
                     if (!inq[i]) {
                         inq[i] = 1;
                         q[qt] = i;
                         if (++qt == MAXN) qt = 0;
                     }
                 }
             }
             inq[from] = 0;
             if (++qh == MAXN) qh = 0;
         }
         if (flg) printf("YES\n");
         else printf("NO\n");
     }
     return 0;
 }
 
