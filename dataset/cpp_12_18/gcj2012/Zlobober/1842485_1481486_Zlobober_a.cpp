#include <iostream>
 #include <algorithm>
 #include <vector>
 #include <cstdio>
 using namespace std;
 
 const int N = 100500;
 
 int X[N], L[N];
 
 int D[N];
 
 void solve(int Case)
 {
     int n;
     scanf("%d", &n);
     for (int i = 0; i < n; i++)
         scanf("%d %d", &X[i], &L[i]);
     scanf("%d", &X[n]);
     for (int i = 0; i <= n; i++)
         D[i] = 0;
     D[0] = X[0];
     bool good = false;
     for (int i = 0; i < n; i++)
     {
         if (D[i] >= X[n] - X[i])
             good = true;
         for (int j = i + 1; j < n; j++)
             if (X[j] - X[i] <= D[i])
                 D[j] = max(D[j], min(L[j], (X[j] - X[i])));
     }
     printf("Case #%d: %s\n", Case, (good) ? "YES" : "NO");
 }
 
 int main()
 {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++)
         solve(i + 1);
 }
