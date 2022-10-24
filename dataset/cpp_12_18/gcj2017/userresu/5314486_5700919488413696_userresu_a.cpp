#include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <queue>
 #include <set>
 using namespace std;
 typedef long long ll;
 
 void main2 () {
 	int N, P;
 	scanf("%d %d",&N,&P);
 	int cnt[4];
 	for (int i=0;i<4;++i) cnt[i] = 0;
 	int sum = 0;
 	for (int i=1;i<=N;++i) {
 		int x;
 		scanf("%d",&x);
 		++cnt[x%P];
 		sum += x;
 	}
 	int tot = cnt[0] - (sum % P == 0);
 	if (P == 2) {
 		printf("%d\n",tot + cnt[1] / 2 + 1);
 		return;
 	}
 	int m = min(cnt[1], cnt[P-1]);
 	cnt[1] -= m;
 	cnt[P-1] -= m;
 	tot += m;
 	if (P == 4) {
 		tot += cnt[2] / 2;
 		if (cnt[2] % 2) {
 			cnt[2] = 1;
 			if (cnt[1] >= 2) cnt[1] -= 2, ++tot;
 			if (cnt[3] >= 2) cnt[3] -= 2, ++tot;
 		}
 	}
 	tot += cnt[1] / P;
 	tot += cnt[P-1] / P;
 	printf("%d\n",tot + 1);
 }
 
 int main () {
 	int T = 1;
 	scanf("%d",&T);
 	for (int z=1;z<=T;++z) {
 		printf("Case #%d: ",z);
 		main2();
 	}
 	return 0;
 }
