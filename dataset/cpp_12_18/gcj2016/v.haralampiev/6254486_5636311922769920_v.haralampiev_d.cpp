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
 
 ll k, c, s;
 
 ll Pow(ll a, ll to){
   ll res = 1;
   for(;to > 0;to >>= 1, a = a * a)
     if(to & 1) res *= a;
   return res;
 }
 
 ll Id(const vi& p){
   ll res = 0;
   for(int i = 0;i < sz(p);++i)
     if(p[i] > 1)
       res += (p[i] - 1) * Pow(k, sz(p) - i - 1);
   return res + 1;
 }
 
 vector<vi> Group(){
   vector<vi> res;
   for(int i = 1;i <= k;i += c){
     res.pb(vi());
     for(int j = i;j < i + c;++j)
       res.back().pb(min((ll) j, k));
   }
   return res;
 }
 
 void Solve(int CASE){
   cerr << "Case: " << CASE << endl;
 
   cin >> k >> c >> s;
   auto out = Group();
 
   cout << "Case #" << CASE << ": ";
 
   if(sz(out) > s) cout << "IMPOSSIBLE" << '\n';
   else{
     for(int i = 0;i < sz(out);++i)
       cout << Id(out[i]) << (i + 1 == sz(out) ? '\n' : ' ');
   }
 }
 
 int main(){
   int q;
   cin >> q;
   for(int i = 1;i <= q;++i) Solve(i);
   return 0;
 }
