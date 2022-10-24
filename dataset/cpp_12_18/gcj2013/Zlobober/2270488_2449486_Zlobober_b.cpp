#include <cstdio>
 #include <algorithm>
 using namespace std;
 
 #define eprintf(...) fprintf(stderr, __VA_ARGS__)
 
 const int N = 105;
 
 int A[N][N];
 bool good[N][N];
 
 void solve(int tc)
 {
     int n, m;
     scanf("%d %d", &n, &m);
     for (int i = 0; i < n; i++)
         for (int j = 0; j < m; j++)
             scanf("%d", &A[i][j]), good[i][j] = true;
     bool bad = false;
     for (int it = 0; it < min(n, m); it++)
     {
         int mn = 1e9, mni = -42, mnj = -42;
         for (int i = 0; i < n; i++)
             for (int j = 0; j < m; j++)
                 if (good[i][j] && mn > A[i][j])
                     mn = A[i][j], mni = i, mnj = j;
         bool r = true, c = true;
         for (int i = 0; i < n; i++)
             if (good[i][mnj])
                 c &= A[i][mnj] == mn;
         for (int j = 0; j < m; j++)
             if (good[mni][j])
                 r &= A[mni][j] == mn;
         if (!r && !c)
         {
             bad = true;
             break;
         }
         if (c)
             for (int i = 0; i < n; i++)
                 good[i][mnj] = false;
         if (r)
             for (int j = 0; j < m; j++)
                 good[mni][j] = false;
     }
     printf("Case #%d: %s\n", tc, bad ? "NO" : "YES");
 }
 
 int main()
 {
     int n;
     scanf("%d", &n);
     for (int i = 0; i < n; i++)
         solve(i + 1);
 }
