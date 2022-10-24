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
 void doit(int CASE = 1){
   int D , T , N;
   scanf("%d%d%d" , &D , &T , &N);
   vi H(N) , G(N);
   for(int i=0;i<N;++i)
    scanf("%d%d" , &H[i] , &G[i]);
   int BEST = 0;
   for(int msk = 0;msk<(1<<N);++msk){
    int avb = 1;
    int cs = 0;
    for(int i=0;i<N;++i){
     if(msk & (1<<i)){
      int rem = H[i] % T;
      avb += H[i] / T;
      if(rem == 0) rem = T , --avb;
      int need = (rem + D - 1) / D;
      if(need <= avb)
       avb -= need , cs += G[i];
      else{
       cs = 0;
       break;
          }
                     }
     else{
      avb += (H[i] + T - 1) / T;
         }
                        }
    relaxMax(BEST , cs);
                                    }
   printf("Case #%d: %d\n" , CASE , BEST);
 }
 int main(){
   int Q;
   scanf("%d" , &Q);
   for(int i=0;i<Q;++i)
    doit(i+1);
   return 0;
 }
