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
 void Solve(){
   CASE++;
   cerr << "Case: " << CASE << "\n";
 
   string in;
   string out;
   cin >> in;
 
   for(int i = 0;i < sz(in);++i){
     string a = out + in[i];
     string b = string(1, in[i]) + out;
     if(a >= b) out = a;
     else out = b;
   }
 
   cout << "Case #" << CASE << ": " << out << '\n';
 }
 
 int main(){
   int q;
   cin >> q;
   while(q-- > 0) Solve();
   return 0;
 }
