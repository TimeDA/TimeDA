#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 typedef long long ll;
 
 bool istidy(ll x){
   int ant = 10;
   
   while(x>0){
     if(x%10 > ant) return false;
     ant = x%10;
     x/=10;
   }
   return true;
 }
 
 void solve(){
   ll n;
   cin >> n;
   
   vector<ll> cand;
   
   ll tail = 0;
   ll pt = 1;
   
   ll ans = -1;
   if(istidy(n)) ans = n;
   ll no = n;
   
   while(n>0){
     
     ll aux = (n-1) * pt + tail;
     //~ cerr << aux << ' ' << istidy(aux) << endl;
     if(aux>ans && aux <= no && istidy(aux)) ans = aux;
     
     n /= 10;
     pt *= 10;
     tail = tail * 10 +9;
   }
   
   cout << ans << endl;
   
 }
 
 int main(){
   for(int i=0,T=in();i<T;i++){
       cout << "Case #"<<i+1 << ": ";
       solve();
     }
 }
