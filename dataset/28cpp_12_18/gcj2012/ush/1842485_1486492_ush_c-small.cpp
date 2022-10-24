
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
 
 
 int n;
 int vs[2010];
 int ans[2010];
 
 bool solve(int i) {
   if(i == -1){
     return true;
   }else{
     
     REP(k, 11){
       ans[i] = k;
       bool ok = true;
 
       // test
       for(int j = i+1; j < n; ++j){
 	if(j < vs[i]){
 	  if(ans[j] >= ans[i] + (ans[vs[i]] - ans[i])*1.0/(vs[i]-i)*(j-i)){
 	    ok = false;
 	    break;
 	  }
 	}else if(vs[i] < j){
 	  if(ans[j] > ans[i] + (ans[vs[i]] - ans[i])*1.0/(vs[i]-i)*(j-i)){
 	    ok = false;
 	    break;
 	  }
 	}
       }
       
       if(ok){
 	if(solve(i-1)){
 	  return true;
 	}
       }
     }
   }
   return false;
 }
 
 int main(void) {
   int nCases;
   cin >> nCases;
   REP(iCase, nCases) {
     cin >> n;
     REP(i, n-1){
       cin >> vs[i];
       --vs[i];
     }
     
     
     bool ok = false;
     REP(times, 10000000){
       ok = true;
       REP(i, n){
 // 	ans[i] = rand() % 1000000001;
 	ans[i] = rand() /4 % 1030;
       }
       REP(i, n-2){
 	for(int j = i + 1; j < n; ++j){
 	  if(j < vs[i]){
 	    if(ans[j] >= vs[i]){
 	      ok = false;
 	      break;
 	    }
 	    if(ans[j] >= ans[i] + (ans[vs[i]] - ans[i])*1.0/(vs[i]-i)*(j-i)){
 	      ok = false;
 	      break;
 	    }
 	  }else if(vs[i] < j){
 	    if(ans[j] >= ans[i] + (ans[vs[i]] - ans[i])*1.0/(vs[i]-i)*(j-i)){
 	      ok = false;
 	      break;
 	    }
 	  }
 	}
 	
 	if(ok == false)
 	  break;
       }
       if(ok)
 	break;
     }
     
     cout << "Case #" << (iCase+1) << ":";
     if(solve(n-1)){
       REP(i, n){
 	cout << " " << ans[i];
       }
     }else{
       cout << " Impossible";
     }
     cout << endl;
   }
   
   return 0;
 }
