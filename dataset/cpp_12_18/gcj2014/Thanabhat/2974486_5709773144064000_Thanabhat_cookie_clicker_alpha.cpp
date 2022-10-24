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
 
     double C,F,X;
     scanf("%lf %lf %lf",&C,&F,&X);
     double sol=X/2.0,t=0.0,r=2.0;
     while(true)
     {
         double newsol = t+C/r+X/(r+F);
         t+=(C/r);
         r+=F;
         if(newsol>sol)
             break;
         else
             sol=newsol;
     }
     printf("Case #%d: %.8lf\n",cc,sol);
     return 1;
 }
 
 int main(){
 
 //	freopen("input.txt","r",stdin);
 //	freopen("output.txt","w",stdout);
 
     int t;
     scanf("%d",&t);
     for(int i=0;i<t;i++)
         solve(i+1);
 
 	return 0;
 }
