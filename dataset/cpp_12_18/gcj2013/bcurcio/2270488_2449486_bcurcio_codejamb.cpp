#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <vector>
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 typedef pair<int,int> pii;
 typedef pair<int,pii> piii;
 
 int mat[111][111];
 int obj[111][111];
 void solve(){
   int N=in();
   int M=in();
   int i,j;
   for(i=0;i<N;i++) for(j=0;j<M;j++) mat[i][j]= 100;
   
   vector<piii> cells;
   for(i=0;i<N;i++) for(j=0;j<M;j++){
     int val = in();
     obj[i][j] = val;
     cells.push_back(piii(-val,pii(i,j)));
   }
   //puts("asdasd");
   //for(i=0;i<N;cerr<<endl,i++) for(j=0;j<M;j++)cerr << obj[i][j] << ' ';
   //puts("asdasd");
   sort(cells.begin(),cells.end());
   
   for(i=0;i<N*M;i++){
     piii aux = cells[i];
     int h = -aux.first;
     int x = aux.second.first;
     int y = aux.second.second;
     bool vale = true;
     //cerr << x << ' ' << y << ' ' << h << endl;
     
     //for(j=0;j<M;j++) cerr << obj[x][j] << " . "; cerr << endl;
     for(j=0;j<M;j++) if(obj[x][j]>h) vale=false;
     if(vale){
       //for(j=0;j<M;j++) mat[x][j]=h;
       continue;
     }
     
     vale=true;
     //for(j=0;j<N;j++) cerr << obj[j][y] << " . "; cerr << endl;
     for(j=0;j<N;j++) if(obj[j][y]>h) vale=false;
     if(vale){
       //for(j=0;j<N;j++) mat[j][y]=h;
       continue;
     }
     
     
     puts("NO");
     return;
   }
   
   puts("YES");
   
 }
 
 int main(){
   for(int i=0,T=in();i<T;i++){
       cout << "Case #"<<i+1<<": ";
       solve();
     }
 }
