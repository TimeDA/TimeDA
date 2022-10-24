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
 
 struct segtree{
   vector<pii> t;
   vector<int> add;
 
   void init(int a,int b,int k){
     t[k]=mp(0,b-a);
     if(b==a+1){
       return;
     }
     int c=(a+b)/2;
     init(a,c,k*2+1);
     init(c,b,k*2+2);
   }
   
   segtree(int n):t(n*4+10),add(n*4+10){init(0,n,0);}
 
   void addv(int l,int r,int v,int a,int b,int k){
     if(r<=a || l>=b)
       return;
     if(l<=a && r>=b){
       add[k]+=v;
       t[k].X+=v;
       return;
     }
     int c=(a+b)/2;
     addv(l,r,v,a,c,k*2+1);
     addv(l,r,v,c,b,k*2+2);
     pii t1=t[k*2+1];
     pii t2=t[k*2+2];
     if(t1.X==t2.X)
       t[k]=mp(t1.X,t1.Y+t2.Y);
     else
       t[k]=min(t1,t2);
     t[k].X+=add[k];
   }
 
   int c0(){
     return t[0].X?0:t[0].Y;
   }
 };
 
 struct solution{
   vector<vector<int>> gr;
   vector<int> A,B,S;
   int cnt=0;
   int n,D;
 
   struct event{
     int x,s,i;
 
     bool operator<(const event&b)const{
       return mp(x,s)<mp(b.x,b.s);
     }
   };
 
   void dfs(int v,int pr){
     A[v]=cnt++;
     for(int p:gr[v]){
       if(p==pr)
 	continue;
       dfs(p,v);
     }
     B[v]=cnt;
   }
 
   void read(){
     cin>>n>>D;
     LL s,as,cs,rs,m,am,cm,rm;
     cin>>s>>as>>cs>>rs>>m>>am>>cm>>rm;
     gr.resize(n);
     A.resize(n);
     B.resize(n);
     S.resize(n);
     forn(i,n){
       if(i)
 	gr[m%i].pb(i);
       S[i]=s;
       s=(s*as+cs)%rs;
       m=(m*am+cm)%rm;
     }
   }
 
   int dfs2(int v,int pr,int s0){
     if(S[v]<s0 || S[v]>s0+D)
       return 0;
     int r=1;
     for(int p:gr[v]){
       if(p==pr)
 	continue;
       r+=dfs2(p,v,s0);
     }
     return r;
   }
 
   int brute(){
     int r=0;
     forn(i,n){
       r=max(r,dfs2(0,0,S[i]));
     }
     return r;
   }
 
   int solve(){
     vector<event> evs;
     forn(i,n){
       evs.pb({S[i]-D,-1,i});
       evs.pb({S[i],1,i});
     }
     dfs(0,0);
     assert(cnt==n);
     segtree T(n);
     auto fire=[&](int i,int s){
       T.addv(A[i],B[i],s,0,n,0);
     };
     forn(i,n){
       fire(i,1);
     }
     int ans=0;
     sort(all(evs));
     for(auto e:evs){
       fire(e.i,e.s);
       ans=max(ans,T.c0());
     }
     assert(ans>0);
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
     int b=s.brute();
     int r=s.solve();
     if(b!=r){
       cerr<<"failed "<<qqq<<": "<<b<<' '<<r<<endl;
       return 1;
     }
     cout<<"Case #"<<qqq+1<<": "<<r<<endl;
   }
   
   return 0;
 }
