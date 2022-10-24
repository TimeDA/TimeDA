#include <cstdio>
 #include <cstring>
 using namespace std;
 
 char A[4][4];
 int main () {
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     int T;
     scanf("%d",&T);
     for (int z=1;z<=T;++z) {
     char found=0;
     for (int i=0;i<4;++i) {
         scanf("%s",A[i]);
         if (found) continue;
         if (i==3) {
             for (int j=0;j<4;++j) if (A[i][j]!='.') {
                 char s=A[i][j];
                 bool flag=0;
                 if (s=='T') flag=1;
                 bool same=1;
                 if (flag) s=A[2][j];
                 for (int k=2;k>=0;--k) if (A[k][j]!=s && A[k][j]!='T') {
                     same=0;
                     break;
                 }
                 if (same) {
                     found=s;
                     break;
                 }
                 if (j==0) {
                     if (flag) s=A[2][1];
                     same=1;
                     for (int k=2;k>=0;--k) if (A[k][j-k+3]!=s && A[k][j-k+3]!='T') {
                         same=0;
                         break;
                     }
                     if (same) {
                         found=s;
                         break;
                     }
                 }
                 else if (j==3) {
                     if (flag) s=A[2][2];
                     same=1;
                     for (int k=2;k>=0;--k) if (A[k][j+k-3]!=s && A[k][j+k-3]!='T') {
                         same=0;
                         break;
                     }
                     if (same) {
                         found=s;
                         break;
                     }
                 }
             }
         }
         
         if (A[i][3]!='.') {
             char s = A[i][3];
             if (s=='T') s=A[i][2];
             bool same=1;
             for (int j=2;j>=0;--j) if (A[i][j]!=s && A[i][j]!='T') {
                 same=0;
                 break;
             }
             if (same) found=s;
         }
     }
     printf("Case #%d: ",z);
     if (found=='X') printf("X won\n");
     else if (found=='O') printf("O won\n");
     else {
         found=0;
         for (int i=0;i<4;++i) for (int j=0;j<4;++j) if (A[i][j]=='.') {
             found=1;
             break;
         }
         if (found) printf("Game has not completed\n");
         else printf("Draw\n");
     }
     }
     return 0;
 }
