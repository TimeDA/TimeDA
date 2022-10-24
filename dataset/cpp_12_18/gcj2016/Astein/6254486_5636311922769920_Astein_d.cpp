#include <cstdio>
 
 using namespace std;
 
 int main()
 {
   int T;
   scanf("%d", &T);
   for (int cn = 1; cn <= T; ++cn)
   {
     int K, C, S;
     scanf("%d%d%d", &K, &C, &S);
     printf("Case #%d: ", cn);
     for (int i = 0; i < S; ++i)
     {
       long long ret = 0;
       for (int j = 0; j < C; ++j)
       {
         ret = ret * K + i;
       }
       ret++;
       printf("%Ld ", ret);
     }
     printf("\n");
   }
 }
 
