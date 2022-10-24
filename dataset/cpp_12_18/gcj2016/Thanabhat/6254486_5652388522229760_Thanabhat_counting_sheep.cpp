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
 
 int cal(int a)
 {
     if(a==0){
         return -1;
     }
     bool m[10];
     for(int i=0;i<10;i++){
         m[i]=false;
     }
     int b=1;
     while(true){
         int tmp=a*b;
         while(tmp>0){
             m[tmp%10]=true;
             tmp/=10;
         }
         bool done=true;
         for(int i=0;i<10;i++){
             if(!m[i]){
                 done=false;
             }
         }
         if(done){
             return a*b;
         }
         b++;
     }
 }
 
 int solve(int cc){
 
     int N;
     scanf("%d",&N);
     printf("Case #%d: ",cc);
     if(N==0){
         printf("INSOMNIA\n");
     }else{
         printf("%d\n",cal(N));
     }
 
     return 1;
 }
 
 int main(){
 
 //	freopen("input.txt","r",stdin);
 //	freopen("output.txt","w",stdout);
 
     int T;
     scanf("%d",&T);
     for(int i=0;i<T;i++){
         solve(i+1);
     }
 
 	return 0;
 }
 
