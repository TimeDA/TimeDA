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
     freopen("3.in", "r", stdin);
     freopen("3.out", "w", stdout);
 }
 
 
 bool check(double limit, int n, double v, double t, const vector<double>& vol, const vector<double> temp) {
     double sumVol = 0.0;
     for (auto a : vol) {
         sumVol += a;
     }
 
     vector<double> x(n, v / sumVol);
     if (x[0] > limit) {
         return false;
     }
 
     double aim = v * t;
     double value = 0.0;
     for (int i = 0; i < n; ++i) {
         value += vol[i] * temp[i] * x[i];
     }
 
     if (std::abs(aim - value) < 1e-9) {
         return true;
     }
 
     //cerr << limit << " " << x[0] << " aim=" << aim << " value=" << value << endl;
 
     int start = 0;
     int end = n - 1;
     while (start < end) {
         if (value > aim) {
             double d = min((limit - x[start]) * vol[start], x[end] * vol[end]);
             double newValue = value + (d * temp[start]) - (d * temp[end]);
             if (newValue < aim + 1e-9) {
                 return true;
             } else {
                 value = newValue;
                 x[start] += d / vol[start];
                 assert(x[start] <= limit + 1e-9);
                 x[end] -= d / vol[end];
                 assert(x[end] >= -1e-9);
             }
             if (std::abs(x[start] - limit) < 1e-9) {
                 start += 1;
             }
             if (std::abs(x[end]) < 1e-9) {
                 end -= 1;
             }
         } else {
             double d = min(x[start] * vol[start], (limit - x[end]) * vol[end]);
             double newValue = value - (d * temp[start]) + (d * temp[end]);
             if (newValue > aim - 1e-9) {
                 return true;
             } else {
                 value = newValue;
                 x[start] -= d / vol[start];
                 assert(x[start] >= -1e-9);
                 x[end] += d / vol[end];
                 assert(x[end] <= limit + 1e-9);
             }
             if (std::abs(x[start]) < 1e-9) {
                 start += 1;
             }
             if (std::abs(x[end] - limit) < 1e-9) {
                 end -= 1;
             }
         }
     }
     return false;
 }
 
 int main()
 {
     initialize();
 
     int T;
     cin >> T;
     for (int tt = 1; tt <= T; ++tt) {
         int n;
         double v, t;
         cin >> n >> v >> t;
 
         bool hasLower = false, hasUpper = false;
 
         vector<pair<double, pair<double, double> > > input;
         for (int i = 0; i < n; ++i) {
             double a, b;
             cin >> a >> b;
             if (b >= t - 1e-8) {
                 hasUpper = true;
             }
             if (b <= t + 1e-8) {
                 hasLower = true;
             }
             input.pb(make_pair(b, make_pair(a, b)));
         }
 
         sort(all(input));
 
         vector<double> vol, temp;
         for (auto pair : input) {
             vol.pb(pair.second.first);
             temp.pb(pair.second.second);
         }
 
         //cerr << vol[0] << " " << temp[0] << endl;
         //cerr << vol[1] << " " << temp[1] << endl;
 
         if (!hasLower || !hasUpper) {
             cout << "Case #" << tt << ": IMPOSSIBLE\n";
             continue;
         }
 
         //cerr << "CASE " << tt << endl;
 
         double lower = 1e-10, upper = 1e10;
         while (lower != upper) {
             double med = (lower + upper) / 2.0;
             if (med == lower || med == upper) { 
                 break;
             }
             if (check(med, n, v, t, vol, temp)) {
                 upper = med;
             } else {
                 lower = med;
             }
         }
         cout << "Case #" << tt << ": ";
         printf("%.10lf\n", upper);
     }
     
     return 0;
 }
