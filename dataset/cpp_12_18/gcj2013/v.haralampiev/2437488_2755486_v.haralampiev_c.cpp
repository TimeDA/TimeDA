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
 struct attack{
   int lo , hi , s;
   attack(int _lo = 0 , int _hi = 0 , int _s = 0){
    lo = _lo , hi = _hi , s = _s;
                                                 }
 };
 void doit(int CASE){
   int ans = 0;
   map<int , int> H;
   map< int , vector<attack> > A;
   int N;
   scanf("%d" , &N);
   for(int i=0;i<N;++i){
    int di, ni, wi, ei, si, delta_di, delta_pi, delta_si;
    cin>>di>>ni>>wi>>ei>>si>>delta_di>>delta_pi>>delta_si;
    for(int j=0;j<ni;++j){
     int day = di + j*delta_di;
     int lo = 2*(wi + j*delta_pi);
     int hi = 2*(ei + j*delta_pi);
     int power = si + j*delta_si;
     A[day].pb(attack(lo , hi , power));
                         }
                       }
   for(map< int , vector<attack> >::iterator it = A.begin();
       it!=A.end();
       ++it){
    vector<attack>& cur = it->se;
    for(int i=0;i<sz(cur);++i){
     //cout<<it->fi<<":"<<cur[i].lo<<' '<<cur[i].hi<<"/"<<cur[i].s<<endl;
     bool OK = false;
     for(int j=cur[i].lo;j<=cur[i].hi;++j)
      if(H[j] < cur[i].s){
       OK = true;
       break;
                         }
     if(OK)++ans;
                              }
    for(int i=0;i<sz(cur);++i)
     for(int j=cur[i].lo;j<=cur[i].hi;++j)
      relaxMax(H[j] , cur[i].s);
            }
   cout<<"Case #"<<CASE<<": "<<ans<<'\n';
 }
 int main(){
   int Q; scanf("%d" , &Q);
   for(int CASE=1;CASE<=Q;++CASE)
    doit(CASE);
   return 0;
 }
