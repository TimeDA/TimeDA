#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <set>
 #include <map>
 
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 
 int mat[2000][2000];
 
 
 void solve(){
   
   int W = in();
   int H = in();
   int B = in();
   
   int i,j,k;
   
   for(i=0;i<W+5;i++)
     for(j=0;j<H+5;j++) mat[i][j] = (i*j==0)||(i==W+1)||(j==H+1) ? 0 : 1;
   
   for(i=0;i<B;i++){
     int x0 = in()+1;
     int y0 = in()+1;
     int x1 = in()+1;
     int y1 = in()+1;
     for(j=x0;j<=x1;j++)
       for(k=y0;k<=y1;k++) mat[j][k] = 0;
   }
   
   int nm = 0 ;
   for(i=1;i<=W;i++) if(mat[i][1] == 1){
     mat[i][1] = 2;
     nm++;
   }
   
   for(i=2;i<=H;i++){
     int cur = 1;
     
     for(j=1;j<=W;j++) if(mat[j][i-1] == 2){
       mat[j][i] = 2;
       cur++;
     }
     nm = min(nm,cur);
     
     for(j=2;j<=W;j++) if(mat[j-1][i] == 2) mat[j][i] = 2;
     for(j=W-1;j>=1;j--) if(mat[j+1][i] == 2) mat[j][i] = 2;
     
   }
   
   cout << nm << endl;
   
   
 }
 
 int main(){
   for(int i=0,T=in();i<T;i++){
       cout << "Case #"<<i+1<<": ";
       solve();
     }
 }
