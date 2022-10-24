#include <cstdio>
 #include <vector>
 #include <string>
 #include <map>
 #include <set>
 #include <cstdlib>
 #include <cmath>
 #include <cassert>
 #include <cstring>
 #include <algorithm>
 
 using namespace std;
 
 #ifdef DBG10
     #define dbg(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
 #else
     #define dbg(...)
 #endif
 
 typedef long long ll;
 typedef unsigned long long ull;
 typedef pair <int, int> pii;
 
 char s[200][200];
 const int dx[] = {-1, 1, 0, 0};
 const int dy[] = {0, 0, -1, 1};
 
 bool isMap(int x, int y, int n, int m) {
   return 0 <= x && x < n && 0 <= y && y < m;
 }
 
 int findDir (char ch) {
   const char zzz[] = "^v<>";
   int i = 0;
   while (i < 4 && zzz[i] != ch) {
     ++i;
   }
   assert (i < 4);
   return i;
 }
 
 void solve() {
   int n, m;
   scanf("%d%d", &n, &m);
   for (int i = 0; i < n; ++i) {
     scanf ("%s", s[i]);
   }
   int res = 0;
   int ok = 1;
   for (int i = 0; i < n; ++i) {
     for (int j = 0; j < m; ++j) {
       if (s[i][j] == '.') {
         continue;
       }
       int curD = findDir(s[i][j]);
       int fl = 0;
       bool ok2 = 0;
       for (int k = 0; k < 4; ++k) {
         int newD = (curD + k) % 4;
         int i0 = i, j0 = j;
         do {
           i0 += dx[newD];
           j0 += dy[newD];
         } while (isMap(i0, j0, n, m) && s[i0][j0] == '.');
         dbg("i = %d, j = %d, k = %d, i0 = %d, j0 = %d\n", i, j, k, i0, j0);
         ok2 |= isMap(i0, j0, n, m);
         fl |= isMap(i0, j0, n, m) && newD == curD;
       }
       ok &= ok2;
       res += (fl ? 0 : 1);
     }
   }
   if (!ok) {
     printf("IMPOSSIBLE\n");
   } else {
     printf("%d\n", res);
   }
 }
 
 int main()
 {
   int tt;
   assert(scanf("%d", &tt) == 1);
   for (int ii = 1; ii <= tt; ++ii) {
     printf("Case #%d: ", ii);
     solve();
   }
 
   return 0;
 }
 
