#define _CRT_SECURE_NO_DEPRECATE
 #define _USE_MATH_DEFINES
 #include <array>
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
 #include <unordered_set>
 #include <unordered_map>
 #include <stack>
 #include <queue>
 #include <forward_list>
 #include <thread>
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
 template<class T> inline T parse(const string&s){T x;stringstream ss(s);ss>>x;return x;}
 #define left asdleft
 #define right asdright
 #define link asdlink
 #define unlink asdunlink
 #define next asdnext
 #define prev asdprev
 #define y0 asdy0
 #define y1 asdy1
 #define mp make_pair
 #define MT make_tuple
 #define pb push_back
 #define sz(x) ((int)(x).size())
 #define all(x) (x).begin(), (x).end()
 #define clr(ar,val) memset(ar, val, sizeof(ar))
 #define istr stringstream
 #define forn(i,n) for(int i=0;i<(n);++i)
 #define forv(i,v) forn(i,sz(v))
 #define X first
 #define Y second
 const ld EPS = 1e-12;
 const int INF = 1000*1000*1000;
 const LL LINF = INF * 1ll * INF;
 const ld DINF = 1e200;
 const ld PI = 3.1415926535897932384626433832795l;
 int gcd(int a,int b){return a?gcd(b%a,a):b;}
 LL gcd(LL a,LL b){return a?gcd(b%a,a):b;}
 LL gcdex(LL a,LL b,LL &x,LL &y){if(!a){x=0,y=1;return b;}LL k=b/a;LL g=gcdex(b-k*a,a,y,x);x-=k*y;return g;}
 LL inv(LL a,LL m){LL x,y,g;g=gcdex(a,m,x,y);return (x%(m/g)+m/g)%m/g;}
 LL crt(LL a1,LL m1,LL a2,LL m2){LL a=(a2-a1%m2+m2)%m2;LL x,y,g;g=gcdex(m1,m2,x,y);if(a%g)return -1;LL m=m1/g*m2;x*=a/g;x=(x%m2+m2)%m2;LL r=(a1+x*m1)%m;assert(r%m1==a1 && r%m2==a2);return r;}
 LL powmod(LL a,LL p,LL m){LL r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
 bool isprime(LL a){if(a<=1)return false;for (LL i=2;i*i<=a;++i){if(a%i==0)return false;}return true;}
 LL sqrtup(LL a){if(!a)return 0;LL x=max(0ll,(LL)sqrt((ld)a));while(x*x>=a)--x;while((x+1)*(x+1)<a)++x;return x+1;}
 LL isqrt(LL a){LL x=max(0ll,(LL)sqrt((ld)a));while(x*x>a)--x;while((x+1)*(x+1)<=a)++x;return x;}
 LL sgn(LL x){return x<0?-1:x>0?1:0;}
 template<class T> ostream& operator<<(ostream &s, const vector<T> &v);
 template<class A,class B> ostream& operator<<(ostream &s, const pair<A,B> &p);
 template<class K,class V> ostream& operator<<(ostream &s, const map<K,V> &m);
 template<class T,size_t N> ostream& operator<<(ostream &s, const array<T,N> &a);
 template<class... T> ostream& operator<<(ostream &s, const tuple<T...> &t);
 template<class T> ostream& operator<<(ostream &s, const vector<T> &v){s<<'[';forv(i,v){if(i)s<<',';s<<v[i];}s<<']';return s;}
 template<class A,class B> ostream& operator<<(ostream &s, const pair<A,B> &p){s<<"("<<p.X<<","<<p.Y<<")";return s;}
 template<class K,class V> ostream& operator<<(ostream &s, const map<K,V> &m){s<<"{";bool f=false;for(const auto &it:m){if(f)s<<",";f=true;s<<it.X<<": "<<it.Y;}s<<"}";return s;}
 template<class T> ostream& operator<<(ostream &s, const set<T> &m){s<<"{";bool f=false;for(const auto &it:m){if(f)s<<",";f=true;s<<it;}s<<"}";return s;}
 template<class T> ostream& operator<<(ostream &s, const multiset<T> &m){s<<"{";bool f=false;for(const auto &it:m){if(f)s<<",";f=true;s<<it;}s<<"}";return s;}
 template<class T,class V,class C> ostream& operator<<(ostream &s, const priority_queue<T,V,C> &q) {auto a=q;s<<"{";bool f=false;while(!a.empty()){if(f)s<<",";f=true;s<<a.top();a.pop();}return s<<"}";}
 template<class T,size_t N> ostream& operator<<(ostream &s, const array<T,N> &a){s<<'[';forv(i,a){if(i)s<<',';s<<a[i];}s<<']';return s;}
 template<size_t n,class... T> struct put1 { static ostream& put(ostream &s, const tuple<T...> &t){s<<get<sizeof...(T)-n>(t);if(n>1)s<<',';return put1<n-1,T...>::put(s,t);} };
 template<class... T> struct put1<0,T...> { static ostream& put(ostream &s, const tuple<T...> &t){return s;} };
 template<class... T> ostream& operator<<(ostream &s, const tuple<T...> &t){s<<"(";put1<sizeof...(T),T...>::put(s,t);s<<")";return s;}
 ostream& put2(ostream &s, const tuple<> &t){return s;}
 template<class U> ostream& put2(ostream &s, const tuple<U> &t){return s<<get<0>(t);}
 template<class U,class V,class... T> ostream& put2(ostream &s, const tuple<U,V,T...> &t){return s<<t;}
 #ifdef __ASD__
 auto asdqwet0 = chrono::steady_clock::now();
 #define dbg(...) do { cerr.setf(ios::fixed,ios::floatfield);cerr.precision(6);double asdqwet = chrono::duration_cast<chrono::duration<double>>(chrono::steady_clock::now() - asdqwet0).count();cerr << '[' << __LINE__ << ' ' << asdqwet << "] " << #__VA_ARGS__ << " = "; put2(cerr, make_tuple(__VA_ARGS__)); cerr << endl; }while(false)
 #include "draw.h"
 #define draw(x) dr::get().add(x)
 #define drawc(x) dr::get().x
 #else
 #define dbg(...) do{}while(false)
 #define draw(...) do{}while(false)
 #define drawc(...) do{}while(false)
 #endif
 
 struct graph{
   vector<vector<int>> G;
   vector<int> mt;
   vector<char> W;
 
   graph(int n):G(n),mt(n,-1){}
 
   bool dfs(int v){
     if(W[v])
       return false;
     W[v]=1;
     for(int p:G[v]){
       if(mt[p]==-1 || dfs(mt[p])){
         mt[p]=v;
         return 1;
       }
     }
     return 0;
   }
   
   int kuhn(){
     int r=0;
     forv(i,G){
       W.assign(sz(G),0);
       r+=dfs(i);
     }
     return r;
   }
 };
 
 struct sol{
   int N;
   map<pii,char> A;
   int ans=0;
   map<pii,char> ansm;
 
   sol(){
     int m;
     cin>>N>>m;
     forn(i,m){
       int a,b;
       char c;
       cin>>c>>a>>b;
       --a;--b;
       A[mp(a,b)]=c;
     }
   }
 
   void solve(){
     set<int> as,bs;
     forn(i,N){
       as.insert(i);
       bs.insert(i);
     }
     set<int> ss,ds;
     for(auto p:A){
       if(p.Y!='+'){
         as.erase(p.X.X);
         bs.erase(p.X.Y);
         ++ans;
       }
       if(p.Y!='x'){
         ss.insert(p.X.X+p.X.Y);
         ds.insert(p.X.X-p.X.Y);
         ++ans;
       }
     }
 
     auto put=[&](int a,int b,char c){
       char&v=A[mp(a,b)];
       //dbg(a,b,c,v);
       if(v){
         assert(c!='o');
         assert(v!='o');
         assert(v!=c);
         v='o';
       }else
         v=c;
       ansm[mp(a,b)]=v;
       ++ans;
     };
 
     //dbg(N,A,as,bs,ss,ds);
     
     {
       auto it=as.begin();
       auto jt=bs.begin();
       while(it!=as.end()){
         assert(jt!=bs.end());
         put(*it,*jt,'x');
         ++it;
         ++jt;
       }
       assert(jt==bs.end());
     }
 
     //dbg(ansm);
 
     graph G(N*2-1);
     forn(i,N){
       forn(j,N){
         int s=i+j;
         int d=i-j;
         if(ss.count(s) || ds.count(d))
           continue;
         G.G[s].pb(d+N-1);
       }
     }
 
     G.kuhn();
     forn(j,N*2-1){
       if(G.mt[j]==-1)
         continue;
       int s=G.mt[j];
       int d=j-N+1;
       assert((s+d)%2==0);
       put((s+d)/2,(s-d)/2,'+');
     }
   }
 
   void output(){
     cout<<ans<<' '<<sz(ansm)<<'\n';
     for(auto p:ansm){
       assert(p.Y=='x' || p.Y=='o' || p.Y=='+');
       assert(p.X.X>=0 && p.X.X<N);
       assert(p.X.Y>=0 && p.X.Y<N);
       cout<<p.Y<<' '<<p.X.X+1<<' '<<p.X.Y+1<<'\n';
     }
   }
 };
 
 int main(int argc, char **argv){
   ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);
 
   int tc;
   cin>>tc;
   const int T = 1;
   struct slot{
     unique_ptr<sol> s;
     thread t;
     chrono::duration<double> d;
   };
   auto ts0 = chrono::steady_clock::now();
   vector<slot> S(T);
   forn(q,tc+T){
     slot*s=&S[q%T];
     if(q>=T){
       s->t.join(); 
 
       double t = chrono::duration_cast<chrono::duration<double>>(chrono::steady_clock::now() - ts0).count();
       cerr.setf(ios::fixed,ios::floatfield);cerr.precision(6);
       cerr<<'['<<t<<"] "<<q-T+1<<" took "<<s->d.count()<<"s"<<endl;
 
       cout<<"Case #"<<q-T+1<<": ";
       s->s->output();
       s->s.reset();
     }
     if(q<tc){
       s->s=make_unique<sol>();
       s->t=thread([s]{
           auto t0=chrono::steady_clock::now();
           s->s->solve();
           auto t1=chrono::steady_clock::now();
           s->d=t1-t0;
         });
     }
   }
   dbg();
 
   return 0;
 }
