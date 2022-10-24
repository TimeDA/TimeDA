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
 
 string s[128];
 
 int main(){
     int caseNumber;
     //scanf("%d", &caseNumber);
     cin>>caseNumber;
     REP(caseN, caseNumber) {
         int n, m; cin>>n>>m; int res = 0, good = 1;
         int d[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
         REP(i, n) cin>>s[i];
         REP(i, n)
             REP(j, m)
                 if (s[i][j] != '.') {
                     int p[4] = {0, 0, 0, 0}, sp = 0;
                     REP(dir, 4) {
                         int x = i, y = j;
                         while (1) {
                             x += d[dir][0]; y += d[dir][1];
                             if (x < 0 || y < 0 || x >= n || y >= m) {
                                 break;
                             }
                             if (s[x][y] != '.') {
                                 p[dir] = 1; break;
                             }
                         }
                     }
                     int cdir;
                     if (s[i][j] == '^') cdir = 0;
                     if (s[i][j] == 'v') cdir = 1;
                     if (s[i][j] == '>') cdir = 2;
                     if (s[i][j] == '<') cdir = 3;
                     if (p[cdir] == 0) res++;
                     sp = p[0] + p[1] + p[2] + p[3] - p[cdir];
                     if (p[cdir] == 0 && sp == 0) good = 0;
                 }
         if (good)
     	    printf("Case #%d: %d\n", caseN + 1, res);
         else
             printf("Case #%d: IMPOSSIBLE\n", caseN + 1);
     }
     return 0;
 }