#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 
 int n,k;
 
 double calc(int m, vector<double> &p){
   int i;
   vector<double> cur;
   
   for(i=0;i<n;i++) if(m&(1<<i)) cur.push_back(p[i]);
   
   double ans = 0;
   int y = cur.size();
   for(i=0;i<(1<<y);i++){
     if(__builtin_popcount(i) != y/2) continue;
     
     int j;
     double act = 1;
     for(j=0;j<y;j++){
       if(i&(1<<j)) act *= cur[j];
       else act *= (1-cur[j]);
     }
     
     ans += act;
   }
   
   return ans;
 }
 
 void solve(){
   n = in();
   k = in();
   
   vector<double> p;
   for(int i=0;i<n;i++){
     double x;
     cin >> x;
     p.push_back(x);
   }
 
   int i;
   
   double last = -1;
   for(i=0;i<(1<<n);i++){
     if(__builtin_popcount(i)!=k) continue;
     
     double prob = calc(i,p);
     
     //~ cerr << prob << endl;
     
     if(prob>last){
       last = prob;
     }
     
   }
   
   cout << last << endl;
   
 }
 
 int main(){
   for(int i=0,T=in();i<T;i++){
       cout << "Case #"<<i+1 << ": ";
       solve();
   }
 }
