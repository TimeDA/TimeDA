#include <cstdio>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 using namespace std;
 int x,y,z,a,b,c;
 int w,h,d,k;
 int startx,starty,t;
 int lim1,lim2,lim3,lim4;
 char grid[35][35];
 int ans,dp[55][55];
 bool seen[105][105];
 int dx[]={0,0,1,1};
 int dy[]={0,1,0,1};
 int gcd(int m, int n){
     if(n==0) return m;
     if(dp[m][n]>0) return dp[m][n];
     return dp[m][n]=gcd(n,m%n);
 }
 int main(){
     memset(dp,0,sizeof(dp));
     scanf("%d",&t);
     for(z=1;z<=t;z++){
         memset(seen,0,sizeof(seen));
         scanf("%d %d %d",&h,&w,&d);
         for(x=0;x<h;x++){
             scanf("%s",&grid[x]);
             for(y=0;y<w;y++){
                 if(grid[x][y]=='X'){
                     startx=2*y-1;
                     starty=2*x-1;
                 }
             }
         }
         ans=0;
         w-=2;
         h-=2;
         lim1=2*w*int((-d-startx)/(2*w));
         lim2=2*w*int(d/(2*w));
         lim3=2*h*int((-d-starty)/(2*h));
         lim4=2*h*int(d/(2*h));
         for(a=lim1;a<=lim2;a+=2*w){
             for(b=lim3;b<=lim4;b+=2*h){
                 for(c=0;c<4;c++){
                     x=a+startx*dx[c];
                     y=b+starty*dy[c];
                     if(x==0&&y==0) continue;
                     if(x*x+y*y>d*d) continue;
                     k=gcd(max(abs(x),abs(y)),min(abs(x),abs(y)));
                     x/=k;
                     y/=k;
                     if(!seen[x+50][y+50]){
                         seen[x+50][y+50]=1;
                         ans++;
                     }
                 }
             }
         }
         printf("Case #%d: %d\n",z,ans);
     }
     return 0;
 }
