#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 
 typedef long long ll;
 
 #define EPS 1e-9
 
 ll readD(){
   string str;
   cin >> str;
   
   int pl = 0;
   ll ans = 0;
   int i;
   for(i=0;i<(int)str.size();i++){
     if(str[i]=='.'){
       pl = i;
       continue;
     }
     
     ans*= 10;
     ans+=(str[i]-'0');
     
   }
   
   return ans;
 }
 
 void solve(){
   int N = in();
   ll V,X;
   V = readD();
   X = readD();
   
   
   
   
   int i;
   double ans = -1;
   
   ll antr, antt = -1;
   for(i=0;i<N;i++){
     ll r,t;
     
     r = readD();
     t = readD();
     
     if(t==X){
       double anst = (V*1.) / r;
       if(ans<0 || anst<ans){
         ans = anst;
       }
     }
     
     if(antt>=0){
       
       if(antt == t && t==X){
         
         double anst = (V*1.) / (r+antr);
           if(ans<0 || anst<ans){
             ans = anst;
           }
               
         
         break;
       }
       
       
       double v0 = (V* 1.*(X-t) ) / (antt-t);
       double v1 = V-v0;
       
       
       if(antt<X && t <X) break;
       if(antt>X && t >X) break;
       
       
       
       double anst = max(v0/antr, v1/r);
       if(ans<0 || anst < ans){
         ans = anst;
       }
       
       
     }
     
     antt = t;
     antr = r;
     
   }
   
   
   
   if(ans<0){
     puts("IMPOSSIBLE");
   }else{
     printf("%.9lf\n",ans);
   }
   
 }
 
 int main(){
   
   //~ freopen("test","r",stdin);
   for(int i=0,T=in();i<T;i++){
     cout << "Case #"<<i+1<<": ";
       solve();
     }
 }
