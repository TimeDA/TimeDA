#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <vector>
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 typedef long long ll;
 int cnt;
 ll pot[40];
 char buff[100];
 bool ispal(ll n){
   sprintf(buff,"%lld\0",n);
   int l = strlen(buff);
   int i;
   for(i=0;i<l;i++) if(buff[i]!=buff[l-1-i]) return false;
   return true;
 }
 
 vector<ll> fas;
 
 void gen(ll x,int p){
   if(x>10000000 || (x==0 && p>12)) return;
   int i;
   if(x%10!=0){
     ll z = x*x;
     if(ispal(z)){
       fas.push_back(z);
     }
   }
   
   for(i=0;i<10;i++){
     gen(i*pot[p]+x*10+i,p+2);
   }
 }
 
 void solve(){
   int i;
   
   ll A,B;
   cin>>A>>B;
   
   cnt=0;
   //for(i=0;i<fas.size();i++) cerr << fas[i]<<endl;
   for(i=0;i<fas.size();i++) if(fas[i]>=A && fas[i]<=B){
     cnt++;
   }
   
   cout << cnt<<endl;
 }
 
 int main(){
   pot[0] = 1;
   for(int i=1;i<19;i++) pot[i] = pot[i-1]*10;
   for(int i=0;i<10;i++) gen(i,1+(i?1:0));
   sort(fas.begin(),fas.end());
   for(int i=0,T=in();i<T;i++){
       cout << "Case #"<<i+1<<": ";
       solve();
     }
 }
