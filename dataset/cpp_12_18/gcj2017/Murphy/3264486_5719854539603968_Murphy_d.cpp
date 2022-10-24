#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <string>
 #include <vector>
 #include <cmath>
 #include <algorithm>
 #include <cassert>
 #include <set>
 #include <map>
 #include <queue>
 #include <iostream>
 #include <fstream>
 using namespace std;
 #define pb push_back 
 #define REP(i,n) for(int i=0;i<(n);i++ )
 typedef long long LL;
 typedef pair<int, int> pii;
 
 const int MAXN = 250;
 #define _clr(x) memset(x, 0xff, sizeof(int) * MAXN)
 
 int hungary(int m, int n, const bool mat[][MAXN], int * match1, int * match2) {
     int s[MAXN + 1], t[MAXN], p, q, ret = 0, i, j, k;
     _clr(match1);
     _clr(match2);
     for (i = 0; i < m; ret += (match1[i++] >= 0)) {
         _clr(t);
         for (s[p = q = 0] = i; p <= q && match1[i] < 0; p++) {
             k = s[p];
             for (j = 0; j < n && match1[i] < 0; j++) {
                 if (mat[k][j] && t[j] < 0) {
                     s[++q] = match2[j];
                     t[j] = k;
                     if (s[q] < 0) {
                         for (p = j; p >= 0; j = p) {
                             match2[j] = k = t[j];
                             p = match1[k];
                             match1[k] = j;
                         }
                     }
                 }
             }
         }
     }
     return ret;
 }
 
 char g[128][128];
 char g2[128][128];
 
 
 int main(){
     int caseNumber;
     cin>>caseNumber;
     REP(caseN, caseNumber) {
         int N, M;
         cin>>N>>M;
         memset(g, ' ', sizeof g);
         memset(g2, ' ', sizeof g2);
         // map<pii, char> m;
         int value = 0;
         REP(i, M) {
             char c; int x, y;
             cin>>c>>x>>y; x--; y--;
             g[x][y] = g2[x][y] = c;
             if (c == '+' || c == 'x') value++;
             if (c == 'o') value += 2;
             // pii p = make_pair(x, y);
             // m[p] = c;
         }
         // cerr<<"value "<<value<<endl;
 
         // process row/column
         {
             vector<bool> x(MAXN, 0);
             vector<bool> y = x;
             REP(i, N) {
                 int vio = 0;
                 REP(j, N) 
                     vio += (g[i][j] != ' ' && g[i][j] != '+');
                 assert(vio <= 1);
                 x[i] = vio < 1;
             }
             REP(i, N) {
                 int vio = 0;
                 REP(j, N) 
                     vio += (g[j][i] != ' ' && g[j][i] != '+');
                 assert(vio <= 1);
                 y[i] = vio < 1;
             }
             bool gr[MAXN][MAXN];
             int mx[MAXN], my[MAXN];
             REP(i, N) REP(j, N) {
                 gr[i][j] = x[i] & y[j] & (g[i][j] != 'x' && g[i][j] != 'o');
                 // cerr<<"edge"<<i<<j<<gr[i][j]<<endl;
             }
             int add = hungary(N, N, gr, mx, my);
             // cerr<<"add 1 "<<add<<endl;
             value += add;
             REP(i, N)
                 if (mx[i] != -1) {
                     int j = mx[i];
                     // cerr<<"x"<<i<<j<<endl;
                     if (g[i][j] == ' ') g[i][j] = 'x';
                     else if (g[i][j] == '+') g[i][j] = 'o'; else assert(0);
                 }
         }
 
 
         // process diagonals
         {
             vector<bool> x(MAXN, 0);
             vector<bool> y = x;
             map<int, int> d1, d2;
             REP(i, N) {
                 REP(j, N) {
                     int t1 = i + j, t2 = i - j;
                     int vio = (g[i][j] != ' ' && g[i][j] != 'x');
                     d1[t1] += vio;
                     d2[t2] += vio;
                 }
             }
             for (auto it : d1) {
                 assert(it.second <= 1);
                 x[it.first] = it.second < 1;
             }
             for (auto it : d2) {
                 assert(it.second <= 1);
                 y[it.first + (N - 1)] = it.second < 1;
             }
             bool gr[MAXN][MAXN];
             memset(gr, 0, sizeof gr);
             int mx[MAXN], my[MAXN];
             REP(i, N) REP(j, N) {
                 int t1 = i + j, t2 = i - j + N - 1;
                 gr[t1][t2] = x[t1] & y[t2] & (g[i][j] != '+' && g[i][j] != 'o');
             }
             int add = hungary(2 * N, 2 * N, gr, mx, my);
             // cerr<<"add 2 "<<add<<endl;
             value += add;
             REP(i, 2 * N)
                 if (mx[i] != -1) {
                     int j = mx[i]; j -= N - 1;
                     int x = (i + j) / 2;
                     int y = i - x;
                     assert(x + y == i);
                     assert(x - y == j);
                     // cerr<<"x"<<x<<y<<endl;
                     if (g[x][y] == ' ') g[x][y] = '+';
                     else if (g[x][y] == 'x') g[x][y] = 'o'; else assert(0);
                 }
         }
         vector<pii> r;
         REP(i, N) REP(j, N)
             if (g[i][j] != g2[i][j]) {
                 r.pb(make_pair(i, j));
             }
         printf("Case #%d: %d %d\n", caseN + 1, value, (int)r.size());
         for (auto it : r) {
             printf("%c %d %d\n", g[it.first][it.second], it.first + 1, it.second + 1);
         }
     }
     return 0;
 }