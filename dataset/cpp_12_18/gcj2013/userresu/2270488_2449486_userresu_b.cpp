#include <cstdio>
 using namespace std;
 
 int A[101][101];
 int main () {
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     int T;
     scanf("%d",&T);
     for (int z=1;z<=T;++z) {
     int N,M;
     scanf("%d %d",&N,&M);
     for (int i=0;i<N;++i) for (int j=0;j<M;++j) scanf("%d",&A[i][j]);
     int good=1;
     for (int i=0;i<N;++i) {
         for (int j=0;j<M;++j) {
             bool ok=1;
             for (int k=0;k<N;++k) if (A[k][j]>A[i][j]) {
                 ok=0;
                 break;
             }
             if (ok) continue;
             ok=1;
             for (int k=0;k<M;++k) if (A[i][k]>A[i][j]) {
                 ok=0;
                 break;
             }
             if (!ok) {
                 good=0;
                 break;
             }
         }
         if (!good) break;
     }
     printf("Case #%d: ",z);
     if (good) printf("YES\n");
     else printf("NO\n");
     }
     return 0;
 }
