#pragma warning(disable:4996)
 #include <stdio.h>
 #include <algorithm>
 #include <vector>
 #include <string>
 using namespace std;
 
 long long a, ac, b, bc;
 int main() {
 	freopen("C-small-1-attempt0.in", "r", stdin);
 	freopen("C-small-1-attempt0.out", "w", stdout);
 	int T;
 	scanf("%d", &T);
 	while (T-- > 0) {
 		long long N, K, sol;
 		scanf("%lld %lld", &N, &K);
 		a = N + 1; ac = 0; b = N; bc = 1;
 		while (1) {
 			K -= ac;
 			if (K <= 0) {
 				sol = a;
 				break;
 			}
 			K -= bc;
 			if (K <= 0) {
 				sol = b;
 				break;
 			}
 
 			if (a % 2 == 1) {
 				ac = ac * 2 + bc;
 			}
 			else {
 				bc = bc * 2 + ac;
 			}
 			a = a / 2;
 			b = a - 1;
 		}
 		static int cs = 1;
 		printf("Case #%d: %lld %lld\n", cs++, sol / 2, (sol - 1) / 2);
 	}
 	return 0;
 }