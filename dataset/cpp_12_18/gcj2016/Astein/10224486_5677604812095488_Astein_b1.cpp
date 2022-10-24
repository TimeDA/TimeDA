#include <cstdio>
 #include <vector>
 
 using namespace std;
 
 int N, K;
 double p[205];
 int a[205];
 double ret;
 
 void backtr(int n, int last)
 {
   if (n == K)
   {
     double probsum = 0;
     int probcnt = 0;
 
     for (int bit = 0; bit < (1 << K); ++bit)
     {
       int cnt = __builtin_popcount(bit);
       if (cnt * 2 == K)
       {
         double prob = 1;
         for (int i = 0; i < K; ++i)
         {
           if (bit & (1 << i))
             prob *= p[a[i]];
           else
             prob *= (1 - p[a[i]]);
         }
         probsum += prob;
       }
     }
     double cur = probsum;
     if (ret < cur) ret = cur;
     return;
   }
   for (int i = last; i < N; ++i)
   {
     a[n] = i;
     backtr(n + 1, i + 1);
   }
 }
 
 int main()
 {
   int T;
   scanf("%d", &T);
   for (int cn = 1; cn <= T; ++cn)
   {
     scanf("%d%d", &N, &K);
     for (int i = 0; i < N; ++i)
       scanf("%lf", &p[i]);
     ret = 0;
     backtr(0, 0);
     printf("Case #%d: %.10lf\n", cn, ret);
   }
 }
