#include <bits/stdc++.h>
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
 #define PI 3.14159265358979323846
 typedef vector<int> vi;
 typedef pair<int,int> pii;
 typedef long long ll;
 
 const int MAX = 110;
 const int oo = 1E9;
 
 char buf[MAX];
 
 int dp[MAX][MAX];
 
 int CASE = 0;
 void Doit(){
   ++CASE;
   cerr << "Case: " << CASE << endl;
   scanf("%s", buf);
   int n = strlen(buf);
 
   for(int i = 0;i < MAX;++i)
     for(int j = 0;j < MAX;++j)
       dp[i][j] = -oo;
 
   for(int i = 0;i < n;++i)
     if(i + 1 < n){
       dp[i][i + 1] = (buf[i] == buf[i + 1] ? 10 : 5);
     }
 
   for(int l = 2;l <= n;l += 2){
     for(int i = 0;i < MAX;++i){
       int j = i + l - 1;
       if(j >= n) break;
       for(int m = i + 1;m < j;m += 2)
         relaxMax(dp[i][j], dp[i][m] + dp[m + 1][j]);
       if(buf[i] == buf[j])
         relaxMax(dp[i][j], dp[i + 1][j - 1] + 10);
       else
         relaxMax(dp[i][j], dp[i + 1][j - 1] + 5);
     }
   }
 
   int best = dp[0][n - 1];
   printf("Case #%d: %d\n", CASE, best);
 }
 
 int main(){
   int q;
   scanf("%d", &q);
   while(q-- > 0) Doit();
   return 0;
 }
