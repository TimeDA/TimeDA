#include <stdio.h>
 #include <string.h>
 #include <algorithm>
 #include <iostream>
 #include <math.h>
 #include <assert.h>
 #include <vector>
 
 using namespace std;
 typedef long long ll;
 typedef unsigned int uint;
 typedef unsigned long long ull;
 static const double EPS = 1e-9;
 static const double PI = acos(-1.0);
 
 #define REP(i, n) for (int i = 0; i < (int)(n); i++)
 #define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
 #define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
 #define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
 #define MEMSET(v, h) memset((v), h, sizeof(v))
 
 void solve();
 int main() {
   int test;
   scanf("%d", &test);
   char str[1000];
   fgets(str, 999, stdin);
   int test_case = 0;
   while (test--) {
     test_case++;
     printf("Case #%d: ", test_case);
     // puts("");
     solve();
   }
 }
 
 char ans[1010];
 char pre_ans[1010];
 
 void solve() {
   MEMSET(ans, 0);
   MEMSET(pre_ans, 0);
   char s1[3] = { 'R', 'Y', 'B' };
   char s2[3] = { 'G', 'V', 'O' };
   int n, c1[3], c2[3];
   scanf("%d %d %d %d %d %d %d", &n, &c1[0], &c2[2], &c1[1], &c2[0], &c1[2], &c2[1]);
   REP(i, 3) {
     if (c1[0] < c1[i]) {
       swap(c1[0], c1[i]);
       swap(c2[0], c2[i]);
       swap(s1[0], s1[i]);
       swap(s2[0], s2[i]);
     }
   }
   int m = 0;
   REP(i, 3) {
     if (n == c1[i]  + c2[i] && c1[i] == c2[i] && n % 2 == 0) {
       REP(j, c1[i]) {
         ans[2 * j + 0] = s1[i];
         ans[2 * j + 1] = s2[i];
       }
       goto end;
     }
     if (c2[i] != 0 && c1[i] <= c2[i]) { goto ng; }
     m += c1[i] - c2[i];
   }
   REP(i, 3) {
     if (m % 2 == 0 && m < (c1[i] - c2[i]) * 2) { goto ng; }
     if (m % 2 == 1 && m < (c1[i] - c2[i]) * 2) { goto ng; }
   }
   {
     int pos = 0;
     REP(i, 3) {
       REP(j, c1[i] - c2[i]) {
         while (pre_ans[pos] != 0) { pos = (pos + 1) % m; }
         pre_ans[pos] = s1[i];
         pos = (pos + 2) % m;
       }
     }
     pos = 0;
     int used[3] = { 0, 0, 0 };
     REP(pre_pos, m) {
       REP(j, 3) {
         if (pre_ans[pre_pos] == s1[j] && !used[j]) {
           used[j] = 1;
           REP(k, c2[j]) {
             ans[pos++] = s1[j];
             ans[pos++] = s2[j];
           }
         }
       }
       ans[pos++] = pre_ans[pre_pos];
     }
   }
 end:
   puts(ans);
   REP(i, n) {
     int prev = (i + n - 1) % n;
     int next = (i + 1)  % n;
     assert(ans[i] != ans[prev] && ans[i] != ans[next]);
   }
   return;
 ng:
    puts("IMPOSSIBLE");
 }
