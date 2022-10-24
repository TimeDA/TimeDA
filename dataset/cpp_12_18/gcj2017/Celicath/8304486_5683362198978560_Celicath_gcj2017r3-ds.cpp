/* 2017.6.11 Celicath */
 #include <stdio.h>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <set>
 #include <stdint.h>
 #include <queue>
 #include <tuple>
 
 FILE* fin = fopen("input.txt", "r");
 FILE* fout = fopen("output.txt", "w");
 
 long long min[300][300];
 long long max[300][300];
 
 int R, C, N, D;
 
 void updatemin(int r, int c, long long b)
 {
 	std::queue<std::tuple<int, int, long long>> que;
 	que.push(std::make_tuple(r, c, b));
 	while (!que.empty())
 	{
 		auto get = que.front();
 		que.pop();
 		r = std::get<0>(get);
 		c = std::get<1>(get);
 		b = std::get<2>(get);
 		if (min[r][c] < b)
 		{
 			min[r][c] = b;
 			if (r > 1) que.push(std::make_tuple(r - 1, c, b - D));
 			if (r < R) que.push(std::make_tuple(r + 1, c, b - D));
 			if (c > 1) que.push(std::make_tuple(r, c - 1, b - D));
 			if (c < C) que.push(std::make_tuple(r, c + 1, b - D));
 		}
 	}
 }
 void updatemax(int r, int c, long long b)
 {
 	std::queue<std::tuple<int, int, long long>> que;
 	que.push(std::make_tuple(r, c, b));
 	while (!que.empty())
 	{
 		auto get = que.front();
 		que.pop();
 		r = std::get<0>(get);
 		c = std::get<1>(get);
 		b = std::get<2>(get);
 		if (max[r][c] > b)
 		{
 			max[r][c] = b;
 			if (r > 1) que.push(std::make_tuple(r - 1, c, b + D));
 			if (r < R) que.push(std::make_tuple(r + 1, c, b + D));
 			if (c > 1) que.push(std::make_tuple(r, c - 1, b + D));
 			if (c < C) que.push(std::make_tuple(r, c + 1, b + D));
 		}
 	}
 }
 
 int main()
 {
 	int T;
 	fscanf(fin, "%d", &T);
 
 	for (int c_n = 1; c_n <= T; c_n++)
 	{
 		fscanf(fin, "%d%d%d%d", &R, &C, &N, &D);
 
 		for (int i = 1; i <= R; i++)
 			for (int j = 1; j <= C; j++)
 			{
 				min[i][j] = 0;
 				max[i][j] = 1000000000000;
 			}
 
 		for (int i = 0; i < N; i++)
 		{
 			int r, c, b;
 			fscanf(fin, "%d%d%d", &r, &c, &b);
 			updatemin(r, c, b);
 			updatemax(r, c, b);
 		}
 		long long result = 0;
 		for (int i = 1; i <= R; i++)
 			for (int j = 1; j <= C; j++)
 			{
 				if (min[i][j] > max[i][j]) goto hell;
 				result = (result + max[i][j]) % 1000000007;
 			}
 		fprintf(fout, "Case #%d: %lld\n", c_n, result);
 		printf("Case #%d: %lld\n", c_n, result);
 		continue;
 		hell:
 		fprintf(fout, "Case #%d: IMPOSSIBLE\n", c_n);
 		printf("Case #%d: IMPOSSIBLE\n", c_n);
 	}
 	return -0;
 }
