#include <cstdio>
 #include <cstring>
 #include <algorithm>
 using namespace std;
 
 const int N = 1050;
 
 char buf[N];
 
 void solve(int cs) {
     scanf("%s", buf);
     int n = strlen(buf);
     int k;
     scanf("%d", &k);
     int cnt = 0;
     for (int i = 0; i + k <= n; i++) {
         if (buf[i] == '-') {
             for (int j = i; j < i + k; j++)
                 buf[j] ^= '+' ^ '-';
             cnt++;
         }
     }
     int minuses = count_if(buf, buf + n, [] (char c) { return c == '-';});
     printf("Case #%d: ", cs);
     if (minuses > 0) {
         puts("IMPOSSIBLE");
     } else {
         printf("%d\n", cnt);
     }
 }
 
 int main() {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {
         solve(i + 1);
     }
 }
