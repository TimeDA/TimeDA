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
 const ld EPS = 1e-9;
 const int inf = 1000*1000*1000;
 const char cinf = 102;
 const LL linf = inf * 1ll * inf;
 const ld dinf = 1e200;
 const ld PI = 3.1415926535897932384626433832795l;
 int gcd(int a,int b){return a?gcd(b%a,a):b;}
 LL gcd(LL a,LL b){return a?gcd(b%a,a):b;}
 LL powmod(LL a,LL p,LL m){LL r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
 #define FAIL { cerr<<"assertion failed on line "<<__LINE__<<endl; exit(123);}
 
 struct Q {
   int x;
   int s;
 
   explicit Q(int x,int s):x(x),s(s){}
 
   static Q one;
   static Q i;
   static Q j;
   static Q k;
 
   Q operator-()const{
     return Q(x,-s);
   }
 
   Q operator*(Q b)const{
     if (x==-1)
       return Q(b.x,s*b.s);
     else if(b.x==-1)
       return Q(x,s*b.s);
     else if(x==b.x)
       return Q(-1,-s*b.s);
     else if(b.x==(x+1)%3)
       return Q((x+2)%3,s*b.s);
     else if(b.x==(x+2)%3)
       return Q((x+1)%3,-s*b.s);
     else
       assert(false);
   }
 
   bool operator==(Q b)const{
     return mp(x,s)==mp(b.x,b.s);
   }
   bool operator!=(Q b)const{
     return !(*this==b);
   }
 
   static Q p(char c){
     if(c=='i')
       return i;
     else if(c=='j')
       return j;
     else if(c=='k')
       return k;
     else
       assert(false);
   }
 };
 
 Q Q::one{-1,1};
 Q Q::i{0,1};
 Q Q::j{1,1};
 Q Q::k{2,1};
 
 int main(){
 	ios_base::sync_with_stdio(false);cin.tie(0);
 
   int tc;
   cin>>tc;
   forn(qqq,tc){
     LL l,n;
     cin>>l>>n;
     string s;
     cin>>s;
     Q x=Q::one;
     LL i=0;
     LL lim=min(10000ll*4*3, l*n);
     bool ok=false;
     do {
       while(i<lim && x != Q::i)
         x=x*Q::p(s[i++%l]);
       if(x!=Q::i)
         break;
       while(i<lim && x != Q::k)
         x=x*Q::p(s[i++%l]);
       if(x!=Q::k)
         break;
       while(i<lim && x != -Q::one)
         x=x*Q::p(s[i++%l]);
       if(x!=-Q::one)
         break;
       lim=n*l-(n*l-i)/l/4*l*4;
       while(i<lim)
         x=x*Q::p(s[i++%l]);
       assert(i==lim);
       ok=x==-Q::one;
     } while(false);
     cout<<"Case #"<<qqq+1<<": "<<(ok?"YES":"NO")<<endl;
   }
   
   return 0;
 }
 
