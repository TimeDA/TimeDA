#ifdef DEBUG_OUTPUT
 #include "debug_output.h"
 #else
 #define PRINT(x)
 #define PRINT_CONT(x)
 #define PRINT_MSG(x)
 #endif
 
 #include <iostream>
 #include <cmath>
 #include <vector>
 #include <string>
 #include <cstring>
 #include <sstream>
 #include <algorithm>
 #include <memory.h>
 #include <set>
 #include <map>
 #include <cstdio>
 #include <cassert>
 using namespace std;
 
 
 // Enlarge MSVS stack size
 #pragma comment(linker, "/STACK:16777216")
 
 #define pb push_back
 #define all(c) c.begin(), c.end()
 #define mp(x, y) make_pair(x, y)
 #define sz(x) static_cast<int>(x.size())
 typedef long long int64;
 
 template<class T> T sqr(const T& t) {return t * t;}
 template<class T> T abs(const T& t) {return ((t > 0) ? (t) : (-t));}
 
 void initialize()
 {
     freopen("1.in", "r", stdin);
     freopen("1.out", "w", stdout);
 }
 
 double calc(const vector<double>& probs) {
     vector<vector<double>> res(probs.size() + 1, vector<double>(probs.size() + 1, 0.0));
     res[0][0] = 1.0;
     for (int i = 1; i <= probs.size(); ++i) {
         for (int j = 0; j <= probs.size(); ++j) {
             res[i][j] = res[i - 1][j] * (1.0 - probs[i - 1]);
             if (j > 0) {
                 res[i][j] += res[i - 1][j - 1] * (probs[i - 1]);
             }
         }
     }
     return res[probs.size()][probs.size() / 2];
 }
 
 int main()
 {
     initialize();
 
     int T;
     cin >> T;
     for (int tt = 1; tt <= T; ++tt) {
         int n, k;
         cin >> n >> k;
 
         cerr << "TEST " << tt << " " << n << " " << k << endl;
 
         vector<double> probs(n);
         for (int i = 0; i < n; ++i) {
             cin >> probs[i];
         }
 
         //vector<vector<vector<double>>> sol(n + 1, vector<vector<double>>(n + 1, vector<double>(2 * n + 2, 0.0)));
 
         //sol[0][0][n] = 1.0;
         //for (int i = 1; i <= n; ++i) {
         //    for (int j = 0; j <= k; ++j) {
         //        for (int balance = -n + 1; balance <= n - 1; ++balance) {
         //            int balanceIndex = balance + n;
         //            sol[i][j][balanceIndex] = sol[i - 1][j][balanceIndex];
         //            if (j > 0) {
         //                sol[i][j][balanceIndex] = max(sol[i][j][balanceIndex],
         //                    max(
         //                        sol[i - 1][j - 1][balanceIndex - 1] * probs[i - 1],
         //                        sol[i - 1][j - 1][balanceIndex + 1] * (1.0 - probs[i - 1])
         //                   ));
         //            }
         //            if (sol[i][j][balanceIndex] > 0.0) {
         //                cerr << i << " " << j << " " << balance << " " << sol[i][j][balanceIndex] << endl;
         //            }
         //        }
         //    }
         //}
         //
 
         double naiveRes = 0.0;
         vector<int> naiveIndices;
         for (int mask = 0; mask < (1 << n); ++mask) {
             vector<double> s;
             vector<int> indices;
             for (int i = 0; i < n; ++i) {
                 if ((mask & (1 << i)) > 0) {
                     s.pb(probs[i]);
                     indices.pb(i);
                 }
             }
             if (s.size() == k && k % 2 == 0) {
                 double c = calc(s);
                 if (c > naiveRes) {
                     naiveIndices = indices;
                     naiveRes = c;
                 }
             }
         }
 
         //sort(all(probs));
         //vector<double> resProbs;
         //for (int i = 0; i < k / 2; ++i) {
         //    resProbs.pb(probs[i]);
         //}
         //for (int i = n - k / 2; i < probs.size(); ++i) {
         //    resProbs.pb(probs[i]);
         //}
 
         //double r = 0.0;
         //if (k % 2 == 0) {
         //    r = calc(resProbs);
         //}
 
         //if (abs(r - naiveRes) > 0.0001) {
         //    cerr << "AAAAA ";
         //    for (int i = 0; i < naiveIndices.size(); ++i) {
         //        cerr << naiveIndices[i] << " ";
         //    }
         //    cerr << endl;
         //}
         printf("Case #%d: %.15lf\n", tt, naiveRes);
     }
     
     return 0;
 }
