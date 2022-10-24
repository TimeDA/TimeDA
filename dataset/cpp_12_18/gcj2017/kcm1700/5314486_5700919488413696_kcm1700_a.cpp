#include <cstdio>
 #include <algorithm>
 #include <cstdlib>
 #include <cmath>
 #include <climits>
 #include <cstring>
 #include <string>
 #include <vector>
 #include <queue>
 #include <numeric>
 #include <functional>
 #include <set>
 #include <map>
 
 using namespace std;
 
 int solve2(vector<int> groups) {
   vector<int> cntrem(10);
   for (const auto &g : groups) {
     cntrem[g % 2]++;
   }
   return cntrem[0] + ((cntrem[1] + 1) / 2);
 }
 
 int solve3(vector<int> groups) {
   vector<int> cntrem(10);
   for (const auto &g : groups) {
     cntrem[g % 3]++;
   }
   int ans = cntrem[0];
   // 1, 2
   int x = min(cntrem[1], cntrem[2]);
   cntrem[1] -= x; cntrem[2] -= x;
   ans += x;
 
   if (cntrem[1]) {
     ans += (cntrem[1] + 2) / 3;
   }
   if (cntrem[2]) {
     ans += (cntrem[2] + 2) / 3;
   }
   return ans;
 }
 
 int solve4(vector<int> groups) {
   vector<int> cntrem(10);
   for (const auto &g : groups) {
     cntrem[g % 2]++;
   }
   return cntrem[0] + ((cntrem[1] + 1) / 2);
 }
 
 
 int main() {
   int TT;
   scanf("%d", &TT);
   for (int testcase = 1; testcase <= TT; testcase++) {
     int n, p;
     scanf("%d%d", &n, &p);
     vector<int> G(n);
     for (int i = 0; i < n; i++) {
       scanf("%d", &G[i]);
     }
     int ans = 0;
     if (p == 2) {
       ans = solve2(G);
     }
     else if (p == 3) {
       ans = solve3(G);
     }
     printf("Case #%d: %d\n", testcase, ans);
   }
   return 0;
 }