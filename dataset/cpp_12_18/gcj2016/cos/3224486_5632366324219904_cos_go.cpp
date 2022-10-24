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
 
 int n, l;
 char goods[110][110];
 char ng[110];
 void solve() {
   scanf("%d %d", &n, &l);
   REP(i, n) {
     scanf("%s", goods[i]);
   }
   scanf("%s", ng);
 
   REP(i, n) {
     if (strstr(goods[i], ng) != NULL) { goto impossible; }
   }
   if (l == 1) {
     puts("0 0?");
   } else {
     string lhs(l - 1, '?');
     string rhs;
     REP(i, l / 2 + 5) {
       rhs += "10";
     }
     rhs += "?";
     REP(i, l / 2 + 5) {
       rhs += "10";
     }
     assert(lhs.size() + rhs.size() < 200);
     printf("%s %s\n", lhs.c_str(), rhs.c_str());
   }
   return;
 impossible:
   puts("IMPOSSIBLE");
 }
