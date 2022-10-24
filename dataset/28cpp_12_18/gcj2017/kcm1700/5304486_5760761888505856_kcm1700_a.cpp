#include <cstdio>
 #include <cstring>
 #include <string>
 #include <vector>
 #include <map>
 #include <set>
 #include <algorithm>
 #include <cmath>
 #include <cstdlib>
 #include <functional>
 #include <numeric>
 
 using namespace std;
 
 char buffer[1048576];
 
 int main() {
   int T;
   scanf("%d", &T);
   for (int testcase = 1; testcase <= T; testcase++) {
     int r, c;
     scanf("%d%d", &r, &c);
     vector<string> dat;
     for (int i = 0; i < r; i++) {
       scanf("%s", buffer);
       dat.emplace_back(buffer);
     }
     vector<string> ans;
     string last;
     for (int i = 0; i < r; i++) {
       string inits;
       for (int j = 0; j < c; j++) {
         if (dat[i][j] != '?') {
           inits.push_back(dat[i][j]);
         }
       }
       if (inits.empty()) {
         ans.emplace_back(last);
         continue;
       }
       string cur(c, '?');
       char lastc='?';
       for (int j = 0; j < c; j++) {
         if (dat[i][j] != '?') {
           lastc = dat[i][j];
         }
         cur[j] = lastc;
       }
       for (int j = c - 1; j >= 0; j--) {
         if (cur[j] == '?') {
           cur[j] = lastc;
         }
         else {
           lastc = cur[j];
         }
       }
       last = cur;
       ans.emplace_back(cur);
     }
     for (int i = r - 1; i >= 0; i--) {
       if (ans[i].empty()) {
         ans[i] = last;
       } else {
         last = ans[i];
       }
     }
     printf("Case #%d:\n", testcase);
     for (int i = 0; i < r; i++) {
       printf("%s\n", ans[i].c_str());
     }
   }
   return 0;
 }