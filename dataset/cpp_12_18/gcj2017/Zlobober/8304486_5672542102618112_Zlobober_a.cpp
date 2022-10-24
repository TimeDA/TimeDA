#include <cstring>
 #include <algorithm>
 #include <set>
 #include <cstdio>
 #include <map>
 #include <cassert>
 #include <vector>
 using namespace std;
 
 vector<int> cur;
 set<vector<int>> all;
 
 vector<int> tofreq(vector<int> x) {
     vector<int> res((int)x.size() + 1);
     for (int i = 0; i < (int)x.size(); i++) {
         res[x[i]]++;
     }
     res.erase(res.begin());
     return res;
 }
 
 int card(vector<int> f) {
     int res = 1;
     for (int i = 0; i < (int)f.size(); i++) {
         res *= (i + 1);
     }
     for (int i = 0; i < (int)f.size(); i++) {
         for (int j = 1; j <= f[i]; j++) {
             assert(res % j == 0);
             res /= j;
         }
     }
     int sum = accumulate(f.begin(), f.end(), 0);
     for (int j = 1; j <= (int)f.size() - sum; j++) {
         assert(res % j == 0);
         res /= j;
     }
     return res;
 }
 
 map<vector<int>, vector<vector<int>>> E;
 
 int cnt = 0;
 
 void gen(int i, int l, int sum) {
     if (i == l) {
         vector<int> f = cur;
         vector<int> fto = tofreq(f);
         all.insert(f);
         E[fto].push_back(f);
         ++cnt;
         return;
     }
 
     for (int x = 0; x <= sum; x++) {
         cur.push_back(x);
         gen(i + 1, l, sum - x);
         cur.pop_back();
     }
 }
 
 set<vector<int>> used;
 
 int DFS(vector<int> v) {
     int ans = 0;
     used.insert(v);
     ans = card(v);
     for (auto u : E[v]) {
         if (used.count(u))
             continue;
         ans += DFS(u);
     }
     return ans;
 }
 
 void solve(int cs) {
     char buf[20];
     scanf("%s", buf);
     int l = strlen(buf);
     vector<int> v;
     for (int i = 0; i < l; i++) {
         v.push_back(buf[i] - '0');
     }
 
     cnt = 0;
     E.clear();
     used.clear();
     all.clear();
 
     gen(0, l, l);
     fprintf(stderr, "l = %d, cnt = %d\n", l, cnt);
 
 
     int res = 0;
 
     int sum = accumulate(v.begin(), v.end(), 0);
     if (sum > l) {
         res = 1;
     } else {
         res = DFS(v) + 1;
         vector<int> spec(l);
         spec[0] = 1;
         if (v == spec)
             --res;
     }
 
     printf("Case #%d: %d\n", cs, res);
 }
 
 
 int main() {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {
         solve(i + 1);
         fflush(stdout);
     }
 }
