#include <cstdio>
 #include <algorithm>
 using namespace std;
 
 int T,N;
 double A[1001],B[1001];
 bool used[1001];
 int main () {
     freopen("input.in","r",stdin);
     freopen("output.out","w",stdout);
     scanf("%d",&T);
     for (int z=1;z<=T;++z) {
     scanf("%d",&N);
     for (int i=1;i<=N;++i) used[i]=0;
     for (int i=1;i<=N;++i) scanf("%lf",&A[i]);
     for (int i=1;i<=N;++i) scanf("%lf",&B[i]);
     printf("Case #%d: ",z);
     sort(A+1,A+N+1);
     sort(B+1,B+N+1);
     
     bool found=0;
     for (int i=N;i>=1;--i) {
         bool ok=1;
         for (int j=1;j<=i;++j) if (B[j]>A[N-i+j]) {
             ok=0;
             break;
         }
         if (ok) {
             printf("%d ",i);
             found=1;
             break;
         }
     }
     if (!found) printf("0 ");
     
     int points=0;
     for (int i=1;i<=N;++i) {
         bool win=1;
         for (int j=1;j<=N;++j) {
             if (!used[j] && B[j]>A[i]) {
                 win=0;
                 used[j]=1;
                 break;
             }
         }
         if (win) {
             ++points;
             for (int j=1;j<=N;++j) if (!used[j]) {
                 used[j]=1;
                 break;
             }
         }
     }
     printf("%d\n",points);
 }
     return 0;
 }
