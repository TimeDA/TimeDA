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
 
 int N, D;
 int S0, AS, CS, RS;
 int M0, AM, CM, RM;
 
 const int P = 1000005;
 int s[P];
 int p[P];
 int l[P], r[P];
 int cnt[2*P];
 
 int cs=0;
 
 void solve() {
   scanf("%d%d", &N, &D);
   scanf("%d%d%d%d", &S0, &AS, &CS, &RS);
   scanf("%d%d%d%d", &M0, &AM, &CM, &RM);
   s[0] = S0;
   p[0] = M0;
   for(int i=1;i<N;i++) {
     s[i] = (s[i-1] * 1LL * AS + CS) % RS;
     p[i] = (p[i-1] * 1LL * AM + CM) % RM;
   }
   for(int i=1;i<N;i++) p[i] = p[i] % i;
   
   l[0] = s[0];
   r[0] = s[0]+D;
   for(int i=1;i<N;i++) {
     int m = p[i];
     l[i] = max(l[m], s[i]);
     r[i] = min(r[m], s[i]+D);
   }
 
   memset(cnt, 0, sizeof(cnt));
   for(int i=0;i<N;i++) {
     if(l[i] <= r[i]) {
     cnt[l[i]]++;
     cnt[r[i]+1]--;
     }
   }
   for(int i=1;i<2*P;i++)
     cnt[i] += cnt[i-1];
   printf("Case #%d: ", cs);
   printf("%d\n", *max_element(cnt+s[0], cnt+s[0]+D+1));
 }
 
 int main(void) {
   int T;
   scanf("%d", &T);
   for(cs=1;cs<=T;cs++) solve();
   return 0;
 }
