//Problem D
 
 #include<iostream>
 #include<cstdio>
 #include<cstdlib>
 #include<cstring>
 #include<algorithm>
 #include<cmath>
 #include<vector>
 #include<set>
 
 using namespace std;
 
 int get() {
 	char c;
 	while (c = getchar(), c != '-' && (c < '0' || c > '9'));
 	bool flag = (c == '-');
 	if (flag)
 		c = getchar();
 	int x = 0;
 	while (c >= '0' && c <= '9') {
 		x = x * 10 + c - '0';
 		c = getchar();
 	}
 	return flag ? -x : x;
 }
 
 const int dir[4][2] = {
 	{-1, 0},
 	{0, -1},
 	{0, 1},
 	{1, 0}
 };
 const int inf = 1000000000;
 
 int R, C, numS, numT;
 char c[100][100];
 pair<int, int> s[100], t[100];
 bool danger[100][100];
 int dist[100][100];
 bool hit[1024][10][10];
 pair<int, int> q[10000];
 bool flag[1024][1024];
 int dp[1024][1024];
 pair<int, int> trans[1024][1024];
 
 bool check(char c) {
 	return c == '#' || c == '.' || c == 'S' || c == 'T';
 }
 
 bool ok(int x, int y) {
 	return x >= 0 && x < R && y >= 0 && y < C && c[x][y] != '#';
 }
 
 void bfs(int x, int y) {
 	for (int i = 0; i < R; i++)
 		for (int j = 0; j < C; j++)
 			dist[i][j] = inf;
 	dist[x][y] = 0;
 	int f = 0, r = 1;
 	q[0] = make_pair(x, y);
 	while (f < r) {
 		int x = q[f].first, y = q[f].second;
 		f++;
 		if (danger[x][y])
 			continue;
 		for (int i = 0; i < 4; i++) {
 			int x0 = x + dir[i][0];
 			int y0 = y + dir[i][1];
 			if (ok(x0, y0) && dist[x0][y0] == inf) {
 				dist[x0][y0] = dist[x][y] + 1;
 				q[r++] = make_pair(x0, y0);
 			}
 		}
 	}
 }
 
 int solve(int maskS, int maskT) {
 	if (flag[maskS][maskT])
 		return dp[maskS][maskT];
 	int ans = 0;
 	pair<int, int> best;
 	for (int i = 0; i < numS; i++)
 		if (maskS & (1 << i))
 			for (int j = 0; j < numT; j++)
 				if (maskT & (1 << j))
 					if (hit[maskT][i][j]) {
 						int tmp = solve(maskS ^ (1 << i), maskT ^ (1 << j)) + 1;
 						if (tmp > ans) {
 							ans = tmp;
 							best = make_pair(i, j);
 						}
 					}
 	trans[maskS][maskT] = best;
 	flag[maskS][maskT] = true;
 	return dp[maskS][maskT] = ans;
 }
 
 int main() {
 	int totalTest = get();
 	for (int test = 1; test <= totalTest; test++) {
 		C = get();
 		R = get();
 		int M = get();
 		for (int i = 0; i < R; i++)
 			for (int j = 0; j < C; j++)
 				while (c[i][j] = getchar(), !check(c[i][j]));
 		numS = numT = 0;
 		for (int i = 0; i < R; i++)
 			for (int j = 0; j < C; j++)
 				if (c[i][j] == 'S')
 					s[numS++] = make_pair(i, j);
 				else if (c[i][j] == 'T')
 					t[numT++] = make_pair(i, j);
 		memset(hit, 0, sizeof(hit));
 		for (int mask = 0; mask < (1 << numT); mask++) {
 			for (int i = 0; i < numT; i++)
 				if (~mask & (1 << i))
 					c[t[i].first][t[i].second] = '.';
 			memset(danger, 0, sizeof(danger));
 			for (int i = 0; i < R; i++)
 				for (int j = 0; j < C; j++)
 					if (c[i][j] == 'T')
 						for (int k = 0; k < 4; k++) {
 							int x = i, y = j;
 							while (true) {
 								danger[x][y] = true;
 								x += dir[k][0];
 								y += dir[k][1];
 								if (!ok(x, y))
 									break;
 							}
 						}
 			for (int i = 0; i < numS; i++) {
 				bfs(s[i].first, s[i].second);
 				for (int j = 0; j < numT; j++)
 					if (mask & (1 << j))
 						for (int k = 0; k < 4; k++) {
 							int x = t[j].first, y = t[j].second;
 							while (true) {
 								if (dist[x][y] <= M)
 									hit[mask][i][j] = true;
 								x += dir[k][0];
 								y += dir[k][1];
 								if (!ok(x, y))
 									break;
 							}
 						}
 			}
 			for (int i = 0; i < numT; i++)
 				if (~mask & (1 << i))
 					c[t[i].first][t[i].second] = 'T';
 		}
 		memset(flag, 0, sizeof(flag));
 		int ans = solve((1 << numS) - 1, (1 << numT) - 1);
 		printf("Case #%d: %d\n", test, ans);
 		int S = (1 << numS) - 1, T = (1 << numT) - 1;
 		while (ans--) {
 			pair<int, int> tmp = trans[S][T];
 			int x = tmp.first, y = tmp.second;
 			printf("%d %d\n", x + 1, y + 1);
 			S ^= (1 << x);
 			T ^= (1 << y);
 		}
 	}
 	return 0;
 }
