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
 #define MAX_MV 210
 #define INF -1
 #define MAX 1000100
 int dp[110][MAX_MV];
 int doit(){
   memset(dp , -1 , sizeof dp);
   int A , N;
   scanf("%d%d" , &A , &N);
   deque<int> mv(N);
   for(int i=0;i<N;++i)
    scanf("%d" , &mv[i]);
   sort(all(mv));
   mv.push_front(A);
   dp[0][0] = A;
   for(int sum = 0;sum <= 400;++sum){
    for(int pos = 0;pos<=min(sz(mv)-1 , sum);++pos){
     int cnt = sum - pos;
     if(cnt < 0 || cnt >= MAX_MV)continue;
     int ch = dp[pos][cnt];
     if(ch == INF)continue;
     if(cnt + 1 < MAX_MV)
      relaxMax(dp[pos][cnt+1] , min(MAX , ch + ch - 1));
     if(pos+1 < sz(mv)){
      if(cnt + 1 < MAX_MV)
       relaxMax(dp[pos+1][cnt+1] , ch);
      if(mv[pos+1] < ch)
       relaxMax(dp[pos+1][cnt] , ch + mv[pos+1]);
                       }
                                                   }
                                    }
   int ans = 1000000000;
   for(int i=0;i<MAX_MV;++i)
    if(dp[sz(mv)-1][i] != -1){
     ans = i;
     break;
                             }
   return ans;
 }
 int main(){
   int CASE = 0 , T;
   scanf("%d" , &T);
   for(CASE=1;CASE<=T;++CASE)
    printf("Case #%d: %d\n" , CASE , doit());
   return 0;
 }
