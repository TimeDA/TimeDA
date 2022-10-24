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
 
 // #define pi 3.14159265358979323846
 
 const double pi = acos(0) * 2;
 
 int main(){
     int caseNumber;
     cin>>caseNumber;
     REP(caseN, caseNumber) {
         int N, K; cin>>N>>K;
         vector<double> R(N, 0), H(N, 0);
         REP(i, N) cin>>R[i]>>H[i];
         double res = 0;
         REP(i, N) {
             double cur = pi * R[i] * R[i];
             cur += 2 * pi * R[i] * H[i];
             vector<double> t;
             REP(j, N)
                 if (R[j] <= R[i] && j != i)
                     t.pb(R[j] * H[j]);
             sort(t.begin(), t.end());
             // cerr<<cur<<' '<<t.size()<<endl;
             REP(j, min(K - 1, (int)t.size())) {
                 cur += 2 * pi * t[t.size() - 1 - j];
                 // cerr<<'x'<<j<<' '<<cur<<' '<<t[t.size() - 1 - j]<<endl;
             }
             // cerr<<cur<<endl;
             res = max(res, cur);
         }
         printf("Case #%d: %.10lf\n", caseN + 1, res);
     }
     return 0;
 }