#define _CRT_SECURE_NO_WARNINGS
 #pragma comment(linker, "/STACK:100000000")
 #include <stdio.h>
 #include <vector>
 #include <string>
 #include <set>
 #include <map>
 #include <queue>
 #include <algorithm>
 #include <string.h>
 #include <math.h>
 #include <fstream>
 #include <iostream>
 #include <ctime>
 #include <fstream>
 using namespace std;
 const int N=110;
 const int M=100000;
 int a[4];
 int d[N][N][3], x[N][N][N][3];
 void solve()
 {
     int n, p;
     scanf("%d%d", &n, &p);
     int j;
     for(int i=0; i<p; a[i]=0, i++);
     for(int i=0; i<n; scanf("%d", &j), a[j%p]++, i++);
     int r;
     if(p==2)
     {
         r=a[0]+(a[1]+1)/2;
     }
     else if(p==3)
     {
         for(int i=0; i<=a[1]; i++)
             for(int j=0; j<=a[2]; j++)
                 for(int k=0; k<p; d[i][j][k]=-M, k++);
         d[0][0][0]=0;
         for(int i=0; i<=a[1]; i++)
             for(int j=0; j<=a[2]; j++)
                 for(int k=0; k<p; k++)
                 {
                     if(i<a[1]) d[i+1][j][(k+1)%p]=max(d[i+1][j][(k+1)%p], d[i][j][k]+(k==0));
                     if(j<a[2]) d[i][j+1][(k+2)%p]=max(d[i][j+1][(k+2)%p], d[i][j][k]+(k==0));
                 }
         r=a[0]+d[a[1]][a[2]][(a[1]+a[2]*2)%p];
     }
     else
     {
         for(int i=0; i<=a[1]; i++)
             for(int j=0; j<=a[2]; j++)
                 for(int l=0; l<=a[3]; l++)
                     for(int k=0; k<p; x[i][j][l][k]=-M, k++);
         x[0][0][0][0]=0;
         for(int i=0; i<=a[1]; i++)
             for(int j=0; j<=a[2]; j++)
                 for(int l=0; l<=a[3]; l++)
                     for(int k=0; k<p; k++)
                     {
                         if(i<a[1]) x[i+1][j][l][(k+1)%p]=max(x[i+1][j][l][(k+1)%p], x[i][j][l][k]+(k==0));
                         if(j<a[2]) x[i][j+1][l][(k+2)%p]=max(x[i][j+1][l][(k+2)%p], x[i][j][l][k]+(k==0));
                         if(l<a[3]) x[i][j][l+1][(k+3)%p]=max(x[i][j][l+1][(k+3)%p], x[i][j][l][k]+(k==0));
                     }
         r=a[0]+x[a[1]][a[2]][a[3]][(a[1]+a[2]*2+a[3]*3)%p];
     }
     printf("%d\n", r);
 }
 int main()
 {
     int ts;
     scanf("%d", &ts);
     for(int t=1; t<=ts; t++)
     {
         printf("Case #%d: ", t);
         solve();
     }
 	return 0;
 }