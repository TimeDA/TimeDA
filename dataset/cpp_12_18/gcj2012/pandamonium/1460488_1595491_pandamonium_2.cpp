#include <cstdio>
 #include <cstring>
 #include <algorithm>
 using namespace std;
 int t,x,n,s,p;
 int k,y,cnt,ans;
 int main(){
     scanf("%d",&t);
     for(x=1;x<=t;x++){
         scanf("%d %d %d",&n,&s,&p);
         ans=0;
         cnt=0;
         for(y=0;y<n;y++){
             scanf("%d",&k);
             if(k>=3*p-2) ans++;
             else if(k>=3*p-4&&p>1) cnt++;
         }
         printf("Case #%d: %d\n",x,ans+min(cnt,s));
     }
     return 0;
 }
