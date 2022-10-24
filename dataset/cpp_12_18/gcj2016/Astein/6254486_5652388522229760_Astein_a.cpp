#include <cstring>
 #include <cstdio>
 
 using namespace std;
 
 int check[10];
 
 long long solve(int N)
 {
   if (N == 0) return -1;
   int cnt = 0;
   long long c = N;
   memset(check, 0, sizeof(check));
   while (true)
   {
     long long cc = c;
     while (cc > 0)
     {
       int m = cc % 10;
 			if (check[m] == 0)
 			{
 			  check[m] = 1;
 			  cnt++;
 			}
       cc /= 10;
     }
     if (cnt == 10)
     {
       break;
     }
     c = c + N;
   }
   return c;
 }
 
 int main()
 {
   int T;
 	scanf("%d", &T);
   for (int cn = 1; cn <= T; ++cn)
   {
 	  int N;
 		scanf("%d", &N);
 		long long ret = solve(N);
     printf("Case #%d: ", cn);
 		if (ret == -1)
 		{
 			printf("INSOMNIA\n");
 		}
 		else
 		{
 		  printf("%Ld\n", ret);
 		}
 
   }
 }
 
