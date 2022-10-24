#include <iostream>
 #include <algorithm>
 #include <cmath>
 #include <cstring>
 #include <cstdlib>
 #include <string>
 #include <vector>
 #include <cstdio>
 #include <cassert>
 
 using namespace std;
 
 typedef long long ll;
 typedef long double ld;
 
 #ifdef WIN32
 #define LLD "%I64d"
 #else
 #define LLD "%lld"
 #endif
 
 const ld inf = 1e18;
 
 int main()
 {
 	int NT = 0;
 	scanf("%d", &NT);
 	for (int T = 1; T <= NT; T++)
 	{
 		printf("Case #%d:", T);
 		
 		ld C, F, X;
 		scanf("%Lf%Lf%Lf", &C, &F, &X);
 		ld answer = inf;
 		for (int i = 0; i <= 2000; i++)
 		{
 			ld curans = 0;
 			for (int j = 0; j < i; j++)
 			{
 				curans += C / (2 + F * j);
 			}
 			curans += X / (2 + i * F);
 			answer = min(answer, curans);
 		}
 		printf(" %.9Lf\n", answer);
 		
 		fprintf(stderr, "%d/%d cases done!\n", T, NT);
 	}
 	return 0;
 }
