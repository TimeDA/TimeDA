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
 
 int cs=0;
 int n;
 char a[10][10];
 int c[10][10];
 bool badflag=false;
 
 int oa[10], ob[10];
 void dfs(int x) {
   if(badflag || x==n) return;
   int choice=0;
   for(int i=0;i<n;i++)
     for(int j=0;j<n;j++)
       if(oa[i]==0 && ob[j]==0 && c[i][j]==1) {
         choice=1;
         oa[i]=ob[j]=1;
         dfs(x+1);
         oa[i]=ob[j]=0;
       }
   if(!choice) { badflag=true; return; }
 }
 
 bool greedy_works() {
   badflag=0;
   for(int i=0;i<n;i++) oa[i]=ob[i]=0;
   dfs(0);
   return !badflag;
 }
 
 void solve() {
   ++cs;
   fprintf(stderr, "Case #%d: ", cs);
   printf("Case #%d: ", cs);
 
   scanf("%d", &n);
   for(int i=0;i<n;i++) scanf("%s", a[i]);
   int best=n*n;
   for(int i=0;i<(1<<(n*n));i++) {
     int cst=0;
     for(int x=0;x<n;x++)
       for(int y=0;y<n;y++) {
         c[x][y] = (a[x][y]=='1' || ((1<<(x*n+y))&i)!=0);
         if(c[x][y] ==1 && a[x][y]=='0') ++cst;
       }
     /*for(int x=0;x<n;x++,puts(""))
       for(int y=0;y<n;y++)
         printf("%d", c[x][y]);*/
     if (cst < best && greedy_works()) {
       best = cst;
     }
   }
   printf("%d\n", best);
   fprintf(stderr, "%d\n", best);
 }
 
 
 int main(void) {
   int T;
   scanf("%d", &T);
   while(T--) solve();  
   return 0;
 }
