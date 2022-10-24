#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <queue>
 #include <map>
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 
 typedef long long ll;
 typedef pair<ll,ll> pll;
 
 
 void solve(){
   ll n,k;
   cin >> n >> k;
   
   priority_queue<ll> pq;
   pq.push(n);
   
   ll acum = 0;
   
   map<ll,ll> cant;
   cant[n] = 1;
   
   while(1){
     
     ll cur = pq.top();
     ll c = cant[cur];
     pq.pop();
     
     //~ cerr << cur <<  ' ' << c << endl;
     
     ll a = (cur - 1) / 2;
     ll b = (cur - 1) - a;
     
     if(acum + c >= k){
       cout << max(a,b) << ' ' << min(a,b) << endl;
       return;
     }else{
       if(cant[a] == 0){
         pq.push(a);
       }
       cant[a] += c;
       
       if(cant[b] == 0){
         pq.push(b);
       }
       cant[b] += c;
       
       acum += c;
     }
     
   }
   
   
 }
 
 int main(){
   for(int i=0,T=in();i<T;i++){
       cout << "Case #"<<i+1<< ": ";
       solve();
     }
 }
