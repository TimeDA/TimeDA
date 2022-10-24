#ifdef _WIN32
 #  define LL "%I64d"
 #else
 #  define LL "%Ld"
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
 #include <cassert>
 #include <sstream>
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
 #define SQR(a) ((a)*(a))
 typedef vector<int> vi;
 typedef pair<int,int> pii;
 typedef long long ll;
 char buf[100000];
 vector<string> read(){
   vector<string> ret;
   do{gets(buf);}while(strlen(buf) == 0);
   stringstream sin;
   sin<<buf;
   string tmp;
   while(sin>>tmp) ret.pb(tmp);
   return ret;
 }
 void doit(int CASE = 1){
   cerr<<"C: "<<CASE<<endl;
   int N;
   scanf("%d" , &N);
   vector<string> E = read();
   vector<string> F = read();
   map<string , int> gtype;
   for(string& c : E)
    gtype[c] |= 1;
   for(string& c : F)
    gtype[c] |= 2;
   vector< vector<string> > NAL;
   vector<vi> nal;
   vi type , base;
   // Names
   map<string , int> name;
   for(int i=2;i<N;++i){
    NAL.pb(read());
    for(string& t : NAL.back())
     name[t] = 0;
                       }
   int nc = 0;
   for(auto& p : name) p.se = nc++;
   int ANS = 1E9 , ADD = 0;
   type.resize(nc) , base.resize(nc);
   for(auto& c : gtype){
    if(!name.count(c.fi)){
     if(c.se == 3) ++ADD;
                         }
    else base[name[c.fi]] = c.se;
                       }
   for(int i=0;i<sz(NAL);++i){
    nal.pb(vi());
    vi& cur = nal.back();
    for(string& t : NAL[i])
     cur.pb(name[t]);
                             }
   // Local
   for(int msk=0;msk<(1<<sz(nal));++msk){
    type = base;
    for(int i=0;i<sz(nal);++i){
     int v = 1;
     if(msk & (1<<i)) v = 2;
     vi& use = nal[i];
     for(int& t : use)
      type[t] |= v;
                              }
    relaxMin(ANS , count(all(type) , 3));
                                        }
   // Out
   printf("Case #%d: " , CASE);
   printf("%d\n" , ANS + ADD);
 }
 int main(){
   int Q;
   scanf("%d" , &Q);
   for(int i=1;i<=Q;++i)
    doit(i);
   return 0;
 }
