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
 
 const int maxN = 101000;
 double c, f, x;
 double t[maxN];
 
 void solve(int tcase) {
   printf("Case #%d: ", tcase);
   scanf("%lf%lf%lf", &c, &f, &x);
 
   double cur = 0;
   double cprod = 2;
 
   for (int i = 0; i < maxN; ++i) {
     t[i] = cur + x / cprod;
     cur += c / cprod;
     cprod += f;
   }
 
   printf("%.10lf\n", *min_element(t, t + maxN));
 }
 
 int main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
 
   int t;
   scanf("%d", &t);
 
   for (int i = 0; i < t; ++i) {
     solve(i + 1);
   }
 
   return 0;
 }
