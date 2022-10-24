#include <cstdio>
 #include <cassert>
 #include <vector>
 using namespace std;
 
 const int MAXN = 128;
 int a[MAXN], t[MAXN];
 int n;
 
 int calc(int *t, int p) {
     int sum = 0, s = 0;
     for (int i = 0 ; i < n ; ++i) {
         if (sum % p == 0) ++s;
         sum += t[i];
     }
     return s;
 }
 
 int main() {
     int T, ans, p;
     scanf("%d",&T);
     for (int ca = 1 ; ca <= T ; ++ca) {
         scanf("%d%d",&n,&p);
         for (int i = 0 ; i < n ; ++i)
             scanf("%d",&a[i]);
         if (p == 2) {
             int p1 = 0, p2 = n - 1;
             for (int i = 0 ; i < n ; ++i) {
                 if (a[i] % 2 == 0) t[p1++] = a[i];
                 else t[p2--] = a[i];
             }
         } else if (p == 3) {
             vector<int> m[3];
             for (int i = 0 ; i < n ; ++i) {
                 m[a[i]%3].push_back(a[i]);
             }
             int p1 = 0;
             for (int i = 0 ; i < m[0].size() ; ++i)
                 t[p1++] = m[0][i];
             int i;
             for (i = 0 ; i < m[1].size() && i < m[2].size() ; ++i)
                 t[p1++] = m[1][i], t[p1++] = m[2][i];
             for (int j = i ; j < m[1].size() ; ++j)
                 t[p1++] = m[1][j];
             for (int j = i ; j < m[2].size() ; ++j)
                 t[p1++] = m[2][j];
             assert(p1 == n);
         } else if (p == 4) {
             vector<int> m[4];
             for (int i = 0 ; i < n ; ++i)
                 m[a[i]%4].push_back(a[i]);
             int p1 = 0;
             for (int i = 0 ; i < m[0].size() ; ++i)
                 t[p1++] = m[0][i];
             int max2 = m[2].size();
             if (max2 % 2 == 1) --max2;
             for (int i = 0 ; i < max2 ; ++i)
                 t[p1++] = m[2][i];
             int min13 = min(m[1].size(), m[3].size());
             int j;
             for (j = 0 ; j < m[1].size() && j < m[3].size() ; ++j)
                 t[p1++] = m[1][j], t[p1++] = m[3][j];
             if (m[2].size() % 2 == 1) t[p1++] = m[2][m[2].size()-1];
             for (int k = j ; k < m[1].size() ; ++k)
                 t[p1++] = m[1][k];
             for (int k = j ; k < m[3].size() ; ++k)
                 t[p1++] = m[3][k];
             /*
             for (int i = 0 ; i < p1 ; ++i)
                 printf("[%d]", t[i]);
             printf("\n");
             */
             assert(p1 == n);
         }
         int ans = calc(t, p);
         printf("Case #%d: %d\n", ca, ans);
     }
     return 0;
 }
 
