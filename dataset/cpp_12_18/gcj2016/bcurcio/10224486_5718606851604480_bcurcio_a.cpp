#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 
 string aux;
 int R,P,S;
 int N;
 
 bool valid(const string &s, int R, int P, int S){
   if(count(s.begin(),s.end(),'R') != R) return false;
   if(count(s.begin(),s.end(),'P') != P) return false;
   if(count(s.begin(),s.end(),'S') != S) return false;
   return true;
 }
 
 string solve2(char c, int r){
   if(r == N){
     string ans = "";
     ans += c;
     return ans;
   }
   
   
   if(c=='P'){
     string a2 = solve2('P',r+1);
     string a3 = solve2('R',r+1);
     if(a2<a3) return a2+a3;
     else return a3+a2;
   }
   
   if(c=='R'){
     
       string a2 = solve2('R',r+1);
       string a3 = solve2('S',r+1);
       if(a2<a3) return a2+a3;
       else return a3+a2;
   }
   
   if(c=='S'){
     string a2 = solve2('P',r+1);
     string a3 = solve2('S',r+1);
     if(a2<a3) return a2+a3;
     else return a3+a2;
   }
   
   return "";
 }
 
 
 
 void solve(){
   
   N = in();
   R = in();
   P = in();
   S = in();
   
   aux = solve2('P',0);
   
   //~ cout << aux << endl;
   if(valid(aux,R,P,S)){
     cout << aux << endl;
     return;
   }
   
   aux = solve2('R',0);
   
   //~ cout << aux << endl;
   if(valid(aux,R,P,S)){
     cout << aux << endl;
     return;
   }
   
   aux = solve2('S',0);
   
   //~ cout << aux << endl;
   if(valid(aux,R,P,S)){
     cout << aux << endl;
     return;
   }
   
   cout << "IMPOSSIBLE" << endl;
   
 }
 
 int main(){
   for(int i=0,T=in();i<T;i++){
       cout << "Case #"<<i+1 << ": ";
       solve();
   }
 }
