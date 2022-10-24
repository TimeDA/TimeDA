
 
 
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
 using namespace std;
 
 const int MaxN = 105;
 
 int T;
 string str;
 
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
     
     cin >> T;
     for (int testcase = 1; testcase <= T; ++ testcase) {
         cin >> str;
         long long ans = 0, check = 0;
         for (int k = 0; k < str.length(); ++ k) {
             char cur = str[k];
             for (int t = k + 1; t < str.length(); ++ t) {
                 if (str[t] < str[k]) -- cur;
                 if (str[t] != str[k]) break;
             }
             ans = ans * 10 + (check ? 9 : cur - '0');
             check += cur < str[k];
         }
         cout << "Case #" << testcase << ": " << ans << endl;
     }
 
     return 0;
 }