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
 
 int n;
 ll p;
 
 ll getworst(ll me, ll tot)
 {
 //     cout << "getworst " << me << ' ' << tot << endl;
     if (tot == 1) return 0;
     if (me == 0) return 0;
 //     cout << "adds " << tot / 2 << endl;
     return tot / 2 + getworst((me - 1) / 2, tot / 2);
 }
 
 ll getbest(ll me, ll tot)
 {
     if (tot == 1) return 0;
     if (me == tot - 1) return me;
     return getbest((me + 1) / 2, tot / 2);
 }
 
 int main()
 {
     int NT = 0;
     scanf("%d", &NT);
     for (int T = 1; T <= NT; T++)
     {
         printf("Case #%d: ", T);
         scanf("%d" LLD, &n, &p);
         p--;
         ll l = 0;
         ll r = 1LL << n;
         while (r - l > 1)
         {
             ll m = (l + r) / 2;
             if (getworst(m, 1LL << n) > p) r = m;
             else l = m;
         }
         ll ans_alw = l;
         
         l = 0;
         r = 1LL << n;
         while (r - l > 1)
         {
             ll m = (l + r) / 2;
             if (getbest(m, 1LL << n) > p) r = m;
             else l = m;
         }
         ll ans_can = l;
         
         printf(LLD " " LLD "\n", ans_alw, ans_can);
         fprintf(stderr, "%d/%d cases done!\n", T, NT);
     }
     return 0;
 }
