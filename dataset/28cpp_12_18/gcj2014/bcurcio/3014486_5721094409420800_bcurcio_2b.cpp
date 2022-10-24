#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <set>
 #include <map>
 
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 
 typedef pair<int,int> pii;
 pii A[12345];
 
 
 void solve(){
   int N = in();
   
   int i,j,k;
   
   int ans = N*N*N*N;
   
   for(i=0;i<N;i++) A[i] = pii(in(),i);
   
   sort(A,A+N);
   
   do{
     int pt = 0;
     while(pt+1<N && A[pt].first<A[pt+1].first) pt++;
     
     while(pt+1<N && A[pt].first>A[pt+1].first) pt++;
     
     if(pt==N-1){
       int cur = 0;
       for(i=0;i<N;i++)
         for(j=i+1;j<N;j++)
           if(A[i].second>A[j].second) cur++;
       ans = min(ans,cur);
     }
     
     
   }while(next_permutation(A,A+N));
   
   cout << ans << endl;
   
   
   return; 
   //*
   //*for(i=0;i<N;i++){
     //*int inv1 = 0;
     //*int inv2 = 0;
     //*
     //*for(j=0;j<i;j++){
       //*for(k=j+1;k<i;k++){
         //*cerr << A[j] << ' ' << A[k] << endl;
         //*if(A[j]>A[k]) inv1++;
       //*}
     //*}
     //*
     //*for(j=i;j<N;j++){
       //*for(k=j+1;k<N;k++){
         //*if(A[j]<A[k]) inv2++;
       //*}
     //*}
     //*
     //*cerr << i << ' ' << inv1 << ' ' << inv2 << endl;
     //*ans = min(inv1+inv2,ans);
     //*
   //*}
   //*
   //*cout << ans << endl;
 }
 
 int main(){
   for(int i=0,T=in();i<T;i++){
       cout << "Case #"<<i+1<<": ";
       solve();
     }
 }
