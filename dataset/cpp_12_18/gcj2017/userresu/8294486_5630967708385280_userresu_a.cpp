#include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <queue>
 #include <set>
 #include <map>
 #include <cstring>
 using namespace std;
 
 int D, N;
 void main2 () {
 	scanf("%d %d",&D,&N);
 	double t = 0;
 	for (int i=1;i<=N;++i) {
 		int K, S;
 		scanf("%d %d",&K,&S);
 		t = max(t, (1.0 * D-K) / S);
 	}
 	printf("%.6lf\n", 1.0 * D / t);
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
