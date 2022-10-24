#include <cstdio>
 #include <memory.h>
 #include <algorithm>
 using namespace std;
 
 const int N = 10500;
 int A[N];
 bool used[N];
 
 void solve(int cs)
 {
     int n, x;
     scanf("%d %d", &n, &x);
     for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
     sort(A, A + n);
     reverse(A, A + n);
     int ans = 0;
     memset(used, 0, sizeof(used));
     for (int i = 0; i < n; i++)
     {
         if (used[i])
             continue;
         int q = x - A[i];
         int id = -1;
         for (int j = i + 1; j < n; j++)
             if (used[j] || A[j] + A[i] > x)
                 continue;
             else
             {
                 id = j;
                 break;
             }
         if (id != -1)
             used[id] = true;
         ans++;
     } 
     printf("Case #%d: %d\n", cs, ans);
 }
 
 int main()
 {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++)
         solve(i + 1), fflush(stdout);
 }
 
