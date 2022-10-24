#include <stdio.h>
 #include <string.h>
 #include <algorithm>
 #include <iostream>
 #include <math.h>
 #include <assert.h>
 #include <vector>
 #include <map>
 #include <sstream>
 
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
 char line[1000000];
 map<string, int> mapto;
 char str[10000];
 bool english[4000];
 vector<int> sentences[4000];
 int words[5000];
 
 int calc2() {
   MEMSET(words, 0);
   REP(i, n) {
     int v = english[i] ? 1 : 2;
     FORIT(it, sentences[i]) { words[*it] |= v; }
   }
   int ans = 0;
   REP(i, mapto.size()) {
     ans += words[i] == 3 ? 1 : 0;
   }
   return ans;
 }
 
 int calc(int depth) {
   if (depth == n) {
     return calc2();
   }
   int ans = 1e+9;
   if (depth == 0) {
     english[depth] = true;
     ans = calc(depth + 1);
   } else if (depth == 1) {
     english[depth] = false;
     ans = calc(depth + 1);
   } else {
     english[depth] = true;
     ans = min(ans, calc(depth + 1));
     english[depth] = false;
     ans = min(ans, calc(depth + 1));
   }
   return ans;
 }
 
 void solve() {
   mapto.clear();
   MEMSET(english, false);
   REP(i, 4000) { sentences[i].clear(); }
   scanf("%d ", &n);
   REP(i, n) {
     fgets(line, 990000, stdin);
     stringstream sin(line);
     while (sin >> str) {
       if (!mapto.count(str)) {
         int index = mapto.size();
         mapto[str] = index;
       }
       sentences[i].push_back(mapto[str]);
     }
   }
   int ans = calc(0);
   printf("%d\n", ans);
 }
