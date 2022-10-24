#include <cstdio>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 int main()
 {
 	int T;
 	scanf("%d", &T);
 	for (int cn = 1; cn <= T; ++cn)
 	{
 		int n;
 		scanf("%d", &n);
 		vector<double> a(n), b(n);
 		for (int i = 0; i < n; ++i) scanf("%lf", &a[i]);
 		for (int i = 0; i < n; ++i) scanf("%lf", &b[i]);
 		sort(a.begin(), a.end());
 		sort(b.begin(), b.end());
 
 		int ret1 = 0, ret2 = 0;
 		vector<int> c1(n, 0), c2(n, 0);
 		for (int i = 0; i < n; ++i) {
 			int win = 1;
 			for (int j = 0; j < n; ++j) {
 				if (c2[j] == 1) continue;
 				if (a[i] < b[j]) {
 					c2[j] = 1;
 					win = 0;
 					break;
 				}
 			}
 			ret2 += win;
 		}
 
 		for (int i = n; i > 0; --i) {
 			bool ispos = true;
 			for (int j = 0; j < i; ++j) {
 				if (a[n - i + j] < b[j]) 
 				{
 					ispos = false;
 					break;
 				}
 			}
 			if (ispos) {
 				ret1 = i;
 				break;
 			}
 		}
 		printf("Case #%d: %d %d\n", cn, ret1, ret2);
 	}
 }
