#include <cstdio>
 #include <vector>
 #include <tuple>
 #include <cassert>
 using namespace std;
 
 typedef long long llong;
 
 int get_div(llong x) {
     for (int t = 2; 1ll * t * t <= x; t++) {
         if (x % t == 0)
             return t;
     }
     return -1;
 }
 
 int n;
 
 llong in_base(int msk, int b) {
     llong val = 0;
     llong cur = 1;
     for (int i = n - 1; i >= 0; i--) {
         if ((msk >> i) & 1)
             val += cur;
         cur *= b;
     }
     return val;
 }
 
 int main() {
     int T;
     scanf("%d", &T);
     assert(T == 1);
     int k;
     scanf("%d %d", &n, &k);
     //assert(n == 16 && k == 50);
     vector<pair<llong, vector<int>>> ans;
     for (int msk = (1 << (n - 1)) + 1; msk < (1 << n); msk += 2) {
         vector<int> cert;
         for (int i = 2; i <= 10; i++) {
             llong x = in_base(msk, i);
             int d = get_div(x);
             if (d == -1)
                 break;
             cert.push_back(d);
         }
         if (cert.size() == 9) {
             ans.emplace_back(in_base(msk, 10), cert);
             fprintf(stderr, "%d\n", (int)ans.size());
         }
         if (ans.size() >= k)
             break;
     }
     assert(ans.size() >= k);
     //ans.resize(k);
     printf("Case #1:\n");
     for (auto pr : ans) {
         llong x;
         vector<int> cert;
         tie(x, cert) = pr;
         printf("%lld", x);
         for (int v : cert) {
             printf(" %d", v);
         }
         printf("\n");
     }
 }
