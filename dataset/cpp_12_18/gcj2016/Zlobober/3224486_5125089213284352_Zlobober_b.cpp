
 #include <cstring>
 #include <cstdio>
 #include <cstdlib>
 #include <cassert>
 #include <vector>
 using namespace std;
 
 const int N = 105;
 vector<int> E[N];
 char X[N];
 
 int sz[N];
 
 void DFS(int x) {
     sz[x] = 1;
     for (int y : E[x])
         DFS(y), sz[x] += sz[y];
 }
 
 char str[N];
 
 int mark[N];
 
 char out[N];
 
 int iter() {
     vector<int> pool = {0};
     int opt = 0;
     while (!pool.empty()) {
         int pt = 0;
         for (int j = 0; j < (int)pool.size(); j++) {
             for (int q = 0; q < sz[pool[j]]; q++)
                 mark[pt++] = j;
         }
         int pos = rand() % pt;
         int rem = mark[pos];
         int ver = pool[rem];
         if (ver != 0)
             out[opt++] = X[ver];
         swap(pool.back(), pool[rem]);
         pool.pop_back();
         pool.insert(pool.end(), E[ver].begin(), E[ver].end());
     }
     out[opt++] = 0;
     return (strstr(out, str) != NULL);
 }
 
 const int IT = 10 * 1000;
 
 void solve(int cs) {
     if (cs < 80)
         return;
     int n;
     scanf("%d", &n);
     for (int i = 0; i <= n; i++)
         E[i].clear();
     for (int i = 1; i <= n; i++) {
         int p;
         scanf("%d", &p);
         E[p].push_back(i);
     }
     for (int i = 1; i <= n; i++) {
         char c;
         scanf(" %c ", &c);
         X[i] = c;
     }
     DFS(0);
 
     int m;
     scanf("%d", &m);
 
     printf("Case #%d:", cs);
     fflush(stdout);
     for (int i = 0; i < m; i++) {
         scanf("%s", str);
         int den = 0;
         int num = 0;
 
         for (int it = 0; it < IT; it++) {
             int val = iter();
             den++;
             num += val;
         }
         printf(" %.5lf", (double)num / den);
         fflush(stdout);
     }
     printf("\n");
 }
 
 int main() {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {
         solve(i + 1);
     }
 }
