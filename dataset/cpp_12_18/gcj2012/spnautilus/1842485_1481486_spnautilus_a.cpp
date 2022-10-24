#include <stdio.h>
 #include <string.h>
 #include <queue>
 
 using namespace std;
 
 #define maxn (10005)
 
 int T;
 
 int N;
 int D;
 
 int di[maxn];
 int li[maxn];
 
 int best[maxn];
 int inq[maxn];
 
 queue <int> Q;
 
 inline int abs1(int a)
 {
 	return (a >= 0) ? a : -a;
 }
 
 inline int min2(int a, int b)
 {
 	return (a <= b) ? a : b;
 }
 
 int main()
 {
 	int tt;
 	scanf("%d", &T);
 	for(tt = 1; tt <= T; ++tt)
 	{
 		int i, j;
 
 		scanf("%d", &N);
 		for(i = 1; i <= N; ++i)
 		{
 			int a, b;
 			scanf("%d %d", &a, &b);
 
 			di[i] = a;
 			li[i] = b;
 		}
 		scanf("%d", &D);
 
 		memset(best, 0, sizeof(best));
 		memset(inq, 0, sizeof(inq));
 
 		best[1] = di[1];
 		Q.push(1);
 		inq[1] = 1;
 
 		int sol = 0;
 
 		while(!Q.empty())
 		{
 			int id = Q.front();
 			Q.pop();
 
 			inq[id] = 0;
 
 			if(D <= di[id] + best[id])
 			{
 				sol = 1;
 				break;
 			}
 
 			for(i = 1; i <= N; ++i)
 			{
 				if(i == id)
 					continue;
 
 				int l = abs1(di[id] - di[i]);
 
 				if(l <= best[id] && best[i] < min2(l, li[i]))
 				{
 					best[i] = min2(l, li[i]);
 
 					if(!inq[i])
 					{
 						inq[i] = 1;
 						Q.push(i);
 					}
 				}
 			}
 		}
 
 		while(!Q.empty())
 			Q.pop();
 
 		printf("Case #%d: %s\n", tt, ((sol == 1) ? "YES" : "NO"));
 	}
 
 	return 0;
 }
