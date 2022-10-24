#include <cstdio>
 #include <cassert>
 #include <algorithm>
 #include <memory.h>
 using namespace std;
 
 const int N = 2050;
 
 int A[N];
 int B[N];
 int P[N * N];
 
 int L[N], R[N];
 int _X[N], *X = _X + 1;
 int V[N];
 int ML[N][N], MR[N][N];
 
 int n;
 
 bool go(int q)
 {
     if (q == n)
         return true;
     ML[q][0] = 0;
     for (int i = 0; i < q; i++)
         ML[q][i + 1] = max(ML[q][i], L[i]);
     MR[q][q] = 0;
     for (int i = q; i > 0; i--)
         MR[q][i - 1] = max(MR[q][i], R[i - 1]);
     for (int i = 0; i <= q; i++)
     {
         int a = ML[q][i] + 1;
         int b = MR[q][i] + 1;
         if (P[a * N + b] != -1 && X[i - 1] <= P[a * N + b] && P[a * N + b] <= X[i])
         {
             L[q] = a;
             R[q] = b;
             V[P[a * N + b]] = q;
             X[q] = P[a * N + b];
             X[q + 1] = n;
             rotate(X + i, X + q, X + q + 1);
             rotate(L + i, L + q, L + q + 1);
             rotate(R + i, R + q, R + q + 1);
             if (go(q + 1))
                 return true;
             else
             {
                 rotate(X + i, X + i + 1, X + q + 1);
                 rotate(L + i, L + i + 1, L + q + 1);
                 rotate(R + i, R + i + 1, R + q + 1);
                 X[q] = n;
             }
         }
     }
     return false;
 }
 
 
 void solve(int tc)
 {
     scanf("%d", &n);
     memset(P, -1, sizeof(P));
     memset(A, -1, sizeof(A));
     memset(B, -1, sizeof(B));
     memset(V, -1, sizeof(V));
     memset(_X, 0, sizeof(X));
     for (int i = 0; i < n; i++)
         scanf("%d", &A[i]);
     for (int i = 0; i < n; i++)
         scanf("%d", &B[i]);
     for (int i = 0; i < n; i++)
         P[A[i] * N + B[i]] = i;
     X[-1] = -1, X[0] = n;
     assert(go(0));
     printf("Case #%d:", tc);
     for (int i = 0; i < n; i++)
         printf(" %d", V[i] + 1);
     printf("\n");
 }
 
 
 int main()
 {
     int tc;
     scanf("%d", &tc);
 
     for (int i = 0; i < tc; i++)
         solve(i + 1);
 
 }
