
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
 
 
 ll xs[50];
 int n;
 
 
 int main(void) {
   int nCases;
   cin >> nCases;
   REP(iCase, nCases) {
     ll iniMoney;
     scanf("%lld%d", &iniMoney, &n);
     memset(xs, 0, sizeof xs);
     REP(i, n)
       scanf("%lld", &xs[i]);
     sort(xs, xs + 37);
     
     double ans = 0;
     for(ll won = 1; won <= 10000; ++won){
       int use = 0;
       int cnt = 0;
       REP(i, 37){
 	if(xs[i] <= won){
 	  use += won - xs[i];
 	  cnt++;
 	}
       }
       
       if(use > iniMoney)
 	break;
       if(cnt == 0)
 	continue;
       double res = -use;
       double rate = 36.0 / cnt;
       REP(i, 37){
 	if(xs[i] <= won)
 	  res += (won - xs[i]) * rate;
       }
 //       cerr << res << endl;
       if(ans < res){
 	ans = res;
       }
     }
     
     
     
     printf("Case #%d: %.12f\n", iCase+1, ans);
   }
   
   return 0;
 }
