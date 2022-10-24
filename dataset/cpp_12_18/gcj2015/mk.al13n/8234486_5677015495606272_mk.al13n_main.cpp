#define _CRT_SECURE_NO_DEPRECATE
 #define _USE_MATH_DEFINES
 #include <iostream>
 #include <fstream>
 #include <cstdio>
 #include <cstdlib>
 #include <cassert>
 #include <climits>
 #include <ctime>
 #include <numeric>
 #include <vector>
 #include <algorithm>
 #include <bitset>
 #include <cmath>
 #include <cstring>
 #include <iomanip>
 #include <complex>
 #include <deque>
 #include <functional>
 #include <list>
 #include <map>
 #include <string>
 #include <sstream>
 #include <set>
 #include <stack>
 #include <queue>
 using namespace std;
 typedef long long LL;
 typedef unsigned long long ULL;
 typedef unsigned int uint;
 typedef unsigned char uchar;
 typedef long double ld;
 typedef pair<int, int> pii;
 typedef pair<short, short> pss;
 typedef pair<LL, LL> pll;
 typedef pair<ULL, ULL> puu;
 typedef pair<ld, ld> pdd;
 template<class T> inline T sqr(T x) { return x * x; }
 template<class T> inline string tostr(const T & x) { stringstream ss; ss << x; return ss.str(); }
 inline LL parse(const string & s) { stringstream ss(s); LL x; ss >> x; return x; }
 #define left asdleft
 #define right asdright
 #define link asdlink
 #define unlink asdunlink
 #define next asdnext
 #define prev asdprev
 #define y0 asdy0
 #define y1 asdy1
 #define mp make_pair
 #define pb push_back
 #define sz(x) ((int)(x).size())
 #define all(x) (x).begin(), (x).end()
 #define clr(ar,val) memset(ar, val, sizeof(ar))
 #define istr stringstream
 #define forn(i,n) for(int i=0;i<(n);++i)
 #define forv(i,v) forn(i,sz(v))
 #define X first
 #define Y second
 #define hash asdhash
 #define move asdmove
 const ld eps = 1e-12;
 const int inf = 1000*1000*1000;
 const char cinf = 102;
 const LL linf = inf * 1ll * inf;
 const ld dinf = 1e200;
 const ld PI = 3.1415926535897932384626433832795l;
 int gcd(int a,int b){return a?gcd(b%a,a):b;}
 LL gcd(LL a,LL b){return a?gcd(b%a,a):b;}
 LL powmod(LL a,LL p,LL m){LL r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
 bool isprime(LL a){for (LL i=2;i*i<=a;++i){if(a%i==0)return false;}return true;}
 #define FAIL { cerr<<"assertion failed on line "<<__LINE__<<endl; exit(123);}
 
 const LL mod=inf+7;
 
 LL solve(int n,int m){
     map<vector<pair<char,char>>,LL> dp;
     dp[vector<pair<char,char>>(n,mp(0,0))]=1;
     forn(q,m){
       forn(i,n){
 	map<vector<pair<char,char>>,LL> ndp;
 	for(const auto &it:dp){
 	  const vector<pair<char,char>> &s=it.X;
 	  LL d=it.Y;
 	  for(int x=1;x<=3;++x){
 	    auto ss=s;
 	    int c=0;
 	    bool ok=true;
 	    if(i && ss[i-1].X==x){
 	      ++ss[i-1].Y;
 	      ++c;
 	      if(ss[i-1].Y>x)
 		ok=false;
 	    }
 	    if(ss[i].X==x){
 	      ++ss[i].Y;
 	      ++c;
 	    }
 	    if(ss[i].Y!=ss[i].X)
 	      ok=false;
 	    if(i+1==n){
 	      if(n==1){
 		c+=2;
 	      }else{
 		if(ss[0].X==x){
 		  ++ss[0].Y;
 		  ++c;
 		  if(ss[0].Y>x)
 		    ok=false;
 		}
 	      }
 	    }
 	    if(c>x)
 	      ok=false;
 	    if(!ok)
 	      continue;
 	    ss[i]=mp(x,c);
 	    (ndp[ss]+=d)%=mod;
 	  }
 	}
 	swap(dp,ndp);
       }
     }
     LL ans=0;
     for(const auto &it: dp){
       const vector<pair<char,char>> &s=it.X;
       LL d=it.Y;
       bool ok=true;
       forv(i,s){
 	if(s[i].X!=s[i].Y)
 	  ok=false;
       }
       if(!ok)
 	continue;
       (ans+=d)%=mod;
     }
     return ans;
 }
 
 int main(){
   ios_base::sync_with_stdio(false);cin.tie(0);
 
   int tc;
   cin>>tc;
   forn(qqq,tc){
     int n,m;
     cin>>n>>m;
     swap(n,m);
     vector<LL> v(n+1);
     for(int i=1;i<=n;++i){
       v[i]=solve(i,m);
       cerr<<i<<' '<<m<<' '<<v[i]<<endl;
     }
     for(int i=2;i<=n;++i){
       for(int j=1;j<i;++j){
 	if(i%j)
 	  continue;
 	v[i]=(v[i]-v[j]*j+mod*j)%mod;
       }
     }
     LL ans=0;
     for(int i=1;i<=n;++i){
       if(n%i)
 	continue;
       (ans+=v[i])%=mod;
     }
     cout<<"Case #"<<qqq+1<<": "<<ans<<endl;
   }
   
   return 0;
 }
