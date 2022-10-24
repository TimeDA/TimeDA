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
 
 vector<pair<int, LL>> c[19];
 vector<LL> r;
 
 int main(){
     REP(i, 10) {
         if (i) {
             c[1].pb(make_pair(i, i));
             r.pb(i);
         }
     }
     LL times = 1;
     for (int i = 1; i < 18; i++) {
         times *= 10;
         for (auto& n : c[i]) {
             for (int a = 1; a <= n.first; a++) {
                 LL nn = a * times + n.second;
                 c[i + 1].pb(make_pair(a, nn));
                 r.pb(nn);
             }
         }
     }
     sort(r.begin(), r.end());
     // cerr<<r.size()<<endl;
     // cerr<<r[r.size() - 1]<<endl;
     int caseNumber;
     cin>>caseNumber;
     REP(caseN, caseNumber) {
         LL N; cin>>N;
         if (N < 10) {
             printf("Case #%d: %lld\n", caseN + 1, N); continue;
         }
         auto it = upper_bound(r.begin(), r.end(), N);
         it--;
         LL res = *it;
         printf("Case #%d: %lld\n", caseN + 1, res);
     }
     return 0;
 }