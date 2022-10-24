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
 		int c[4];
 		for (int i = 0; i < 4; i++)
 			c[i] = 0;
 		scanf("%d %d\n", &n, &p);
 		for (int i = 0; i < n; i++)
 		{
 			int temp;
 			scanf("%d\n", &temp);
 			c[temp % p]++;
 		}
 
 		int resp = 0;
 		if (p == 2)
 		{
 			resp = c[0] + (c[1] + 1) / 2;
 		}
 		else if (p == 3)
 		{
 			int block12 = min(c[1], c[2]);
 			int rest = max(c[1], c[2]) - block12;
 			resp = c[0] + block12 + (rest + 2) / 3;
 		}
 		else if (p == 4)
 		{
 			int rest2 = c[2] % 2;
 			int block13 = min(c[1], c[3]);
 			int rest = rest2 * 2 + (max(c[1], c[3]) - block13);
 			resp = c[0] + c[2] / 2 + block13 + (rest + 3) / 4;
 		}
 
 		printf("Case #%d: %d\n", t + 1, resp);
 	}
 	return 0;
 }
