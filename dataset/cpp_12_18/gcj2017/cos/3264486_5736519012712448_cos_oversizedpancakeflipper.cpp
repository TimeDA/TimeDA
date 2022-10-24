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
 
 char str[10000];
 int k;
 
 void solve() {
   scanf("%s %d", str, &k);
   int n = strlen(str);
   int ans = 0;
   REP(i, n) {
     if (str[i] == '-')  {
       ans++;
       REP(j, k) {
         if (i + j >= n) { goto ng; }
         if (str[i + j] == '+') { str[i + j] = '-'; }
         else { str[i + j] = '+'; }
       }
     }
   }
   printf("%d\n", ans);
   return;
 ng:
   puts("IMPOSSIBLE");
 }
