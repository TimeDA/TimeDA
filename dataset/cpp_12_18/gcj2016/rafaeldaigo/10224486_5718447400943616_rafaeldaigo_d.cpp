#include<cstdio>
 #include<cstring>
 #include<queue>
 #include<utility>
 #include<vector>
 #include<algorithm>
 
 using namespace std;
 
 char can[30][30];
 
 int n;
 
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
 
 bool isvalid(int mask)
 {
 	int lines[100];
 	int linecount[100];
 	for (int i = 0; i < (1 << n); i++)
 	{
 		linecount[i] = 0;
 	}
 	int smask = (1 << n) - 1;
 	int cover = 0;
 	for (int i = 0; i < n; i++)
 	{
 		int line = mask & smask;
 		mask = mask >> n;
 		lines[i] = line;
 		linecount[line]++;
 		cover |= line;
 	}
 	if (cover != smask)
 		return false;
 	for (int i = 0; i < n; i++)
 	{
 		for (int j = i + 1; j < n; j++)
 		{
 			if ((lines[i] != lines[j]) && ((lines[i] & lines[j]) != 0))
 				return false;
 		}
 		if (linecount[lines[i]] != btcount(lines[i]))
 			return false;
 	}
 	return true;
 }
 
 int main()
 {
 	int t, teste;
 	scanf("%d\n", &teste);
 
 	for (int t = 0; t < teste; t++)
 	{
 		scanf("%d\n", &n);
 		int mask = 0;
 		for (int i = 0; i < n; i++)
 		{
 			scanf("%s\n", can[i]);
 			for (int j = 0; j < n; j++)
 			{
 				if (can[i][j] == '1')
 					mask |= (1 << (i * n + j));
 			}
 		}
 		int best = n * n - btcount(mask);
 
 		for (int a = 0; a < (1 << n * n); a++)
 		{
 			if ((mask | a) != a)
 				continue;
 			int cand = btcount(a) - btcount(mask);
 			if (cand < best && isvalid(a))
 			{
 				best = cand;
 			}
 		}
 
 		printf("Case #%d: %d\n", t + 1, best);
 	}
 	return 0;
 }
