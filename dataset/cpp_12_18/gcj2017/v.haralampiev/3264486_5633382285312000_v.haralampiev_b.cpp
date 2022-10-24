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
 
 char in[110];
 vi Read(){
   vi res;
 
   scanf("%s", in);
   int n = strlen(in);
   for(int i = 0;i < n;++i)
     res.pb(in[i] - '0');
 
   return res;
 }
 
 ll ToLL(const vi& w){
   ll res = 0;
   for(int i = 0;i < sz(w);++i)
     (res *= 10) += w[i];
   return res;
 }
 
 int CASE = 0;
 void Doit(){
   ++CASE;
   cerr << "Case: " << CASE << endl;
 
   auto n = Read();
   ll res = -1;
 
   if(sz(n) > 1)
     relaxMax(res, ToLL(vi(sz(n) - 1, 9)));
 
   while(n[0] > 0){
     int bad;
     for(bad = 0;bad + 1 < sz(n);++bad)
       if(n[bad] > n[bad + 1]) break;
 
     if(bad + 1 >= sz(n)){
       relaxMax(res, ToLL(n));
       break;
     } else {
       --n[bad];
       for(int j = bad + 1;j < sz(n);++j)
         n[j] = 9;
     }
   }
 
   cout << "Case #" << CASE << ": ";
   cout << res << '\n';
 }
 
 int main(){
   int q;
   cin >> q;
   while(q-- > 0) Doit();
 
   return 0;
 }
