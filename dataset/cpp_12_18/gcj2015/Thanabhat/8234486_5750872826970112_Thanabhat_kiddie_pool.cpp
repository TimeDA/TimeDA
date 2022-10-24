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
 
 #define eps 1e-7
 
 using namespace std;
 
 int solve(int cc){
     int N;
     double V,X;
     double R[105],C[105];
     double sol;
     scanf("%d %lf %lf",&N,&V,&X);
     for(int i=0;i<N;i++){
         scanf("%lf %lf",&R[i],&C[i]);
     }
     if(N==1){
         if(fabs(X-C[0])<eps){
             sol=V/R[0];
             printf("Case #%d: %.8lf\n",cc,sol);
             return 1;
         }else{
             printf("Case #%d: IMPOSSIBLE\n",cc);
             return 1;
         }
     }else{
         double v0v1 = -(C[1]-X)/(C[0]-X);
         if((X-eps>C[0]&&X-eps>C[1])||(X+eps<C[0]&&X+eps<C[1])){
             printf("Case #%d: IMPOSSIBLE\n",cc);
             return 1;
         }else{
             if(fabs(C[0]-C[1])<eps){
                 sol=V/(R[0]+R[1]);
                 printf("Case #%d: %.8lf\n",cc,sol);
                 return 1;
             }else{
     //            double v0=(v0v1/(v0v1+1.0))*V;
                 double v0=-((C[1]-X)/(C[0]-C[1]))*V;
                 double v1=V-v0;
                 double s0=v0/R[0];
                 double s1=v1/R[1];
 //                printf("%.8lf %.8lf %.8lf\n",v0v1,v0,v1);
                 printf("Case #%d: %.8lf\n",cc,max(s0,s1));
                 return 1;
             }
         }
     }
 
 
 
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
