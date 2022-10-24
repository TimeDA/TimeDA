#include <cstring>
 #include <algorithm>
 #include <cstdlib>
 #include <vector>
 #include <map>
 #include <tuple>
 #include <set>
 
 using namespace std;
 
 int n, len;
 char good[110][60];
 char bad[60];
 
 int main() {
     int tc;
     scanf("%d", &tc);
     for (int t = 1; t <= tc; t++) {
         scanf("%d%d", &n, &len);
         for (int i = 0; i < n; i++) scanf("%s", good[i]);
         scanf("%s", bad);
         bool ok = true;
         for (int i = 0; i < n && ok; i++) if (strcmp(good[i], bad) == 0) ok = false;
         if (!ok) printf("Case #%d: IMPOSSIBLE\n", t);
         else {
             printf("Case #%d: ", t);
             if (len == 1) puts("0 ?");
             else {
                 for (int i = 0; i < len - 1; i++) putchar('?');
                 printf(" 10?");
                 for (int i = 0; i < len - 1; i++) printf("10");
                 putchar('\n');
             }
         }
     }
 
     return 0;
 }
 
