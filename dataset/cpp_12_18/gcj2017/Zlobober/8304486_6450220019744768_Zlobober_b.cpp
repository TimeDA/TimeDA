#include <cstdio>
 #include <tuple>
 #include <cassert>
 #include <vector>
 using namespace std;
 
 const int N = 2050;
 
 vector<int> E[N];
 int A[N], B[N];
 
 int sgn(int e, int x, int y) {
     if (x == A[e] && y == B[e])
         return 1;
     if (x == B[e] && y == A[e])
         return -1;
     assert(false);
 }
 
 int to(int e, int x) {
     return A[e] ^ B[e] ^ x;
 }
 
 int val[N];
 int add[N];
 int used[N];
 
 vector<tuple<int, int, int>> st;
 
 void DFS(int x, int pe = -1) {
     used[x] = 1;
     for (int e : E[x]) {
         if (e == pe) {
             continue;
         }
         int y = to(e, x);
         if (used[y] == 0) {
             st.push_back(make_tuple(x, e, sgn(e, x, y)));
             DFS(y, e);
             st.pop_back();
         } else if (used[y] == 1) {
             val[e] = sgn(e, x, y);
 
             for (int p = (int)st.size() - 1; p >= 0; p--) {
                 int v = get<0>(st[p]);
                 int ve = get<1>(st[p]);
                 int vs = get<2>(st[p]);
                 val[ve] += vs;
                 if (v == y)
                     break;
             }
         }
     }
     used[x] = 2;
 }
 
 void solve(int cs) {
     int n, m;
     scanf("%d %d", &n, &m);
 
     for (int i = 0; i < n; i++) {
         E[i].clear();
         used[i] = 0;
         add[i] = 0;
     }
     for (int e = 0; e < m; e++) {
         val[e] = 0;
     }
 
     for (int i = 0; i < m; i++) {
         scanf("%d %d", &A[i], &B[i]);
         --A[i], --B[i];
         E[A[i]].push_back(i);
         E[B[i]].push_back(i);
     }
 
     for (int i = 0; i < n; i++) {
         if (!used[i]) {
             DFS(i);
         }
     }
 
     bool bad = false;
     for (int i = 0; i < m; i++) {
         if (val[i] == 0)
             bad = true;
     }
 
     printf("Case #%d:", cs);
     if (bad) {
         puts(" IMPOSSIBLE");
     } else {
         vector<int> tot(m);
         for (int i = 0; i < m; i++) {
             tot[A[i]] -= val[i];
             tot[B[i]] += val[i];
         }
         for (int i = 0; i < m; i++) {
             assert(tot[i] == 0);
         }
         for (int i = 0; i < m; i++) {
             printf(" %d", val[i]);
         }
         printf("\n");
     }
 }
 
 int main() {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {
         solve(i + 1);
     }
 }
