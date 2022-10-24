#include<cstdio>
 #include<cstring>
 #include<queue>
 #include<utility>
 #include<vector>
 #include<algorithm>
 
 using namespace std;
 
 int main()
 {
 	int t, teste;
 	scanf("%d\n", &teste);
 	for (int t = 0; t < teste; t++)
 	{
 		int n, c, m;
 		scanf("%d %d %d\n", &n, &c, &m);
 		int tcount[1100];
 		int pcount[1100];
 		for (int i = 0; i < c; i++)
 		{
 			tcount[i] = 0;
 		}
 		for (int i = 0; i < n; i++)
 		{
 			pcount[i] = 0;
 		}
 		for (int i = 0; i < m; i++)
 		{
 			int pi, bi;
 			scanf("%d %d", &bi, &pi);
 			bi--;
 			pi--;
 			tcount[pi]++;
 			pcount[bi]++;
 		}
 
 		int respr = 0;
 		for (int i = 0; i < c; i++)
 		{
 			respr = max(respr, tcount[i]);
 		}
 		int acc = 0;
 		for (int i = 0; i < n; i++)
 		{
 			acc += pcount[i];
 			int neededr = acc / (i + 1);
 			respr = max(respr, neededr);
 		}
 
 		int respp = 0;
 		for (int i = 0; i < n; i++)
 		{
 			if (pcount[i] > respr)
 				respp += pcount[i] - respr;
 		}
 
 		printf("Case #%d: %d %d\n", t + 1, respr, respp);
 	}
 	return 0;
 }
