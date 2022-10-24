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
 
 void solve() {
   static int cs = 0;
   printf("Case #%d: ", ++cs);
   fprintf(stderr, "Case #%d: ", cs);
   
   int n, P;
   int c[4] = {};
   int dp[109][109][109]={};
   int a[105];
 
   scanf("%d%d", &n, &P);
   for(int i=0;i<n;i++) scanf("%d", &a[i]);
   for(int i=0;i<n;i++) c[a[i]%P]++;
 
   int ans = 0;
   dp[0][0][0] = 1;
   for(int i=0;i<=c[1];i++)
     for(int j=0;j<=c[2];j++)
       for(int k=0;k<=c[3];k++) {
         if(dp[i][j][k]==0) continue;
         if(i==c[1] && j==c[2] && k==c[3])
           ans = max(ans, dp[i][j][k]);
         else
           ans = max(ans, dp[i][j][k]+1);
 
         for(int x=0;x<=3;x++)
           for(int y=x;y<=3;y++)
             for(int z=y;z<=3;z++)
               for(int w=z;w<=3;w++) {
                 int d[4]={};
                 if(x==0 && y==0 && z==0 && w==0) continue;
                 d[x]++;d[y]++;d[z]++;d[w]++;
                 if((x+y+z+w)%P!=0) continue;
                 int &up = dp[i+d[1]][j+d[2]][k+d[3]];
                 if(up < dp[i][j][k] + 1)
                   up = dp[i][j][k] + 1;
               }
       }
   printf("%d\n", ans +c[0]-1);
   fprintf(stderr, "%d\n", ans+c[0]-1);
   return ;
 }
 
 int main(void) {
   int T;
   scanf("%d", &T);
   while(T--) solve();
   return 0;
 }
