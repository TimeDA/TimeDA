#include <iostream>
 #include <cstring>
 #include <algorithm>
 #include <cstdlib>
 #include <vector>
 #include <map>
 #include <tuple>
 
 using namespace std;
 
 map<pair<int, int>, string > dp[13][3];
 
 void build() {
     int cnt = 3;
     dp[0][0][{1,0}] = "R";
     dp[0][1][{0,1}] = "P";
     dp[0][2][{0,0}] = "S";
     for (int n = 1; n <= 12; n++) {
         for (int tar = 0; tar < 3; tar++) {
             int a, b;
             if (tar == 0) { a = 0, b = 2; }
             if (tar == 1) { a = 1, b = 0; }
             if (tar == 2) { a = 2, b = 1; }
             for (auto & p1 : dp[n - 1][a]) {
                 for (auto & p2 : dp[n - 1][b]) {
                     pair<int, int> pp;
                     pp.first = p1.first.first + p2.first.first;
                     pp.second = p1.first.second + p2.first.second;
                     string s = min(p1.second + p2.second, p2.second + p1.second);
                     if (dp[n][tar].find(pp) == dp[n][tar].end()) dp[n][tar][pp] = s, cnt++;
                     else dp[n][tar][pp] = min(dp[n][tar][pp], s);
                 }
             }
         }
     }
 }
 
 int main() {
     build();
     
     int tc;
     cin >> tc;
     for (int t = 1; t <= tc; t++) {
         int n, r, p, s;
         cin >> n >> r >> p >> s;
         pair<int, int> pp = {r, p};
         string out = "";
         
         for (int i = 0; i < 3; i++) {
             if (dp[n][i].find(pp) != dp[n][i].end()) {
                 if (out == "") out = dp[n][i][pp];
                 else out = min(out, dp[n][i][pp]);
             }
         }
         
         printf("Case #%d: ", t);
         if (out == "") puts("IMPOSSIBLE");
         else puts(out.c_str());
     }
     
     return 0;
 }
 
