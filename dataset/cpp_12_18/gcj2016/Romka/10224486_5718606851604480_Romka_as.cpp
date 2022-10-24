#include <cstdio>
 #include <vector>
 #include <cmath>
 #include <set>
 #include <map>
 #include <algorithm>
 #include <cstring>
 #include <string>
 #include <iostream>
 #include <cassert>
 #include <memory.h>
 using namespace std;
 
 #define forn(i, n) for (int i = 0; i < (int)(n); i++)
 #define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
 #define pb push_back
 typedef long long ll;
 typedef pair<int, int> pii;
 typedef long double ld;
 
 
 void solve() {
     int n, p, r, s;
     scanf("%d %d %d %d", &n, &r, &p, &s);
     string ans = "";
     string a = "";
     forn(z, p) a += "P";
     forn(z, r) a += "R";
     forn(z, s) a += "S";
     do {
         string w = a;
         bool failed = false;
         while (w.size() > 1 && !failed) {
             string w2 = "";
             for (size_t i = 0; i < w.size(); i += 2) {
                 if (w[i] == w[i+1]) {
                     failed = true;
                     break;
                 }
                 if ((w[i] == 'P' && w[i+1] == 'R') || (w[i] == 'R' && w[i+1] == 'P')) w2 += 'P';
                 if ((w[i] == 'P' && w[i+1] == 'S') || (w[i] == 'S' && w[i+1] == 'P')) w2 += 'S';
                 if ((w[i] == 'S' && w[i+1] == 'R') || (w[i] == 'R' && w[i+1] == 'S')) w2 += 'R';
             }
             w = w2;
         }
         if (!failed) {
             ans = a;
             break;
         }
     } while (next_permutation(a.begin(), a.end()));
 
     if (ans.empty()) ans = "IMPOSSIBLE";
     printf("%s\n", ans.c_str());
 }
 
 int main() {
     int tc;
     scanf("%d", &tc);
     for (int q = 1; q <= tc; q++) {
         printf("Case #%d: ", q);
         solve();
     }
     return 0;
 }
 
