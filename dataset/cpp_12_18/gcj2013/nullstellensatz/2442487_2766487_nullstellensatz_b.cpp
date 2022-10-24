
 
 
 /*
     Prob:   Google code jam Round 2 2013 B
     Author: peanut
     Time:   01/06/13 23:03
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
 
 long long dep(int n, long long p) {
     if (n == 1) return p - 1;
     if (p == 1) return 0;
     
     int t = 0;
     long long d = 1;
     while (d < p) {
         ++ t;
         d <<= 1;
     }
     if (t == n) {
         if (d == p) return d - 1;
         return d - 2;
     }
     return (1LL << n) - (d - dep(t, p)) * ((1LL << n) / d);
 }
 
 long long ind(int n, long long p) {
     long long d = 1LL << (n - 1);
     if (p <= d) return 0;
     return min((1LL << n) - 1, (ind(n - 1, p - d) + 1) << 1);
 }
 
 int n, T;
 long long p;
 
 int main(int argc, char* argv[]) {
     if (argc >= 2) {
         string input_file  = string(argv[1]) + ".in",
                output_file = string(argv[1]) + ".out";
         freopen(input_file.c_str(), "r", stdin);
         freopen(output_file.c_str(), "w", stdout);
     }
     
     scanf("%d", &T);
     for (int testcase = 1; testcase <= T; ++ testcase) {
         scanf("%d %I64d", &n, &p);
         printf("Case #%d: %I64d %I64d\n", testcase, ind(n, p), dep(n, p));
     }
     
     return 0;
 }
