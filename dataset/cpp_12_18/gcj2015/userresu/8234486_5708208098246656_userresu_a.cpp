#include <cstdio>
 #include <algorithm>
 #include <vector>
 using namespace std;
 
 int R,C;
 char A[101][101];
 int main () {
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     
     int T = 1;
     scanf("%d",&T);
     for (int zz=1;zz<=T;++zz) {
         int cnt = 0;
         bool possible = 1;
         scanf("%d %d",&R,&C);
         for (int i=0;i<R;++i) {
             scanf("%s",A[i]);
         }
         for (int i=0;i<R;++i) {
             if (possible)
             for (int j=0;j<C&&possible;++j) if (A[i][j]!='.') {
                 bool ok = 0;
                 bool found = 0;
                 for (int k=1;j+k<C;++k) {
                     if (A[i][j+k] != '.') {
                         found = 1;
                         
                         if (A[i][j]=='>') ok = 1;
                         break;
                     }
                 }
                 if (ok) continue;
                 for (int k=1;j-k>=0;++k) {
                     if (A[i][j-k] != '.') {
                         found = 1;
                         if (A[i][j]=='<') ok = 1;
                         break;
                     }
                 }
                 if (ok) continue;
                 for (int k=1;i+k<R;++k) {
                     if (A[i+k][j] != '.') {
                         found = 1;
                         if (A[i][j]=='v') ok = 1;
                         break;
                     }
                 }
                 if (ok) continue;
                 for (int k=1;i-k>=0;++k) {
                     if (A[i-k][j] != '.') {
                         found = 1;
                         if (A[i][j]=='^') ok = 1;
                         break;
                     }
                 }
                 if (ok) continue;
                 if (!found) possible = 0;
                 else ++cnt;
             }
         }
         printf("Case #%d: ",zz);
         if (possible) printf("%d\n",cnt);
         else printf("IMPOSSIBLE\n");
     }
     return 0;
 }
