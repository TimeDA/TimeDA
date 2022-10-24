#include <cstdio>
 #include <algorithm>
 using namespace std;
 
 int a[10010];
 int tk[10010];
 
 int main() {
   int T, n, k;
   scanf("%d", &T);
   for (int ca = 1 ; ca <= T ; ++ca) {
     scanf("%d%d", &n, &k);
     for (int i = 0 ; i < n ; ++i)
       scanf("%d", &a[i]);
     sort(a, a+n);
     /*
     int ans = 0;
     for (int i = 0 ; i < n ; ++i) {
       if (tk[i]) continue;
       for (int j = i + 1 ; j < n ; ++j) {
         if (tk[j]) continue;
         if (a[i] + a[j] <= k) {
           tk[i] = tk[j] = 1;
           ++ans;
         }
       }
     }
     */
     int p1 = 0, p2 = n - 1;
     int ans = 0;
     while (p1 < p2) {
       while (p1 < p2 && a[p1] + a[p2] > k) {
         --p2;
         continue;
       }
       if (p1 >= p2) break;
       // printf("(%d,%d)\n", p1, p2);
       ++ans; ++p1; --p2;
     }
     ans += n - ans*2;
     printf("Case #%d: %d\n", ca, ans);
   }
   return 0;
 }
 
