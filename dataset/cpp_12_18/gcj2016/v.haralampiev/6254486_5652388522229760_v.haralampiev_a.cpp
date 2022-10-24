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
 
 vi Digs(ll w){
   vi res;
   while(w > 0) res.pb(w % 10), w /= 10;
   return res;
 }
 
 ll Go(ll w){
   vi nal(10, 0);
   ll last = 0;
   while(count(all(nal), 0) > 0){
     last += w;
     auto cur = Digs(last);
     for(int d : cur) nal[d] = 1;
   }
   return last;
 }
 
 void Solve(int CASE){
   ll n;
   cin >> n;
 
   cout << "Case #" << CASE << ": ";
   if(n == 0) cout << "INSOMNIA\n";
   else cout << Go(n) << '\n';
 }
 
 int main(){
   int q;
   cin >> q;
   for(int i = 1;i <= q;++i) Solve(i);
   return 0;
 }
