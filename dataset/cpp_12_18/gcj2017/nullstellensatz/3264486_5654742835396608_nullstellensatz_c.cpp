
 
 
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
 #include <queue>
 using namespace std;
 
 int T;
 long long n, m;
 
 priority_queue<long long> Q;
 
 int main(int argc, char* argv[]) { 
     if (argc >= 2) {
         string post = argv[1][0] == 's' ? 
                       "-small-" + string(argv[2]) + "-attempt" + string(argv[3]):
                       "-large";  
         string input_file  = string(argv[0]) + post + ".in",
                output_file = string(argv[0]) + post + ".out";
         freopen(input_file.c_str(), "r", stdin);
         freopen(output_file.c_str(), "w", stdout);
     }
     
     cin >> T;
     for (int testcase = 1; testcase <= T; ++ testcase) {
         cin >> n >> m;
         while (!Q.empty()) Q.pop();
         Q.push(n);
         for (int k = 1; k < m; ++ k) {
             long long tmp = Q.top(); Q.pop();
             if (tmp > 0) {
                 Q.push(tmp >> 1);
                 Q.push((tmp - 1) >> 1);
             }
         }
         long long ansl = Q.top() >> 1, anss = (Q.top() - 1) >> 1;
         cout << "Case #" << testcase << ": " << ansl << " " << anss << endl;
     }
     
     return 0;
 }