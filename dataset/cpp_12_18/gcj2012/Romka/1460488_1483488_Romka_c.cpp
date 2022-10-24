#include <cstdio>
 
 int main() {
     int tc, a, b;
     scanf("%d", &tc);
     for (int q = 0; q < tc; q++) {
         scanf("%d %d", &a, &b);
         int res = 0;
         for (int n = a; n < b; n++) {
             int z = n, d = 0, p = 1;
             for ( ; z>0; z/=10) d++, p *= 10;
             p /= 10;
             int nn = n;
             for (int w = 0; w < d; w++) {
                 nn = nn / 10 + (nn % 10) * p;
                 if (nn > n && nn <= b) {
                     res++;
                //     printf("%d %d\n", n, nn);
                 }
             }
         }
         printf("Case #%d: %d\n", q+1, res);
     }
 }
