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
 		int n, p;
 		int packs[60][60];
 		int need[60];
 		int testindexes[60];
 		long long maxcount = 1000000;
 		scanf("%d %d\n", &n, &p);
 		for (int i = 0; i < n; i++)
 		{
 			scanf("%d", &need[i]);
 			testindexes[i] = 0;
 		}
 		for (int i = 0; i < n; i++)
 		{
 			for (int j = 0; j < p; j++)
 			{
 				scanf("%d", &packs[i][j]);
 			}
 			sort(&packs[i][0], &packs[i][p]);
 			maxcount = min(maxcount, packs[i][p - 1] * 10LL / (9 * need[i]) + 1);
 		}
 
 		bool finished = false;
 		int resp = 0;
 		for (long long count = 1; count <= maxcount && !finished; )
 		{
 			bool valid = true;
 			bool movedindex = false;
 			for (int j = 0; j < n; j++)
 			{
 				long long packsize10 = packs[j][testindexes[j]] * 10;
 				bool toosmall = (count * need[j] * 9LL > packsize10);
 				bool toobig = (count * need[j] * 11LL < packsize10);
 				if (toosmall)
 				{
 					valid = false;
 					movedindex = true;
 					testindexes[j]++;
 					if (testindexes[j] == p)
 					{
 						finished = true;
 					}
 				}
 				else if (toobig)
 				{
 					valid = false;
 				}
 			}
 			if (valid)
 			{
 				resp++;
 				for (int j = 0; j < n; j++)
 				{
 					testindexes[j]++;
 					if (testindexes[j] == p)
 					{
 						finished = true;
 					}
 				}
 			}
 			else if (!movedindex)
 			{
 				count++;
 			}
 		}
 
 		printf("Case #%d: %d\n", t + 1, resp);
 	}
 	return 0;
 }
