
 
 
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
 
 const int MaxN = 1 << 10;
 
 int T, n;
 double nao[MaxN], ken[MaxN];
 
 int main(int argc, char* argv[]) {
     if (argc >= 2) {
         string input_file  = "D-" + string(argv[1]) + ".in",
                output_file = "D-" + string(argv[1]) + ".out";
         freopen(input_file.c_str(), "r", stdin);
         freopen(output_file.c_str(), "w", stdout);
     }
     
     scanf("%d", &T);
     for (int testcase = 1; testcase <= T; ++ testcase) {
         scanf("%d", &n);
         for (int k = 0; k < n; ++ k)
             scanf("%lf", nao + k);
         sort(nao, nao + n);
         for (int k = 0; k < n; ++ k)
             scanf("%lf", ken + k);
         sort(ken, ken + n);
         
         int d = 0, w = 0, l = 0, r = n - 1, s = 0;
         for (int k = 0; k < n; ++ k) {
             if (nao[k] < ken[l]) -- r;
             if (nao[k] > ken[l]) {
                 ++ l; ++ d;
             }
         }
         for (int k = 0; k < n; ++ k) {
             while (s < n && nao[k] > ken[s]) ++ s;
             if (s < n) ++ s; else ++ w;
         }
         printf("Case #%d: %d %d\n", testcase, d, w);
     }
     
     return 0;
 }
