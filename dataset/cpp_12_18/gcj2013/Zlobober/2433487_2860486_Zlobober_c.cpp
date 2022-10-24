#include <cstdio>
 #include <vector>
 #include <cassert>
 using namespace std;
 
 const int N = 20;
 
 vector<int> E[N], iE[N];
 
 int BIT(int msk, int i)
 {
     return (msk >> i) & 1;
 }
 
 int L[N];
 int A[N], B[N];
 int P[N], Q[N];
 int DD[2][N];
 int fl[N];
 
 int to(int e, int x)
 {
     return A[e] ^ B[e] ^ x;
 }
 
 int n, m, p;
 
 int PP[N];
 
 void dij(int st, int* D)
 {
     for (int i = 0; i < n; i++)
         if (i == st)
             D[i] = fl[i] = 0;
         else
             D[i] = 1e9, fl[i] = 0;
     for (int it = 0; it < n; it++)
     {
         pair<int, int> mn(1e9 + 42, -1);
         for (int i = 0; i < n; i++)
             if (!fl[i])
                 mn = min(mn, make_pair(D[i], i));
         if (mn.second == -1)
             break;
         int x = mn.second;
         fl[x] = true;
         if (!st)
         {
             for (int i = 0; i < E[x].size(); i++)
             {
                 int y = to(E[x][i], x);
                 D[y] = min(D[y], D[x] + L[E[x][i]]);
             }
         }
         else
         {
             for (int i = 0; i < iE[x].size(); i++)
             {
                 int y = to(iE[x][i], x);
                 D[y] = min(D[y], D[x] + L[iE[x][i]]);
             }
         }
     }
     assert(D[!st] < 1e9 - 1);
 }
 
 
 
 void solve(int tc)
 {
     scanf("%d %d %d", &n, &m, &p);
     int mx = 0;
     for (int i = 0; i < n; i++)
         E[i].clear(), iE[i].clear();
     for (int i = 0; i < m; i++)
     {
         scanf("%d %d %d %d", &A[i], &B[i], &P[i], &Q[i]);
         --A[i], --B[i];
         E[A[i]].push_back(i);
         iE[B[i]].push_back(i);
     }
     for (int i = 0; i < p; i++)
     {
         scanf("%d", &PP[i]);
         --PP[i];
     }
     for (int msk = 0; msk < (1 << m); msk++)
     {
         for (int i = 0; i < m; i++)
             L[i] = (BIT(msk, i)) ? P[i] : Q[i];
         for (int v = 0; v < 2; v++)
             dij(v, DD[v]);
         assert(DD[0][1] == DD[1][0]);
         int cur = p;
         for (int i = 0; i < p; i++)
             if (DD[0][A[PP[i]]] + L[PP[i]] + DD[1][B[PP[i]]] != DD[0][1])
             {
                 cur = i;
                 break;
             }
         mx = max(mx, cur);
     }
     printf("Case #%d: ", tc + 1);
 
     if (mx == p)
         printf("Looks Good To Me\n");
     else
         printf("%d\n", 1 + PP[mx]);
 }
 
 int main()
 {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++)
     {
         #define eprintf(...) fprintf(stderr, __VA_ARGS__)
         eprintf("%d\n", i + 1);
         solve(i + 1);
     }
 }
