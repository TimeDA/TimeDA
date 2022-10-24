#include <cstdio>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 #include <vector>
 using namespace std;
 
 #define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
 #define SZ(c) ((int)(c).size())
 typedef long long LL;
 
 int cs;
 LL a[1000005];
 void solve() {
   int N, p, q, r, s;
   scanf("%d%d%d%d%d", &N, &p, &q, &r, &s);
   for(int i = 0; i < N; i++) a[i] = (i*1LL*p+q)%r+s;
   LL p1=0, p2=a[0], p3=0, ans=0;
   for(int i=1;i<N;i++) p3 += a[i];
   ans = min(p2, p3);
   for(int i=0,j=0;i<N;i++) {
     ans = max(p1+p2+p3-max(p1, max(p2, p3)), ans);
     while(j<N && p2<=p3) {
       ++j;
       p3 -= a[j];
       p2 += a[j];
       ans = max(p1+p2+p3-max(p1, max(p2, p3)), ans);
     }
     p1 += a[i];
     p2 -= a[i];
   }
   printf("Case #%d: %.10f\n", cs, ans / (double) (p1+p2+p3));
 }
 
 int main(void) {
   int T;
   scanf("%d", &T);
   for(cs=1;cs<=T;cs++) solve();
   return 0;
 }
