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
   int N , X;
   scanf("%d%d" , &N , &X);
   vi cnt(X+1 , 0);
   for(int i=0;i<N;++i){
    int p;
    scanf("%d" , &p);
    ++cnt[p];
                       }
   int ans = 0;
   for(int i=X;i>0;--i){
    if(cnt[i] == 0) continue;
    if(i + i <= X){
     int take = cnt[i] / 2;
     ans += take;
     cnt[i] -= 2*take;
                  }
    for(int j=i-1;j>=0;--j)
     if(i + j <= X){
      int take = min(cnt[i] , cnt[j]);
      ans += take;
      cnt[i] -= take;
      cnt[j] -= take;
                   }
    ans += cnt[i];
                       }
   printf("Case #%d: %d\n" , CASE , ans);
 }
 int main(){
   int Q;
   scanf("%d" , &Q);
   for(int i=1;i<=Q;++i)
    doit(i);
   return 0;
 }
