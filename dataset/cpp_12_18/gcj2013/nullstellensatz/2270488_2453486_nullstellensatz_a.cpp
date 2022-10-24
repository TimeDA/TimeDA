
 
 
 /*
     Prob:   Google code jam Qualification Round 2013 A
     Author: peanut
     Time:   13/04/13 20:56
     Description:
 */
 
 #include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 #include <string>
 using namespace std;
 
 int T;
 string b[4];
 
 inline bool same(int cur_x, int cur_y, int dir_x, int dir_y) {
     string o = "";
     for (int k = 0, x = cur_x, y = cur_y; k < 4; ++ k, x += dir_x, y += dir_y)
         if (b[x & 3][y & 3] == '.') return false; else o += b[x & 3][y & 3];
     for (int i = 0; i < 4; ++ i)
         for (int j = 0; j < 4; ++ j)
             if (o[i] != o[j] && o[i] != 'T' && o[j] != 'T') return false;
     for (int k = 0; k < 4; ++ k)
         if (o[k] != 'T') {
             printf("%c won\n", o[k]);
             return true;
         }
 }
 
 inline bool check() {
     for (int k = 0; k < 4; ++ k) {
         if (same(k, 0, 0, 1)) return true;
         if (k == 0 && same(k, 0, 1, 1)) return true;
         if (same(0, k, 1, 0)) return true;
         if (k == 3 && same(0, k, 1, 3)) return true;
     }
     return false;
 }
 
 int main(int argc, char* argv[]) {
     if (argc >= 2) {
         string input_file  = string(argv[1]) + ".in",
                output_file = string(argv[1]) + ".out";
         freopen(input_file.c_str(), "r", stdin);
         freopen(output_file.c_str(), "w", stdout);
     }
     
     cin >> T;
     for (int testcase = 1; testcase <= T; ++ testcase) {
         int cnt = 0;
         for (int i = 0; i < 4; ++ i) {
             cin >> b[i];
             for (int j = 0; j < 4; ++ j)
                 if (b[i][j] == '.') ++ cnt;
         }
         
         printf("Case #%d: ", testcase);
         if (!check()) {
             if (cnt) puts("Game has not completed"); else puts("Draw");
         }
     }
     
     return 0;
 }
