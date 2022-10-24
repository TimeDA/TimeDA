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
 typedef double ld;
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
 const ld EPS = 1e-12;
 const int INF = 1000*1000*1000;
 const LL LINF = INF * 1ll * INF;
 const ld DINF = 1e200;
 const ld PI = 3.1415926535897932384626433832795l;
 int gcd(int a,int b){return a?gcd(b%a,a):b;}
 LL gcd(LL a,LL b){return a?gcd(b%a,a):b;}
 LL powmod(LL a,LL p,LL m){LL r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
 bool isprime(LL a){for (LL i=2;i*i<=a;++i){if(a%i==0)return false;}return true;}
 #define FAIL { cerr<<"assertion failed on line "<<__LINE__<<endl; exit(123);}
 
 
 struct solution{
   ld y;
   vector<pdd> A,B;
 
   void read(){
     int n;
     cin>>y>>n;
     vector<ld> pp(n);
     forn(i,n){
       cin>>pp[i];
     }
     forn(i,n){
       ld p=pp[i],s;
       cin>>s;
       if(p<0)
 	A.pb(mp(s,-p));
       else
 	B.pb(mp(s,p));
     }
   }
   
   ld solve(){
     sort(all(A));
     sort(all(B));
     vector<vector<vector<ld>>> dp(sz(A)+1,vector<vector<ld>>(sz(B)+1,vector<ld>(2,1e200)));
     dp[sz(A)][sz(B)][0]=dp[sz(A)][sz(B)][1]=0;
     ld ans=1e200;
     for(int a=sz(A);a>=0;--a){
       for(int b=sz(B);b>=0;--b){
 	forn(q,2){
 	  ld t=dp[a][b][q];
 	  if(t>1e100)
 	    continue;
 	  ld p;
 	  if(a==sz(A) && b==sz(B))
 	    p=0;
 	  else if(q)
 	    p=B[b].Y+B[b].X*t;
 	  else
 	    p=-(A[a].Y+A[a].X*t);
 	  //cerr<<a<<' '<<b<<' '<<q<<' '<<p<<' '<<t<<endl;
 	  forn(qq,2){
 	    ld tt=t;
 	    for(int k=1;;++k){
 	      ld xx,ss;
 	      int aa=a,bb=b;
 	      if(qq){
 		if(b<k)
 		  break;
 		bb-=k;
 		tie(ss,xx)=B[bb];
 	      }else{
 		if(a<k)
 		  break;
 		aa-=k;
 		tie(ss,xx)=A[aa];
 		xx*=-1;
 		ss*=-1;
 	      }
 	      xx+=ss*t;
 	      if(fabs(ss)>y){
 		//cerr<<"oops "<<ss<<' '<<y<<' '<<aa<<' '<<bb<<' '<<q<<' '<<qq<<' '<<a<<' '<<b<<' '<<k<<endl;
 	      }
 	      ld mt=t+fabs(p-xx)/(y-fabs(ss));
 	      tt=max(tt,mt);
 	      if(mt>=tt-EPS){
 		dp[aa][bb][qq]=min(dp[aa][bb][qq],tt);
 	      }
 	      if(!aa && !bb)
 		ans=min(ans,tt);
 	    }
 	  }
 	}
       }
     }
     return ans;
   }
 };
 
 int main(){
   ios_base::sync_with_stdio(false);cin.tie(0);
 
   int tc;
   cin>>tc;
   forn(qqq,tc){
     solution s;
     s.read();
     ld r=s.solve();
     cout.precision(20);
     cout.setf(ios::fixed);
     cout<<"Case #"<<qqq+1<<": "<<r<<endl;
   }
   
   return 0;
 }
