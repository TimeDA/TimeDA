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
     cin>>caseNumber;
     REP(caseN, caseNumber) {
         int N, K; cin>>N>>K;
         double U; cin>>U;
         vector<double> P(N, 0);
         REP(i, N) cin>>P[i];
         double L = 0, R = 1;
         REP(r, 500) {
             double M = (L + R) / 2;
             double s = 0;
             REP(i, N) s += max(0.0, M - P[i]);
             if (s > U) R = M; else L = M;
         }
         double succ = 1;
         REP(i, N)
             succ *= max(R, P[i]);
         printf("Case #%d: %.10lf\n", caseN + 1, succ);
         
     }
     return 0;
 }