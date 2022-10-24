#include<cstdio>
 #include<cstring>
 #include<queue>
 #include<utility>
 #include<vector>
 #include<algorithm>
 
 using namespace std;
 
 int r, c;
 char s[30][30];
 
 void solverow(int row)
 {
 	char use = '?';
 	for (int i = 0; i < c; i++)
 	{
 		if (s[row][i] != '?')
 		{
 			if (use == '?')
 			{
 				for (int j = 0; j < i; j++)
 				{
 					s[row][j] = s[row][i];
 				}
 			}
 			use = s[row][i];
 		}
 		else
 		{
 			 s[row][i] = use;
 		}
 	}
 }
 
 int main()
 {
 	int t, teste;
 	scanf("%d\n", &teste);
 	for (int t = 0; t < teste; t++)
 	{
 		scanf("%d %d\n", &r, &c);
 		for (int i = 0; i < r; i++)
 		{
 			scanf("%s\n", s[i]);
 			solverow(i);
 		}
 
 		int index = -1;
 		for (int i = 0; i < r; i++)
 		{
 			if (s[i][0] != '?')
 			{
 				if (index == -1)
 				{
 					for (int j = 0; j < i; j++)
 					{
 						strcpy(s[j], s[i]);
 					}
 				}
 				index = i;
 			}
 			else if (index != -1)
 			{
 				strcpy(s[i], s[index]);
 			}
 		}
 
 		printf("Case #%d:\n", t + 1);
 		for (int i = 0; i < r; i++)
 		{
 			printf("%s\n", s[i]);
 		}
 	}
 	return 0;
 }
