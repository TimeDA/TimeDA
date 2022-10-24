#include <cstdio>
 #include <algorithm>
 #include <cstring>
 using namespace std;
 
 const int N = 200;
 
 int D[N][N];
 
 char buf[N];
 
 void solve(int cs) {
     scanf("%s", buf);
     int n = strlen(buf);
     for (int i = 0; i <= n; i++) {
         for (int j = 0; j <= n; j++) {
             D[i][j] = -100 * n;
         }
     }
     for (int i = 0; i < n - 1; i++) {
         D[i][i + 1] = (buf[i] == buf[i + 1]) ? 10 : 5;
     }
     for (int len = 4; len <= n; len += 2) {
         for (int i = 0; i + len <= n; i++) {
             int j = i + len - 1;
             D[i][j] = max(D[i][j], D[i + 1][j - 1] + ((buf[i] == buf[j]) ? 10 : 5));
             for (int k = i + 1; k < j; k += 2) {
                 D[i][j] = max(D[i][j], D[i][k] + D[k + 1][j]);
             }
         }
     }
     printf("Case #%d: %d\n", cs, D[0][n - 1]);
 }
 
 int main() {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {
         solve(i + 1);
     }
 }
