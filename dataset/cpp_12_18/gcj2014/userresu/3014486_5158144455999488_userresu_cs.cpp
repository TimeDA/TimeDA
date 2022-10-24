#include <cstdio>
 using namespace std;
 
 int ok[101][501];
 int W,H,B;
 int cnt;
 void go (int i,int j) {
     if (j==H-1) {
         ++cnt;
         return;
     }
     if (i && ok[i-1][j]>0) ok[i-1][j]=0,go(i-1,j);
     else if (ok[i][j+1]>0) ok[i][j+1]=0,go(i,j+1);
     else if (i<W && ok[i+1][j]>0) ok[i+1][j]=0,go (i+1,j);
 }
 
 int main () {
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     int T;
     scanf("%d",&T);
     for (int z=1;z<=T;++z) {
     scanf("%d %d %d",&W,&H,&B);
     cnt=0;
     for (int i=0;i<=W;++i) for (int j=0;j<=H;++j) ok[i][j]=1;
     for (int i=0;i<W;++i) ok[i][0]=0;
     for (int i=1;i<=B;++i) {
         int a,b,c,d;
         scanf("%d %d %d %d",&a,&b,&c,&d);
         for (int x=a;x<=c;++x) for (int y=b;y<=d;++y) {
             ok[x][y]=-1;
         }
     }
     for (int i=0;i<W;++i) if (!ok[i][0]) {
         go(i,0);
     }
     printf("Case #%d: %d\n",z,cnt);}
     return 0;
 }
