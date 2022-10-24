#include <cstdio>
 #include <algorithm>
 using namespace std;
 
 typedef long long llong;
 
 const int N = 1000500;
 llong A[N];
 
 llong S[N];
 
 void solve(int cs)
 {
     int n;
     llong p, q, r, s;
     scanf("%d", &n);
     scanf("%lld %lld %lld %lld", &p, &q, &r, &s);
     for (int i = 0; i < n; i++)
         A[i] = ((i * 1LL * p + q) % r + s);
     for (int i = 0; i < n; i++)
         S[i + 1] = S[i] + A[i];
     llong ss = S[n];
     llong mn = 1e18;
     for (int a = 0; a < n; a++)
         for (int b = a + 1; b <= n; b++)
         {
             llong u = S[a], v = S[b] - S[a], w = S[n] - S[b];
             mn = min(mn, max(u, max(v, w)));
         }
     printf("Case #%d: %.10lf\n", cs, 1 - mn * 1.0 / ss);
 }
 
 int main()
 {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++)
         solve(i + 1);
 }
