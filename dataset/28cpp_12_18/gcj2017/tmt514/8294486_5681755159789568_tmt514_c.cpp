// by tmt514
 #include <algorithm>
 #include <cmath>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <iostream>
 #include <string>
 #include <vector>
 #define SZ(x) ((int)(x).size())
 #define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
 using namespace std;
 typedef long long LL;
 
 const double INF = 1e50;
 LL a[105][105];
 double ans[105][105];
 int N, Q;
 LL E[105], S[105];
 
 void solve() {
   memset(a, -1, sizeof(a));
 
   cin >> N >> Q;
   for(int i=1;i<=N;i++) cin >> E[i] >> S[i];
   for(int i=1;i<=N;i++)
     for(int j=1;j<=N;j++)
       cin >> a[i][j];
   for(int k=1;k<=N;k++)
     for(int i=1;i<=N;i++)
       for(int j=1;j<=N;j++) {
         if(a[i][k]!=-1 && a[k][j]!=-1 && (a[i][j]==-1 || a[i][j] > a[i][k] + a[k][j]))
           a[i][j] = a[i][k] + a[k][j];
       }
   for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
     if(i==j) ans[i][j] = 0.0;
     else if(a[i][j]!=-1 && a[i][j]<=E[i])
       ans[i][j] = (a[i][j] / (double) S[i]);
     else
       ans[i][j] = INF;
   }
   for(int k=1;k<=N;k++)
     for(int i=1;i<=N;i++)
       for(int j=1;j<=N;j++)
         if(ans[i][k] + ans[k][j] < ans[i][j])
           ans[i][j] = ans[i][k] + ans[k][j];
   static int cs=0;
   printf("Case #%d:", ++cs);
   fprintf(stderr, "Case #%d:", cs);
   for(int i=1;i<=Q;i++) {
     int u, v;
     scanf("%d%d", &u, &v);
     printf(" %.9f", ans[u][v]);
     fprintf(stderr, " %.9f", ans[u][v]);
   }
   printf("\n");
   fprintf(stderr, "\n");
 }
 
 int main(void) {
   int T;
   scanf("%d", &T);
   while(T--) solve();
   return 0;
 }
