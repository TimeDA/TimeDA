#include <cstdio>
 
 typedef long long LL;
 const int MAXN = 1000100;
 LL a[MAXN];
 int n;
 
 int check(LL mid) {
   LL tmp = a[0];
   int res = 1;
   for (int i = 1 ; i < n ; ++i) {
     if (tmp + a[i] > mid) {
       if (++res > 3) return 0;
       tmp = a[i];
     } else tmp += a[i];
   }
   return 1;
 }
 
 int main() {
   int T;
   scanf("%d", &T);
   for (int ca = 1 ; ca <= T ; ++ca) {
     LL p, q, r, s;
     scanf("%d%lld%lld%lld%lld", &n, &p, &q, &r, &s);
     LL sum = 0;
     LL lo = 0;
     for (int i = 0 ; i < n ; ++i) {
       a[i] = ((LL)i * p + q) % r + s;
       sum += a[i];
       if (a[i] > lo) lo = a[i];
     }
     LL hi = sum, best = sum;
     while (lo <= hi) {
       LL mid = (lo + hi) / 2;
       if (check(mid)) {
         if (mid < best) best = mid;
         hi = mid - 1;
       } else lo = mid + 1;
     }
     // printf("%lld\n", best);
     printf("Case #%d: %.12lf\n", ca, 1 - (double)best/sum);
   }
   return 0;
 }
 
