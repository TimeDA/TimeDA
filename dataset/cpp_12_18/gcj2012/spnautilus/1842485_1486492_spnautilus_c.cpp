#include <stdio.h>
 #include <string.h>
 
 #define maxn (2005)
 
 int T;
 
 int N;
 int P[maxn];
 int furthest[maxn];
 
 int bucket[maxn];
 int bn;
 
 int sol[maxn];
 
 int gen(int depth)
 {
 	if(depth > N)
 	{
 		int i, j;
 //		int yes = 1;
 
 /*
 		printf("check :");
 		for(i = 1; i <= N; ++i)
 			printf(" %d", sol[i]);
 		putchar('\n');
 //*/
 
 		for(i = 1; i < N; ++i)
 		{
 			int dom = i + 1;
 			for(j = i + 2; j <= N; ++j)
 			{
 				if(((double) sol[j] - sol[i]) / (j - i) > ((double) sol[dom] - sol[i]) / (dom - i))
 					dom = j;
 			}
 
 			if(dom != P[i])
 				return 0;
 //				yes = 0;
 
 //			printf(" %d", dom);
 		}
 
 		return 1;
 	}
 	else
 	{
 		int i;
 		for(i = 1; i <= bn; ++i)
 		{
 			if(i == bn)
 			{
 				sol[depth] = bucket[bn];
 				--bn;
 				if(gen(depth + 1))
 					return 1;
 				++bn;
 			}
 			else
 			{
 				sol[depth] = bucket[i];
 				bucket[i] = bucket[bn];
 				--bn;
 				if(gen(depth + 1))
 					return 1;
 				++bn;
 				bucket[bn] = bucket[i];
 				bucket[i] = sol[depth];
 			}
 		}
 	}
 
 	return 0;
 }
 
 int main()
 {
 	int tt;
 	scanf("%d", &T);
 	for(tt = 1; tt <= T; ++tt)
 	{
 		int i, j;
 		int valid = 1;
 
 		memset(furthest, 0, sizeof(furthest));
 
 		scanf("%d", &N);
 		for(i = 1; i < N; ++i)
 		{
 			int a;
 			scanf("%d", &a);
 			P[i] = a;
 
 			if(furthest[i] && furthest[i] < a)
 				valid = 0;
 
 			for(j = i + 1; j < a; ++j)
 			{
 				if(furthest[j] == 0 || furthest[j] > a)
 					furthest[j] = a;
 			}
 		}
 
 //		for(i = 1; i < N; ++i)
 //			printf("%d %d\n", i, furthest[i]);
 
 		if(!valid)
 		{
 			printf("Case #%d: impossible\n", tt);
 			continue;
 		}
 
 		for(i = 1; i <= N; ++i)
 			bucket[i] = i;
 		bn = N;
 
 		int res = gen(1);
 
 		if(res == 0)
 		{
 			printf("This is to be changed by hand.\n");
 			printf("!!!!!\n");
 		}
 
 		printf("Case #%d:", tt);
 
 		for(i = 1; i <= N; ++i)
 			printf(" %d", sol[i]);
 
 		putchar('\n');
 	}
 
 	return 0;
 }
