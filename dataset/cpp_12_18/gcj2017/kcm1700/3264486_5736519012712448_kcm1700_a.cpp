#include <cstdio>
 #include <vector>
 #include <cstring>
 #include <cstring>
 #include <string>
 
 using namespace std;
 
 char input[1048576];
 
 int main() {
   int T;
   scanf("%d", &T);
   for (int testcase = 1; testcase <= T; testcase++) {
     int K;
     scanf("%s%d", input, &K);
     int n = strlen(input);
 
     bool impossible = false;
     int cnt = 0;
     vector<bool> fl(n + 1);
     int acc = 0;
     for (int i = 0; i < n; i++) {
       if (fl[i]) {
         acc ^= 1;
       }
       int cur = acc;
       if (input[i] == '-') {
         cur ^= 1;
       }
 
       if (cur) {
         if (i + K <= n) {
           cnt++;
           acc ^= 1;
           fl[i + K] = true;
         }
         else {
           impossible = true;
           break;
         }
       }
     }
     if (impossible) {
       printf("Case #%d: IMPOSSIBLE\n", testcase);
     }
     else {
       printf("Case #%d: %d\n", testcase, cnt);
     }
   }
   return 0;
 }