#ifdef DBG1
   #define _GLIBCXX_DEBUG
 #endif
 
 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <cassert>
 #include <cstring>
 #include <string>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <set>
 
 #ifdef DBG12
     #define dbg(...) fprintf(stderr, __VA_ARGS__)
 #else
     #define dbg(...)
 #endif
 
 using namespace std;
 
 typedef long long ll;
 typedef unsigned long long ull;
 typedef pair <int, int> pii;
 
 void solve() {
   int n;
   scanf("%d", &n);
   int a[6];
   for (int i = 0; i < 6; ++i) {
     scanf("%d", &a[i]);
   }
   const char chars[] = "ROYGBV";
   const int pair[6] = {-1, 4, -1, 0, -1, 2};
 
   for (int i = 0; i < 6; ++i) {
     if (pair[i] == -1) { continue; }
     if (a[i] == 0) { continue; }
     if (a[i] == a[pair[i]] && a[i] + a[pair[i]] == n) {
       for (int x = 0; x < a[i]; ++x) {
         printf("%c%c", chars[i], chars[pair[i]]);
       }
       return;
     }
     if (a[i] >= a[pair[i]]) {
       printf("IMPOSSIBLE");
       return;
     }
     a[pair[i]] -= a[i];
   }
 
   dbg("zzz\n");
   int ind[3] = {0, 2, 4};
   for (int i = 0; i < 3; ++i) {
     for (int j = 1; j < 3; ++j) {
       if (a[ind[j - 1]] < a[ind[j]]) {
         swap(ind[j - 1], ind[j]);
       }
     }
   }
   dbg("zzz2\n");
   if (a[ind[0]] > a[ind[1]] + a[ind[2]]) {
     printf("IMPOSSIBLE");
     return;
   }
   char res[10000];
   int k = 0;
   int last = -1;
   memset(res, 0, sizeof(res));
   while (a[ind[0]] + a[ind[1]] + a[ind[2]]) {
     int bestI = -1;
     for (int i = 0; i < 3; ++i) {
       if (i == last || a[ind[i]] == 0) { continue; }
       if (bestI == -1 || a[ind[i]] > a[ind[bestI]]) {
         bestI = i;
       }
     }
     assert(bestI != -1 && a[ind[bestI]] > 0);
     last = bestI;
     a[ind[last]] --;
     res[k++] = chars[ind[last]];
   }
 /*  int n2 = a[ind[0]] + a[ind[1]] + a[ind[2]];
   for (int i = 0; i < 3; ++i) {
     for (int j = 0; j < a[ind[i]]; ++j) {
       res[k % n2] = chars[ind[i]];
       k += 2;
     }
   }*/
   assert(res[0] != res[k - 1]);
   for (int i = 0; i < k; ++i) {
     printf("%c", res[i]);
     int j = 0;
     while (j < 6 && (pair[j] == -1 || chars[pair[j]] != res[i])) {
       ++j;
     }
     dbg("i = %d res[i] %c j %d\n", i, res[i], j); 
     assert(j < 6);
     for (int x = 0; x < a[j]; ++x) {
       printf("%c%c", chars[j], chars[pair[j]]);
     }
     a[j] = 0;
   }
 }
 
 int main() {
   int tt;
   scanf("%d", &tt);
   for (int ii = 1; ii <= tt; ++ii) {
 //    dbg("Case #%d:\n", ii);
     printf("Case #%d: ", ii);
     solve();
     printf("\n");
     fflush(stdout);
   }
   return 0;
 }
