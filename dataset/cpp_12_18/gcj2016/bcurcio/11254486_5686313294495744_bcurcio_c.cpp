#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <string>
 #include <vector>
 
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 
 
 int adja[1040][1050];
 int adjb[1040][1050];
 int used[1040];
 
 
 bool check(vector<int> &ids, int N){
   int i,j,k;
   
   int ni = ids.size();
   
   for(i=0;i<ni;i++)
   for(j=0;j<ni;j++) if(i!=j && adja[ids[i]][ids[j]])
   for(k=0;k<ni;k++) if(j!=k && adjb[ids[j]][ids[k]]) return false;
   
   
   for(i=0;i<N;i++){
     bool sk = false;
     for(j=0;j<ni;j++) if(ids[j]==i) sk = true; 
     if(sk) continue;
     
     for(j=0;j<ni;j++)
     for(k=0;k<ni;k++) if(adja[ids[j]][i] && adjb[ids[k]][i]) sk = true;
     
     if(!sk) return false;
     
   }
    
   return true;
 }
 
 void solve(){
   int N = in();
   
   vector<string> ta(N);
   vector<string> tb(N);
   
   int i,j;
   for(i=0;i<N;i++){
     used[i] = 0;
     cin >> ta[i] >> tb[i];
   }
   
   for(i=0;i<N;i++)
     for(j=0;j<N;j++){
       adja[i][j] = (ta[i] == ta[j]) ? 1 : 0;
       adjb[i][j] = (tb[i] == tb[j]) ? 1 : 0;
     }
   
   int fake = 0;
   
   for(i=0;i<(1<<N);i++){
     int sz = __builtin_popcount(i); 
     if(sz<2) continue;
     if(N-sz <= fake) continue;
     //~ cerr << sz << endl;
     vector<int> ids;
     for(j=0;j<N;j++) if(i&(1<<j)) ids.push_back(j);
     
     if(check(ids,N)){
       fake = N-sz;
     }
     
   }
   
   
   cout << fake << endl;
   
 }
 
 int main(){
   for(int i=0,T=in();i<T;i++){
       cout << "Case #" << i+1 << ": ";
       solve();
     }
 }
