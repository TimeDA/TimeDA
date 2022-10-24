#include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <set>
 
 using namespace std;
 
 int k;
 int nt;
 
 char s[10000];
 
 char cnt[200];
 
 int c[100][100];
 char v[100];
 
 int main()
 {
 	for(int i = 'a'; i <= 'z'; i++) cnt[i] = 1;
 
 	cnt['o'] = cnt['i'] = cnt['e'] = cnt['a'] = cnt['s'] = cnt['t'] = cnt['b'] = cnt['g'] = 2;
 
 	scanf("%d", &nt);
 	
 	for(int tt = 1; tt <= nt; tt++)
 	{	
 		printf("Case #%d: ", tt);
 		
 		scanf("%d ", &k);
 		scanf("%s", s);
 
 		if (k != 2)  { puts(":-S"); continue;}
 
 		memset(c, 0, sizeof c);
 		memset(v, 0, sizeof v);
 
 		for(int i = 1; s[i]; i++)
 		{
 			char c1 = s[i - 1] - 'a';
 			char c2 = s[i] - 'a';
 			c[c1][c2] = 1;
 			v[c1] = v[c2] = 1;
 
 			if (cnt[c1 + 'a'] == 2)
 			{
 				v[c1 + 50] = 1;
 				c[c1 + 50][c2] = 1;
 				if (cnt[c2 + 'a'] == 2) c[c1 + 50][c2 + 50] = 1;
 			}
 			if (cnt[c2 + 'a'] == 2)
 			{
 				v[c2 + 50] = 1;
 				c[c1][c2 + 50] = 1;
 			}
 		}
 		
 		int add = 1;
 		int res = 0;
 		for(int i = 0; i < 100; i++)
 		{
 			int ci = 0, co = 0;
 			for(int j = 0; j < 100; j++)
 			{
 				if (c[i][j]) co++;
 				if (c[j][i]) ci++;
 			}
 			if (ci != co) add = 0;
 			res += max(ci, co);
 		}
 
 		printf("%d\n", res + add);
 
 	}
 	
 	return 0;
 }
