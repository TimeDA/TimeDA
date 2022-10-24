#include<cstdio>
 #include<cstring>
 #include<queue>
 #include<utility>
 #include<vector>
 #include<algorithm>
 
 using namespace std;
 
 double p[30];
 int n, k;
 
 int btcount(int mask)
 {
 	int resp = 0;
 	while (mask)
 	{
 		if (mask & 1)
 		{
 			resp++;
 		}
 		mask = mask >> 1;
 	}
 	return resp;
 }
 
 double calc(int mask)
 {
 	double prob[20];
 	for (int i = 0; i <= k; i++)
 	{
 		prob[i] = 0;
 	}
 	prob[0] = 1;
 	for (int i = 0; i < n; i++)
 	{
 		if ((mask & (1 << i)) == 0)
 			continue;
 		for (int j = k; j >= 1; j--)
 		{
 			prob[j] = prob[j] * (1 - p[i]) + prob[j - 1] * p[i];
 		}
 		prob[0] = prob[0] * (1 - p[i]);
 	}
 	return prob[k/2];
 }
 
 int main()
 {
 	int t, teste;
 	scanf("%d\n", &teste);
 
 	for (int t = 0; t < teste; t++)
 	{
 		scanf("%d %d\n", &n, &k);
 		for (int i = 0; i < n; i++)
 		{
 			scanf("%lf\n", &p[i]);
 		}
 		double best = 0;
 
 		for (int a = 0; a < (1 << n); a++)
 		{
 			if (btcount(a) != k)
 				continue;
 			double cand = calc(a);
 			if (cand > best)
 			{
 				best = cand;
 			}
 		}
 
 		printf("Case #%d: %lf\n", t + 1, best);
 	}
 	return 0;
 }
