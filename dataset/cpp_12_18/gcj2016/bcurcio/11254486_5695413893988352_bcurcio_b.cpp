#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <string>
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 
 typedef long long ll;
 
 ll mlabs(ll a){
   if(a<0) return -a;
   return a;
 }
 
 
 ll tt(int p, string &a){
   int i;
   ll res = 0;
   for(i=p;i<a.size();i++){
     res *= 10;
     if(a[p]=='?') res+=9;
     else res += (a[p] -'0');
   }
   
   return res;
   
 }
 
 void fun(string &a, string &b, ll s1, ll s2, ll l1, ll l2, ll pt,int i){
   
           int nb = b[i] - '0';
           int na = max(nb - 1,0);
           ll curdif;
           ll dif =mlabs(  (na * pt + l1) - (nb * pt + s2) );
           a[i] = na+'0';
           curdif = mlabs(  (na * pt + s1) - (nb * pt + s2) );
           if(curdif < dif){
             dif = curdif;
             a[i] = na+'0';
           }
           curdif = mlabs(  (na * pt + s1) - (nb * pt + l2) );
           if(curdif < dif){
             dif = curdif;
             a[i] = na+'0';
           }
           curdif = mlabs(  (na * pt + l1) - (nb * pt + s2) );
           if(curdif < dif){
             dif = curdif;
             a[i] = na+'0';
           }
           curdif = mlabs(  (na * pt + l1) - (nb * pt + l2) );
           if(curdif < dif){
             dif = curdif;
             a[i] = na+'0';
           }
           
           na = nb;
           curdif = mlabs(  (na * pt + s1) - (nb * pt + s2) );
           if(curdif < dif){
             dif = curdif;
             a[i] = na+'0';
           }
           curdif = mlabs(  (na * pt + s1) - (nb * pt + l2) );
           if(curdif < dif){
             dif = curdif;
             a[i] = na+'0';
           }
           curdif = mlabs(  (na * pt + l1) - (nb * pt + s2) );
           if(curdif < dif){
             dif = curdif;
             a[i] = na+'0';
           }
           curdif = mlabs(  (na * pt + l1) - (nb * pt + l2) );
           if(curdif < dif){
             dif = curdif;
             a[i] = na+'0';
           }
           
           
           na = min(nb+1, 9);
           curdif = mlabs(  (na * pt + s1) - (nb * pt + l2) );
           if(curdif < dif){
             dif = curdif;
             a[i] = na+'0';
           }
           curdif = mlabs(  (na * pt + s1) - (nb * pt + s2) );
           if(curdif < dif){
             dif = curdif;
             a[i] = na+'0';
           }
           curdif = mlabs(  (na * pt + s1) - (nb * pt + l2) );
           if(curdif < dif){
             dif = curdif;
             a[i] = na+'0';
           }
           curdif = mlabs(  (na * pt + l1) - (nb * pt + s2) );
           if(curdif < dif){
             dif = curdif;
             a[i] = na+'0';
           }
           curdif = mlabs(  (na * pt + l1) - (nb * pt + l2) );
           if(curdif < dif){
             dif = curdif;
             a[i] = na+'0';
           }
 }
 
 ll ss(int p, string &a){
   int i;
   ll res = 0;
   for(i=p;i<a.size();i++){
     res *= 10;
     if(a[p]=='?') res+=0;
     else res += (a[p] -'0');
   }
   
   return res;
   
 }
 
 
 
 void solve(){
   string a,b;
   
   cin >> a >> b;
   
   int n = a.size();
   int i;
   long long dif = 0;
   
   for(i=0;i<n;i++) if(a[i]!=b[i] && a[i]!='?' && b[i]!='?'){
   }
   
   for(i=0;i<n;i++){
     dif*= 10;
     
     if(dif == 0){
       if(a[i] == '?' && b[i] == '?' ) a[i] = b[i] = '0';
       
       if(a[i]=='?' || b[i]=='?'){
         int pp = n-i-1;
         long long pt = 1;
         while(pp){
           pp--;
           pt*=10;
         }
         
         int l1 = tt(i+1,a);
         int l2 = tt(i+1,b);
         int s1 = ss(i+1,a);
         int s2 = ss(i+1,b);
         
         if(a[i] == '?'){
           fun(a,b,s1,s2,l1,l2,pt,i);
         }
         
         if(b[i] == '?'){
           fun(b,a,s2,s1,l2,l1,pt,i);
         }
         
         
       
       }
     }
     if(dif>0){
       if(a[i] == '?') a[i]='0';
       if(b[i] == '?') b[i]='9';
     }
     if(dif<0){
       if(a[i] == '?') a[i]='9';
       if(b[i] == '?') b[i]='0';
     }
     
     int na = a[i]-'0';
     int nb = b[i]-'0';
     
     dif += (na - nb);
      
   }
   
   cout << a << " " << b << endl;
   
 }
 
 
 int main(){
   for(int i=0,T=in();i<T;i++){
       cout << "Case #" << i+1 << ": ";
       solve();
     }
 }
