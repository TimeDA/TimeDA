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
 
 char End(const string& w){
   return w[sz(w) - 1];
 }
 
 string Comp(const string& w){
   string res;
   for(char c : w)
     if(res.empty() || End(res) != c)
       res += c;
   return res;
 }
 
 void Solve(int CASE){
   cerr << "Case: " << CASE << '\n';
   string in;
   cin >> in;
   in = Comp(in);
 
   cout << "Case #" << CASE << ": ";
 
   if(End(in) == '-') cout << sz(in) << '\n';
   else cout << sz(in) - 1 << '\n';
 }
 
 int main(){
   int q;
   cin >> q;
   for(int i = 1;i <= q;++i)
     Solve(i);
   return 0;
 }
