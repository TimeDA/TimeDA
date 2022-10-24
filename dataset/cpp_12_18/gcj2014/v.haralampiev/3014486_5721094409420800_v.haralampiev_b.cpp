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
 #define INF 1000000000
 // BIT
 int UP = 10 , ALL;
 int bit[2010];
 void clear(){
   ALL = 0;
   fill(bit , bit + UP , 0);
 }
 void add(int pos){
   ++ALL;
   for(;pos<UP;pos += pos&(-pos))
    ++bit[pos];
 }
 int get(int pos){
   int ret = 0;
   for(;pos > 0;pos -= pos&(-pos))
    ret += bit[pos];
   return ret;
 }
 int bigger(int t){
   return ALL - get(t);
 }
 //
 void doit(int CASE = 0){
   int N , ans = (int)1E9;
   scanf("%d" , &N);
   UP = N + 20;
   vi in(N);
   map<int , int> id;
   for(int i=0;i<N;++i){
    scanf("%d" , &in[i]);
    id[in[i]] = i+1;
                       }
   clear();
   sort(all(in));
   vi cdp(N+2) , ndp(N+2);
   fill(all(cdp) , INF);
   cdp[0] = 0;
   add(id[in.back()]);
   for(int p=N-2;p>=0;--p){
    fill(all(ndp) , INF);
    int pos = id[in[p]];
    int gr = bigger(pos);
    int ls = get(pos);
    for(int i=0;i<N;++i){
     if(cdp[i] >= INF) continue;
     relaxMin(ndp[i] , cdp[i] + ls);
     if(i+1 < N)
      relaxMin(ndp[i+1] , cdp[i] + gr);
                        }
    cdp.swap(ndp);
    add(pos);
                               }
   for(int i=0;i<N;++i)
    relaxMin(ans , cdp[i]);
   printf("Case #%d: %d\n" , CASE , ans);
 }
 int main(){
   int Q;
   scanf("%d" , &Q);
   for(int i=1;i<=Q;++i)
    doit(i);
   return 0;
 }
