#include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>
 #define INF 3000000
 using namespace std;
 vector<int>v[2000005];
 vector<int>::iterator ii;
 int t,x,y,y2,z;
 int a,b,pow10[10],ans;
 int main(){
     pow10[0]=1;
     for(x=1;x<=7;x++) pow10[x]=10*pow10[x-1];
     for(x=2;x<=6;x++){
         for(y=pow10[x-1]+1;y<pow10[x];y++){
             for(z=1;z<x;z++){
                 y2=(y/pow10[z])+(y%pow10[z])*pow10[x-z];
                 if(y2>y){
                      v[y].push_back(y2);
                 }
             }
             if(v[y].size()>1){
                 sort(v[y].begin(),v[y].end());
                 for(z=0;z<v[y].size()-1;z++){
                     if(v[y][z]==v[y][z+1]) v[y][z]=INF;
                 }
                 sort(v[y].begin(),v[y].end());
             }
         }
     }
     for(y=pow10[6];y<2*pow10[6];y++){
         for(z=1;z<7;z++){
             y2=(y/pow10[z])+(y%pow10[z])*pow10[x-z];
             if(y2>y){
                  v[y].push_back(y2);
             }
         }
     }
     scanf("%d",&t);
     for(x=1;x<=t;x++){
         scanf("%d %d",&a,&b);
         ans=0;
         for(y=a;y<b;y++){
             ii=upper_bound(v[y].begin(),v[y].end(),b);
             ans+=int(ii-v[y].begin());
         }
         printf("Case #%d: %d\n",x,ans);
     }
     return 0;
 }
