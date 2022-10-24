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
 
 char s[100005];
 void solve() {
   static int cs = 0;
   ++cs;
   printf("Case #%d: ", cs);
   fprintf(stderr, "Case #%d: ", cs);
   
   int k;
   scanf("%s%d", s, &k);
   int n = strlen(s);
   int ans = 0;
   for(int i=0;i+k<=n;i++) {
     if(s[i]=='-') {
       for(int j=0;j<k;j++)
         s[i+j] = '-'+'+'-s[i+j];
       ++ans;
     }
   }
   int bad = 0;
   for(int i=0;i<n;i++) if(s[i]=='-') bad = 1;
   if(bad) {
     printf("IMPOSSIBLE\n");
     fprintf(stderr, "IMPOSSIBLE\n");
   } else {
     printf("%d\n", ans);
     fprintf(stderr, "%d\n", ans);
   }
 
 }
 
 int main(void) {
   int T;
   scanf("%d", &T);
   for(int cs=1;cs<=T;cs++) solve();
   return 0;
 }
