#include <cstdio>
 #include <algorithm>
 using namespace std;
 
 const int N = 1050;
 
 void solve(int cs) {
     double d;
     int n;
     scanf("%lf %d", &d, &n);
     double mn = 1e100;
     for (int i = 0; i < n; i++) {
         double k, s;
         scanf("%lf %lf", &k, &s);
         mn = min(mn, s * d / (d - k));
     }
     printf("Case #%d: %.10lf\n", cs, mn);
 }
 
 int main() {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {
         solve(i + 1);
     }
 }
