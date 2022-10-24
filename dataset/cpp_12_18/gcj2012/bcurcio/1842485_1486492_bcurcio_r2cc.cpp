#include <algorithm>
 #include <bitset>
 #include <cmath>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <ctime>
 #include <deque>
 #include <functional>
 #include <iomanip>
 #include <iostream>
 #include <iterator>
 #include <list>
 #include <map>
 #include <numeric>
 #include <queue>
 #include <set>
 #include <sstream>
 #include <stack>
 #include <string>
 #include <utility>
 #include <vector>
 
 using namespace std;
 
 #define PB push_back
 #define SZ(X) ((int)(X.size()))
 #define ALL(X) (X).begin(), (X).end()
 #define FE(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
 #define MOD 1000000007ll
 
 const double PI=acos(-1.0);
 const double EPS=1e-10;
 
 typedef long long ll;
 typedef vector<int> vint;
 typedef vector<vint> vvint;
 typedef pair<int,int> pii;
 typedef vector<pii> vpii;
 typedef vector<string> vstr;
 int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
 #define MAXN 2200
 
 vint hij[MAXN];
 
 int usado[MAXN];
 int sol[MAXN];
 int cvec[MAXN];
 
 void init(int x){
   memset(cvec,0,sizeof cvec);
   int i;
   for(i=0;i<=x;i++) hij[i].clear();
 }
 
 void add_edge(int u,int v){
   cvec[u]++;
   hij[v].push_back(u);
 }
 
 void sacar(int u, int h){
   sol[u]=h;
   usado[u]=1;
   int i;
   for(i=0;i<hij[u].size();i++){
     cvec[hij[u][i]]--;
   }
 }
 
 int x[MAXN];
 
 void solve(){
   int N=in();
   init(N);
   
   int i,j;
   
   for(i=0;i<N-1;i++) x[i]=in()-1;
   int inc=2;
   int ss; int ant=1;
   sol[0]=1;
   for(i=1;i<N;i++) { sol[i]=inc; ss=inc; inc+=ant; ant=ss;  }
   bool can;
   ll best;
   bool done=false;
   
   do{
     
     can=true;
     
     for(i=0;i<N-1;i++){
       
       best=i+1;
       
       for(j=i+2;j<N;j++){
         if ((sol[best]-sol[i])<0 && (sol[j]-sol[i])<0 ){
           if( (sol[best]-sol[i])*(j-i)> (sol[j]-sol[i])*(best-i) )  best=j;
         }
         else{
           if( (sol[best]-sol[i])*(j-i)< (sol[j]-sol[i])*(best-i) )  best=j;
         }
       }
       
       
       if(best!=x[i]){
         can=false;
         break;
       }
     }
     
     
     if(can){
       done=true;
       break;
     }
     
   } while( next_permutation(sol,sol+N));
   
   if(!done){
   inc=1;
   sol[0]=1;
   for(i=1;i<N;i++) { sol[i]=inc; inc*=2;  }
   do{
     
     can=true;
     
     for(i=0;i<N-1;i++){
       
       best=i+1;
       
       for(j=i+2;j<N;j++){
         if ((sol[best]-sol[i])<0 && (sol[j]-sol[i])<0 ){
           if( (sol[best]-sol[i])*(j-i)> (sol[j]-sol[i])*(best-i) )  best=j;
         }
         else{
           if( (sol[best]-sol[i])*(j-i)< (sol[j]-sol[i])*(best-i) )  best=j;
         }
       }
       
       
       if(best!=x[i]){
         can=false;
         break;
       }
     }
     
     
     if(can){
       done=true;
       break;
     }
     
   } while( next_permutation(sol,sol+N));
   }
   
   if(!done){
   inc=2;
   sol[0]=1;
   for(i=1;i<N;i++) { sol[i]=inc; inc++;  }
   do{
     
     can=true;
     
     for(i=0;i<N-1;i++){
       
       best=i+1;
       
       for(j=i+2;j<N;j++){
         if ((sol[best]-sol[i])<0 && (sol[j]-sol[i])<0 ){
           if( (sol[best]-sol[i])*(j-i)> (sol[j]-sol[i])*(best-i) )  best=j;
         }
         else{
           if( (sol[best]-sol[i])*(j-i)< (sol[j]-sol[i])*(best-i) )  best=j;
         }
       }
       
       
       if(best!=x[i]){
         can=false;
         break;
       }
     }
     
     
     if(can){
       done=true;
       break;
     }
     
   } while( next_permutation(sol,sol+N));
   }
   
   
   if(!done){
   inc=2;
   sol[0]=1;
   for(i=1;i<N;i++) { sol[i]=sol[i-1]+inc; inc=rand()%10;  }
   do{
     
     can=true;
     
     for(i=0;i<N-1;i++){
       
       best=i+1;
       
       for(j=i+2;j<N;j++){
         if ((sol[best]-sol[i])<0 && (sol[j]-sol[i])<0 ){
           if( (sol[best]-sol[i])*(j-i)> (sol[j]-sol[i])*(best-i) )  best=j;
         }
         else{
           if( (sol[best]-sol[i])*(j-i)< (sol[j]-sol[i])*(best-i) )  best=j;
         }
       }
       
       
       if(best!=x[i]){
         can=false;
         break;
       }
     }
     
     
     if(can){
       done=true;
       break;
     }
     
   } while( next_permutation(sol,sol+N));
   }
   
   if(!done){
   inc=2;
   sol[0]=1;
   for(i=1;i<N;i++) { sol[i]=sol[i-1]+inc; inc=rand()%10;  }
   do{
     
     can=true;
     
     for(i=0;i<N-1;i++){
       
       best=i+1;
       
       for(j=i+2;j<N;j++){
         if ((sol[best]-sol[i])<0 && (sol[j]-sol[i])<0 ){
           if( (sol[best]-sol[i])*(j-i)> (sol[j]-sol[i])*(best-i) )  best=j;
         }
         else{
           if( (sol[best]-sol[i])*(j-i)< (sol[j]-sol[i])*(best-i) )  best=j;
         }
       }
       
       
       if(best!=x[i]){
         can=false;
         break;
       }
     }
     
     
     if(can){
       done=true;
       break;
     }
     
   } while( next_permutation(sol,sol+N));
   }
   if(!done) puts(" Impossible");
   else { for(i=0;i<N;i++) printf(" %d",sol[i]); puts("");}
   
 
 }
 
 int main(){
 	//freopen("C.in","r",stdin);
 	//freopen("C-small-attempt0.in","r",stdin); 
 	//freopen("C-small-attempt1.in","r",stdin); 
 	//freopen("C-small-attempt2.in","r",stdin); 
 	//freopen("C-small-attempt3.in","r",stdin); 
 	//freopen("C-small-attempt4.in","r",stdin); 
 	freopen("C-small-attempt5.in","r",stdin); 
 	//freopen("C-large.in","r",stdin);
   freopen("Cout","w",stdout);
   
   int C=in();
   for(int caso=1;caso<=C;caso++){
     printf("Case #%d:",caso);
     solve();
   }
   
   return 0;
 }
 
 
