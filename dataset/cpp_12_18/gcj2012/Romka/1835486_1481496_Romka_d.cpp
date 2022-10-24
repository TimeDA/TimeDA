#include <cstdio>
 #include <vector>
 #include <cmath>
 #include <set>
 #include <map>
 #include <algorithm>
 #include <cstring>
 #include <string>
 #include <iostream>
 #include <memory.h>
 using namespace std;
 
 #define forn(i, n) for (int i = 0; i < (int)(n); i++)
 #define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
 #define pb push_back
 typedef long long ll;
 typedef pair<int, int> pii;
 typedef long double ld;
 
 int g[256][256];
 char s[1010];
 int in[256], out[256];
 map<char, char> tt;
 
 void solve() {
     scanf("%*d");
     scanf("%s", s);
     int n = strlen(s);
 
     memset(g, 0, sizeof(g));
 
     int mx = 'z' + 1;
     forn(i, n-1) {
         vector<int> v1, v2;
         v1.pb(s[i]);
         if (tt.find(s[i]) != tt.end()) v1.pb(tt[ s[i] ]);
         v2.pb(s[i+1]);
         if (tt.find(s[i+1]) != tt.end()) v2.pb(tt[ s[i+1] ]);
 
         forn(i1, v1.size())
             forn(i2, v2.size()) {
                 // printf("%d -> %d\n", v1[i1], v2[i2]);
                 g[v1[i1]][v2[i2]] = 1;
             }
     }
 
     forn(i, mx)
         out[i] = in[i] = 0;
 
     forn(i, mx)
         forn(j, mx)
             if (g[i][j]) {
                 out[i]++;
                 in[j]++;
             }
 
     forn(i, mx)
         if (out[i] != in[i]) {
             if (in[i] < out[i]) g[0][i] = out[i] - in[i], out[0] += out[i] - in[i];
             else g[i][0] = in[i] - out[i], in[0] += in[i] - out[i];
         }
 
     int ans = 0;
     forn(i, mx)
         forn(j, mx) if (j)
             ans += g[i][j];
     if (out[0] == 0) ans++;
 
     printf("%d\n", ans);
 }
 
 int main() {
     tt['o'] = '0';
     tt['i'] = '1';
     tt['e'] = '3';
     tt['a'] = '4';
     tt['s'] = '5';
     tt['t'] = '7';
     tt['b'] = '8';
     tt['g'] = '9';
     int tc;
     scanf("%d", &tc);
     for (int q = 1; q <= tc; q++) {
         printf("Case #%d: ", q);
         solve();
     }
 }
