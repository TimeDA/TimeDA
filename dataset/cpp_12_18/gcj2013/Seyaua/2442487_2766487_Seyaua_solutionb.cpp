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
 
 int check1(long long n, long long p, long long pos) {
   while (true) {
     if (pos == 0) return 1;
     if (p <= (1LL << (n - 1))) return 0;
     pos = min((1LL << (n - 1)) - 1, (pos - 1) / 2);
     --n;
     p -= (1LL << n);
   }
 }
 
 int check2(long long n, long long p, long long pos) {
   while (true) {
     if (pos == 0) return 1;
     if (n == 1) {
       if (pos + 1 == p) return 1;
       return 0;
     }
     if (p == (1LL << n)) return 1;
     if (pos + 1 == (1LL << n) && p != pos + 1) return 0;
     if (p > (1LL << (n - 1))) return 1;
     if (pos + 1 == (1LL << n)) return 0;
     --n;
     pos = min((1LL << n) - 1, (pos + 1) / 2);
   }
 }
 
 long long bs(long long n, long long p, int mode) {
   long long l = 0, r = (1LL << n) - 1;
   long long result = 0;
 
   while (l <= r) {
     long long key = (l + r) / 2LL;
     int buf = mode ? check1(n, p, key) : check2(n, p, key);
     if (buf) {
       result = key;
       l = key + 1;
     } else {
       r = key - 1;
     }
   }
   return result;
 }
 
 void solve(int tt) {
   printf("Case #%d: ", tt + 1);
 
   long long n, p;
   cin >> n >> p;
   cout << bs(n, p, 1) << " " << bs(n, p, 0) << endl;
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
