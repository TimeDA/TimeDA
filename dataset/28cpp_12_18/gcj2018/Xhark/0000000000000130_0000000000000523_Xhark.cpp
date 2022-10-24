
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:36777216")
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <string.h>
using namespace std;
string small = "TOO_SMALL";
string big = "TOO_BIG";
string correct = "CORRECT";
char res_t[512];
int main() {
	int T, A, B, N;
	scanf("%d", &T);
	for (int t = 0; t<T; t++) {
		scanf("%d%d%d", &A, &B, &N);
		A++;
		while (1) {
			int C = (A + B) / 2;
			printf("%d\n", C);
			fflush(stdout);
			scanf("%s", res_t);
			string res = res_t;
			if (res == small) {
				A = C + 1;
			}
			else if (res == big) {
				B = C - 1;
			}
			else {
				break;
			}
		}
	}
	return 0;
}