#include <cstdio>
 #include <cassert>
 #include <cstring>
 #include <algorithm>
 using namespace std;
 
 void solve(int cs) {
     int n;
     scanf("%d", &n);
     int ans = -1;
     for (int i = n; i >= 1; i--) {
         char buf[10];
         sprintf(buf, "%d", i);
         int l = strlen(buf);
         if (is_sorted(buf, buf + l)) {
             ans = i;
             break;
         }
     }
     assert(ans != -1);
     printf("Case #%d: %d\n", cs, ans);
 }
 
 int main() {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {
         solve(i + 1);
         fflush(stdout);
         fprintf(stderr, "%d\n", i);
     }
 }
