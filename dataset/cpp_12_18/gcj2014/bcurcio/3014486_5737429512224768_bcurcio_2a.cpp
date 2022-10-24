#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <set>
 #include <map>
 
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 
 
 int A[112345];
 
 void solve(){
   int N = in();
   int X = in();
   int i;
   for(i=0;i<N;i++) A[i] = in();
   
   sort(A,A+N);
   
   int ans = 0;
   int pt1 = 0;
   int pt2 = N-1;
   while(pt1<pt2){
     if(A[pt1]+A[pt2]<=X){
       ans++;
       pt1++;
       pt2--;
     }else{
       ans++;
       pt2--;
     }
   }
   
   ans += (pt2-pt1+1);
   
   cout << ans << endl;
 }
 
 int main(){
   for(int i=0,T=in();i<T;i++){
       cout << "Case #"<<i+1<<": ";
       solve();
     }
 }
