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
 
 int n;
 char str[100];
 string memo[20][10][2];
 string dfs(int depth, int prev, int upper) {
   if (memo[depth][prev][upper] != "?") { return memo[depth][prev][upper]; }
   if (depth == n) { return ""; }
   if (!upper) {
     string now(1, '9');
     string next = dfs(depth + 1, 9, false);
     return now + next;
   }
   for (int i = str[depth] - '0'; i >= prev; i--) {
     bool nupper = 0;
     if (i == str[depth] - '0') { nupper = 1; }
     string now(1, i + '0');
     string next = dfs(depth + 1, i, nupper);
     if (prev == 0 && i == 0) { now = ""; }
     if (next != "!") { return memo[depth][prev][upper] = now + next; }
   }
   return "!";
 }
 
 void solve() {
   REP(i, 20) REP(j, 10) REP(k, 2) { memo[i][j][k] = "?"; }
   scanf("%s", str);
   n = strlen(str);
   string ans = dfs(0, 0, 1);
   cout << ans << endl;
 }
