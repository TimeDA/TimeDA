
 
 
 /*
     Prob:   Google code jam Qualification Round 2013 C
     Author: peanut
     Time:   13/04/13 22:56
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
 
 const int MaxN = 10;
 
 int T;
 long long A, B;
 int b[MaxN];
 
 inline bool check(long long n) {
     int w = 0;
     while (n > 0) {
         b[w ++] = n % 10;
         n /= 10;
     }
     for (int k = 0; k < w; ++ k)
         if (b[k] != b[w - k - 1]) return false;
     return true;
 }
 
 inline long long calc(long long lim) {
     if (lim == 0) return 0;
     long long ans = 0;
     for (int n = 1; n; ++ n) {
         int w = (n - 1) >> 1;
         long long tmp = 1;
         for (int k = 0; k < w; ++ k)
             tmp *= 10;
         
         for (long long half = tmp; half <= tmp * 10 - 1; ++ half) {
             memset(b, 0, sizeof b);
             long long tmp_h = half;
             for (int k = 0; k <= w; ++ k) {
                 b[k] = tmp_h % 10;
                 tmp_h /= 10;
             }
             tmp_h = half;
             for (int k = (n & 1); k <= w; ++ k)
                 tmp_h = tmp_h * 10 + b[k];
             if (tmp_h * tmp_h > lim) return ans;
             if (check(tmp_h * tmp_h)) ++ ans;
         }
     }
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
         cin >> A >> B;
         cout << "Case #" << testcase << ": " << calc(B) - calc(A - 1) << endl;
     }
     
     return 0;
 }
