#include <cstdio>
 #include <cassert>
 #include <memory.h>
 using namespace std;
 
 int n;
 int apply(int msk, int i) {
     int res = 0;
     for (int j = 0; j < n; j++) {
         if (j < i) {
             res |= (1 ^ ((msk >> j) & 1)) << (i - j - 1);
         } else {
             res |= ((msk >> j) & 1) << j;
         }
     }
     return res;
 }
 
 const int N = 1 << 10;
 int Q[N];
 int lpt = 0, rpt = 0;
 int D[N];
 
 int BFS(int s) {
     lpt = rpt = 0;
     Q[rpt++] = s;
     memset(D, -1, sizeof(D));
     D[s] = 0;
     while (lpt < rpt) {
         int x = Q[lpt++];
         for (int i = 1; i <= n; i++) {
             int y = apply(x, i);
             if (D[y] == -1)
                 D[y] = D[x] + 1, Q[rpt++] = y;
         }
     }
     assert(D[0] != -1);
     return D[0];
 }
 
 int main() {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {
         char buf[15];
         scanf("%s", buf);
         n = strlen(buf);
         int msk = 0;
         for (int i = 0; i < n; i++)
             if (buf[i] == '-')
                 msk |= 1 << i;
         int ans = BFS(msk);
         printf("Case #%d: %d\n", i + 1, ans);
     }
 }
