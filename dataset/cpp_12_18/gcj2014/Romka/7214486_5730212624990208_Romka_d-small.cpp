#include <cstdio>
 #include <map>
 #include <set>
 #include <vector>
 #include <algorithm>
 #include <utility>
 #include <memory.h>
 #include <cmath>
 #include <iostream>
 #include <string>
 #include <ctime>
 #include <sstream>
 
 using namespace std;
 
 #define forn(i, n) for (int i = 0; i < (int)(n); i++)
 #define pb push_back
 typedef long long ll;
 typedef long double ld;
 typedef pair<int, int> pii;
 
 double curtime() {
     return double(clock()) / CLOCKS_PER_SEC;
 }
 
 int n, A;
 char s[110][110];
 int a[110];
 
 void solve() {
     scanf("%d %d", &n, &A);
     forn(i, n) scanf("%s", s[i]);
 
     forn(i, n) a[i] = i;
     do {
         int c = a[0];
         for (int i = 1; i < n; i++)
             if (s[a[i]][c] == 'Y') c = a[i];
         if (c == A) {
             forn(i, n) printf("%d ", a[i]);
             printf("\n");
             return;
         }
     } while (next_permutation(a, a + n));
 
     printf("IMPOSSIBLE\n");
 }
 
 int main() {
     int tc;
     scanf("%d", &tc);
     for (int t = 1; t <= tc; t++) {
         printf("Case #%d: ", t);
         solve();
         fprintf(stderr, "Test %d done, time: %.5f sec.\n", t, curtime());
     }
 	return 0;
 }
