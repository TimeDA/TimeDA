#include <cstdio>
 #include <vector>
 
 using namespace std;
 
 vector<long long> primes;
 
 int main()
 {
   primes.push_back(2);
 	for (long long i = 3; i <= 10000000; i += 2)
 	{
 	  bool f = true;
 	  for (int j = 0; j < primes.size(); ++j)
 	  {
 	    if (i % primes[j] == 0) { f = false; break; }
 	    if (primes[j] * primes[j] > i) break;
 	  }
 	  if (f)
 	  {
 	    primes.push_back(i);
 	  }
 	}
 	
   int T;
   scanf("%d", &T);
   
   int a[11];
   long long aa[11];
 
   for (int cn = 1; cn <= T; ++cn)
   {
     printf("Case #%d:\n", cn);
 
     int N, J;
     scanf("%d %d", &N, &J);
     for (int i = (1 << (N - 1)) + 1; ; i += 2)
     {
 			bool allprime = true;
 			long long b, num;
 			for (int base = 2; base <= 10; ++base)
 			{
 				b = 1;
 				num = 0;
 				long long two = 0;
 				int ii = i;
 				while (ii)
 				{
 					if (ii % 2 == 1)
 					{
 						num = num + b;
 					}
 					ii /= 2;
 					b = b * base;
 				}
 				bool isprime = true;
 				for (int j = 0; j < primes.size(); ++j)
 				{
 				  if (num % primes[j] == 0)
 				  {
 				    isprime = false;
 				    a[base] = primes[j];
 				    aa[base] = num;
 				    break;
 				  }
 				  if (primes[j] * primes[j] > num)
 					  break;
 				}
 				if (isprime)
 				{
 				  allprime = false;
 				  break;
 				}
 			}
 			if (allprime)
 			{
 			  printf("%Ld ", num);
 			  for (int base = 2; base <= 10; ++base)
 			  {
 			    printf("%d ", a[base]);
 			  }
 			  printf("\n");
 			  J--;
 			  if (J == 0) break;
 
 			}
 		}
 	}
 }
 
