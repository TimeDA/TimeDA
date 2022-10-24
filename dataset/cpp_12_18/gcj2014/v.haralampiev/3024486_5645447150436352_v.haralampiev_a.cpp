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
 #define MAXN 1000010
 ll N , P , Q , R , S;
 ll val[MAXN] , sum[MAXN];
 map<ll , int> pref;
 map<ll , int> suff;
 ll ival(int f , int t){
   if(f > t) return 0;
   return sum[t] - (f==0 ? 0 : sum[f-1]);
 }
 bool fine(ll how){
   ll odr = ival(0 , N-1) - how;
   int a = (--pref.lower_bound(odr + 1))->se + 1;
   int b = (--suff.lower_bound(odr + 1))->se - 1;
   return ival(a , b) <= odr;
 }
 void doit(int CASE = 1){
   pref.clear();
   suff.clear();
   cin>>N>>P>>Q>>R>>S;
   for(int i=0;i<N;++i)
    val[i] = ((i * P + Q) % R + S);
   sum[0] = val[0];
   for(int i=1;i<N;++i)
    sum[i] = sum[i-1] + val[i];
   pref[0] = -1;
   for(int i=0;i<N;++i)
    pref[ival(0 , i)] = i;
   suff[0] = N;
   for(int i=N-1;i>=0;--i)
    suff[ival(i , N-1)] = i;
   ll lo = 0 , hi = ival(0 , N-1) , mid;
   for(;;){
    if(lo+1 >= hi){
     if(fine(hi)) mid = hi;
     else mid = lo;
     break;
                  }
    mid = (lo+hi) / 2;
    if(fine(mid)) lo = mid;
    else hi = mid;
          }
   printf("Case #%d: %.12lf\n" , CASE , ((double)(mid)) / ival(0 , N-1));
 }
 int main(){
   int Q;
   scanf("%d" , &Q);
   for(int i=0;i<Q;++i)
   doit(i+1);
   return 0;
 }
