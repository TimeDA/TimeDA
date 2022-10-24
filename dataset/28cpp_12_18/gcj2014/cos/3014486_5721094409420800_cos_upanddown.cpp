#include <stdio.h>
 #include <string.h>
 #include <algorithm>
 #include <iostream>
 #include <math.h>
 #include <assert.h>
 #include <vector>
 #include <map>
 
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
 
 int n;
 int seq[10010];
 int used[10010];
 map<int, int> mapto;
 
 void solve() {
   MEMSET(used, false);
   mapto.clear();
   scanf("%d", &n);
   REP(i, n) {
     scanf("%d", &seq[i]);
     mapto[seq[i]] = i;
   }
   int ans = 0;
   FORIT(it, mapto) {
     //int v = it->first;
     int pos = it->second;
     int lcnt = 0;
     int rcnt = 0;
     used[pos] = true;
     REP(i, n) {
       if (used[i]) { continue; }
       if (i < pos) { lcnt++; }
       if (pos < i) { rcnt++; }
     }
     ans += min(lcnt, rcnt);
   }
   cout << ans << endl;
 }
