
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
 
 
 long long inv(int a, int p) { return a==1 ? 1 : (1-p*inv(p%a,a))/a+p; }
 static const int MODVAL = 1000002013;
 struct mint {
   int val;
   mint():val(0){}
   mint(int x):val(x%MODVAL) {}
   mint(size_t x):val(x%MODVAL) {}
   mint(long long x):val(x%MODVAL) {}
   mint& operator+=(mint y) { val=(val+y.val)%MODVAL; return *this; }
   mint& operator-=(mint y) { val=(val-y.val+MODVAL)%MODVAL; return *this; }
   mint& operator*=(mint y) { val=((long long)val*y.val)%MODVAL; return *this; }
   mint& operator/=(mint y) { val=(val*inv(y.val,MODVAL))%MODVAL; return *this; }
 };
 inline mint operator+(mint x, mint y) { return x+=y; }
 inline mint operator-(mint x, mint y) { return x-=y; }
 inline mint operator*(mint x, mint y) { return x*=y; }
 inline mint operator/(mint x, mint y) { return x/=y; }
 mint POW(mint x, long long n) { mint r(1); for(;n;x*=x,n>>=1) if(n&1) r*=x; return r; }
 mint FAC(int n) { static vector<mint> FAC_(1,1);
   while(int(FAC_.size())<=n) FAC_.push_back(FAC_.back()*FAC_.size()); return FAC_[n]; }
 inline mint CMB(int n, int k) { return k<0||n<k ? 0 : FAC(n) / (FAC(k) * FAC(n-k)); }
 inline ostream& operator<<(ostream& os, mint a) { return os << a.val; }
 
 
 
 struct K{
   ll pos;
   ll num;
   int type;
 };
 bool operator<(const K& a, const K& b) {
   if(a.pos != b.pos) return a.pos < b.pos;
   return a.type < b.type;
 }
 ll n;
 
 inline mint dist(ll a, ll b) {
   mint d = b - a;
   return d*(n+n-d+1)/2;
 }
 
 int main(void) {
   int nCases;
   cin >> nCases;
   REP(iCase, nCases) {
     int M;
     cin >> n >> M;
     
     vector<K> evs;
     mint total = 0;
     REP(i, M){
       ll o, e, p;
       cin >> o >> e >> p;
       evs.push_back((K){o, p, 0});
       evs.push_back((K){e, p, 1});
       total += p*dist(o, e);
     }
     sort(evs.begin(), evs.end());
     
     vector<pair<ll,ll> > st;
     mint res = 0;
     REP(i, evs.size()){
       K cur = evs[i];
       if(cur.type == 0){ // ride
 	st.push_back(make_pair(cur.pos, cur.num));
       }else{
 	while(cur.num > 0){
 	  pair<ll,ll> p = st.back();
 	  st.pop_back();
 	  ll consume = min(p.second, cur.num);
 	  res += consume * dist(p.first, cur.pos);
 // 	  cerr << consume << " * " << p.first << "->" << cur.pos << " : res = " << res << endl;
 	  p.second -= consume;
 	  cur.num -= consume;
 	  if(p.second > 0){
 	    st.push_back(p);
 	  }
 	}
       }
     }
     
     cout << "Case #" << (iCase+1) << ": " << total - res << endl;
   }
   
   return 0;
 }
