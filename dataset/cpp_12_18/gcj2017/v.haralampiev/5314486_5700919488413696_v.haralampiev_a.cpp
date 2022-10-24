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
 
 const int MAXN = 110;
 
 int dp[4][MAXN][MAXN][MAXN];
 
 int n, p;
 
 int Eval(int beg, int c1, int c2, int c3){
   if(dp[beg][c1][c2][c3] != -1)
     return dp[beg][c1][c2][c3];
 
   int& v = dp[beg][c1][c2][c3];
   if(c1 + c2 + c3 == 0) return v = 0;
 
   v = 0;
   if(c1 > 0)
     relaxMax(v, Eval((beg + 1) % p, c1 - 1, c2, c3));
   if(c2 > 0)
     relaxMax(v, Eval((beg + 2) % p, c1, c2 - 1, c3));
   if(c3 > 0)
     relaxMax(v, Eval((beg + 3) % p, c1, c2, c3 - 1));
 
   if(beg == 0) ++v;
   return v;
 }
 
 int CASE = 0;
 void Doit(){
   ++CASE;
   cerr << "Case: " << CASE << endl;
   memset(dp, -1, sizeof dp);
 
   scanf("%d%d", &n, &p);
 
   int ans = 0;
   int cnt[4] = {0, 0, 0, 0};
   for(int i = 0;i < n;++i){
     int c;
     scanf("%d", &c);
     if(c % p == 0) ++ans;
     else ++cnt[c % p];
   }
 
   printf("Case #%d: ", CASE);
   printf("%d\n", ans + Eval(0, cnt[1], cnt[2], cnt[3]));
 }
 
 int main(){
   int q;
   scanf("%d", &q);
   while(q-- > 0) Doit();
   return 0;
 }
