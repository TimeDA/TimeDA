#include <cstdio>
 #include <vector>
 #include <set>
 
 using namespace std;
 
 int r, c;
 int ret;
 int a[7][7];
 int dx[4] = { -1, 0, 0, 1 };
 int dy[4] = { 0, -1, 1, 0 };
 set<string> sets;
 
 void backtr(int x, int y)
 {
 	if (x == r)
 	{
 		bool ispos = true;
 		for (int i = 0; i < r; ++i)
 			for (int j = 0; (j < c) && ispos; ++j)
 			{
 				int cnt = 0;
 				for (int k = 0; k < 4; ++k)
 				{
 					int xx = i + dx[k], yy = j + dy[k];
 					if (xx < 0 || xx == r) continue;
 					if (yy < 0) yy += c;
 					if (yy == c) yy = 0;
 					if (a[xx][yy] == a[i][j]) cnt++;
 				}
 				if (cnt != a[i][j]) ispos = false;
 			}
 		if (ispos)
 		{
 			string mins, ss;
 			for (int start = 0; start < c; ++start)
 			{
 				ss = "";
 				for (int i = 0; i < r; ++i)
 					for (int j = 0; j < c; ++j)
 						ss += (char)('0' + a[i][(start + j) % c]);
 				if (start == 0 || mins > ss) mins = ss;
 			}
 			sets.insert(mins);
 			ret++;
 		}
 		return;
 	}
 	for (int i = 1; i <= 3; ++i)
 	{
 		a[x][y] = i;
 		if (y + 1 == c)
 		{
 			if (x > 1)
 			{
 				bool ispos = true;
 				int i = x - 1;
 				for (int j = 0; (j < c) && ispos; ++j)
 				{
 					int cnt = 0;
 					for (int k = 0; k < 4; ++k)
 					{
 						int xx = i + dx[k], yy = j + dy[k];
 						if (xx < 0 || xx == r) continue;
 						if (yy < 0) yy += c;
 						if (yy == c) yy = 0;
 						if (a[xx][yy] == a[i][j]) cnt++;
 					}
 					if (cnt != a[i][j]) ispos = false;
 				}
 				if (!ispos) continue;
 			}
 			backtr(x + 1, 0);
 		}
 		else
 			backtr(x, y + 1);
 	}
 }
 
 int ttable[7][7] = {
 	{ 0, 0, 0, 0, 0, 0, 0 },
 	{ 0, 0, 0, 0, 0, 0, 0 },
 	{ 0, 0, 0, 2, 1, 1, 3 },
 	{ 0, 0, 0, 2, 3, 2, 2 },
 	{ 0, 0, 0, 3, 1, 1, 5 },
 	{ 0, 0, 0, 3, 3, 1, 5 },
 	{ 0, 0, 0, 6, 4, 2,19 }};
 
 int main()
 {
 	freopen("d2.in", "r", stdin);
 	freopen("d2.out", "w", stdout);
 	int T;
 	scanf("%d", &T);
 	for (int cn = 1; cn <= T; ++cn)
 	{
 		scanf("%d%d", &r, &c);
 		printf("Case #%d: %d\n", cn, ttable[r][c]);
 		/*
 		ret = 0;
 		sets.clear();
 		backtr(0, 0);
 		printf("%d %d\n", ret, sets.size());
 		*/
 	}
 	return 0;
 }