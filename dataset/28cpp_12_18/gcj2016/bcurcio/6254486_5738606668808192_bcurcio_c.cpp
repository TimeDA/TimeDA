#include <iostream>
 #include <set>
 #include <string>
 using namespace std;
 
 int n = 9;
 
 int p[40];
 int q[40];
 int r[80];
 
 int count = 0;
 
 set<string> todos;
 
 void mostrar(){
   string s = "";
   int i;
   for(i=2*n-3;i>=0;i--) s+=('0'+r[i]); 
   
   if(todos.count(s)==0){
     todos.insert(s);
     cout << s << ' ';
     
     for(i=2;i<=10;i++){
       long long ans = 0;
       long long p = 1;
       for(int j=0;j<n-1;j++){
         ans += p * (q[n-2-j]-2);
         p*=i;
       }
       
       cout << ans << ' ';
     }
     
     cout << endl;
     count ++;
     if(count == 50) exit(0);
     
   }
   
 }
 bool check(int n){
   int i,j;
   for(i=0;i<2*n;i++) r[i] = 0;
   
   for(i=0;i<n;i++){
     for(j=0;j<n-1;j++){
       r[i+j] += (p[n-1-i]-2) * (q[n-2-j]-2);
     }
   }
   
   //~ mostrar();
   bool vale = true;
   for(i=0;i<2*n;i++) vale &= (r[i]>=0 && r[i]<=1);
   
   return vale;
 }
 
 
 void gen2(int x){
   if(x == n-2){
     q[n-2] = 3;
     if(check(n)) mostrar();
     return;
   }
   
   q[x] = 0;
   gen2(x+1);
   
   q[x] = 1;
   gen2(x+1);
   
   q[x] = 2;
   gen2(x+1);
   
   q[x] = 3;
   gen2(x+1);
 }
 
 
 void gen(int x){
   
   if(x==n-1){
     p[n-1] = 3;
     q[0] = 3;
     gen2(1);
     return;
   }
   
   p[x] = 0;
   gen(x+1);
   
   p[x] = 1;
   gen(x+1);
   
   p[x] = 2;
   gen(x+1);
   
   p[x] = 3;
   gen(x+1);
   
 }
 
 
 int main(){
   
   cout << "Case #1:" << endl;
   p[0] = 3;
   gen(1);
   
 }
