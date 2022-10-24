
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:36777216")
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;
const int MAX_N = 100005;
int V[MAX_N], N;
int Ve[MAX_N], Vo[MAX_N];
int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &V[i]);
			if (i % 2 == 0) Ve[i / 2] = V[i];
			else Vo[i / 2] = V[i];
		}
		int eN = (N + 1) / 2;
		int oN = N - eN;
		sort(V, V + N);
		sort(Ve, Ve + eN);
		sort(Vo, Vo + oN);
		static int cs = 1;
		printf("Case #%d: ", cs++);
		int sol = -1;
		for (int i = 0; i < N; i++) {
			if (i % 2 == 0) {
				if (Ve[i / 2] != V[i]) {
					sol = i;
					break;
				}
			}
			else {
				if (Vo[i / 2] != V[i]) {
					sol = i;
					break;
				}
			}
		}
		if (sol == -1) {
			printf("OK");
		}
		else {
			printf("%d", sol);
		}
		printf("\n");
	}
	return 0;
}