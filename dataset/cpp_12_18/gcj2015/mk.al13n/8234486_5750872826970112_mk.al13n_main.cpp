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
 
 ld solve(ld X, ld VV, vector<pdd> A){
   auto scr=[&]{
     ld s=0;
     forv(i,A){
       s+=A[i].X*A[i].Y;
     }
     return s;
   };
   auto sr=[&]{
     ld s=0;
     forv(i,A){
       s+=A[i].Y;
     }
     return s;
   };
   if(scr()/sr()<X){
     forv(i,A){
       A[i].X*=-1;
     }
     X*=-1;
   }
   sort(all(A));
   ld ans=-1;
   if(fabs(scr()/sr()-X)<eps){
     ans=VV/sr();
   }else{
   while(sz(A)>1){
     ld c=A.back().X;
     ld r=A.back().Y;
     A.pop_back();
     if(scr()/sr()>X+eps)
       continue;
     if(scr()/sr()>X-eps){
       ans=VV/sr();
       break;
     }
     ld a=0,b=r;
     forn(qq,100){
       ld x=(a+b)/2;
       A.pb(mp(c,x));
       if(scr()/sr()>X)
 	b=x;
       else
 	a=x;
       A.pop_back();
     }
     A.pb(mp(c,a));
     if(fabs(scr()/sr()-X)>.01){
       cerr<<"oops "<<sz(A)<<' '<<scr()<<' '<<sr()<<' '<<X<<' '<<VV<<' '<<a<<endl;
     }
     ans=VV/sr();
     break;
   }}
   if(ans<-.5){
     assert(sz(A)==1);
     if(fabs(scr()/sr()-X)<eps)
       ans=VV/sr();
   }
   return ans;
 }
 
 ld brute(ld X, ld VV, vector<pdd> A){
   if(sz(A)==2 && fabs(A[0].X-A[1].X)<eps){
     A[0].Y+=A[1].Y;
     A.pop_back();
   }
   if(sz(A)==1){
     if(fabs(A[0].X-X)<eps)
       return VV/A[0].Y;
     return -1;
   }
   sort(all(A));
   if(A[0].X>X+eps || A[1].X<X-eps)
     return -1;
   ld x=(X-A[1].X)*A[1].Y/(A[0].X*A[0].Y-A[1].X*A[1].Y-X*A[0].Y+X*A[1].Y);
   cerr.precision(20);
   //cerr<<x<<endl;
   assert(x>-1e-3 && x<1+1e-3);
   return VV/(A[0].Y*x+A[1].Y*(1-x))*max(x,1-x);
 }
 
 int main(){
   ios_base::sync_with_stdio(false);cin.tie(0);
 
   int tc;
   cin>>tc;
   forn(qqq,tc){
     int n;
     ld VV,X;
     cin>>n>>VV>>X;
     vector<pdd> A(n);
     forn(i,n)
       cin>>A[i].Y>>A[i].X;
     ld ans=solve(X,VV,A);
     ld ans2=brute(X,VV,A);
     cout.precision(20);
     if(fabs(ans-ans2)>1e-6 && fabs(ans/ans2)>1e-6){
       cerr<<qqq+1<<": "<<ans2<<' '<<ans<<endl;
       cerr<<n<<' '<<VV<<' '<<X<<endl;
       forv(i,A){
 	cerr<<A[i].Y<<' '<<A[i].X<<endl;
       }
     }
     //continue;
     cout<<"Case #"<<qqq+1<<": ";
     if(ans<-.5)
       cout<<"IMPOSSIBLE\n";
     else{
       cout.precision(20);
       cout<<fixed<<ans<<endl;
     }
   }
   
   return 0;
 }
