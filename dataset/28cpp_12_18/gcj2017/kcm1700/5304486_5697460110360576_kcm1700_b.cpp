#include <cstdio>
 #include <climits>
 #include <cstring>
 #include <string>
 #include <vector>
 #include <map>
 #include <set>
 #include <algorithm>
 #include <cmath>
 #include <cstdlib>
 #include <functional>
 #include <numeric>
 
 using namespace std;
 
 int main() {
   int T;
   scanf("%d", &T);
   for (int testcase = 1; testcase <= T; testcase++) {
     int n, p;
     scanf("%d%d", &n, &p);
     vector<int> R(n);
     for (int i = 0; i < n; i++) {
       scanf("%d", &R[i]);
     }
     vector<vector<pair<int, int>>> servings;
     for (int i = 0; i < n; i++) {
       vector<pair<int, int>> cur;
       for (int j = 0; j < p; j++) {
         int q;
         scanf("%d", &q);
         // R[i]*nr * 0.9 <= q <= R[i]*nr * 1.1
         // q*10/11 <= R[i]*nr && R[i]*nr <= q * 10 / 9
         int low = (q * 10 + (R[i] * 11 - 1)) / (R[i] * 11), high = (q * 10) / (9 * R[i]);
         cur.emplace_back(low, high);
       }
       sort(cur.begin(), cur.end());
       servings.emplace_back(cur);
     }
     vector<int> ptr(n);
     int ans = 0;
     for (;;) {
       int maxlow = 0;
       int minhigh = INT_MAX;
       bool finished = false;
       for (int i = 0; i < n; i++) {
         if (ptr[i] >= servings[i].size()) {
           finished = true;
           break;
         }
         minhigh = min(minhigh, servings[i][ptr[i]].second);
         maxlow = max(maxlow, servings[i][ptr[i]].first);
       }
       if (finished) {
         break;
       }
       if (maxlow <= minhigh) {
         ans++;
         for (int i = 0; i < n; i++) {
           ptr[i]++;
         }
       }
       else {
         for (int i = 0; i < n; i++) {
           if (minhigh == servings[i][ptr[i]].second) {
             ptr[i]++;
           }
         }
       }
     }
     printf("Case #%d: ", testcase);
     printf("%d\n", ans);
   }
   return 0;
 }