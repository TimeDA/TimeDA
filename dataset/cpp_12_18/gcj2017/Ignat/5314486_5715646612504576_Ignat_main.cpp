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
     freopen("2.in", "r", stdin);
     freopen("2.out", "w", stdout);
 }
 
 int main()
 {
     initialize();
 
     int T;
     cin >> T;
     for (int tt = 1; tt <= T; ++tt) {
         cerr << "TEST: " << tt << endl;
         int r, c;
         cin >> r >> c;
         vector<vector<int>> table(r, vector<int>(c, 0));
         for (int i = 0; i < r; ++i) {
             string str;
             cin >> str;
             for (int j = 0; j < c; ++j) {
                 if (str[j] == '#') {
                     table[i][j] = 1;
                 }
                 if (str[j] == '|' || str[j] == '-') {
                     table[i][j] = 2;
                 }
             }
         }
 
         for (int i = -1; i < r; ++i) {
             for (int j = -1; j < c; ++j) {
                 if (i == -1 && j == -1) {
                     continue;
                 }
 
                 if (i != -1 && j != -1 && table[i][j] != 1) {
                     continue;
                 }
 
                 if (j >= 0) 
                 {
                     int k = i + 1;
                     for (; k < r && table[k][j] != 1; ++k) {
                     }
 
                     int shouters = 0;
                     for (int l = i + 1; l < k; ++l) {
                         if (table[l][j] > 1) {
                             shouters += 1;
                         }
                     }
                     if (shouters != 1) {
                         for (int l = i + 1; l < k; ++l) {
                             if (table[l][j] > 1) {
                                 table[l][j] = 3; // '-'
                             } else {
                                 table[l][j] = 5; // need '-'
                             }
                         }
                     }
                 }
 
                 if (i >= 0)
                 {
                     int k = j + 1;
                     for (; k < c && table[i][k] != 1; ++k) {
                     }
 
                     int shouters = 0;
                     for (int l = j + 1; l < k; ++l) {
                         if (table[i][l] > 1) {
                             shouters += 1;
                         }
                     }
                     if (shouters != 1) {
                         for (int l = j + 1; l < k; ++l) {
                             if (table[i][l] > 1) {
                                 table[i][l] = 4; // '|'
                             } else {
                                 table[i][l] = 6; // need '|'
                             }
                         }
                     }
                 }
             }
         }
 
         cerr << "PART1 finished" << endl;
         
         for (int i = 0; i < r; ++i) {
             for (int j = 0; j < c; ++j) {
                 if (table[i][j] == 5) {
                     for (int l = j - 1; l >= 0; --l) {
                         if (table[i][l] == 1) {
                             break;
                         }
                         if (table[i][l] == 2) {
                             cerr << "SET3 " << i << " " << l << endl;
                             table[i][l] = 3;
                         }
                     }
                     for (int l = j + 1; l < c; ++l) {
                         if (table[i][l] == 1) {
                             break;
                         }
                         if (table[i][l] == 2) {
                             cerr << "SET3 " << i << " " << l << endl;
                             table[i][l] = 3;
                         }
                     }
                 }
                 if (table[i][j] == 6) {
                     for (int l = i - 1; l >= 0; --l) {
                         if (table[l][j] == 1) {
                             break;
                         }
                         if (table[l][j] == 2) {
                             cerr << "SET4 " << i << " " << l << endl;
                             table[l][j] = 4;
                         }
                     }
                     for (int l = i + 1; l < r; ++l) {
                         if (table[l][j] == 1) {
                             break;
                         }
                         if (table[l][j] == 2) {
                             cerr << "SET4 " << i << " " << l << endl;
                             table[l][j] = 4;
                         }
                     }
                 }
             }
         }
         
         cerr << "PART2 finished" << endl;
         
         int uuu = 0;
         for (int i = 0; i < r; ++i) {
             for (int j = 0; j < c; ++j) {
                 if (table[i][j] == 2) {
                     uuu += 1;
                 }
             }
         }
 
         uuu = min(uuu, 10);
 
         cerr << "UUU: " << uuu << endl;
 
         bool globalPossible = false;
         int index = -1;
         for (int mask = 0; mask < (1 << uuu); ++mask) {
             vector<vector<int>> covered(r, vector<int>(c, 0));
             for (int i = 0; i < r; ++i) {
                 for (int j = 0; j < c; ++j) {
                     if (table[i][j] == 1) {
                         covered[i][j] = 1;
                     }
                     if (table[i][j] == 2) {
                         index += 1;
                     }
                     if (table[i][j] == 3 || (table[i][j] == 2 && ((mask & (1 << index)) == 0))) {
                         for (int l = j; l >= 0; --l) {
                             if (table[i][l] == 1) {
                                 break;
                             }
                             covered[i][l] += 1;
                         }
                         for (int l = j + 1; l < c; ++l) {
                             if (table[i][l] == 1) {
                                 break;
                             }
                             covered[i][l] += 1;
                         }
                     }
 
                     if (table[i][j] == 4 || (table[i][j] == 2 && ((mask & (1 << index)) == 1))) {
                         for (int l = i; l >= 0; --l) {
                             if (table[l][j] == 1) {
                                 break;
                             }
                             covered[l][j] += 1;
                         }
                         for (int l = i + 1; l < r; ++l) {
                             if (table[l][j] == 1) {
                                 break;
                             }
                             covered[l][j] += 1;
                         }
                     }
                 }
             }
 
             cerr << "PART3 finished" << endl;
 
             bool possible = true;
             for (int i = 0; i < r && possible; ++i) {
                 for (int j = 0; j < c && possible; ++j) {
                     if (covered[i][j] != 1 && table[i][j] != 0 && table[i][j] != 5 && table[i][j] != 6) {
                         possible = false;
                     }
                 }
             }
 
             if (possible) {
                 globalPossible = true;
             }
         }
         
         cerr << "PART4 finished" << endl;
 
         cout << "Case #" << tt << ": " << (globalPossible ? "POSSIBLE" : "IMPOSSIBLE") << endl;
         if (globalPossible) {
             for (int i = 0; i < r; ++i) {
                 for (int j = 0; j < c; ++j) {
                     if (table[i][j] == 1) {
                         cout << "#";
                     }
                     else if (table[i][j] == 2 || table[i][j] == 3) {
                         cout << "-";
                     }
                     else if (table[i][j] == 4) {
                         cout << "|";
                     }
                     else {
                         cout << ".";
                     }
                 }
                 cout << "\n";
             }
         } else {
             for (int i = 0; i < r; ++i) {
                 for (int j = 0; j < c; ++j) {
                     if (table[i][j] == 1) {
                         cerr << "#";
                     }
                     else if (table[i][j] == 2 || table[i][j] == 3) {
                         cerr << "-";
                     }
                     else if (table[i][j] == 4) {
                         cerr << "|";
                     }
                     else {
                         cerr << ".";
                     }
                 }
                 cerr << "\n";
             }
         }
     }
     
     return 0;
 }
