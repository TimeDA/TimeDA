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
     freopen("0.in", "r", stdin);
     freopen("0.out", "w", stdout);
 }
 
 int trieSize(const vector<string>& ss) {
     vector<vector<int>> nodes;
     auto next = [&] (int index, char c) -> int {
         if (nodes[index][c] == -1) {
             nodes[index][c] = nodes.size();
             nodes.pb(vector<int>(26, -1));
         }
         return nodes[index][c];
     };
     nodes.pb(vector<int>(26, -1));
 
     for (int i = 0; i < ss.size(); ++i) {
         int cur = 0;
         for (int j = 0; j < ss[i].size(); ++j) {
             cur = next(cur, ss[i][j] - 'A');
         }
     }
 
     if (nodes.size() == 1) {
         return 0;
     }
 
     return nodes.size();
 }
 
 void solve(const vector<string>& all, int index, vector<vector<string>>& partition, int& bestSize, int& bestSizeCount)
 {
     if (index == all.size()) {
         int size = 0;
         for (int i = 0; i < partition.size(); ++i) {
             size += trieSize(partition[i]);
         }
 
         if (size > bestSize) {
             bestSize = size;
             bestSizeCount = 0;
         }
         
         if (size == bestSize) {
             bestSizeCount += 1;
         }
 
         return;
     }
 
     for (int i = 0; i < partition.size(); ++i) {
         partition[i].pb(all[index]);
         solve(all, index + 1, partition, bestSize, bestSizeCount);
         partition[i].pop_back();
     }
 }
 
 int main()
 {
     initialize();
 
     int T;
     cin >> T;
     for (int tt = 1; tt <= T; ++tt) {
         cerr << tt << endl;
         int n, m;
         cin >> n >> m;
         vector<string> all;
         for (int i = 0; i < n; ++i) {
             string s;
             cin >> s;
             all.pb(s);
         }
 
         vector<vector<string>> partition(m);
         int bestSize = -1;
         int bestSizeCount = 0;
         
         solve(all, 0, partition, bestSize, bestSizeCount);
 
         cout << "Case #" << tt << ": " << bestSize << " " << bestSizeCount << endl;
     }
     
     return 0;
 }
