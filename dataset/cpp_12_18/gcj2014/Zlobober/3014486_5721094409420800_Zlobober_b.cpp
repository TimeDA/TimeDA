#include <cstdio>
 #include <algorithm>
 #include <memory.h>
 using namespace std;
 
 const int N = 1050;
 int A[N];
 pair<int, int> B[N];
 bool used[N];
 
 void solve(int cs)
 {
     int n; 
     scanf("%d", &n);
     for (int i = 0; i < n; i++)
         scanf("%d", &A[i]), B[i] = make_pair(A[i], i);
     sort(B, B + n);
     memset(used, 0, sizeof(used));
     int ans = 0;
     for (int i = 0; i < n; i++)
     {
         int p = B[i].second;
         int a = 0, b = 0;
         for (int j = p - 1; j >= 0; j--)
             a += !used[j];
         for (int j = p + 1; j < n; j++)
             b += !used[j];
         ans += min(a, b);
         used[p] = true;
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
