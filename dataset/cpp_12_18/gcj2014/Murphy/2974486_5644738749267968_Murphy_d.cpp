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
 
 int main(){
     int caseNumber;
     //scanf("%d", &caseNumber);
     cin>>caseNumber;
     REP(caseN, caseNumber) {
         int N; cin>>N;
         double r;
         vector<pii> V;
         int w2 = 0;
         REP(i, N) {
             cin>>r;
             V.push_back(make_pair((int)(r * 1000000), 0));
         }
         REP(i, N) {
             cin>>r;
             V.push_back(make_pair((int)(r * 1000000), 1));
         }
         sort(V.begin(), V.end(), greater<pii>());
         int c = 0;
         REP(i, V.size()) {
             if (V[i].second == 1) {
                 c++;
             } else {
                 if (c) {
                     c--; w2++;
                 }
             }
         }
 
         int w1 = 0;
         REP(cut, N + 1) {
             c = 0; 
             int w3 = 0;
             int cd = cut, cp = N - cut;
             int bad = 0;
             // cerr<<cut<<' '<<endl;
             REP(i, V.size()) {
                 if (V[i].second == 1) {
                     //enemy
                     if (cd) {
                         cd--; 
                     } else {
                         c--;
                     }
                     if (c < 0) bad = 1;
                 } else {
                     if (cp) {
                         cp--;
                         c++;
                     }
                 }
             }
             if (bad == 0)
             w1 = max(w1, N -  cut);
         }
         
         
     	printf("Case #%d: %d %d\n", caseN + 1, w1, N - w2);
     }
     return 0;
 }