#include <cstdio>
 #include <cassert>
 #include <algorithm>
 using namespace std;
 
 typedef long long llong;
 
 const int N = 1050;
 llong S[N];
 
 llong D[N];
 
 llong A[N];
 llong B[N];
 
 #define eprintf(...) fprintf(stderr, __VA_ARGS__)
 
 void solve(int cs) {
     int n, k;
     scanf("%d %d", &n, &k);
     for (int i = 0; i < n - k + 1; i++) {
         scanf("%lld", &S[i]);
     }
     for (int i = 0; i < k; i++)
         D[i] = 0;
     for (int i = k; i < n; i++) {
         D[i] = D[i - k] + S[i - k + 1] - S[i - k];
     }
     llong supp = 0;
 
     for (int i = 0; i < k; i++) {
         llong mx = 0, mn = 0;
         for (int j = i; j < n; j += k) {
             mx = max(mx, D[j]);
             mn = min(mn, D[j]);
         }
         A[i] = mn;
         B[i] = mx;
         supp = max(supp, mx - mn);
     }
     int supp_i = -1;
     for (int i = 0; i < k; i++)
         if (B[i] - A[i] == supp)
             supp_i = i;
     assert(supp_i != -1);
     swap(A[supp_i], A[0]);
     swap(B[supp_i], B[0]);
     for (int i = 0; i < k; i++) {
         if (i < 5)
             eprintf("%d -> [%lld, %lld]\n", i, A[i], B[i]);
         else if (i == 5)
             eprintf("...\n");
     }
     eprintf("supposed answer: %lld\n", supp);
     
     llong s = S[0];
     llong r_d = 0, r_u = 0;
     for (int i = 0; i < k - 1; i++) {
         r_d += -A[i];
         r_u += supp - B[i];
     }
     r_d = s - r_d;
     r_u = s - r_u;
     swap(r_d, r_u);
     assert(r_d <= r_u);
     eprintf("r_d = %lld r_u = %lld\n", r_d, r_u);
     bool good = false;
     
     llong need_a = -A[k - 1];
     llong need_b = supp - B[k - 1];
     
     need_b += -need_a;
     r_d += -need_a;
     r_u += -need_a;
     need_a = 0;
 
     if (r_d >= 0) {
         llong t = r_d / k;
         r_d -= t * k;
         r_u -= t * k;
     } else {
         llong t = (-r_d + k - 1) / k;
         r_d += t * k;
         r_u += t * k;
     }
     if (r_d <= need_b)
         good = true;
     else {
         r_d -= k, r_u -= k;
         if (r_u >= 0)
             good = true;
     }
     eprintf("good: %d\n\n", (int)good);
     printf("Case #%d: %lld\n", cs, supp + (llong)!good);
 }
 
 int main() {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {
         solve(i + 1);
         fflush(stdout);
     }
 }
