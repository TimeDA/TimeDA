#include <cstdio>
 #include <algorithm>
 using namespace std;
 
 int A[4][4], B[4][4];
 int tmp[4];
 
 void solve(int cs)
 {
     int a;
     scanf("%d", &a);
     --a;
     for (int i = 0; i < 4; i++)
         for (int j = 0; j < 4; j++)
             scanf("%d", &A[i][j]);
     int b;
     scanf("%d", &b);
     --b;
     for (int i = 0; i < 4; i++)
         for (int j = 0; j < 4; j++)
             scanf("%d", &B[i][j]);
     sort(A[a], A[a] + 4);
     sort(B[b], B[b] + 4);
     int t = set_intersection(A[a], A[a] + 4, B[b], B[b] + 4, tmp) - tmp;
     if (t > 1)
         printf("Case #%d: Bad magician!\n", cs);
     else if (!t)
         printf("Case #%d: Volunteer cheated!\n", cs);
     else
         printf("Case #%d: %d\n", cs, tmp[0]);
 }
 
 int main()
 {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++)
         solve(i + 1);
 }
