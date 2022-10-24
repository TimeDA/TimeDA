
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
 
 
 ll ts[300];
 ll ps[300];
 ll money, fee;
 
 vector<pair<ll, ll> > vs;
 
 ll calc(ll nFee) {
   ll res = 0;
   ll curM = money - nFee * fee;
   if(curM <= 0)
     return 0;
 
   ll lastT = 0;
   REP(i, vs.size()){
     ll v = (vs[i].first+1 - lastT) * vs[i].second * nFee;
     ll num = (vs[i].first+1 - lastT) * nFee;
 
     if(v > curM){
       num = curM / vs[i].second;
     }
 
     res += num;
     curM -= num * vs[i].second;
   }
   
   return res;
   
 }
 
 
 int main(void) {
 
   int nCases;
   cin >> nCases;
   REP(iCase, nCases) {
     int n;
     cin >> money >> fee >> n;
     REP(i, n){
       cin >> ps[i] >> ts[i];
     }
     
     vs.clear();
     REP(i, n){
       bool ok = true;
       REP(j, n){
 	if(i == j)
 	  continue;
 	
 	if(ts[i] < ts[j] && ps[i] >= ps[j] ||
 	   ts[i] <= ts[j] && ps[i] > ps[j] ||
 	   ts[i] == ts[j] && ps[i] == ps[j] && i < j){
 	  ok = false;
 	  break;
 	}
       }
 
       if(ok)
 	vs.push_back(make_pair(ts[i], ps[i]));
     }
 
     ll res = 0;
     ll left = 0;
     ll right = money / fee + 1;
 //     for(ll i = 1; ; ++i){
 //       ll tmp = calc(i);
 //       if(tmp == 0)
 // 	break;
 //       res = max(res, calc(i));
 //     }
     
     while(left+2 < right) {
       ll m1 = (left*2 + right) / 3;
       ll m2 = (left + right*2) / 3;
       ll v1 = calc(m1);
       ll v2 = calc(m2);
       res = max(res, max(v1, v2));
       if(v1 < v2){
 	left = m1;
       }else{
 	right = m2;
       }
     }
     REP(i, 200000){
       res = max(res, calc(left-100000+i));
     }
 //     res = max(res, calc(left-4));
 //     res = max(res, calc(left-3));
 //     res = max(res, calc(left-2));
 //     res = max(res, calc(left-1));
 //     res = max(res, calc(left));
 //     res = max(res, calc(left+1));
 //     res = max(res, calc(left+2));
 //     res = max(res, calc(left+3));
 //     res = max(res, calc(left+4));
     
     cout << "Case #" << (iCase+1) << ": " << res << endl;
   }
   
   return 0;
 }
