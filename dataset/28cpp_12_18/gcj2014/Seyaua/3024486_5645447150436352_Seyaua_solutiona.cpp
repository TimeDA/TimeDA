#include <iostream>
 #include <cstdio>
 #include <string>
 #include <cstring>
 #include <bitset>
 #include <queue>
 #include <set>
 #include <map>
 #include <cmath>
 #include <algorithm>
 #include <vector>
 #include <ctime>
 #pragma comment(linker, "/STACK:256000000")
 
 using namespace std;
 
 const int maxN = 1010000;
 const long long INF = 1000000000000000000LL;
 
 long long a[maxN];
 long long sums[maxN];
 long long n, p, q, r, s;
 
 bool check(long long value) {
   for (int i = 0; i < n; ++i) {
     long long psum = 0;
     if (i > 0) {
       psum = sums[i - 1];
     }
     if (psum > value) {
       return false;
     }
     long long add_value = psum + value;
     if (sums[i] > add_value) {
       return false;
     }
     int index = upper_bound(sums + i, sums + n, add_value) - sums;
     --index;
     long long rst = sums[n - 1] - sums[index];
     if (rst <= value) {
       return true;
     }
   }
   return false;
 }
 
 void solve(int tcase) {
   cin >> n >> p >> q >> r >> s;
   for (long long i = 0; i < n; ++i) {
     a[i] = (i * p + q) % r + s;
   }
   sums[0] = a[0];
   for (int i = 1; i < n; ++i) {
     sums[i] = a[i] + sums[i - 1];
   }
 
   long long l = 0, r = sums[n - 1] - 1LL;
   long long res = sums[n - 1];
   while (l <= r) {
     long long key = (l + r) / 2;
     if (check(key)) {
       res = key;
       r = key - 1;
     } else {
       l = key + 1;
     }
   }
   double ans = sums[n - 1] - (double)(res);
   ans /= (double)(sums[n - 1]);
   printf("Case #%d: %.10lf\n", tcase, ans);
 }
 
 int main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
 
   int t;
   cin >> t;
 
   for (int i = 1; i <= t; ++i) {
     solve(i);
     cerr << i << endl;
   }
 
   return 0;
 }
