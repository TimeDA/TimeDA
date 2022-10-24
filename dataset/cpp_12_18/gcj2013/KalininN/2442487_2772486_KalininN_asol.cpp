#include <iostream>
 #include <algorithm>
 #include <cmath>
 #include <cstring>
 #include <cstdlib>
 #include <string>
 #include <vector>
 #include <cstdio>
 #include <cassert>
 #include <queue>
 
 using namespace std;
 
 typedef long long ll;
 typedef long double ld;
 
 #ifdef WIN32
     #define LLD "%I64d"
 #else
     #define LLD "%lld"
 #endif
 
 const int MOD = 1000002013;
 
 const int OPEN = 0;
 const int CLOSE = 1;
 
 struct tsob
 {
     int x, kv, t;
     tsob(){}
     tsob(int x, int kv, int t): x(x), kv(kv), t(t) {}
 };
 
 inline bool operator <(const tsob &a, const tsob &b)
 {
     if (a.x != b.x) return a.x < b.x;
     return (a.t == OPEN && b.t == CLOSE);
 }
 
 vector<tsob> sob;
 priority_queue<pair<int, int> > q;
 int n, m;
 
 inline int get(int len)
 {
     if (len == 0) return 0;
     if (len == 1) return 0;
     len--;
     return (ll)len * (len + 1) / 2;
 }
 
 int main()
 {
     int NT = 0;
     scanf("%d", &NT);
     for (int T = 1; T <= NT; T++)
     {
         ll ans = 0;
         
         sob.resize(0);
         scanf("%d%d", &n, &m);
         for (int i = 0; i < m; i++)
         {
             int a, b, c;
             scanf("%d%d%d", &a, &b, &c);
             ans = ((ans - (ll)get(b - a) * c) % MOD + MOD) % MOD;
             sob.push_back(tsob(a, c, OPEN));
             sob.push_back(tsob(b, c, CLOSE));
         }
 //         cout << ans << ' ' << ans - MOD << endl;
         sort(sob.begin(), sob.end());
         while (!q.empty()) q.pop();
         for (int i = 0; i < (int)sob.size(); i++)
         {
             if (sob[i].t == OPEN)
             {
                 q.push(make_pair(sob[i].x, sob[i].kv));
             } else
             {
                 int cnt = sob[i].kv;
                 while (cnt > 0)
                 {
                     pair<int, int> last = q.top();
                     q.pop();
                     if (last.second > cnt)
                     {
                         last.second -= cnt;
                         ans = (ans + (ll)get(sob[i].x - last.first) * cnt) % MOD;
                         cnt = 0;
                         q.push(last);
                     } else
                     {
                         ans = (ans + (ll)get(sob[i].x - last.first) * last.second) % MOD;
                         cnt -= last.second;
                     }
                 }
             }
         }
         
         printf("Case #%d: ", T);
         printf("%d\n", (int)ans);
         fprintf(stderr, "%d/%d cases done!\n", T, NT);
     }
     return 0;
 }
