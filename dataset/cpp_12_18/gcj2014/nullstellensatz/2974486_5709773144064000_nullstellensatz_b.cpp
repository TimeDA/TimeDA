
 
 
 /*
     Prob:   Google Code Jam Qualification Round 2014
     Author: peanut
     Time:   12/04/14 15:47
     Description:
 */
 
 #include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 using namespace std;
 
 const double eps = 1e-6;
 
 double C, F, X;
 int T;
 
 int main(int argc, char* argv[]) {
     if (argc >= 2) {
         string input_file  = "B-" + string(argv[1]) + ".in",
                output_file = "B-" + string(argv[1]) + ".out";
         freopen(input_file.c_str(), "r", stdin);
         freopen(output_file.c_str(), "w", stdout);
     }
     
     scanf("%d", &T);    
     for (int testcase = 1; testcase <= T; ++ testcase) {
         double ans = 0, speed = 2;
         scanf("%lf %lf %lf", &C, &F, &X);
         
         while (true) {
             if (X / speed < C / speed + X / (speed + F)) {
                 ans += X / speed;
                 break;
             }
             ans += C / speed;
             speed += F;
         }
         printf("Case #%d: %.8f\n", testcase, ans);
     }
     
     return 0; 
 } 
