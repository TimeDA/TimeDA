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
 
 #ifdef DBG1
     #define dbg(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
 #else
     #define dbg(...)
 #endif
 
 typedef long long ll;
 typedef unsigned long long ull;
 typedef pair <int, int> pii;
 
 void solve() {
   int n, k;
   assert (scanf ("%d%d", &n, &k) == 2);
   int m = n - k + 1;
   vector <int> s(m);
   for (int i = 0; i < m; ++i) {
     assert (scanf("%d", &s[i]) == 1);
   }
   vector <pii> a(n);
   for (int i = 0; i < k; ++i) {
     a[i] = pii(i, 0);
   }
   for (int i = k; i < n; ++i) {
     a[i].first = a[i - k].first;
     a[i].second = a[i - k].second + s[i - k + 1] - s[i - k];
   }
 
   vector <pii> b(2 * k);
   for (int i = 0; i < n; ++i) {
     if (i < k) {
       b[i] = b[i + k] = a[i];
     } else {
       int j = i % k;
       if (b[j].second > a[i].second) {
         b[j].second = a[i].second;
       }
       if (b[j + k].second < a[i].second) {
         b[j + k].second = a[i].second;
       }
     }
   }
   vector <int> diff(k);
   for (int i = 0; i < k; ++i) {
     diff[i] = b[i + k].second - b[i].second;
   }
   int sum0 = s[0], sum1 = s[0];
   for (int i = 0; i < k; ++i) {
     sum0 += b[i].second;
     sum1 += b[i + k].second;
   }
   sort(diff.begin(), diff.end());
   for (int i = 0; i < (k + (sum0 % k)) % k; ++i) {
     diff[i]++;
   }
   printf("%d\n", *max_element(diff.begin(), diff.end()));
 }
 
 int main()
 {
   int tt;
   assert(scanf("%d", &tt) == 1);
   for (int ii = 1; ii <= tt; ++ii) {
     printf("Case #%d: ", ii);
     solve();
     fflush (stdout);
   }
 
   return 0;
 }
 
