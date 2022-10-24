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
 void Doit(){
   ++CASE;
   cerr << "Case: " << CASE << endl;
 
   ll n, k;
   cin >> n >> k;
 
   ll last;
   map<ll, ll> cnt;
   cnt[n] = 1;
 
   while(k > 0){
     auto e = *cnt.rbegin();
     ll len = e.fi, how = e.se;
     cnt.erase(len);
 
     if(how == 0) continue;
 
     ll sa = (len - 1) >> 1,
        sb = len - 1 - sa;
 
     ll take = min(k, how);
     k -= take;
     last = len;
 
     if(sa > 0) cnt[sa] += take;
     if(sb > 0) cnt[sb] += take;
     if(how > take) cnt[len] += how - take;
   }
 
   cout << "Case #" << CASE << ": ";
   ll sa = (last - 1) >> 1,
      sb = last - 1 - sa;
   if(sa < sb) swap(sa, sb);
   cout << sa << ' ' << sb << '\n';
 }
 
 int main(){
   int q;
   cin >> q;
   while(q-- > 0) Doit();
 
   return 0;
 }
