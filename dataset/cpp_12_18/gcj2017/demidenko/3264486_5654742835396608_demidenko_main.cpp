#include <bits/stdc++.h>
 using ll = long long;
 using namespace std;
 
 void solve(int tt){
     ll n, k;
     cin>>n>>k;
     
     map<ll,ll> a;
     a[n] = 1;
     for(;;){
         auto i = a.end();
         --i;
         a.erase(i);
         ll x = i->first, y = i->second;
         ll z = (x-1)/2;
         if(k<=y){
             cout<<"Case #"<<tt<<": "<<x-1-z<<' '<<z<<endl;
             return ;
         }
         k-=y;
         a[z]+=y;
         a[x-1-z]+=y;
     }
 }
 
 int main()
 {
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
     
     int t;
     cin>>t;
     for(int i=1;i<=t;++i) solve(i);
     
     return 0;
 }
