#include <cstdio>
 #include <cassert>
 #include <map>
 #include <algorithm>
 using namespace std;
 
 typedef long long llong;
 
 const llong MOD = 1000002013;
 
 llong n, m;
 
 inline llong get(llong x)
 {
     return ((n * (n + 1) / 2 - (n - x) * (n - x + 1) / 2) % MOD + MOD) % MOD;
 }
 
 const int N = 4200;
 
 llong tmp[N];
 
 llong A[N], X[N];
 
 
 void solve(int tc)
 {
     scanf("%lld %lld", &n, &m);
     map<int, llong> M;
     llong Q = 0;
     for (int i = 0; i < m; i++)
     {
         int a, b, e;
         scanf("%d %d %d", &a, &b, &e);
         M[a] += e;
         M[b] -= e;
         Q = (Q + e * get(b - a)) % MOD;
     }
     int pt = 0;
     for (map<int, llong>::iterator it = M.begin(); it != M.end(); it++)
         A[pt] = it->second, X[pt] = it->first, pt++;
     llong ans = 0;
     for (int i = 0; i < pt; i++)
     {
         assert(A[i] >= 0);
         llong S = 0;
         for (int j = i + 1; j < pt; j++)
             tmp[j] = -S, S += A[j];
         for (int j = i + 2; j < pt; j++)
             tmp[j] = max(tmp[j], tmp[j - 1]);
         for (int j = pt - 1; j >= 0; j--)
         {
             llong q = min(A[i] - tmp[j], max(-A[j], 0LL));
             ans = (ans + q * get(X[j] - X[i])) % MOD;
             A[i] -= q;
             A[j] += q;
         }
     }
     for (int i = 0; i < pt; i++)
         assert(A[i] == 0);
     printf("Case #%d: %lld\n", tc, (Q - ans + MOD) % MOD);
 }
 
 int main()
 {
     int tc;
     scanf("%d", &tc);
     for (int i = 0; i < tc; i++)
         solve(i + 1);
 }
