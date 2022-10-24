#include <cstdio>
 #include <string>
 using namespace std;
 
 void solve(int cs) {
     int n, l;
     scanf("%d %d", &n, &l);
     string bad(l, '1');
     bool fail = false;
     for (int i = 0; i < n + 1; i++) {
         char tmp[1000];
         scanf("%s", tmp);
         string q = tmp;
         if (q == bad && i != n) {
             fail = true;
         }
     }
     if (fail) {
         printf("Case #%d: IMPOSSIBLE\n", cs);
         return;
    }
     string a, b;
     if (l == 1) {
         a = "0?";
         b = "0";
     } else {
         string p = "10?";
         string q = "1";
         for (int i = 0; i < l; i++)
             a += p;
         for (int i = 0; i < l - 1; i++)
             b += q;
     }
     printf("Case #%d: %s %s\n", cs, a.data(), b.data());
 }
 
 int main() {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {
         solve(i + 1);
     }
 }
