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
 
 struct Level {
   int index;
   int time;
   int p;
   bool operator<(const Level &rhs) const {
     if (time * rhs.p != rhs.time * p) { return time * rhs.p < rhs.time * p; }
     return index < rhs.index;
   }
 };
 
 int n;
 Level levels[1010];
 void solve() {
   scanf("%d", &n);
   REP(i, n) {
     levels[i].index = i;
     scanf("%d", &levels[i].time); 
   }
   REP(i, n) {
     scanf("%d", &levels[i].p);;
   }
   sort(levels, levels + n);
   REP(i, n) {
     if (i != 0) { putchar(' '); }
     printf("%d", levels[i].index);
   }
   puts("");
 }
