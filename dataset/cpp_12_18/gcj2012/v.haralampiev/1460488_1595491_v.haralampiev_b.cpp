#include <iostream>
 #include <cstdio>
 #include <algorithm>
 using namespace std;
 int N,S,P;
 void doit(int CASE){
   int ans=0;
   scanf("%d%d%d",&N,&S,&P);
   int ok=P+2*max(0 , P-1) , okup=P+2*max(0 , P-2);
   for(int i=0;i<N;++i){
    int T; scanf("%d",&T);
    if(T>=ok)++ans;
    else if(T>=okup && S>0)--S , ++ans;
                       }
   printf("Case #%d: %d\n" , CASE , ans);
 }
 int main(){
   int Q; scanf("%d",&Q);
   for(int i=1;i<=Q;++i)doit(i);
   //system("pause");
   return 0;
 }
