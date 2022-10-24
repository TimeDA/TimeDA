
 
 
 /*
     Prob:   Google Code Jam 2012 Qualification_Round C
     Author: peanutyk
     Time:   14/04/12 23:50
     Description: Сʾ
 */
 
 #include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 using namespace std;
 
 const int MaxN = 2000005;
 
 int T, A, B;
 int cnt[MaxN];
 
 inline int calc(int num) {
     int res = num, tmp = num, d = 1;
     while (tmp >= 10) {
         tmp /= 10;
         d *= 10;
     }
     for (int k = num; k / 10 + (k % 10) * d != num; k = k / 10 + (k % 10) * d)
         if (k % 10 != 0)
             res = min(res, k / 10 + (k % 10) * d);
     return res;
 }
 
 int main() {
     scanf("%d", &T);
     for (int n = 1; n <= T; ++ n) {
         scanf("%d %d", &A, &B);
         memset(cnt, 0, sizeof cnt);
         for (int k = A; k <= B; ++ k)
             ++ cnt[calc(k)];
         
         int ans = 0;
         for (int k = 1; k <= B; ++ k)
             ans += (cnt[k] * (cnt[k] - 1)) >> 1;
         printf("Case #%d: %d\n", n, ans);
     }
     
     return 0;
 }
