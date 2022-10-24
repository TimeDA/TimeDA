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
 
 int R, C;
 char g[100][100];
 int d[3][2] = {-1, 0, 0, -1, 0, 1};
 int d2[3][2] = {1, 0, 0, -1, 0, 1};
 int xx, yy;
 
 int gao2(set<pii> s, int L) {
     if (s.size() == 1) {
         for (set<pii>::iterator it = s.begin(); it != s.end(); it++) {
             int x = it->first, y = it->second;
             if (x == xx && y == yy) {
     //~ cout<<s.size()<<' '<<L<<endl;
                 return 1;
             }
         }
         return 0;
     }
     if (L == 12) {
         return 0;
     }
     REP(D, 3) {
         set<pii> S2;
         for (set<pii>::iterator it = s.begin(); it != s.end(); it++) {
             int x = it->first, y = it->second;
             int x2 = x + d2[D][0], y2 = y + d2[D][1];
             if (g[x2][y2] == '#') {
                 x2 = x;
                 y2 = y;
             }
             S2.insert(make_pair(x2, y2));
         }
         if (gao2(S2, L + 1)) {
             return 1;
         }
     }
 }
 
 int main(){
     int caseNumber;
     scanf("%d", &caseNumber);
     //cin>>caseNumber;
     REP(caseN, caseNumber) {
         scanf("%d%d", &R, &C);
         REP(i, R) {
             scanf("%s", g[i]);
         }
         printf("Case #%d:\n", caseN + 1);
         REP(cv, 10) {
             int x = -1, y;
             REP(i, R) REP(j, C) if (g[i][j] == ('0' + cv)) {
                 x = i; y = j;
             }
             if (x == -1) {
                 break;
             }
             set<pii> S;
             vector<pii> v;
             S.insert(make_pair(x, y));
             v.pb(make_pair(x, y));
             //~ int d[3][2] = {-1, 0, 0, -1, 0, 1};
             while (1) {
                 int updated = 0, sz = S.size();
                 REP(i, sz) {
                     int x = v[i].first, y = v[i].second;
                     REP(D, 3) {
                         int x2 = x + d[D][0], y2 = y + d[D][1];
                         pii p = make_pair(x2, y2);
                         if (S.find(p) == S.end()) {
                             if (g[x2][y2] != '#') {
                                 S.insert(p);
                                 updated = 1;
                                 v.pb(p);
                             }
                         }
                     }
             
                 }
                 if (!updated) {
                     break;
                 }
             }
             xx = x; yy = y;
             int r = gao2(S, 0);
             //~ 0: 9 Lucky
             printf("%d:%d %s\n", cv, S.size(), r ? "Lucky" : "Unlucky");
             fprintf(stderr, "%d:%d %s\n", cv, S.size(), r ? "Lucky" : "Unlucky");
         }
     }
     return 0;
 }
