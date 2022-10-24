#include <algorithm>
 #include <vector>
 #include <cstdio>
 
 using namespace std;
 
 int main() {
 	int T;
 	scanf("%d", &T);
 	for (int cn = 1; cn <= T; ++cn) {
 		int B, N;
 		scanf("%d%d", &B, &N);
 		vector<long long> a(37, 0);
 		int maxm = 0;
 		for (int i = 0; i < N; ++i) {
 			scanf("%d", &a[i]);
 		}
 		sort(a.begin(), a.end());
 
 		double ret = 0;
 		for (int i = (37 - N); i <= 36; ++i) {
 			// ÷ Ȯ ִ   = i (37̸  غ?)
 			for (int j = 1; j <= i; ++j) {
 				// j ּҰ̰   ּҰ+1 ̻
 				for (int jm = 1; jm <= 9999; ++jm) {
 					int need = 0;
 					int earn = 0;
 					bool ispos = true;
 					for (int k = 0; k < 37; ++k) {
 						if (k < j) {
 							if (a[k] > jm) { ispos = false; break; }
 							need += jm - a[k];
 							earn += 36 * (jm - a[k]);
 						} else {
 							if (a[k] < (jm + 1)) {
 								need += (jm + 1) - a[k];
 							} 
 						}
 					}
 					if (need > B) break;
 					if (ispos) {
 						double tmp = earn * 1.0 / i - need;
 						if (ret < tmp) ret = tmp;
 					}
 				}
 			}
 		}
 /*		
 		double ret = 0;
 		for (int i = 1; i <= maxm + 1; ++i) {
 			// need money;
 			int need = (37 - N) * i;
 			int winm = (37 - N) * 36 * i;
 			int totp = (37 - N), same = 0;
 			for (int j = 0; j < N; ++j) {
 				if (i > a[j]) {
 					need += (i - a[j]);
 					winm += (i - a[j]) * 36;
 					totp++;
 				}
 				if (i == a[j]) { totp++; same++; }
 			}
 			if (need > B) break;
 			for (int j = 0; j <= same; ++j) {
 				if (ret < winm * 1.0 / (totp - j) - (need + j) && (need + j <= B))
 				{
 					ret = winm * 1.0 / (totp - j) - (need + j);
 				}
 			}
 		}
 */
 		printf("Case #%d: %.10lf\n", cn, ret);
 	}
 }
 
