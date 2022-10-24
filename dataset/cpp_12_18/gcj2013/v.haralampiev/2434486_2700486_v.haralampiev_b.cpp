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
 map<pii , double> ans[10];
 double dp[1500][1500];
 void init(){
   ans[1][mp(0,0)] = 1;
 
   ans[2][mp(0,0)] = 1;
   ans[2][mp(-2 , 0)] = ans[2][mp(2 , 0)] = 1.0/2;
 
   ans[3][mp(0,0)] = 1;
   ans[3][mp(-2 , 0)] = 3.0/4;
   ans[3][mp(2 , 0)] = 3.0/4;
   ans[3][mp(-1 , 1)] = 1.0/4;
   ans[3][mp(1 , 1)] = 1.0/4;
 
   ans[4][mp(0,0)] = 1;
   ans[4][mp(-2,0)] = ans[4][mp(2,0)] = 1;
   ans[4][mp(-1 , 1)] = 1.0/2;
   ans[4][mp(1,1)] = 1.0/2;
 
   dp[0][0] = 1;
   for(int i=1;i<1500;++i){
    for(int j=0;j<=i;++j){
     dp[i][j] += dp[i-1][j];
     if(j-1 >= 0)dp[i][j] += dp[i-1][j-1];
     dp[i][j] /= 2;
                         }
                          }
 
 }
 
 double doit(){
   int N , X , Y;
   scanf("%d%d%d" , &N , &X , &Y);
   if(N < 5){
    return ans[N][mp(X , Y)];
            }
   int L = 1;
   while(L * (L+1) / 2 <= N)
    L += 2;
   L -= 2;
   if(abs(X) + abs(Y) <= L-1)return 1.0;
   if(abs(X) + abs(Y) > L+1)return 0.0;
   int H = L+1 - abs(X);
   ++H;
   int Left = N - L * (L+1) / 2;
   double ans = 0;
   for(int i=H;i<=Left;++i)
    ans += dp[Left][i];
   return ans;
 }
 int main(){
   init();
   int CASE , T;
   scanf("%d" , &T);
   for(CASE = 1;CASE<=T;++CASE)
    printf("Case #%d: %.9lf\n" , CASE , doit());
   return 0;
 }
