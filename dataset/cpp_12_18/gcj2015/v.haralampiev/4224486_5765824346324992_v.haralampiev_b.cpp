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
 int B , N;
 vi sp;
 bool can(ll t){
   ll sum = 0;
   for(int i=0;i<sz(sp);++i){
    sum += (t + sp[i] - 1) / sp[i];
    if(sum >= N) return true;
                            }
   return false;
 }
 void doit(int CASE = 1){
   scanf("%d%d" , &B , &N);
   sp.resize(B);
   for(int i=0;i<B;++i)
    scanf("%d" , &sp[i]);
   ll lo = 0 , hi = 10000000000000000LL , mid;
   for(;;){
    if(lo+1 >= hi){
     if(can(lo)) mid = lo;
     else mid = hi;
     break;
                  }
    mid = (lo+hi)>>1;
    if(can(mid)) hi = mid;
    else lo = mid;
          }
   mid = mid-1;
   ll done = 0;
   for(int i=0;i<sz(sp);++i)
    done += (mid + sp[i] - 1) / sp[i];
   vi fin;
   for(int i=0;i<sz(sp);++i)
    if(mid % sp[i] == 0) fin.pb(i+1);
   N -= done;
   int ans = fin[N-1];
   printf("Case #%d: %d\n" , CASE , ans);
 }
 int main(){
   int Q;
   scanf("%d" , &Q);
   for(int i=0;i<Q;++i)
    doit(i+1);
   return 0;
 }
