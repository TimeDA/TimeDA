/* 2018.4.7 Celicath */
#include <stdio.h>
#include <string.h>
#include <algorithm>

int T, N;
int V[2][100000];

int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	scanf("%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &V[i % 2][i / 2]);
		}
		std::qsort(V[0], (N + 1) / 2, sizeof(T), compare);
		std::qsort(V[1], N / 2, sizeof(T), compare);

		for (int i = 0; i < N - 1; i++)
		{
			if (V[i % 2][i / 2] > V[(i + 1) % 2][(i + 1) / 2])
			{
				printf("Case #%d: %d\n", c_n, i);
				goto hell;
			}
		}
		printf("Case #%d: OK\n", c_n);
	hell:;
	}
	return -0;
}
