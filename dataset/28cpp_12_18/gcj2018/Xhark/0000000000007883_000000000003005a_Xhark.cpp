
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:36777216")
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;
int R, C, Rc, Cc;
char buf[1024];
int dat[128][128], sum;
int main() {
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		scanf("%d %d %d %d", &R, &C, &Rc, &Cc);
		sum = 0;
		for (int i = 0; i < R; i++) {
			scanf("%s", buf);
			for (int j = 0; j < C; j++) {
				dat[i][j] = (buf[j] == '@') ? 1 : 0;
				sum += dat[i][j];
			}
		}
		bool possible = (sum == 0);
		int pc = (Rc + 1) * (Cc + 1);
		if (sum % pc == 0 && sum > 0) {
			int per = sum / pc;
			int perR = sum / (Cc + 1);
			int perC = sum / (Rc + 1);

			vector<int> cutR, cutC;

			int rsum = 0;
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					rsum += dat[i][j];
				}
				if (rsum == perR) {
					cutR.push_back(i);
					rsum = 0;
				}
				else if (rsum > perR) {
					break;
				}
			}

			int csum = 0;
			for (int j = 0; j < C; j++) {
				for (int i = 0; i < R; i++) {
					csum += dat[i][j];
				}
				if (csum == perC) {
					cutC.push_back(j);
					csum = 0;
				}
				else if (csum > perC) {
					break;
				}
			}
			if (cutR.size() == Rc + 1 && cutC.size() == Cc + 1) {
				possible = true;
				int br = 0;
				for (int r = 0; r < Rc; r++) {
					int bc = 0;
					for (int c = 0; c < Cc; c++) {
						int psum = 0;
						for (int i = br; i <= cutR[r]; i++) {
							for (int j = bc; j <= cutC[c]; j++) {
								psum += dat[i][j];
							}
						}
						if (psum != per) possible = false;
						bc = cutC[c]+1;
					}
					br = cutR[r]+1;
				}
			}
		}
		static int cs = 1;
		printf("Case #%d: %s\n", cs++, possible? "POSSIBLE" : "IMPOSSIBLE");
	}
	return 0;
}