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
     //puts("");
     solve();
   }
 }
 
 int n, k;
 char str[2000];
 int convert[200];
 int matrix[128][128];
 
 void Push(int c1, int c2) {
   matrix[c1][c2] = 1;
   if (convert[c1] != -1) { Push(convert[c1], c2); }
   if (convert[c2] != -1) { Push(c1, convert[c2]); }
 }
 void solve() {
   MEMSET(convert, -1);
   convert[(int)'o'] = 0;
   convert[(int)'i'] = 1;
   convert[(int)'e'] = 3;
   convert[(int)'a'] = 4;
   convert[(int)'s'] = 5;
   convert[(int)'t'] = 7;
   convert[(int)'b'] = 8;
   convert[(int)'g'] = 9;
 
   MEMSET(matrix, 0);
   scanf("%d %s", &k, str);
   n = strlen(str);
   REP(i, n - 1) { Push(str[i], str[i + 1]); }
   int ans = 0;
   int euler = 0;
   REP(f, 128) {
     int sum = 0;
     REP(t, 128) {
       ans += matrix[f][t];
       sum += matrix[f][t] - matrix[t][f];
     }
     euler += max(sum, 0);
   }
   if (euler <= 1) {
     ans++;
   } else {
     ans += euler;
   }
   printf("%d\n", ans);
 }
