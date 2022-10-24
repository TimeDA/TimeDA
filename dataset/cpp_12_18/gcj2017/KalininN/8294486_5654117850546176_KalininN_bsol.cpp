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
 
 string chr[6] = {"R", "O", "Y", "G", "B", "V"};
 
 int cnt[6];
 vector<string> blocks;
 int n;
 int a[6];
 bool ok;
 
 void check(bool t)
 {
     ok &= t;
 }
 
 int main()
 {
     int NT = 0;
     scanf("%d", &NT);
     for (int T = 1; T <= NT; T++)
     {
         printf("Case #%d: ", T);
         
         ok = true;
         scanf("%d", &n);
         for (int i = 0; i < 6; i++) scanf("%d", &a[i]);
         blocks.clear();
         for (int i = 0; i < 3; i++)
         {
             int in = 2 * i + 1;
             int out = (2 * i + 1 + 3) % 6;
             check(a[in] * 2 <= a[out]);
             for (int j = 0; j < a[in]; j++) blocks.pb(chr[out] + chr[in] + chr[out]);
             for (int j = a[in] * 2; j < a[out]; j++) blocks.pb(chr[out]);
             cnt[i] = a[out] - a[in];
         }
         int ttlcnt = blocks.size();
         int pmax = max_element(cnt, cnt + 3) - cnt;
         check(2 * cnt[pmax] <= ttlcnt);
         int start = accumulate(cnt, cnt + pmax, 0);
         if (!ok) printf("IMPOSSIBLE\n");
         else
         {
             int st = (ttlcnt + 1) / 2;
             for (int i = 0; i < st; i++)
             {
                 printf("%s", blocks[(start + i) % ttlcnt].c_str());
                 if (st + i < (int)blocks.size()) printf("%s", blocks[(start + st + i) % ttlcnt].c_str());
             }
             printf("\n");
         }
 
         fprintf(stderr, "%d/%d cases done!\n", T, NT);
     }
     return 0;
 }
