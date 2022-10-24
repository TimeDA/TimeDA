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
 int N;
 void doit(int CASE = 1){
   ll a1 = 0 , a2 = 0;
   scanf("%d" , &N);
   vi M(N);
   for(int i=0;i<N;++i)
    scanf("%d" , &M[i]);
   for(int i=1;i<N;++i)
    if(M[i-1] > M[i]) a1 += abs(M[i-1] - M[i]);
   ll sp = 0;
   for(int i=1;i<N;++i)
    if(M[i-1] > M[i])
     relaxMax(sp , ll(abs(M[i-1] - M[i])));
   for(int i=1;i<N;++i)
    a2 += min(sp , ll(M[i-1]));
   printf("Case #%d: " , CASE);
   cout<<a1<<' '<<a2<<'\n';
 }
 int main(){
   int Q;
   scanf("%d" , &Q);
   for(int i=1;i<=Q;++i) doit(i);
   return 0;
 }
