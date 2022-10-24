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
 		int m, n;
 		scanf("%d %d\n", &n, &m);
 		bool oplus[110][110], ocross[110][110];
 		bool plus[110][110], cross[110][110];
 		bool r[300], c[300], d[300], sd[300];
 		for (int i = 0; i < n; i++)
 		{
 			for (int j = 0; j < n; j++)
 			{
 				plus[i][j] = false;
 				cross[i][j] = false;
 				oplus[i][j] = false;
 				ocross[i][j] = false;
 			}
 			r[i] = false;
 			c[i] = false;
 		}
 		for (int i = 0; i < 2 * n; i++)
 		{
 			d[i] = false;
 			sd[i] = false;
 		}
 
 		for (int i = 0; i < m; i++)
 		{
 			int a, b;
 			char buffer[10];
 			scanf("%s %d %d\n", buffer, &a, &b);
 			char type = buffer[0];
 			a--;
 			b--;
 			if (type != 'x')
 			{
 				plus[a][b] = oplus[a][b] = true;
 				d[a-b+n] = true;
 				sd[a+b] = true;
 			}
 			if (type != '+')
 			{
 				cross[a][b] = ocross[a][b] = true;
 				r[a] = true;
 				c[b] = true;
 			}
 		}
 
 		for (int i = 0; i < n; i++)
 		{
 			if (r[i])
 				continue;
 			for (int j = 0; j < n; j++)
 			{
 				if (c[j])
 					continue;
 				cross[i][j] = true;
 				r[i] = true;
 				c[j] = true;
 				break;
 			}
 		}
 
 		if (d[n] == false)
 		{
 			plus[0][0] = true;
 			d[n] = true;
 			sd[0] = true;
 		}
 		for (int i = n - 2; i >= 0; i--)
 		{
 			if (sd[n - 1 - i] == false)
 			{
 				for (int a = 0; a < n - i; a++)
 				{
 					int b = n - 1 - i - a;
 					if (d[a-b+n])
 						continue;
 					plus[a][b] = true;
 					d[a-b+n] = true;
 					sd[a+b] = true;
 					break;
 				}
 			}
 			if (sd[n - 1 + i] == false)
 			{
 				for (int a = i; a < n; a++)
 				{
 					int b = n - 1 + i - a;
 					if (d[a-b+n])
 						continue;
 					plus[a][b] = true;
 					d[a-b+n] = true;
 					sd[a+b] = true;
 					break;
 				}
 			}
 		}
 
 		int resp = 0;
 		int changes = 0;
 		for (int i = 0; i < n; i++)
 		{
 			for (int j = 0; j < n; j++)
 			{
 				if (plus[i][j])
 					resp++;
 				if (cross[i][j])
 					resp++;
 				if (plus[i][j] != oplus[i][j] || cross[i][j] != ocross[i][j])
 					changes++;
 			}
 		}
 
 		printf("Case #%d: %d %d\n", t + 1, resp, changes);
 		for (int i = 0; i < n; i++)
 		{
 			for (int j = 0; j < n; j++)
 			{
 				if (plus[i][j] != oplus[i][j] || cross[i][j] != ocross[i][j])
 				{
 					char type;
 					if (plus[i][j] && cross[i][j]) type = 'o';
 					else if (plus[i][j]) type = '+';
 					else if (cross[i][j]) type = 'x';
 					else type = ' ';
 					printf("%c %d %d\n", type, i + 1, j + 1);
 				}
 			}
 		}
 	}
 	return 0;
 }
