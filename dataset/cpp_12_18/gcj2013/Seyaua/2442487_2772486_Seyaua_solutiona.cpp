#include <iostream>
 #include <string>
 #include <cstdio>
 #include <cstring>
 #include <set>
 #include <map>
 #include <queue>
 #include <algorithm>
 #include <vector>
 #include <bitset>
 #include <cmath>
 #pragma comment(linker, "/STACK:256000000")
 
 using namespace std;
 
 const long long mod = 1000002013;
 long long n, m;
 vector <pair<long long, long long> > rs;
 
 void solve(int tt) {
   printf("Case #%d: ", tt + 1);
   cin >> n >> m;
   long long bans = 0;
   for (int i = 0; i < m; ++i) {
     long long o, e, p;
     cin >> o >> e >> p;
     rs.push_back(make_pair(o, -p));
     rs.push_back(make_pair(e, +p));
     long long cnt = ((e - o) * n) % mod;
     long long add = ((e - o) * (e - o - 1)) / 2;
     add %= mod;
     cnt -= add;
     cnt = (cnt % mod + mod) % mod;
     bans += (cnt * p) % mod;
   }
 
   long long ans = 0;
   while (true) {
     sort(rs.begin(), rs.end());
     vector <pair<long long, long long> > nw;
     for (int i = 0; i < rs.size(); ++i) {
       if (rs[i].second != 0) nw.push_back(rs[i]);
     }
 
     int change = 0;
     for (int i = 1; i < nw.size(); ++i) {
       if (nw[i - 1].second < 0 && nw[i].second > 0) {
         change = 1;
         long long mn = min(-nw[i - 1].second, nw[i].second);
         long long len = nw[i].first - nw[i - 1].first;
         long long cur = (len * n) % mod;
         long long add = ((len) * (len - 1)) / 2;
         add %= mod;
         cur -= add;
         cur = (cur % mod + mod) % mod;
         ans += ((mn % mod) * cur) % mod;
         ans %= mod;
         nw[i - 1].second += mn;
         nw[i].second -= mn;
       }
     }
     rs = nw;
     if (!change) break;
   }
   cout << ((bans - ans) % mod + mod) % mod << endl;
 }
 
 int main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
 
   int t;
   cin >> t;
   for (int i = 0; i < t; ++i) {
     solve(i);
     cerr << i << endl;
   }
 
   return 0;
 }
