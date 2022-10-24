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
 
 string getProgram(int n, int mask) {
     string res;
     for (int i = 0; i < n; ++i) {
         char sym;
         int c = mask % 3;
         if (c == 0) {
             sym = '0';
         }
         if (c == 1) {
             sym = '1';
         }
         if (c == 2) {
             sym = '?';
         }
         res += sym;
         mask /= 3;
     }
     return res;
 }
 
 int apply(char c, int& val, string& cur)
 {
     if (c == '0') {
         val = 0;
     }
     if (c == '1') {
         val = 1;
     }
     if (c == '?') {
         cur += ('0' + val);
     }
 }
 
 void recurse(int i, int j, const string& pA, const string& pB, int val, set<string>& res, string cur) {
     if (i == pA.size() && j == pB.size()) {
         res.insert(cur);
         return;
     }
 
     if (i != pA.size()) {
         int newVal = val;
         string newCur = cur;
         apply(pA[i], newVal, newCur);
         recurse(i + 1, j, pA, pB, newVal, res, newCur);
     }
     
     if (j != pB.size()) {
         int newVal = val;
         string newCur = cur;
         apply(pB[j], newVal, newCur);
         recurse(i, j + 1, pA, pB, newVal, res, newCur);
     }
 
 }
 
 set<string> getOutputs(const string& pA, const string& pB) {
     set<string> res;
     recurse(0, 0, pA, pB, 0, res, "");
     return res;
 }
 
 int main()
 {
     initialize();
 
     int T;
     cin >> T; 
 
     for (int tt = 1; tt <= T; ++tt) {
         int n, l;
         cin >> n >> l;
         bool impossible = false;
         string str, ones = string(l, '1');
         for (int i = 0; i < n; ++i) {
             cin >> str;
             if (str == ones) {
                 impossible = true;
             }
         }
         cin >> str;
         //assert(str == ones);
 
         auto a = string(l - 1, '?');
         string b = "";
         for (int i = 0; i < l - 1; ++i) {
             b += "10";
         }
         b += "?1";
 
         if (l == 1) {
             a = "?";
             b = "0";
         }
 
         cout << "Case #" << tt << ": ";
         if (impossible) {
             cout << "IMPOSSIBLE";
         } else {
             cout << a << " " << b;
         }
         cout << endl;
     }
 
     //for (int n = 1; n <= 5; ++n) {
     //    for (int m = 1; m <= 5; ++m) {
     //        for (int maskA = 0; maskA < pow(3, n); ++maskA) {
     //            string pA = getProgram(n, maskA);
     //            int qa = 0;
     //            for (int i = 0; i < n; ++i) {
     //                if (pA[i] == '?') {
     //                    qa += 1;
     //                }
     //            }
     //            if (qa > 4) {
     //                continue;
     //            }
 
     //            for (int maskB = 0; maskB < pow(3, m); ++maskB) {
     //                string pB = getProgram(m, maskB);
     //                int q = qa;
     //                for (int i = 0; i < m; ++i) {
     //                    if (pB[i] == '?') {
     //                        q += 1;
     //                    }
     //                }
     //                if (q != 4) {
     //                    continue;
     //                }
 
     //                auto s = getOutputs(pA, pB);
     //                //cerr << "Programs: " << pA << " " << pB << endl;
     //                //for (auto elem : s) {
     //                //    cerr << elem << " " ;
     //                //}
     //                //cerr << endl;
     //                //cerr << endl;
     //                if (s == set<string>({"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
     //                                      "1000", "1001", "1010", "1011", "1100", "1101", "1110"})) {
     //                    cerr << pA << " " << pB << endl;
     //                }
     //            }
     //        }
     //    }
     //}
     
     return 0;
 }
