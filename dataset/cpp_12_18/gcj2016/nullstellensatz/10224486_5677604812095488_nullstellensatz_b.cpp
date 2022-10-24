
 
 
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
 
 const int MaxN = 205; 
 
 int T, n, K;
 double p[MaxN], v[MaxN][MaxN];
 
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
         scanf("%d %d", &n, &K);
         for (int k = 0; k < n; ++ k)
             scanf("%lf", p + k);
         sort(p, p + n);
         
         vector<double> ls, gr;
         ls.clear(); gr.clear();
         for (int k = 0; k < n; ++ k) {
             if (p[k] < 0.5 || (p[k] == 0.5 && ls.size() < k))
                 ls.push_back(p[k]);
             else
                 gr.push_back(p[k]);
         }
         reverse(gr.begin(), gr.end());
         
         vector<double> m;
         m.clear();
         for (int k = 0; k < K / 2 && k < ls.size() && k < gr.size(); ++ k) {
             m.push_back(ls[k]);
             m.push_back(gr[k]);
         }
         reverse(ls.begin(), ls.end());
         reverse(gr.begin(), gr.end());
         
         for (int k = 0; m.size() < K; ++ k) {
             if (ls.size() < K / 2)
                 m.push_back(gr[k]);
             else
                 m.push_back(ls[k]);
         }
         
         memset(v, 0, sizeof v);
         v[0][0] = 1.0;
         for (int i = 0; i < K; ++ i) {
             v[i + 1][0] = v[i][0] * (1.0 - m[i]);
             v[i + 1][i + 1] = v[i][i] * m[i];
             for (int j = 1; j <= i; ++ j)
                 v[i + 1][j] = v[i][j] * (1.0 - m[i]) + v[i][j - 1] * m[i];
         }
         printf("Case #%d: %.6f\n", testcase, v[K][K / 2]);
     }
     
     return 0;
 }
