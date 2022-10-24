
 
 
 #include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 using namespace std;
 
 const int MaxN = 1005;
 
 int T, n, W, L;
 int x[MaxN], y[MaxN];
 pair<int, int> tmp[MaxN];
 
 int main() {
     scanf("%d", &T);
     bool check = true;
     for (int TestCase = 1; TestCase <= T; ++ TestCase) {
         scanf("%d %d %d", &n, &W, &L);
         for (int k = 1; k <= n; ++ k) {
             int r; scanf("%d", &r);
             tmp[k - 1] = make_pair(r, k);
         }
         sort(tmp, tmp + n);
         
         int cur_x = 0, cur_y = 0, next = 0;
         for (int k = n - 1; k >= 0; -- k) {
             if (cur_y > 0) cur_y += tmp[k].first;
             if (cur_y > L) {
                 cur_x = next + tmp[k].first;
                 cur_y = 0;
             }
             x[tmp[k].second] = cur_x;
             y[tmp[k].second] = cur_y;
             cur_y += tmp[k].first;
             next = max(next, cur_x + tmp[k].first);
         }
         
         printf("Case #%d:", TestCase);
         for (int k = 1; k <= n; ++ k) {
             if (x[k] > W) check = false;
             printf(" %d %d", x[k], y[k]);
         }
         puts("");
     }
     if (check)
         puts("Right!");
     else
         puts("Wrong!");
     
     return 0;
 }
