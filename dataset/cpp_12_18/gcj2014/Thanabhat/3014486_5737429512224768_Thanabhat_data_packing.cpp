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
 
 int solve(int cc){
 
     int S[1024];
     bool m[1024];
     int N,X;
 
     scanf("%d %d",&N,&X);
     for(int i=0;i<N;i++)
     {
         scanf("%d",&S[i]);
         m[i]=false;
     }
 
     int x2 = X/2;
     int a=N-1,b=N;
     sort(S,S+N);
     for(int i=0;i<N;i++)
     {
         if(S[i]>x2){
             a=i-1;
             b=i;
             break;
         }
     }
     int sol=0;
     while(b<N){
 //            printf("a %d b %d sol %d\n",a,b,sol);
         while(a>=0&&S[a]+S[b]>X){
             a--;
         }
         if(a>=0){
             m[a]=true;
             sol++;
             a--;
         }else {
             sol++;
         }
         m[b]=true;
         b++;
 //            printf(" - a %d b %d sol %d\n",a,b,sol);
     }
     int tmp=0;
     for(int i=0;i<N;i++){
         if(!m[i]){
             tmp++;
         }
     }
     if(tmp%2==0){
         sol+=tmp/2;
     }else{
         sol+=tmp/2+1;
     }
     printf("Case #%d: %d\n",cc,sol);
     return 1;
 }
 
 int main(){
 
 //	freopen("input.txt","r",stdin);
 //	freopen("output.txt","w",stdout);
 
     int t;
     scanf("%d",&t);
     for(int i=0;i<t;i++){
         solve(i+1);
     }
 
 	return 0;
 }
