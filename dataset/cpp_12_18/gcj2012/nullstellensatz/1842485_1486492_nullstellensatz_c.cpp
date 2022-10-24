
 
 
 #include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 using namespace std;
 
 const int MaxN = 2005;
 
 int T, n;
 int next[MaxN], h[MaxN], level[MaxN];
 
 int main() {
     scanf("%d", &T);
     for (int TestCase = 1; TestCase <= T; ++ TestCase) {
         scanf("%d", &n);
         for (int k = 1; k < n; ++ k)
             scanf("%d", next + k);
         bool check = false;
         for (int i = 1; i < n; ++ i)
             for (int j = i + 1; j < n; ++ j)
                 if (next[i] > j && next[i] < next[j])
                     check = true;
         if (check) {
             printf("Case #%d: Impossible\n", TestCase);
             continue;
         }
         
         int max_level = 0;
         memset(level, 0, sizeof level);
         for (int i = 1; i < n; ++ i) {
             for (int j = i - 1; j >= 1; -- j)
                 if (next[j] > i) {
                     level[i] = level[j];
                     break;
                 }
             ++ level[i];
             max_level = max(max_level, level[i]);
         }
         
         for (int k = 1; k <= n; ++ k)
             h[k] = k;
         for (int L = 1; L <= max_level; ++ L) {
             for (int k = n - 1; k >= 1; -- k)
                 if (level[k] == L) {
                     h[k] = h[next[k]] - (next[k] - k) * L;
                     for (int r = k + 1; r < next[k]; ++ r)
                         h[r] = h[k] + (r - k) * L - 1;
                 }
         }
         int min_height = 0;
         for (int k = 1; k <= n; ++ k)
             min_height = min(min_height, h[k]);
         printf("Case #%d:", TestCase);
         for (int k = 1; k <= n; ++ k)
             printf(" %d", h[k] - min_height);
         puts("");
     }
     
     return 0;
 }
