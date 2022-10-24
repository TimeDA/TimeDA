#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 
 int N;
 int a[15];
 int b[15];
 int uso[15];
 
 
 int calctrivial(int a[],int b[]){
   int i;
   
   for(i=0;i<N;i++) uso[i] = 0;
   int ans = 0;
   
   for(i=0;i<N;i++){
     int x = upper_bound(b,b+N,a[i]) - b;
     
     if(x==N) x = 0;
     while(uso[x]){
       x++;
       if(x==N) x = 0;
     }
       
     if(b[x]<a[i]) ans++;
     uso[x] = 1;
   }
   
   return ans;
 }
 
 
 int calccomplicada(int a[],int b[]){
   int i;
   
   for(i=0;i<N;i++) uso[i] = 0;
   int ans = 0;
   
   for(i=0;i<N;i++){
     
     int inf = a[i];
     int sup = b[N-1]>a[i]?b[N-1]:1000000;
     int mid;
     int x;
     int st = 0;
     
     while(inf+1<sup){
       
       mid = (inf+sup)/2;
           
       x = upper_bound(b,b+N,mid) - b;
       
       if(x==N) x = 0;
       while(uso[x]){
         x++;
         if(x==N) x = 0;
       }
       
       if(((a[i]>b[x] && mid>=b[x]) || (a[i]<b[x] && mid <= b[x])) ){
         inf = mid;
         st = x;
       }else{
         sup = mid;
       }
       
     }
 
     //*cerr << inf << ' ' << b[st] << endl;
     if(inf>b[st]) ans++;
     uso[st] = 1;
     //*cerr << ans << endl;
   }
   
   return ans;
 }
 
 void solve(){
   
   N = in();
   
   int i;
   double f;
   for(i=0;i<N;i++) {
     scanf("%lf",&f);
     a[i] = f*1000000;
   }
   
   for(i=0;i<N;i++) {
     scanf("%lf",&f);
     b[i] = f*1000000;
   }
     
   sort(a,a+N);
   sort(b,b+N);
   
   int facil = 0;
   int dificil = 0;
   int aux;
   do{
     
     if(facil!=N) aux = calctrivial(a,b);
     facil = max(facil,aux);
     
     if(dificil!=N)  aux = calccomplicada(a,b);
     //*cerr << aux << endl;
     dificil = max(dificil,aux);
     
     
     
   }while(next_permutation(a,a+N));
   
   cout << dificil << ' ' << facil << endl;
   
   
 }
 
 int main(){
   for(int i=0,T=in();i<T;i++){
       cout << "Case #"<<i+1<<": ";
       solve();
     }
 }
