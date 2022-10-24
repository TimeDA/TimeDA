#ifdef _WIN32
 #  define LL "%I64d"
 #else
 #  define LL "%ll"
 #endif
 
 #include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <cmath>
 #include <cstring>
 #include <ctime>
 #include <vector>
 #include <deque>
 #include <set>
 #include <map>
 #include <queue>
 #include <stack>
 #include <bitset>
 #include <string>
 #include <algorithm>
 #include <complex>
 #include <utility>
 using namespace std;
 #define null NULL
 #define mp make_pair
 #define pb(a) push_back(a)
 #define sz(a) ((int)(a).size())
 #define all(a) a.begin() , a.end()
 #define fi first
 #define se second
 #define relaxMin(a , b) (a) = min((a),(b))
 #define relaxMax(a , b) (a) = max((a),(b))
 typedef vector<int> vi;
 typedef pair<int,int> pii;
 typedef long long ll;
 #define BITS(a) __builtin_popcount(a)
 struct point{
   ll x,y;
   point(ll _x=0 , ll _y=0){x=_x; y=_y;}
   point operator-(point w){return point(x-w.x , y-w.y);}
   bool operator<(const point& w)const{return x<w.x;}
   bool operator==(const point& w){
    return mp(x,y) == mp(w.x , w.y);
                                  }
 };
 inline ll vp(point f,point s){return f.x*s.y - f.y*s.x;}
 inline ll sp(point f,point s){return f.x*s.x + f.y*s.y;}
 inline int sgn(ll w){
   return w == 0 ? 0 : (w > 0 ? 1 : -1);
 }
 #define ppv(a) a[sz(a)-2]
 bool compare(const point& f , const point& s){
   return mp(f.x , f.y) < mp(s.x , s.y);
 }
 vector<point> hull(vector<point> from){ // from ne pustoe
   sort(all(from) , compare);
   from.erase( unique(all(from)) , from.end() );
   if(sz(from) <= 2)return from;
   bool OK = true;
   for(int i=2;i<sz(from);++i)
    if(vp(from[1] - from[0] , from[i] - from[0]) != 0){
     OK = false; break;;
                                                      }
   if(OK){
    vector<point> ret;
    ret.pb(from[0]);
    ret.pb(from.back());
    return ret;
         }
   vector<point> lo,up;
   for(int i=1;i<sz(from);++i)
    if(from[i]<from[0] || from[i].x==from[0].x&&from[i].y<from[0].y)swap(from[0] , from[i]);
   for(int i=2;i<sz(from);++i)
    if(from[1]<from[i] || from[1].x==from[i].x&&from[1].y<from[i].y)swap(from[1] , from[i]);
   if(sz(from)<2 || from[0].x==from[1].x&&from[0].y==from[1].y)return vector<point>(1,from[0]);
   from.pb(from[1]);
   lo.pb(from[0]); up.pb(from[0]);
   sort(from.begin()+2 , from.end());
   for(int i=2;i<sz(from);++i){
    if(vp(from[i]-from[0] , from[1]-from[0]) >= 0){
     while(sz(lo)>1 && vp(lo.back()-ppv(lo) , from[i]-ppv(lo))<=0)lo.pop_back();
     lo.pb(from[i]);
                                                  }
    if(vp(from[i]-from[0] , from[1]-from[0]) <= 0){
     while(sz(up)>1 && vp(up.back()-ppv(up) , from[i]-ppv(up))>=0)up.pop_back();
     up.pb(from[i]);
                                                  }
                              }
   for(int i=sz(up)-2;i>0;--i)lo.pb(up[i]);
   return lo;
 }
 bool on_line(point f , point t , point w){
   if(w == f || w == t) return true;
   if(vp(t - f , w - f) != 0) return false;
   if(sgn(sp(t - w , f - w)) < 0) return true;
   return false;
 }
 void doit(int CASE = 0){
   int N; scanf("%d" , &N);
   vector<point> in;
   for(int i=0;i<N;++i){
    int x , y;
    scanf("%d%d" , &x , &y);
    in.pb(point(x , y));
                       }
   vi ans(N , N-1);
   for(int msk = 1;msk < (1<<N);++msk){
    vector<point> pts;
    for(int i=0;i<N;++i)
     if(msk & (1<<i)) pts.pb(in[i]);
    pts = hull(pts);
    int val = N - BITS(msk);
    for(int i=0;i<N;++i)
     if(val < ans[i]){
      if(sz(pts) == 1 && pts[0] == in[i])
       ans[i] = val;
      if(sz(pts) > 1){
       for(int j=0;j<sz(pts);++j){
        point prv;
        if(j-1 >= 0) prv = pts[j-1];
        else prv = pts.back();
        if(on_line(prv , pts[j] , in[i])){
         ans[i] = val;
         break;
                                         }
                                 }
                     }
                     }
                                      }
   printf("Case #%d:\n" , CASE);
   for(int i=0;i<N;++i)
    printf("%d\n" , ans[i]);
 }
 int main(){
   int Q;
   scanf("%d" , &Q);
   for(int i=1;i<=Q;++i) doit(i);
   return 0;
 }
 
