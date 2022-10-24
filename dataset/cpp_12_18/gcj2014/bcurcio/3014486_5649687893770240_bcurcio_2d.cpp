#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <set>
 #include <map>
 
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 #define FE(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
 int T[100];
 
 int mxnodes,ways;
 int M,N;
 
 string str[100];
 
 struct trie{
   char cur;
   map<char,trie> nst;
   trie(){}
 } root;
 
 int dfs(trie &t){
   int chl = 1;
   FE(t.nst,it){
     //*cerr << " entra " << endl;
     chl += dfs(it->second);
   }
   //*cerr << "   " << chl << endl;
   return chl;
 }
 
 void check(){
   int i,j;
   int nodes = 0;
   //*cerr << "check " << endl;
   for(i=0;i<N;i++){
       trie root;
       //*cerr << "server " << i << endl;
       bool has = false;
       for(j=0;j<M;j++){
         
         if(T[j]==i){
           //*cerr << "string " << j << endl;
           has = true;
           
           string cur = str[j];
           unsigned pos = 0;
           trie *act = &root;
           
           while(pos!=cur.size()){
             act = &(act->nst[cur[pos]]);
             pos++;
           }
           
         }
       }
       
       if(!has) return;
       int aux = dfs(root);
       //*cerr << "nodes ****** " << aux << endl;
       nodes += aux;
       
   }
 
 
       //*cerr << "nodestotal ****** " << nodes << endl;
   if(nodes == mxnodes) ways++;
   if(nodes > mxnodes){
     mxnodes = nodes;
     ways = 1;
   }
 }
 
 
 void parti(int pos){
   if(pos==M){
     check();
     return;
   }
   
   int i;
   for(i=0;i<N;i++){
     T[pos] = i;
     parti(pos+1);
   }
   
   
 }
 
 void solve(){
   M = in();
   N = in();
   mxnodes = -1;
 
   int i;
   for(i=0;i<M;i++){
     cin >> str[i];
   }
   
   
   if(M==1){
     cout << str[0].size()+1 << ' ' << 1<<  endl;
     return; 
   }
   
   parti(0);
   
   
   cout << mxnodes << ' ' << ways << endl;
 }
 
 int main(){
   for(int i=0,T=in();i<T;i++){
       cout << "Case #"<<i+1<<": ";
       solve();
     }
 }
