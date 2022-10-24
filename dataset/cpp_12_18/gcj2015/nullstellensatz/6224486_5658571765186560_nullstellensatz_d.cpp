
 
 
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
 using namespace std;
 
 const int MaxN = 10005;
 
 int T, X, R, C;
 
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
         scanf("%d %d %d", &X, &R, &C);
         
         bool check = ((R >= X) || (C >= X)) 
                   && ((R >= X - 1) && (C >= X - 1))
                   && (R * C % X == 0);
         printf("Case #%d: ", testcase);
         puts(check ? "GABRIEL" : "RICHARD");
     }
     
     return 0;
 }
