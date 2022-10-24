#include <stdio.h>
 #include <algorithm>
 
 using namespace std;
 
 int A[32];
 int B[32];
 
 int answer[32];
 int aA[32];
 int aB[32];
 int n;
 int rec(int pos)
 {
 	if (pos == n)
 	{
 		for(int i = n - 1; i>= 0;i--)
 		{
 			aB[i] = 1;
 			for(int j = n - 1; j > i; j--)
 			{
 				if (answer[j] < answer[i])
 				{
 					aB[i] = max(aB[i], aB[j] + 1);
 				}
 			}
 			if (aB[i] != B[i])
 				return 0;
 		}
 		return 1;
 	}
 	for(int i = pos; i >= 0; i--)
 	{
 		int cur[32];
 		memcpy(cur, answer, sizeof(cur));
 		answer[pos] = i;
 		aA[pos] = 1;
 		for(int j = 0;j < pos; j++)
 		{
 			if (answer[j] >= i)
 			{
 				answer[j] ++;
 			} else {
 				aA[pos] = max(aA[pos], aA[j] + 1);
 			}
 		}
 		if (aA[pos] == A[pos])
 		{
 			if(rec(pos+1))
 			{
 				return 1;
 			}
 		}
 		memcpy(answer, cur, sizeof(cur));
 	}
 	return 0;
 }
 
 int main()
 {
 	int T;
 	scanf("%d", &T);
 	for(int testcase = 1; testcase <= T; testcase++)
 	{
 		scanf("%d",&n);
 		for(int i = 0; i < n; i++)
 		{
 			scanf("%d",&A[i]);
 		}
 		for(int i = 0; i < n; i++)
 		{
 			scanf("%d",&B[i]);
 		}
 		int res = rec(0);
 		printf("Case #%d:",testcase);
 		for(int i = 0; i < n; i++) printf(" %d",answer[i] + 1);
 		printf("\n");
 	}
 	return 0;
 }