#include <cstdio>
 #include <cmath>
 using namespace std;
 
 int T,R,C,M;
 int good[51][51];
 
 int main () {
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     scanf("%d",&T);
     for (int z=1;z<=T;++z) {
     scanf("%d %d %d",&R,&C,&M);
     printf("Case #%d:\n",z);
     M = R*C-M;
     bool ok=0;
     for (int i=1;i<=R;++i) for (int j=1;j<=C;++j) good[i][j]=0;
     if (R==1) {
         ok=1;
         good[1][1]=2;
         for (int j=2;j<=M;++j) good[1][j]=1;
     }
     else if (C==1) {
         ok=1;
         good[1][1]=2;
         for (int i=2;i<=M;++i) good[i][1]=1;
     }
     else if (R==2) {
         int cnt=0;
         ok=1;
         bool breaked=0;
         for (int j=1;!breaked;++j) for (int i=1;i<=2;++i) {
             ++cnt;
             good[i][j]=1;
             if (cnt==M) {
                 if (j==1 || j==2 && i==1) ok=0;
                 breaked=1;
                 break;
             }
         }
         good[1][1]=2;
     }
     else if (C==2) {
         ok=1;
         int cnt=0;
         bool breaked=0;
         for (int i=1;!breaked;++i) for (int j=1;j<=2;++j) {
             ++cnt;
             good[i][j]=1;
             if (cnt==M) {
                 if (i==1 || i==2 && j==1) ok=0;
                 breaked=1;
                 break;
             }
         }
         good[1][1]=1;
     }
     else {
         for (int k=2;k<=C;++k) {
             double rows=1.0*M/k;
             int r = (int)rows;
             if (rows<2 || (int)ceil(rows) > R) continue;
             ok=1;
             for (int i=1;i<=r;++i) for (int j=1;j<=k;++j) good[i][j]=1;
             int left = M-r*k;
             for (int j=1;j<=left;++j) good[r+1][j]=1;
             good[1][1]=2;
             break;
         }   
     }
     if (!ok) printf("Impossible\n");
     else {
         for (int i=1;i<=R;++i) {
             for (int j=1;j<=C;++j) {
                 if (good[i][j]==1) printf(".");
                 else if (good[i][j]==2) printf("c");
                 else printf("*");
             }
             printf("\n");
         }
     }}
     return 0;
 }
