#include <cstdio>
 #include <algorithm>
 #include <cstring>
 using namespace std;
 int t,x,y,z,a,n,D;
 int v[10005],vis[10005],maxl[10005],l[10005];
 bool done=0;
 int bsearch(int k,int s, int e){
     if(s==e) return s;
     int m=(s+e)/2+1;
     if(v[m]<=k) return bsearch(k,m,e);
     else return bsearch(k,s,m-1);
 }
 int main(){
     scanf("%d",&t);
     for(x=1;x<=t;x++){
         scanf("%d",&n);
         for(y=0;y<n;y++){
             scanf("%d %d",&v[y],&l[y]);
         }
         scanf("%d",&D);
         v[n]=D;
         memset(maxl,0,sizeof(maxl));
         memset(vis,0,sizeof(vis));
         maxl[0]=min(v[0],l[0]);
         vis[0]=1;
         done=0;
         for(z=0;z<n;z++){
             if(!vis[z]) continue;
             a=bsearch(v[z]+maxl[z],0,n);
             if(a==n){
                 printf("Case #%d: YES\n",x);
                 done=1;
                 break;
             }
             for(y=a;y>=0;y--){
                 if(!vis[y]){
                     vis[y]=1;
                     maxl[y]=min(v[y]-v[z],l[y]);
                 }
                 else break;
             }
         }
         if(!done) printf("Case #%d: NO\n",x);
     }
     return 0;
 }
