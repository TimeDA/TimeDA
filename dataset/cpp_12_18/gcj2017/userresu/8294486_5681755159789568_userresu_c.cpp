#include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <queue>
 #include <set>
 #include <map>
 #include <cstring>
 using namespace std;
 #define MAXN 102
 typedef long long ll;
 
 ll cost[MAXN][MAXN];
 ll dist[MAXN][MAXN];
 int E[MAXN], S[MAXN];
 double t[MAXN][MAXN];
 void main2 () {
 	int N, Q;
 	scanf("%d %d",&N,&Q);
 	for (int i=1;i<=N;++i) scanf("%d %d",&E[i],&S[i]);
 	for (int i=1;i<=N;++i) for (int j=1;j<=N;++j) {
 		scanf("%lld",&cost[i][j]);
 	}
 	ll INF = 1000000000000000LL;
 	for (int i=1;i<=N;++i) for (int j=1;j<=N;++j) {
 		if (i == j) dist[i][j] = 0;
 		else if (cost[i][j] != -1) dist[i][j] = cost[i][j];
 		else dist[i][j] = INF;
 	}
 	for (int k=1;k<=N;++k) for (int i=1;i<=N;++i) for (int j=1;j<=N;++j) {
 		dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
 	}
 	for (int i=1;i<=N;++i) for (int j=1;j<=N;++j) {
 		if (i == j) t[i][j] = 0;
 		else if (E[i] < dist[i][j]) t[i][j] = INF;
 		else t[i][j] = 1.0 * dist[i][j] / S[i];
 	}
 	for (int k=1;k<=N;++k) for (int i=1;i<=N;++i) for (int j=1;j<=N;++j) {
 		t[i][j] = min(t[i][j], t[i][k] + t[k][j]);
 	}
 	for (int z=1;z<=Q;++z) {
 		int x, y;
 		scanf("%d %d",&x,&y);
 		printf("%.7lf",t[x][y]);
 		if (z < Q) printf(" ");
 		else printf("\n");
 	}
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
