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
 
 int solve(int p, vector<int> c) {
     int res = c[0];
     if (p == 2) {
         res += (c[1] + 1) / 2;
     } else if (p == 3) {
         int x = min(c[1], c[2]);
         int y = max(c[1], c[2]) - x;
         res += x + (y + 2) / 3; 
     } else if (p == 4) {
         res += c[2] / 2;
         bool hasAdd = (c[2] % 2 == 1);
         
         int x = min(c[1], c[3]);
         int y = max(c[1], c[3]) - x;
         res += x;
 
         if (hasAdd && y >= 2) {
             res += 1;
             y -= 2;
             hasAdd = false;
         }
         res += (y + 3) / 4;
 
         if (y % 4 == 0 && hasAdd) {
             res += 1;
         }
     }
 
     return res;
 }
 
 int naive(int p, vector<int> c) {
     vector<int> nums;
     for (int i = 0; i < c.size(); ++i) {
         for (int j = 0; j < c[i]; ++j) {
             nums.pb(i);
         }
     }
 
     int best = 0;
     do {
         int res = 0;
         int sum = 0;
         for (int i = 0; i < nums.size(); ++i) {
             if (sum % p == 0) {
                 res += 1;
             }
             sum += nums[i];
         }
         best = max(best, res);
     } while (next_permutation(all(nums)));
 
     return best;
 }
 
 int main()
 {
     initialize();
 
     //int p = 4;
     //while (true) {
     //    int n = 1 + (rand() % 8);
     //    vector<int> c(p);
     //    for (int i = 0; i < n; ++i) {
     //        c[rand() % p] ++;
     //    }
     //    if (solve(p, c) != naive(p, c)) {
     //        cerr << p << endl;
     //        for (int i = 0; i < p; ++i) {
     //            cerr << c[i] << " ";
     //        }
     //        cerr << endl;
     //        cerr << solve(p, c) << " " << naive(p, c) << endl;
     //        break;
     //    }
 
     //}
 
     int T;
     cin >> T;
 
     for (int tt = 1; tt <= T; ++tt) {
         cerr << "TEST: " << tt << endl;
         int n, p;
         cin >> n >> p;
 
         vector<int> c(p);
         for (int i = 0; i < n; ++i) {
             int num;
             cin >> num;
             c[num % p] ++;
         }
 
         //if (n > 10) {
         //    continue;
         //}
 
         //if (solve(p, c) != naive(p, c)) {
         //    cerr << p << endl;
         //    for (int i = 0; i < p; ++i) {
         //        cerr << c[i] << " ";
         //    }
         //    cerr << endl;
         //    cerr << solve(p, c) << " " << naive(p, c) << endl;
         //    break;
         //}
     //    int res = c[0];
     //    if (p == 2) {
     //        res += (c[1] + 1) / 2;
     //    } else if (p == 3) {
     //        int x = min(c[1], c[2]);
     //        int y = max(c[1], c[2]) - x;
     //        res += x + (y + 2) / 3; 
     //    } else if (p == 4) {
     //        res += c[2] / 2;
     //        bool hasAdd = (c[2] % 2 == 1);
     //        
     //        int x = min(c[1], c[3]);
     //        int y = max(c[1], c[3]) - x;
     //        res += x;
 
     //        if (hasAdd && y >= 2) {
     //            res += 1;
     //            y -= 2;
     //            hasAdd = false;
     //        }
     //        res += (y + 3) / 4;
 
     //        if (y % 4 == 0 && hasAdd) {
     //            res += 1;
     //        }
     //    }
 
         cout << "Case #" << tt << ": " << solve(p, c) << endl;
     }
     
     return 0;
 }
