
 
 
 /*
     Prob:   Google Code Jam Round2 2014
     Author: peanut
     Time:   
     Description:
 */
 
 #include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 #include <vector>
 using namespace std;
 
 int T, m, n; 
 string str[10];
 
 inline int common(string A, string B) {
     for (int k = 0; k < A.length() && k < B.length(); ++ k)
         if (A[k] != B[k]) return k;
     return min(A.length(), B.length());
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
         cin >> m >> n;
         for (int k = 0; k < m; ++ k)
             cin >> str[k];
         
         int ans = 0, cnt = 0;
         for (int k = 0; k < (1 << (m << 1)); ++ k) {
             int tmp = 0;
             bool v = true;
             for (int t = 0; t < m; ++ t)
                 if (((k >> (t << 1)) & 3) >= n) v = false;
             if (!v) continue;
             
             for (int i = 0; i < m; ++ i) {
                 tmp += str[i].length();
                 int max_com = 0;
                 for (int j = 0; j < i; ++ j)
                     if (((k >> (i << 1)) & 3) == ((k >> (j << 1)) & 3))
                         max_com = max(max_com, common(str[i], str[j]));
                 tmp -= max_com;
             }
             for (int t = 0; t < n; ++ t) {
                 bool check = false;
                 for (int r = 0; r < m; ++ r)
                     if (((k >> (r << 1)) & 3) == t) check = true;
                 if (check) ++ tmp;
             }
             
             if (tmp > ans) {
                 ans = tmp;
                 cnt = 1;
             }
             else if (tmp == ans) ++ cnt;
         }
         printf("Case #%d: %d %d\n", testcase, ans, cnt);
     }
 
     return 0;
 }
