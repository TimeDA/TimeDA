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
 
 vector<LL> all;
 
 void pre() {
   all.push_back(0);
   for(int i=0;i<(int)all.size();i++) {
     int v = all[i]%10;
     if(all[i]<=1e17)
     for(int j=max(v, 1); j<=9;j++)
       all.push_back(all[i]*10+j);
   }
 }
 
 void solve() {
   LL n, ans=0;
   cin >> n;
   static int cs=0;
   for(auto &&x: all) if(x<=n) ans=max(ans, x);
   printf("Case #%d: %lld\n", ++cs, ans);
   fprintf(stderr, "Case #%d: %lld\n", cs, ans);
 }
 
 int main(void) {
   int T;
   pre();
   scanf("%d", &T);
   while(T--) solve();
   return 0;
 }
