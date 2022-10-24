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
 
 #ifdef DBG1
     #define dbg(...) fprintf(stderr, __VA_ARGS__)
 #else
     #define dbg(...)
 #endif
 
 using namespace std;
 
 typedef long long ll;
 typedef unsigned long long ull;
 typedef pair <int, int> pii;
 
 void solve() {
   static char s[2000];
   int k;
   scanf("%s%d", s, &k);
   int n = (int)strlen(s);
   int res = 0;
   for (int i = 0; i < n; ++i) {
     if (s[i] == '-') {
       if (i + k > n) {
         printf("IMPOSSIBLE");
         return;
       }
       res++;
       for (int j = 0; j < k; ++j) {
         s[i + j] ^= ('-' ^ '+');
       }
     }
   }
   printf("%d", res);
 }
 
 int main() {
   int tt;
   scanf("%d", &tt);
   for (int ii = 1; ii <= tt; ++ii) {
     dbg("Case #%d:\n", ii);
     printf("Case #%d: ", ii);
     solve();
     printf("\n");
     fflush(stdout);
   }
   return 0;
 }
