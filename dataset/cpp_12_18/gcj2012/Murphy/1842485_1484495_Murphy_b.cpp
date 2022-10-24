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
 
 int X[1024], Y[1024], R[1024];
 pii r[1024];
 
 int main(){
     int caseNumber;
     scanf("%d", &caseNumber);
     //cin>>caseNumber;
     REP(caseN, caseNumber) {
         int N, W, L;
         scanf("%d%d%d", &N, &W, &L);
         REP(i, N) {
             int tmp;
             scanf("%d", &tmp);
             R[i] = tmp;
             r[i] = make_pair(-tmp, i);
         }
         sort(r, r + N);
         int px, py, x = -1, y = -1, x2 = 0;
         REP(i, N) {
             int rr = -r[i].first, idx = r[i].second;
             rc:;
             if (x == -1) {
                 px = 0;
             } else {
                 px = x + rr;
             }
             if (y == -1) {
                 py = 0;
             } else {
                 py = y + rr;
             }
             if (py > L) {
                 x = x2;
                 y = -1;
                 goto rc;
             }
             X[idx] = px; Y[idx] = py;
             x2 = max(x2, px + rr);
             //~ if (y == -1) y= 0;
             y = py + rr;
         }
         if (1) {
             printf("Case #%d: ", caseN + 1);
             REP(i, N) {
                 printf("%d %d ", X[i], Y[i]);
             }
             puts("");
         } else {
             printf("%d %d %d\n", N, W, L);
             REP(i, N) {
                 printf("%d %d %d\n", R[i], X[i], Y[i]);
             }
             puts("");
             puts("");
         }
     }
     return 0;
 }
