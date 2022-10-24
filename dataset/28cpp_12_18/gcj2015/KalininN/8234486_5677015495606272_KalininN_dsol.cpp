#include <iostream>
 #include <algorithm>
 #include <cmath>
 #include <cstring>
 #include <cstdlib>
 #include <string>
 #include <vector>
 #include <cstdio>
 #include <cassert>
 
 using namespace std;
 
 typedef long long ll;
 typedef long double ld;
 
 #ifdef WIN32
 #define LLD "%I64d"
 #else
 #define LLD "%lld"
 #endif
 
 const int MOD = 1000000007;
 
 int n, m;
 
 int ans(int r)
 {
     if (r < 0) return 0;
     if (r <= 1) return 1;
     if (r == 2)
     {
         if (m % 6 == 0) return 1;
         else return 0;
     }
     if (r == 3)
     {
         if (m % 4 == 0) return 2;
         else return 1;
     }
     int ans1 = (m % 4 == 0 ? ans(r - 5) : 0) % MOD;
     int ans2 = (m % 6 == 0 ? ans(r - 4) : 0) % MOD;
     int ans3 = ans(r - 3);
     return ((ll)ans1 + ans2 + ans3) % MOD;
 }
 
 int main()
 {
     int NT = 0;
     scanf("%d", &NT);
     for (int T = 1; T <= NT; T++)
     {
         printf("Case #%d:", T);
 
         scanf("%d%d", &n, &m);
         printf(" %d\n", (ans(n) + ans(n - 2)) % MOD);
 
         fprintf(stderr, "%d/%d cases done!\n", T, NT);
     }
     return 0;
 }
