#include <iostream>
 #include <string>
 #include <cstdio>
 #include <cstring>
 #include <set>
 #include <map>
 #include <queue>
 #include <algorithm>
 #include <vector>
 #include <bitset>
 #include <cmath>
 #pragma comment(linker, "/STACK:256000000")
 
 using namespace std;
 
 void solve(int tt) {
   printf("Case #%d: ", tt + 1);
   long long b;
   cin >> b;
   int n;
   cin >> n;
   vector <long long> a(n);
   for (int i = 0; i < n; ++i) {
     cin >> a[i];
   }
   while (a.size() < 37) a.push_back(0);
 
   sort(a.begin(), a.end());
   double res = 0.;
   for (int i = 1; i <= 37; ++i) {
     long long l = a[i - 1], r = 10000000000000LL;
     long long rs = -1;
     vector <long long> cur = a;
     long long st = cur[i - 1];
     long long cursum = 0;
     for (int j = 0; j < i; ++j) {
       cursum += st - cur[j];
     }
     for (int j = i; j < 37; ++j) {
       if (cur[j] == st) ++cursum;
     }
     if (cursum > b) continue;
     while (l <= r) {
       if (i == 33) {
         cursum = 1;
       }
       long long key = (l + r) / 2;
       long long sum = 0;
       for (int j = 0; j < i; ++j) {
         cur[j] = key - a[j];
         sum += cur[j];
       }
       for (int j = i; j < 37; ++j) {
         if (a[j] <= key) {
           cur[j] = key + 1 - a[j];
           sum += cur[j];
         }
       }
       if (sum > b) {
         r = key - 1;
       } else {
         double cres = 0.;
         for (int j = 0; j < i; ++j) {
           cres += 1. / (double)(i) * 36.0 * cur[j];
         }
         cres -= sum;
         res = max(res, cres);
         l = key + 1;
       }
     }
   }
   printf("%.10lf\n", res);
 }
 
 int main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
 
   int t;
   cin >> t;
   for (int i = 0; i < t; ++i) {
     solve(i);
     cerr << i << endl;
   }
 
   return 0;
 }
