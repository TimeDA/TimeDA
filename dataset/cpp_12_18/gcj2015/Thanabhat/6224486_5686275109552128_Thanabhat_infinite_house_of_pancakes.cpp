/*
 AUTHOR: THANABHAT KOOMSUBHA
 LANG: C++
 */
 
 #include<cstdio>
 #include<cstdlib>
 #include<algorithm>
 #include<cmath>
 #include<functional>
 #include<vector>
 #include<list>
 #include<set>
 #include<queue>
 #include<map>
 #include<cctype>
 #include<cstring>
 #include<string>
 #include<sstream>
 #include<iostream>
 #include<ctime>
 
 using namespace std;
 
 int D,P[1024];
 
 int solve(int cc){
     for(int i=0;i<=1000;i++){
         P[i]=0;
     }
     scanf("%d",&D);
     int mx=0;
     for(int i=0;i<D;i++){
         scanf("%d",&P[i]);
         mx=max(mx,P[i]);
     }
     int sol=mx;
     for(int i=1;i<=mx;i++){
         int tmpsol=i;
         for(int j=0;j<D;j++){
             if(P[j]%i==0){
                 tmpsol+=P[j]/i-1;
             }else{
                 tmpsol+=P[j]/i;
             }
         }
         sol=min(sol,tmpsol);
     }
     printf("Case #%d: %d\n",cc,sol);
     return 1;
 }
 
 int main(){
 
 //	freopen("input.txt","r",stdin);
 //	freopen("output.txt","w",stdout);
 
     int T;
     scanf("%d",&T);
     for(int i=1;i<=T;i++){
         solve(i);
     }
 
 	return 0;
 }
