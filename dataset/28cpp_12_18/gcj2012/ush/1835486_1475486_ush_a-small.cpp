
 #include <cstdio>
 #include <iostream>
 #include <sstream>
 #include <string>
 #include <cstring>
 #include <cctype>
 #include <algorithm>
 #include <vector>
 #include <map>
 #include <queue>
 #include <set>
 #include <list>
 #include <cmath>
 #include <complex>
 #include <numeric>
 #include <cassert>
 using namespace std;
 
 #define REP(i,n) for(int i = 0; i < (int)(n); ++i)
 #define FOR(i,s) for(__typeof((s).begin()) i = (s).begin(); i != (s).end(); ++i)
 
 typedef long long ll;
 
 int n;
 pair<int,int> vs[1010];
 
 int main(void) {
   int nCases;
   cin >> nCases;
   REP(iCase, nCases) {
     cin >> n;
     REP(i, n){
       int v;
       cin >> v;
     }
 
     REP(i, n){
       int p;
       cin >> p;
       vs[i] = make_pair(100-p, i);
     }
     sort(vs, vs + n);
     
     cout << "Case #" << (iCase+1) << ":";
     REP(i, n){
       cout << " " << vs[i].second;
     }
     cout << endl;
   }
   
   return 0;
 }
