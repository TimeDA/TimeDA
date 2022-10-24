#include <cstdio>
 #include <cstring>
 #include <ctime>
 using namespace std;
 
 #define eprintf(...) fprintf(stderr, __VA_ARGS__)
 
 const int N = 20;
 
 double D[N + 1][1 << N];
 
 int BIT(int x, int i)
 {
     return (x >> i) & 1;
 }
 
 void SBIT(int& msk, int i, int v)
 {
     msk ^= (BIT(msk, i) ^ v) << i;
 }
 
 void init()
 {
     for (int n = 1; n <= N; n++)
     {
         eprintf("here %d\n", n);
         D[n][-1 + (1 << n)] = 0;
         for (int msk = -2 + (1 << n); msk >= 0; msk--)
         {
             int j = 0;
             #define INC(j) j = (j + 1), d = d + 1; if (j == n) j = 0
             double av = 0;
             int d = 0;
             for (int i = 0; i < n; i++)
             {
                 while (BIT(msk, j))
                 {
                     INC(j);
                 }
                 int nmsk = msk;
                 SBIT(nmsk, j, 1);
                 av += (n - d) + D[n][nmsk];
                 if (j == i)
                 {
                     INC(j);
                 }
                 d--;
             }
             av /= n;
             D[n][msk] = av;
         }
     }
 }
 
 char buf[23];
 
 void solve(int tc)
 {
     gets(buf);
     int l = strlen(buf);
     int msk = 0;
     for (int i = 0; i < l; i++)
         SBIT(msk, i, buf[i] == 'X');
     double ans = D[l][msk];
     printf("Case #%d: %.12lf\n", tc, ans);
 }
 
 int main()
 {
     int t;
     scanf("%d ", &t);
     init();
     eprintf("inited time = %.10lf\n", clock() / (double)CLOCKS_PER_SEC);
     for (int i = 0; i < t; i++)
         solve(i + 1);
 }
