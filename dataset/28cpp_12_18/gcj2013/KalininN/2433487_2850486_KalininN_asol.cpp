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
 
 const int maxn = 37;
 const int arrsz = maxn + 5;
 const ll inf = 1e18;
 
 ll x[arrsz];
 ll B;
 int n;
 
 int main()
 {
 	int NT = 0;
 	scanf("%d", &NT);
 	for (int T = 1; T <= NT; T++)
 	{
 		printf("Case #%d: ", T);
 		
 		scanf(LLD "%d", &B, &n);
 		for (int i = 0; i < n; i++) scanf(LLD, &x[i]);
 		for (int i = n; i < maxn; i++) x[i] = 0;
 		sort(x, x + maxn);
 		ll cursum = 0;
 		x[maxn] = inf;
 		double answer = 0;
 		for (int i = 0; i < maxn; i++)
 		{
 			cursum += x[i];
 // 			if (x[i] == x[i + 1]) continue;
 			ll curB = -x[i];
 			for (int j = i; j < maxn; j++)
 			{
 				curB += x[j];
 				ll maxX = x[j + 1] - 1;
 				ll minX = max(x[i], x[j] - 1);
 				if (minX > maxX) continue;
 				ll curneed = minX * (i + 1) - cursum + (minX + 1) * (j - i) - curB;
 				ll have = B - curneed;
 				if (have < 0) continue;
 				maxX = min(minX + have / (j + 1), maxX);
 				double profit = ((i + 1) * minX - cursum) * (36.0 / (i + 1) - 1) - (double) (minX + 1) * (j - i) + curB;
 				answer = max(answer, profit);				
 				profit = ((i + 1) * maxX - cursum) * (36.0 / (i + 1) - 1) - (double) (maxX + 1) * (j - i) + curB;
 				answer = max(answer, profit);				
 			}
 		}
 		
 		printf("%.7lf\n", answer);
 		
 		fprintf(stderr, "%d/%d cases done!\n", T, NT);
 	}
 	return 0;
 }
