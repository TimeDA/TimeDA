
 
 
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
 
 const int MaxN = 3005;
 
 int T, n;
 int R, O, Y, G, B, V;
 char ans[MaxN];
 
 bool check() {
     if (R < G) return false;
     if (R == G && R + G > 0 && R + G < n) return false;
     if (Y < V) return false;
     if (Y == V && Y + V > 0 && Y + V < n) return false;
     if (B < O) return false;
     if (B == O && B + O > 0 && B + O < n) return false;
     return true;
 }
 
 void print_r(int num) {
     if (num == 0) {
         for (int k = 0; k < G; ++ k)
             printf("RG");
     }
     printf("R");
 }
 
 void print_y(int num) {
     if (num == 0) {
         for (int k = 0; k < V; ++ k)
             printf("YV");
     }
     printf("Y");
 }
 
 void print_b(int num) {
     if (num == 0) {
         for (int k = 0; k < O; ++ k)
             printf("BO");
     }
     printf("B");
 }
 
 bool arrange() {
     if (R + Y + B == 0) {
         for (int k = 0; k < G; ++ k)
             printf("RG");
         for (int k = 0; k < V; ++ k)
             printf("YV");
         for (int k = 0; k < O; ++ k)
             printf("BO");
     } else {
         int m = R + Y + B, cur_r = R, cur_y = Y, cur_b = B;
         for (int k = 0; k < m; k += 2) {
             if (R > 0) {ans[k] = 'R'; -- R;} else
             if (Y > 0) {ans[k] = 'Y'; -- Y;} else
             if (B > 0) {ans[k] = 'B'; -- B;}
         }
         for (int k = 1; k < m; k += 2) {
             if (R > 0) {ans[k] = 'R'; -- R;} else
             if (Y > 0) {ans[k] = 'Y'; -- Y;} else
             if (B > 0) {ans[k] = 'B'; -- B;}
         }
         for (int k = 0; k < m - 1; ++ k)
             if (ans[k] == ans[k + 1]) return false;
         if (ans[0] == ans[m - 1]) return false;
         
         int cnt_r = 0, cnt_y = 0, cnt_b = 0;
         for (int k = 0; k < m; ++ k) {
             if (ans[k] == 'R') {
                 ++ cnt_r;
                 print_r(cur_r - cnt_r);
             }
             if (ans[k] == 'Y') {
                 ++ cnt_y;
                 print_y(cur_y - cnt_y);
             }
             if (ans[k] == 'B') {
                 ++ cnt_b;
                 print_b(cur_b - cnt_b);
             }
         }
     }
     puts("");
     
     return true;
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
         scanf("%d %d %d %d %d %d %d", &n, &R, &O, &Y, &G, &B, &V);
         printf("Case #%d: ", testcase);
         
         if (check()) {
             R -= G; Y -= V; B -= O;
             if (!arrange()) puts("IMPOSSIBLE");
         } else puts("IMPOSSIBLE");
     }
     
     return 0;
 }
