
 
 
 /*
     Prob:
     Author: 
     Time:   
     Description:
 */
 
 #include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 #include <string>
 #include <vector>
 using namespace std;
 
 const int MaxN = 15;
 const int MaxM = 2050;
 
 int T, n, R, P, S;
 vector<string> check;
 
 string recover(string root) {
     string pre = "", cur = root;
     for (int k = 1; k <= n; ++ k) {
         pre = cur; cur = "";
         int tmp = (n - k) % 6;
         for (int t = 0; t < pre.length(); ++ t) {
             if (pre[t] == 'P') {
                 if (tmp == 0 || tmp == 1 || tmp == 2)
                     cur += "PR";
                 else
                     cur += "RP";
             }
             if (pre[t] == 'R') {
                 if (tmp == 0 || tmp == 4 || tmp == 5)
                     cur += "RS";
                 else
                     cur += "SR";
             }
             if (pre[t] == 'S') {
                 if (tmp == 0 || tmp == 1 || tmp == 5)
                     cur += "PS";
                 else
                     cur += "SP";
             }
         }
     }
     
     int cnt_R = 0, cnt_P = 0, cnt_S = 0;
     for (int k = 0; k < cur.length(); ++ k) {
         if (cur[k] == 'R') ++ cnt_R;
         if (cur[k] == 'P') ++ cnt_P;
         if (cur[k] == 'S') ++ cnt_S;
     }
     if (cnt_R == R && cnt_P == P && cnt_S == S)
         return cur;
     else
         return "";
 }
 
 int main(int argc, char* argv[]) { 
     if (argc >= 2) {
         string post = argv[1][0] == 's' ? 
                       "-small-attempt" + string(argv[2]):
                       "-large";  
         string input_file  = string(argv[0]) + post + ".in",
                output_file = string(argv[0]) + post + ".out";
         freopen(input_file.c_str(), "r", stdin);
         freopen(output_file.c_str(), "w", stdout);
     }
     
     scanf("%d", &T);
     for (int testcase = 1; testcase <= T; ++ testcase) {
         scanf("%d %d %d %d", &n, &R, &P, &S);
         cout << "Case #" << testcase << ": ";
         
         check.clear();
         check.push_back(recover("P"));
         check.push_back(recover("R"));
         check.push_back(recover("S"));
         sort(check.begin(), check.end());
         for (int k = 0; k < 3; ++ k)
             if (check[k].length() == (1 << n)) {
                 cout << check[k] << endl;
                 break;
             }
         if (check[2].length() != (1 << n)) cout << "IMPOSSIBLE" << endl;
     }
     
     return 0;
 }
