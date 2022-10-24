
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
 typedef complex<double> P;
 
 pair<ll, int> vs[1000+10];
 P ans[1000+10];
 int n;
 ll W, H;
 const double EPS = 1e-3;
 
 inline bool isOK(double x, double y, ll idx) {
   if(x < 0 || W < x || y < 0 || H < y) return false;
   P pi(x, y);
   ll r = vs[idx].first;
   
   REP(i, idx){
     const P& p = ans[vs[i].second];
     if(abs(p-pi) <= vs[i].first + r){
       return false;
     }
   }
   return true;
 }
 
 int main(void) {
   int nCases;
   cin >> nCases;
   REP(iCase, nCases) {
     cin >> n >> W >> H;
     REP(i, n){
       cin >> vs[i].first;
       vs[i].second = i;
       ans[i] = P(-1, -1);
     }
     sort(vs, vs + n);
     reverse(vs, vs + n);
     
     ans[vs[0].second] = P(0,0);
     double x0 = vs[0].first;
     double y0 = vs[0].first;
     if(n > 1){
       ans[vs[1].second] = P(W, H);
       double x1 = W - vs[1].first;
       double y1 = H - vs[1].first;
       for(int i = 2; i < n; ++i){
 	ll r = vs[i].first;
 	double x = x0 + r;
 	if(isOK(x+EPS, 0, i)){
 	  ans[vs[i].second] = P(x+EPS, 0);
 	  x0 += 2*r;
 	  continue;
 	}
 	double y = y0 + r;
 	if(isOK(0, y+EPS, i)){
 	  ans[vs[i].second] = P(0, y+EPS);
 	  y0 += 2*r;
 	  continue;
 	}
 	x = x1 - r;
 	if(isOK(x-EPS, H, i)){
 	  ans[vs[i].second] = P(x-EPS, H);
 	  x1 -= 2*r;
 	  continue;
 	}
 
 	y = y1 - r;
 	if(isOK(W, y-EPS, i)){
 	  ans[vs[i].second] = P(W, y-EPS);
 	  y1 -= 2*r;
 	  continue;
 	}
 	
 	bool ok = false;
 	REP(xd, 100){
 	  REP(yd, 100){
 	    x = W / 100 * xd;
 	    y = H / 100 * yd;
 	    if(isOK(x, y, i)){
 	      ok = true;
 	      ans[vs[i].second] = P(x, y);
 	      goto HOGE;
 	    }
 	  }
 	}
 	
       HOGE:
 	if(!ok){
 	  assert(false);
 	}
       }
     }
     
     printf("Case #%d:", iCase+1);
     REP(i, n){
       printf(" %.7f %.7f", ans[i].real(), ans[i].imag());
     }
     puts("");
   }
   
   return 0;
 }
