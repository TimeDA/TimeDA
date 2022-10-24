#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <vector>
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 
 int can[1<<13];
 int M;
 
 void doit(vector<int> &o,int s, int e){
   if(s>=e) return;
   vector<int> aux2;
   int i,j;
   ///cerr << endl << "ROUND " << s<< ' ' <<e<< endl;
   ///for(i=0;i<o.size();i++) cerr << o[i] << ' ';
   ///cerr << endl;
   
   for(i=0;i<(e-s+1)/2;i++){
     int t1 = o[s+2*i];
     int t2 = o[s+2*i+1];
     o[s+i] = (min(t1,t2));
     aux2.push_back(max(t1,t2));
   }
   
   for(j=0;j<(int)aux2.size();j++) o[s+i++] = aux2[j];
   
   ///for(i=0;i<o.size();i++) cerr << o[i] << ' ';
   ///cerr << endl;
   
   doit(o,s,(s+e)/2);
   doit(o,(s+e)/2+1,e);
 }
 
 
 void solve(){
   srand(time(NULL));
   int N = in();
   M = 1<<N;
   int P = in();
   int ans1 = 0;
   int ans2 = 0;
   int i,j;
   memset(can,1,sizeof can);
   int k;
   for(k=0;k<M;k++){
     vector<int> o2;
     o2.push_back(k);
     for(j=M-1;j>=0;j--) if(k!=j) o2.push_back(j);
     
     doit(o2,0,M-1);
     for(i=0;i<P;i++) ans2 = max(ans2,o2[i]);
     for(;i<M;i++) can[o2[i]] = 0;
   }
   for(k=0;k<M;k++){
     vector<int> o2;
     for(j=M-1;j>=0;j--) if(k!=j) o2.push_back(j);
     o2.push_back(k);
     
     doit(o2,0,M-1);
     for(i=0;i<P;i++) ans2 = max(ans2,o2[i]);
     for(;i<M;i++) can[o2[i]] = 0;
   }
   
   ///vector<int> order;
   ///for(i=0;i<M;i++) order.push_back(i);
   ///
   ///for(k=0;k<900;k++){
     ///random_shuffle(order.begin(),order.end());
     ///doit(order,0,M-1);
     ///for(i=0;i<P;i++) ans2 = max(ans2,order[i]);
     ///for(;i<M;i++) can[order[i]] = 0;
   ///}
   
   
   for(i=0;i<M;i++) if(can[i]) ans1 = i; else break;
   
   cout << ans1 << ' ' << ans2 << endl;
 }
 
 int main(){
   for(int i=0,T=in();i<T;i++){
     cerr << i  << endl;
     printf("Case #%d: ",i+1);
       solve();
   }
 }
