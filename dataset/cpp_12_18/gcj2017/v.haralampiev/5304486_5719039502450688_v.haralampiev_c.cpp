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
 
 const int oo = 1E9;
 const int MAX = 110;
 
 int _hd, _ad, _hk, _ak, b, d;
 
 int dp[MAX][MAX][MAX][MAX];
 int done[MAX][MAX][MAX][MAX], dst = 1;
 
 int Step(int hd, int ad, int hk, int ak);
 
 int Eval(int hd, int ad, int hk, int ak){
   if(done[hd][ad][hk][ak] == dst)
     return dp[hd][ad][hk][ak];
 
   done[hd][ad][hk][ak] = dst;
   int& v = dp[hd][ad][hk][ak];
   v = oo;
 
   if(max(0, hk - ad) != hk)
     relaxMin(v, 1 + Step(hd, ad, max(0, hk - ad), ak));
 
   if(hd != _hd)
     relaxMin(v, 1 + Step(_hd, ad, hk, ak));
 
   if(max(0, ak - d) != ak)
     relaxMin(v, 1 + Step(hd, ad, hk, max(0, ak - d)));
 
   if(min(hk, ad + b) != ad)
     relaxMin(v, 1 + Step(hd, min(hk, ad + b), hk, ak));
 
   return v;
 }
 
 int Step(int hd, int ad, int hk, int ak){
   if(hk <= 0) return 0;
   hd -= ak;
   if(hd <= 0) return oo;
   else return Eval(hd, ad, hk, ak);
 }
 
 int CASE = 0;
 void Doit(){
   ++CASE;
   cerr << "Case: " << CASE << endl;
 
   scanf("%d%d%d%d%d%d", &_hd, &_ad,
                         &_hk, &_ak,
                         &b, &d);
   printf("Case #%d: ", CASE);
   ++dst;
   int ans = Eval(_hd, _ad, _hk, _ak);
   if(ans >= oo / 2) printf("IMPOSSIBLE\n");
   else printf("%d\n", ans);
 }
 
 int main(){
   int q;
   scanf("%d", &q);
   while(q-- > 0) Doit();
   return 0;
 }
