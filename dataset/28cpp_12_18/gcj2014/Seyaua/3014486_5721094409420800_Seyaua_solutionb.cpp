#include <iostream>
 #include <cstdio>
 #include <string>
 #include <cstring>
 #include <set>
 #include <map>
 #include <vector>
 #include <bitset>
 #include <algorithm>
 #include <cmath>
 #include <queue>
 #include <ctime>
 #pragma comment(linker, "/STACK:256000000")
 
 using namespace std;
 
 const int maxN = 11000;
 
 int n;
 int a[maxN];
 int b[maxN];
 
 void solve(int tcase) {
   printf("Case #%d: ", tcase);
   scanf("%d", &n);
   for (int i = 0; i < n; ++i) {
     scanf("%d", &a[i]);
     b[i] = a[i];
   }
   sort(b, b + n);
 
   int l = 0, r = n - 1;
   int res = 0;
   for (int i = 0; i < n; ++i) {
     int cur = b[i];
     int ps = 0;
     for (int j = 0; j < n; ++j) {
       if (a[j] == cur) {
         ps = j;
         break;
       }
     }
 
     int d1 = ps - l;
     int d2 = r - ps;
 
     if (d1 < d2) {
       for (int j = ps; j > l; --j) {
         swap(a[j], a[j - 1]);
         ++res;
       }
       ++l;
     } else {
       for (int j = ps; j < r; ++j) {
         swap(a[j], a[j + 1]);
         ++res;
       }
       --r;
     }
   }
   printf("%d\n", res);
 }
 
 int main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
 
   int t;
   scanf("%d", &t);
 
   for (int i = 0; i < t; ++i) {
     solve(i + 1);
     cerr << i << endl;
   }
 
   return 0;
 }
