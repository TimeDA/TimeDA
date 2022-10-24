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
 
 int CASE = 0;
 
 int n;
 vector<vi> in;
 
 void Solve(){
   CASE++;
   cerr << "Case: " << CASE << "\n";
 
   scanf("%d", &n);
   in.resize(2 * n - 1);
   for(int i = 0;i < sz(in);++i){
     in[i].resize(n);
     for(int j = 0;j < sz(in[i]);++j)
       scanf("%d", &in[i][j]);
   }
 
   map<int, int> cnt;
   for(int i = 0;i < sz(in);++i)
     for(int v : in[i])
       ++cnt[v];
 
   vi out;
   for(const auto p : cnt)
     if(p.se & 1) out.pb(p.fi);
 
   sort(all(out));
 
   printf("Case #%d: ", CASE);
   for(int i = 0;i < sz(out);++i)
     printf("%d%c", out[i], (i + 1 == sz(out) ? '\n' : ' '));
 }
 
 int main(){
   int q;
   scanf("%d", &q);
   while(q-- > 0) Solve();
   return 0;
 }
