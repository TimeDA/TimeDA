
 
 
 #include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 using namespace std;
 
 const int MaxN = 10005;
 int T, n, D;
 int d[MaxN], l[MaxN], h[MaxN];
 
 string check() {
     memset(h, -1, sizeof h);
     h[0] = d[0];
     for (int k = 0; k < n; ++ k) {
         if (h[k] < 0) continue;
         for (int r = k + 1; r < n && h[k] + d[k] >= d[r]; ++ r)
             h[r] = max(h[r], min(l[r], d[r] - d[k]));
         if (d[k] + h[k] >= D) return "YES";
     }
     return "NO";
 }
 
 int main() {
     scanf("%d", &T);
     for (int TestCase = 1; TestCase <= T; ++ TestCase) {
         scanf("%d", &n);
         for (int k = 0; k < n; ++ k)
             scanf("%d %d", d + k, l + k);
         scanf("%d", &D);
         printf("Case #%d: %s\n", TestCase, check().c_str());
     }
     
     return 0;
 }
