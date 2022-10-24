#include <bits/stdc++.h>
 using namespace std;
 
 
 void put_case(){
   static int t = 1;
   printf("Case #%d: ",t++);
 }
 
 double memo[300][300];
 
 vector<double> hoge;
 double dfs(int x,int k){
   if( memo[x][k] != -1 ) return memo[x][k];
   if( k < 0 ) return 0;
   if( hoge.size() == x ) return k == 0;
   return  memo[x][k] = hoge[x] * dfs(x+1,k-1) + (1-hoge[x]) * dfs(x+1,k);
 
 }
 int main(){
   int T;
   cin >> T;
   while(T--){
     put_case();
     int N,K;
     cin >> N >> K;
     double p[210];
     for(int i = 0 ; i < N ; i++) cin >> p[i];
     sort(p,p+N);
     double ans = 0;
     for(int bit = 0 ; bit < (1<<N) ; bit++){
       if( __builtin_popcount(bit) != K ) continue;
       hoge.clear();
       for(int j = 0 ; j < N ; j++)
         if( bit >> j & 1 )
           hoge.push_back(p[j]);
 
      
       //for(int i = 0 ; i < K/2 ; i++){
       //  hoge.push_back(p[N-i-1]);
       //  hoge.push_back(p[i]);
       //}
       for(int i = 0 ; i < 300 ; i++)
         for(int j = 0 ; j < 300 ; j++)
           memo[i][j] = -1;
       ans = max(ans,dfs(0,K/2));
     }
 
     printf("%.10lf\n",ans);
   }
 }
