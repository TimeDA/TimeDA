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
 
 struct sol{
   LL P;
   vector<LL> G;
   LL ans=0;
 
   sol(){
     int n;
     cin>>n>>P;
     G.resize(n);
     forn(i,n)
       cin>>G[i];
   }
 
   void solve(){
     vector<LL> C(P);
     for(LL x:G)
       ++C[x%P];
     ans=C[0];
 
     if(P==2){
       ans+=(C[1]+1)/2;
       return;
     }
     if(P==3){
       LL m=min(C[1],C[2]);
       ans+=m+(C[1]-m)/3+(C[2]-m)/3+((C[1]-m+C[2]-m)%3>0);
       return;
     }
     assert(P==4);
     for(LL t1=0;t1*2<=C[1];++t1){
       for(LL t3=0;t3*2<=C[3];++t3){
         LL c1=C[1]-t1*2;
         LL c2=C[2]+t1+t3;
         LL c3=C[3]-t3*2;
         LL m=min(c1,c3);
         LL r=C[0]+c2/2+m+(c1-m)/4+(c3-m)/4 + (c2%2+(c1-m+c3-m)%4>0);
         ans=max(ans,r);
       }
     }
   }
 
   void output(){
     cout<<ans<<endl;
   }
 };
 
 
 void gen(){}
 
 int main(int argc, char **argv){
   ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);
 
     if(argc>1){gen();return 0;}
 
   int T = 1; // concurrency
   int M = 1; // memory
 
   int tc;
   cin>>tc;
   M = min(M,tc);
   T = min(T, M);
   struct slot{
     int i;
     sol s;
     thread t;
     bool r=true;
     slot(int i):i(i){}
   };
   mutex mu;
   condition_variable cv;
   auto ts0 = chrono::steady_clock::now();
   queue<unique_ptr<slot>> Q;
   int q=0,t=0;
   unique_lock<mutex> l(mu);
   while(q<tc || sz(Q)){
     slot*s;
     if(sz(Q) && !Q.front()->r){
       s=Q.front().get();
       s->t.join();
       cout<<"Case #"<<s->i<<": ";
       s->s.output();
       Q.pop();
       continue;
     }
     if(q<tc && t<T && sz(Q)<M){
       ++t;
       s=new slot(++q);
       Q.emplace(s);
       s->t=thread([s,&mu,&cv,ts0,&t]{
           auto t0=chrono::steady_clock::now();
           s->s.solve();
           auto t1=chrono::steady_clock::now();
           double d=chrono::duration_cast<chrono::duration<double>>(t1-t0).count();
 
           {
             unique_lock<mutex> l(mu);
 
             double ti = chrono::duration_cast<chrono::duration<double>>(chrono::steady_clock::now() - ts0).count();
             cerr.setf(ios::fixed,ios::floatfield);cerr.precision(6);
             cerr<<'['<<ti<<"] "<<s->i<<" took "<<d<<"s"<<endl;
 
             s->r=false;
             --t;
           }
           cv.notify_one();
         });
       continue;
     }
     cv.wait(l);
   }
   dbg();
 
   return 0;
 }
