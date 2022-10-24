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
 
 int S;
 map<pii, int> M;
 int code[20000], code2[20000], fat[20000];
 
 int corner(pii p) {
     int S2 = 2 * S - 1;
     if (p.first == 1 && p.second == 1) {
         return 1;
     }
     if (p.first == S && p.second == 1) {
         return 2;
     }
     if (p.first == 1 && p.second == S) {
         return 3;
     }
     if (p.first == S2 && p.second == S) {
         return 4;
     }
     if (p.first == S && p.second == S2) {
         return 5;
     }
     if (p.first == S2 && p.second == S2) {
         return 6;
     }
     return 0;
 }
 
 int edge(pii p) {
     if (corner(p)) {
         return 0;
     }
     if (p.first == 1) {
         return 1;
     }
     if (p.second == 1) {
         return 2;
     }
     if (p.first == 2 * S - 1) {
         return 3;
     }    
     if (p.second == 2 * S - 1) {
         return 4;
     }
     if (p.second - p.first == S - 1) {
         return 5;
     }
     if (p.first - p.second == S - 1) {
         return 6;
     }
     return 0;
 }
 
 int d[6][2] = {0, 1, 1, 0, 1, 1, 0, -1, -1, 0, -1, -1};
 
 int gf(int r) {
     if (fat[r] != r) {
         int t = gf(fat[r]);
         fat[r] = t;
     }
     return fat[r];
 }
 
 int st[2000][2000], tot2;
 
 void gao(int i, int j) {
     if (i <= 0 || j <= 0) return;
     if (i >= 2 * S || j >= 2 * S) 
         return;
     if (i - j >= S || j - i >= S) return;
     if (st[i][j]) {
         return;
     }
     tot2++;
     st[i][j] = 1;
     REP(dir, 6) {
         int i2 = i + d[dir][0];
         int j2 = j + d[dir][1];
         pii p = make_pair(i2, j2);
         if (!st[i2][j2] && M.find(p) == M.end()) {
             gao(i2, j2);
         }
     }
 }
 int getR(int x) {
     //st.clear();
     memset(st, 0, sizeof st);
     int total = 3 * S * S - 3 * S + 1;
     tot2 = 0;;
     for (int i = 1; i <= 2 * S - 1; i ++) {
         int upper = i <= S ? 1 : i - S + 1;
         int ender = i <= S ? S + i - 1 : 2 * S - 1;
         for (int j = upper; j <= ender; j++) {
             pii p = make_pair(i, j);
             if (M.find(p) != M.end()) {
                 tot2++;
                 continue;
             }
             if (!st[i][j]) {
                 if (edge(p) || corner(p)) {
                     gao(i, j);
                 }
             }
             //printf("x%d y%d\n", i, j);
             /*
             tot2++;
             REP(dir, 3) {
                 pii p2 = make_pair(p.first + d[dir][0], p.second + d[dir][1]);
                 if (M.find(p2) == M.end()) {
                     st[p2.first][p2.second] = 1;
                 }
             }*/
         }
     }
     //printf("%d %d\n", total, tot2);
     return total != tot2;
 }
 
 int main(){
     int caseNumber;
     //scanf("%d", &caseNumber);
     cin>>caseNumber;
     REP(caseN, caseNumber) {
         int idx;
         cin>>S>>idx;
         M.clear();
         memset(code, 0, sizeof code); memset(code2, 0, sizeof code2);
         int fsh = 0;
         printf("Case #%d: ", caseN + 1);
         fprintf(stderr, "Case #%d: %d %d\n", caseN + 1, S, idx);
         int tot = 0;
         REP(_tmp, idx) {
             int x, y;
             cin>>x>>y;
             if (fsh == 1) {
                 continue;
             }
             pii p = make_pair(x, y);
             M[p] = _tmp;
             fat[_tmp] = _tmp;
             if (corner(p)) {
                 code[_tmp] |= 1 << corner(p);
             }
             if (edge(p)) {
                 code2[_tmp] |= 1 <<edge(p);
             }
             int C = 0;
             REP(dir, 6) {
                 int nx = x + d[dir][0], ny = y + d[dir][1];
                 pii p2 = make_pair(nx, ny);
                 if (M.find(p2)!= M.end()) {
                     int g = gf(M[p2]);
                     if (g == fat[_tmp]) {
                         C = 1;
                         continue;
                     }
                     fat[g] = fat[_tmp];
                     code[_tmp] |= code[g];
                     code2[_tmp] |= code2[g];
                 }
             }
             int B = __builtin_popcount(code[_tmp]) >= 2;
             int F = __builtin_popcount(code2[_tmp]) >= 3;
             int R = C ? getR(gf(_tmp)) : 0;
             if (B || F || R) {
                 fsh = 1;
                 int x = 0;
                 if (B) {
                     if (x) putchar('-');
                     printf("bridge"); x= 1;
                 }
                 if (F) {
                     if (x) putchar('-');
                     printf("fork");x = 1;
                 }
                 if (R) {
                     if (x) putchar('-');
                     printf("ring");
                 }
                 printf(" in move %d\n", _tmp + 1);
             }
         }
         if (!fsh) {
             puts("none");
         }
 
     }
     return 0;
 }