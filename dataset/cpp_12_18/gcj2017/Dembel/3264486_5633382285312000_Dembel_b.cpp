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
   static char s[20];
   scanf("%s", s);
   int n = (int)strlen(s);
   int i = 0;
   while (i + 1 < n && s[i] <= s[i + 1]) {
     ++i;
   }
   if (i == n - 1) {
     printf("%s", s);
     return;
   }
   while (i > 0 && s[i] == s[i - 1]) {
     --i;
   }
   for (int j = i + 1; j < n; ++j) {
     s[j] = '9';
   }
   s[i]--;
   if (s[i] == '0') {
     printf("%s", s + 1);
   } else {
     printf("%s", s);
   }
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
