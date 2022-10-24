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
     int N,A[1024];
     scanf("%d",&N);
     for(int i=1;i<=N;i++){
         scanf("%d",&A[i]);
     }
     int aa=0,bb=N+1;
     int sol=0;
     while(aa+1<bb){
         int mm=aa+1;
         for(int i=aa+1;i<bb;i++)
         {
             if(A[i]<A[mm]){
                 mm=i;
             }
         }
 //        printf("mm=%d aa=%d bb=%d",mm,aa,bb);
         if(mm-aa<bb-mm){
             int tmp=A[mm];
             for(int i=mm;i>aa+1;i--){
                 A[i]=A[i-1];
                 sol++;
             }
             A[aa+1]=tmp;
             aa++;
         }else{
             int tmp=A[mm];
             for(int i=mm;i<bb-1;i++){
                 A[i]=A[i+1];
                 sol++;
             }
             A[bb-1]=tmp;
             bb--;
         }
 //        printf("sol=%d\n",sol);
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
