#include <bits/stdc++.h>
 using namespace std;
 
 
 void put_case(){
   static int t = 1;
   printf("Case #%d: ",t++);
 }
 
 int tr,ts,tp;
 string f(char c,int d){
   if( d == 0 ){
     if( c == 'R' ) tr++;
     else if( c == 'S' ) ts++;
     else tp++;
     return string(1,c); 
   }else{
     if( c == 'R' ){
       string a = f('S',d-1);
       string b = f('R',d-1);
       if( a < b ) return a + b;
       else return b + a;
     }
     if( c == 'S' ){
       string a = f('S',d-1);
       string b = f('P',d-1);
       if( a < b ) return a + b;
       else return b + a;
     }
     if( c == 'P' ){
       string a = f('P',d-1);
       string b = f('R',d-1);
       if( a < b ) return a + b;
       else return b + a;
     }
   }
 
 }
 int main(){
   int T;
   cin >> T;
   while(T--){
     put_case();
     int n,r,s,p;
     cin >> n >> r >> p >> s;
     int ok = 0;
     string ans = "~";
     for( auto c : string("RSP") ){
       tr = tp = ts = 0;
       string res = f(c,n);
 
       if( tr == r and tp == p and ts == s ){
         ans = min(ans,res);
       }
     }
     if(ans == "~"){
       cout << "IMPOSSIBLE" << endl;
     }else{
       cout << ans << endl;
     }
   }
 }
