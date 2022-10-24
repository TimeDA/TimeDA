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
 		int n, k;
 		char buffer[1100];
 		scanf("%s %d\n", buffer, &k);
 		n = strlen(buffer);
 		int resp = 0;
 
 		for (int i = 0; i + k <= n; i++)
 		{
 			if (buffer[i] == '-')
 			{
 				for (int j = i; j < i + k; j++)
 				{
 					buffer[j] = (buffer[j] == '+') ? '-' : '+';
 				}
 				resp++;
 			}
 		}
 
 		for (int i = n - k; i < n; i++)
 		{
 			if (buffer[i] == '-')
 			{
 				resp = -1;
 				break;
 			}
 		}
 
 		if (resp == -1)
 			printf("Case #%d: IMPOSSIBLE\n", t + 1);
 		else
 			printf("Case #%d: %d\n", t + 1, resp);
 	}
 	return 0;
 }
