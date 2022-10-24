#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <vector>
 #include <algorithm>
 #define SZ(x) ((int)(x).size())
 #define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
 using namespace std;
 typedef long long LL;
 
 int cs=0;
 int m, n;
 char a[105][105];
 int u[105][105][4];
 
 void solve() {
   int m, n, ans=0;
   scanf("%d%d", &m, &n);
   for(int i=0;i<m;i++) scanf("%s", a[i]);
   memset(u, 0, sizeof(u));
   for(int i=0;i<m;i++)
     for(int j=0;j<n;j++) {
       if(a[i][j]!='.') {
         if(a[i][j]=='<') ++ans;
         u[i][j][0] = 1;
         break;
       }
     }
   for(int i=0;i<m;i++)
     for(int j=n-1;j>=0;j--) {
       if(a[i][j]!='.') {
         if(a[i][j]=='>') ++ans;
         u[i][j][1] = 1;
         break;
       }
     }
   for(int j=0;j<n;j++)
     for(int i=0;i<m;i++)
       if(a[i][j]!='.') {
         if(a[i][j]=='^') ++ans;
         u[i][j][2] = 1;
         break;
       }
   for(int j=0;j<n;j++)
     for(int i=m-1;i>=0;i--)
       if(a[i][j]!='.') {
         if(a[i][j]=='v') ++ans;
         u[i][j][3] = 1;
         break;
       }
   int bad=0;
   for(int i=0;i<m;i++)
     for(int j=0;j<n;j++) {
       int fail=1;
       for(int v=0;v<4;v++)
         if(u[i][j][v]==0) fail=0;
       if(fail) bad = 1;
     }
 
   printf("Case #%d: ", cs);
   if(bad) puts("IMPOSSIBLE");
   else printf("%d\n", ans);
 }
 
 int main(void) {
   int T;
   scanf("%d", &T);
   for(cs=1;cs<=T;cs++) solve();
   return 0;
 }
