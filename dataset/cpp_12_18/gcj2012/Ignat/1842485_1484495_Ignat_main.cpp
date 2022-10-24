#ifdef DEBUG_OUTPUT
 #include "debug_output.h"
 #else
 #define DEBUG(x)
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
     freopen("_.out", "w", stdout);
 }
 
 struct Circle {
     Circle(): r(-1), num(-1) {}
     Circle(int r_, int num_): r(r_), num(num_) {}
     int r;
     int num;
 
     bool operator < (const Circle& c) const {
         return r < c.r;
     }
 };
 
 const int MAX = 10000;
 Circle c[MAX];
 
 double xRes[MAX];
 double yRes[MAX];
 int n;
 double w, l;
 
 void add(int ind, int x, int y) {
     xRes[c[ind].num] = x;
     yRes[c[ind].num] = y;
 }
 
 bool check() {
     for (int i = 0; i < n; ++i) {
         if (xRes[i] < 0 || xRes[i] > w) {
             cerr <<"X ERROR" << endl;
             return false;
         }
         if (yRes[i] < 0 || yRes[i] > l) {
             cerr <<"Y ERROR" << endl;
             return false;
         }
         for (int j = 0; j < i; ++j) {
             int ii = c[i].num;
             int jj = c[j].num;
             if (sqrt(sqr(double(xRes[ii] - xRes[jj])) + sqr(double(yRes[ii] - yRes[jj]))) < c[i].r + c[j].r - 1e-7) {
                 cerr << "INTER" << endl;
                 cerr << "Point: " << xRes[ii] << " " << yRes[ii] << ", rad: " <<c[i].r << endl;;
                 cerr << "Point: " << xRes[jj] << " " << yRes[jj] << ", rad: " <<c[j].r << endl;;
                 return false;
             }
         }
     }
     return true;
 }
 
 int main()
 {
     initialize();
 
     int T;
     cin >> T;
     for (int tt = 1; tt <= T; ++tt) {
         cerr << "TEST " << tt << endl;
         cin >> n >> w >> l;
         for (int i = 0; i < n; ++i) {
             int num;
             cin >> num;
             c[i] = Circle(num, i);
         }
         sort(c, c + n);
         reverse(c, c + n);
 
         double curX = 0;
         double curY = 0;
         double largest  = 0;
         for (int i = 0; i < n; ++i) {
             largest = max(largest, double(c[i].r));
             add(i, curX, curY);
             if (i + 1 == n) continue;
             curY += c[i].r;
             double nextR = c[i + 1].r;
             curY += nextR;
             if (curY > l) {
                 curX += largest + nextR;
                 curY = 0;
                 largest = 0;
             }
         }
 
         check();
         printf("Case #%d: ", tt);
         for (int i = 0; i < n; ++i) {
             printf("%.8lf %.8lf", xRes[i], yRes[i]); 
             if (i + 1 < n) printf(" ");
             else printf("\n");
         }
 
     }
     
     return 0;
 }
