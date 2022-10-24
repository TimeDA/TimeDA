#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 
 char mat[100][100];
 char sol[100][100];
 bool can;
 
 int R,C,M;
 
 int dx[] = { 1, 1, 1, 0, 0,-1,-1,-1};
 int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
 
 void check(){
   int i,j,k;
   for(i=1;i<=R;i++)
     for(j=1;j<=C;j++){
       if(mat[i][j]!='*') mat[i][j] = 0;
     }
     
   for(i=1;i<=R;i++){
     for(j=1;j<=C;j++) if(mat[i][j]=='*'){
       for(k=0;k<8;k++) if(mat[i+dx[k]][j+dy[k]]!='*')mat[i+dx[k]][j+dy[k]]++;
     }
   }
   
   int count = 0;
   
   for(i=1;i<=R;i++){
     for(j=1;j<=C;j++) if(mat[i][j]==0) count++;
     }
   
   //*for(i=1;i<=R;i++){
     //*for(j=1;j<=C;j++) cout << (int)mat[i][j] ;
     //*cout << endl;
   //*}
   
   if(M!=R*C-1){
     for(i=1;i<=R;i++)
       for(j=1;j<=C;j++) if(mat[i][j]!='*' && (count>1 || mat[i][j]!=0)){
         bool cortar = true;
         for(k=0;k<8 && cortar;k++)
           if(i+dx[k]>0 && i+dx[k]<=R) 
             if(j+dy[k]>0 && j+dy[k]<=C) 
              if(mat[i+dx[k]][j+dy[k]]==0) cortar = false;
         if(cortar) return;
       }
     
     bool puse = false;
     for(i=1;i<=R;i++){
       for(j=1;j<=C;j++){
         if(mat[i][j] == '*') sol[i][j] = '*';
         else if(mat[i][j] > 0) sol[i][j] = '.';
         else if(puse) sol[i][j] = '.';
         else{
           puse = true;
           sol[i][j] = 'c';
         }
       }
     }  
       
   }else{
     for(i=1;i<=R;i++)
       for(j=1;j<=C;j++){
           sol[i][j] = mat[i][j]=='*'?'*':'c';
       }
   }
     
   can = true;
 }
 
 
 void dfs(int x,int y, int m){
   if(m==0){
     check();
     return;
   }
     
   if(x==R+1) return;
   
   if(y==C+1){
     dfs(x+1,1,m);
     return;
   }
   
   if(!can){
     m = m-1;
     mat[x][y] = '*';
     dfs(x,y+1,m);
     mat[x][y] = '.';
     m = m+1;
   }
   
   if((R-x)*C+(C-y) < m) return;
 
   if(!can) dfs(x,y+1,m);
 }
 
 void solve(){
   R = in();
   C = in();
   M = in();
   
   int i,j;
   for(i=1;i<=R;i++) for(j=1;j<=C;j++) mat[i][j] = 0;
   
   can = false;
   dfs(1,1,M);
   
   if(can){
     for(i=1;i<=R;i++){
       for(j=1;j<=C;j++)
         cout<< sol[i][j] ;
       cout << endl;
     }
   }else{
     cout << "Impossible" << endl;
     
   }
   
 }
 
 int main(){
   for(int i=0,T=in();i<T;i++){
       cout <<"Case #"<<i+1<<": " <<endl;;;;;;;;;;;;;;
       solve();
     }
 }
