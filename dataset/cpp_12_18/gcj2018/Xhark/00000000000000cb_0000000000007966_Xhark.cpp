
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:36777216")
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <string.h>
using namespace std;
int D;
char P[64];
int lenP;
int calcPoint() {
	int str = 1;
	int point = 0;
	for (int i = 0; i < lenP; i++) {
		if (P[i] == 'C') str *= 2;
		if (P[i] == 'S') point += str;
	}
	return point;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		scanf("%d %s", &D, P);
		lenP = strlen(P);
		int sol = 0;
		while (calcPoint() > D) {
			int loc = -1;
			for (int i = 0; i+1 < lenP; i++) {
				if (P[i] == 'C' && P[i + 1] == 'S') {
					loc = i;
				}
			}
			if (loc == -1) {
				break;
			}
			swap(P[loc], P[loc + 1]);
			sol++;
		}
		static int cs = 1;
		printf("Case #%d: ", cs++);
		if (calcPoint() <= D) {
			printf("%d", sol);
		}
		else {
			printf("IMPOSSIBLE");
		}
		printf("\n");
	}
	return 0;
}