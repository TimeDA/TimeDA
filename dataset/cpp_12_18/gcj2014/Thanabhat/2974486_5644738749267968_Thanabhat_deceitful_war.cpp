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
     int N;
     double A[1024],B[1024];
     scanf("%d",&N);
     for(int i=0;i<N;i++)
         scanf("%lf",&A[i]);
     for(int i=0;i<N;i++)
         scanf("%lf",&B[i]);
     sort(A,A+N);
     sort(B,B+N);
     int y=0,z=N;
     for(int i=N-1,j=N-1;i>=0,j>=0;i--,j--)
     {
         while(j>0&&B[j]>A[i])
             j--;
         if(B[j]<A[i])
             y++;
     }
     for(int i=N-1,j=N-1;i>=0,j>=0;i--,j--)
     {
         while(j>0&&A[j]>B[i])
             j--;
         if(A[j]<B[i])
             z--;
     }
     printf("Case #%d: %d %d\n",cc,y,z);
     return 1;
 }
 
 int main(){
 
 //	freopen("input.txt","r",stdin);
 //	freopen("output.txt","w",stdout);
 
     int T;
     scanf("%d",&T);
     for(int i=0;i<T;i++)
         solve(i+1);
 
 	return 0;
 }
