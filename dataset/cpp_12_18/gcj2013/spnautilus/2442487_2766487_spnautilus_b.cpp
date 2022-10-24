#include <stdio.h>
 
 typedef long long ll;
 
 int T;
 int N;
 ll P;
 
 int main()
 {
 	int tt;
 	scanf("%d", &T);
 	for(tt = 1; tt <= T; ++tt)
 	{
 		scanf("%d %I64d", &N, &P);
 		ll NP2 = 1ll << N;
 
 //		printf("2^N : %I64d\n", NP2);
 
 		ll sola = 0;
 		ll solb = -1;
 
 		ll suma = 1;
 		ll sumb = 0;
 		ll a = NP2 >> 1;
 		ll b = 2;
 
 		while(a >= 1)
 		{
 			suma += a;
 
 			ll s = NP2 + 1 - suma;
 //			printf("s p %I64d %I64d\n", s, P);
 			if(solb == -1 && s <= P)
 			{
 				solb = NP2 - sumb - 2;
 //				printf("---%I64d\n", solb);
 			}
 
 			if(a == 1)
 				sumb += 1;
 			else
 				sumb += b;
 
 //			printf("+%I64d %I64d : %I64d %I64d\n", a, b, suma, sumb);
 
 			if(suma <= P)
 			{
 				sola = sumb;
 //				printf("best %I64d\n", sola);
 			}
 
 			a >>= 1;
 			b <<= 1;
 		}
 
 		if(P == NP2)
 			solb = NP2 - 1;
 
 		printf("Case #%d: %I64d %I64d\n", tt, sola, solb);
 	}
 
 	return 0;
 }
