#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <vector>
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 
 typedef pair<int,int> pii;
 
 int dr[] = {0, 1, 0 ,-1};
 int dc[] = {1, 0 ,-1, 0};
 int inv[255];
 
 bool inRange(int a,int b, int A, int B){
   if(a<0) return false;
   if(b<0) return false;
   if(a==A) return false;
   if(b==B) return false;
   return true;
 }
 
 void solve(){
   int R = in();
   int C = in();
   int i,j;
   
   vector<string> mapa(R);
   for(i=0;i<R;i++) cin>> mapa[i];
   
   vector<int> acr(R);
   vector<int> acc(C);
   vector<pii> arr;
   for(i=0;i<R;i++)
     for(j=0;j<C;j++){
       if(mapa[i][j] != '.'){
         acr[i]++;
         acc[j]++;
         arr.push_back(pii(i,j));
       }
     }
     
     
   
   int ans = 0;
   
   for(i=0;i<arr.size();i++){
     int r = arr[i].first;
     int c = arr[i].second;
     
     if(acr[r]==1 && acc[c]==1){
       puts("IMPOSSIBLE");
       return;
     }
     
     int dir = inv[mapa[r][c]];
     
     r+= dr[dir];
     c+= dc[dir];
     
     
     while(inRange(r,c,R,C) && mapa[r][c]=='.'){      
       r+= dr[dir];
       c+= dc[dir];
     }
     
     if(!inRange(r,c,R,C)){
       ans++;
     }
     
   }
   
   cout << ans << endl;
   
 }
 
 int main(){
   //~ freopen("test","r",stdin);
   
   inv['^'] = 3;
   inv['<'] = 2;
   inv['v'] = 1;
   inv['>'] = 0;
   
   for(int i=0,T=in();i<T;i++){
     cout << "Case #"<<i+1<<": " ;
       solve();
     }
 }
