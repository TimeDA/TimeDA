
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
 #define ALLOF(s) ((s).begin()), ((s).end())
 
 typedef long long ll;
 
 
 int ds[10000+10];
 int lens[10000+10];
 int vs[10000+10];
 
 int main(void) {
   int nCases;
   cin >> nCases;
   REP(iCase, nCases) {
     int n;
     cin >> n;
     REP(i, n){
       cin >> ds[i] >> lens[i];
     }
     memset(vs, -1, sizeof vs);
     
     int dist;
     cin >> dist;
     
     vs[0] = ds[0];
     bool ok = false;
     for(int i = 0; i < n; ++i){
       if(vs[i] < 0)
 	continue;
       if(ds[i] + vs[i] >= dist){
 	ok = true;
 	break;
       }
 
       for(int j = i + 1; j < n; ++j){
 	if(ds[i] + vs[i] >= ds[j]){
 	  vs[j] = max(vs[j], min(lens[j], ds[j] - ds[i]));
 	}else{
 	  break;
 	}
       }
     }
     
     cout << "Case #" << (iCase+1) << ": " << (ok ? "YES" : "NO") << endl;
   }
   
   return 0;
 }
