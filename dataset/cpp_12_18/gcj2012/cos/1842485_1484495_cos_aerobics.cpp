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
 
 int n;
 ll w, h;
 int r[10000];
 int order[100000];
 ll xs[10000];
 ll ys[10000];
 const int ITER_CNT = 100;
 
 inline ll square(ll x) { return x * x; }
 void Print() {
   REP(i, n) {
     if (i != 0) { putchar(' '); }
     printf("%lld %lld", xs[i], ys[i]);
   }
   puts("");
 }
 
 bool Check(ll x, ll y, ll l, int upper) {
   REP(i, upper) {
     ll dx = abs(x - xs[order[i]]);
     ll dy = abs(y - ys[order[i]]);
     if (dx * dx + dy * dy < square(l + r[order[i]])) { return false; }
   }
   return true;
 }
 
 void solve() {
   scanf("%d %lld %lld", &n, &w, &h);
   REP(i, n) {
     scanf("%d", &r[i]);
   }
   REP(i, n) {
     order[i] = i;
   }
   while (true) {
     REP(i, n) {
       REP(iter, ITER_CNT) {
         int x = rand() % (w + 1);
         int y = rand() % (h + 1);
         if (Check(x, y, r[order[i]], i)) {
           xs[order[i]] = x;
           ys[order[i]] = y;
           goto next;
         }
         if (iter == ITER_CNT - 1) { goto end; }
       }
 next:;
     }
     Print();
     break;
 end:
     random_shuffle(order, order + n);
   }
   /*
   while (true) {
     anss.clear();
     open.clear();
     open[0] = -1e+8;
     open[w] = -1e+8;
     REP(i, n) {
       ll l = r[order[i]];
       ll minY = 1e+10;
       ll minX = -1;
       map<ll, ll>::iterator it;
       FORIT(it2, open) {
         if (it->second > minY) {
           minY = it->second;
           minX = it->first;
           it = it2;
         }
       }
       if (minX == -1) { goto next; }
       if (open.lower_bound(minX + l) == open.end()) {
         open.erase(minX);
         i--;
         continue;
       }
       while (it != open.end() && it->second < minX + 2 * l) {
       }
     }
     if (anss.size() == n) {
       REP(i, n) {
         int l = r[order[i]];
       }
       break;
     }
 next:;
     random_shuffle(order, order + n);
   }
   */
 }
