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
 
 int n, x;
 int a[maxN];
 int used[maxN];
 
 void solve(int tcase) {
   scanf("%d", &n);
   scanf("%d", &x);
 
   for (int i = 0; i < n; ++i) {
     scanf("%d", &a[i]);
   }
   sort(a, a + n);
   reverse(a, a + n);
 
   for (int i = 0; i < n; ++i) used[i] = 0;
 
   int res = 0;
   for (int i = 0; i < n; ++i) {
     if (!used[i]) {
       ++res;
       used[i] = 1;
       for (int j = i + 1; j < n; ++j) {
         if (!used[j]) {
           if (a[i] + a[j] <= x) {
             used[j] = 1;
             break;
           }
         }
       }
     }
   }
   printf("Case #%d: %d\n", tcase, res);
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
