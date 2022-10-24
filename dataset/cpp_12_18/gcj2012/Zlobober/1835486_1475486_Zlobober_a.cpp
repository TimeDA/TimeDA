#include <iostream>
 #include <cassert>
 #include <algorithm>
 #include <cstdio>
 using namespace std;
 
 void solve(int C)
 {
     int n;
     scanf("%d", &n);
     const int N = 21;
     int L[N];
     int P[N];
     pair<int, int> Q[N];
     for (int i = 0; i < n; i++)
     {
         scanf("%d", &L[i]);
         assert(L[i] == 1);
     }
     for (int i = 0; i < n; i++)
     {
         scanf("%d", &P[i]);
         Q[i] = make_pair(-P[i], i);
     }
     sort(Q, Q + n);
     printf("Case #%d: ", C);
     for (int i = 0; i < n; i++)
         printf("%d ", Q[i].second);
     printf("\n");
 }
 
 int main()
 {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++)
         solve(i + 1);
 }
