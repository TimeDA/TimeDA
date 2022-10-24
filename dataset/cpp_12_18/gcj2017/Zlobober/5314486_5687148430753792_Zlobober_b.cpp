#include <cstdio>
 #include <memory.h>
 #include <cassert>
 #include <algorithm>
 using namespace std;
 
 const int N = 1050;
 int cnt[N];
 int W[N];
 int rem[N];
 
 int moved = 0;
 
 int n, c, m;
 
 bool can(int k) {
     for (int i = 1; i <= n; i++) {
         rem[i] = k;
     }
     moved = 0;
     for (int i = 1; i <= n; i++) {
         int need = W[i];
         for (int j = i; need > 0; --j) {
             if (j == 0)
                 return false;
             int here = min(need, rem[j]);
             rem[j] -= here;
             need -= here;
             if (j == i)
                 moved += need;
         }
     }
     return true;
 }
 
 void solve(int cs) {
     scanf("%d %d %d", &n, &c, &m);
     memset(W, 0, sizeof(W));
     memset(cnt, 0, sizeof(cnt));
     for (int i = 0; i < m; i++) {
         int x, b;
         scanf("%d %d", &x, &b);
         cnt[b]++;
         W[x]++;
     }
     int mx = *max_element(cnt + 1, cnt + c + 1);
     int l = mx - 1, r = m;
     while (r - l > 1) {
         int mid = (l + r) / 2;
         if (can(mid)) {
             r = mid;
         } else {
             l = mid;
         }
     }
     assert(can(r));
     printf("Case #%d: %d %d\n", cs, r, moved);
 }
 
 int main() {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {
         solve(i + 1);
     }
 }
