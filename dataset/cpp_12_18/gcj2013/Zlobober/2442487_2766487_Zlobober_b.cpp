#include <cstdio>
 #include <algorithm>
 using namespace std;
 
 typedef long long llong;
 
 llong rev(llong x, int n)
 {
     llong y = 0;
     for (int i = 0; i < n; i++)
         y |= ((x >> i) & 1) << (n - i - 1);
     return y;
 }
 
 void solve(int cs)
 {
     int n;
     llong p;
     scanf("%d %lld", &n, &p);
     llong mn = 1e9;
     int mxw = 0;
     for (int i = 0; i < p; i++)
         mn = min(mn, rev((1 << n) - i - 1, n));
     for (int i = p; i < (1LL << n); i++)
         mxw = max(mxw, __builtin_popcount((1 << n) - i - 1));
     llong ans2 = (1LL << n) - mn - 1;
     llong ans1 = (1LL << (n - mxw)) - 2 + (p == (1LL << n));
     printf("Case #%d: %lld %lld\n", cs, ans1, ans2);
 }
 
 int main()
 {
     int t;
     scanf("%d", &t);
     for (int i = 0; i < t; i++)
         solve(i + 1);
 }
