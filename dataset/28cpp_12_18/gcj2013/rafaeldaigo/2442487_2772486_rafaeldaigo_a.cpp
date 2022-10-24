#include<cstdio>
 #include<cstring>
 #include<queue>
 #include<utility>
 #include<algorithm>
 
 #define INF 1234567890
 #define MOD 1000002013
 
 using namespace std;
 
 int passin[1100];
 int passout[1100];
 int passquant[1100];
 int n, m;
 
 int stack[1100];
 int stackaboard[1100];
 int iorder[1100];
 int oorder[1100];
 
 long long cost(int i, int o)
 {
     long long a = o - i;
     return (a * (2 * n - a + 1) / 2) % MOD;
 }
 
 bool icompare(int i, int j)
 {
     return (passin[i]<passin[j]);
 }
 
 bool ocompare(int i, int j)
 {
     return (passout[i]<passout[j]);
 }
 
 int main()
 {
     int t, teste;
     int i, j;
     scanf("%d\n", &teste);
     for (int t = 0; t < teste; t++)
     {
         scanf("%d %d\n", &n, &m);
         for (i = 0; i < m; i++)
         {
             scanf("%d %d %d\n", &passin[i], &passout[i], &passquant[i]);
         }
         long long normal = 0;
         for (i = 0; i < m; i++)
         {
             normal = (normal + (cost(passin[i], passout[i]) * passquant[i]) % MOD) % MOD;
         }
 
         for (i = 0; i < m; i++)
         {
             iorder[i] = oorder[i] = i;
         }
         sort(&iorder[0], &iorder[m], icompare);
         sort(&oorder[0], &oorder[m], ocompare);
 
         int ci = 0;
         int co = 0;
         int stacksize = 0;
 
         long long special = 0;
         while (ci < m || co < m)
         {
             int citime = (ci < m) ? passin[iorder[ci]] : INF;
             int cotime = (co < m) ? passout[oorder[co]] : INF;
             if (citime <= cotime)
             {
                 //printf("in %d %d %d %d\n", iorder[ci], passin[iorder[ci]], passout[iorder[ci]], passquant[iorder[ci]]);
                 stack[stacksize] = iorder[ci];
                 stackaboard[stacksize] = passquant[iorder[ci]];
                 stacksize++;
                 ci++;
             }
             else
             {
                 //printf("out %d %d %d %d\n", oorder[co], passin[oorder[co]], passout[oorder[co]], passquant[oorder[co]]);
                 int outquant = passquant[oorder[co]];
                 while (outquant > 0)
                 {
                     int index = stack[stacksize - 1];
                     int stackquant = stackaboard[stacksize - 1];
                     if (outquant >= stackquant)
                     {
                         long long drop = (cost(passin[index], passout[oorder[co]]) * stackquant) % MOD;
                         //printf("%d %d %d %lld\n", stackquant, passin[index], passout[oorder[co]], drop);
                         special = (special + drop) % MOD;
                         outquant -= stackquant;
                         stackaboard[stacksize - 1] = 0;
                         stacksize--;
                     }
                     else
                     {
                         long long drop = (cost(passin[index], passout[oorder[co]]) * outquant) % MOD;
                         //printf("%d %d %d %lld\n", outquant, passin[index], passout[oorder[co]], drop);
                         special = (special + drop) % MOD;
                         stackaboard[stacksize - 1] -= outquant;
                         outquant = 0;
                     }
                 }
                 co++;
             }
             /*for (i = 0; i < stacksize; i++)
             {
                 printf("  %d %d %d %d %d\n", stack[i], stackaboard[i], passin[stack[i]], passout[stack[i]], passquant[stack[i]]);
             }*/
         }
 
         //printf("%lld %lld\n", normal, special);
         long long resp = (normal - special + MOD) % MOD;
         printf("Case #%d: %lld\n", t + 1, resp);
     }
     return 0;
 }
