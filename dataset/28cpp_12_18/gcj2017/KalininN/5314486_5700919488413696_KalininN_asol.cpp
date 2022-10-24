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
 
 map<vector<int>, int> was;
 int n, p;
 vector<int> cnt;
 
 int go(vector<int> pos)
 {
     if (was.count(pos)) return was[pos];
     int &ans = was[pos];
     ans = 0;
     bool was1 = false;
     for (int i = 0; i < (int)pos.size() - 1; i++) if (pos[i] > 0)
     {
         was1 = true;
         vector<int> newpos = pos;
         newpos[i]--;
         newpos.back() = (pos.back() + i) % p;
         ans = max(ans, go(newpos));
     }
     if (was1 && pos.back() == 0) ans++;
     return ans;
 }
 
 int main()
 {
     int NT = 0;
     scanf("%d", &NT);
     for (int T = 1; T <= NT; T++)
     {
         printf("Case #%d:", T);
         
         scanf("%d%d", &n, &p);
         cnt.resize(p);
         for (int i = 0; i < p; i++) cnt[i] = 0;
         for (int i = 0; i < n; i++)
         {
             int x;
             scanf("%d", &x);
             cnt[x % p]++;
         }
         was.clear();
         cnt.pb(0);
         printf(" %d\n", go(cnt));
 
         fprintf(stderr, "%d/%d cases done!\n", T, NT);
     }
     return 0;
 }
