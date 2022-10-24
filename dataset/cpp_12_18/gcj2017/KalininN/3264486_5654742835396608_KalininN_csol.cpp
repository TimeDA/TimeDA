#include <bits/stdc++.h>
 
 using namespace std;
 
 using ll = long long;
 using ld = long double;
 using D = double;
 using uint = unsigned int;
 template<typename T>
 using pair2 = pair<T, T>;
 
 #ifdef WIN32
     #define LLD "%I64d"
 #else
     #define LLD "%lld"
 #endif
 
 #define pb push_back
 #define mp make_pair
 #define all(x) (x).begin(),(x).end()
 #define fi first
 #define se second
 
 map<pair<ll, ll>, ll> segs;
 ll n, k;
 
 void add(ll n, ll kv)
 {
     segs[{(n - 1) / 2, n / 2}] += kv;
 }
 
 int main()
 {
     int NT = 0;
     scanf("%d", &NT);
     for (int T = 1; T <= NT; T++)
     {
         printf("Case #%d: ", T);
         
         scanf("%lld%lld", &n, &k);
         segs.clear();
         add(n, 1);
         while (k > 0)
         {
             auto cur = segs.rbegin();
             if (cur->se >= k)
             {
                 printf("%lld %lld\n", cur->fi.se, cur->fi.fi);
                 break;
             }
             k -= cur->se;
             add(cur->fi.fi, cur->se);
             add(cur->fi.se, cur->se);
             segs.erase(prev(segs.end()));
         }
         
 
         fprintf(stderr, "%d/%d cases done!\n", T, NT);
     }
     return 0;
 }
