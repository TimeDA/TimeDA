#include <cstdio>
 #include <string>
 #include <cstring>
 #include <iostream>
 #include <queue>
 #include <map>
 
 using namespace std;
 
 int main()
 {
 	freopen("D-small-attempt1.in", "r", stdin);
 	freopen("D-small.out", "w", stdout);
 
 	int T;
 	cin >> T;
 
 	for (int cn = 1; cn <= T; ++cn)
 	{
 		int N, M;
 		cin >> N >> M;
 		for (int i = 0; i < M; ++i)
 		{
 			char c;
 			int x, y;
 			scanf(" %c %d %d", &c, &x, &y);
 		}
 		printf("Case #%d: %d %d\n", cn, 2 * N, 2 * N - 1);
 		for (int i = 0; i < N; ++i)
 		{
 			char ch = (i == N - 1) ? 'o' : '+';
 			printf("%c %d %d\n", ch, 1, i + 1);
 			if (i != N - 1)
 			{
 				printf("+ %d %d\n", N, i + 1);
 			}
 		}
 	}
 }