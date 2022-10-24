#include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <queue>
 #include <cstring>
 #include <string>
 
 using namespace std;
 
 int n,d;
 int mark[3048576];
 pair<int,int> range[2048576];
 
 
 int main(){
 	int T;
 	scanf("%d",&T);
 	for (int testcase = 1; testcase <= T; testcase++){
 		scanf("%d%d",&n,&d);
 		memset(mark, 0, sizeof(mark));
 		int s0, as, cs, rs;
 		int m0, am, cm, rm;
 		scanf("%d%d%d%d",&s0,&as,&cs,&rs);
 		scanf("%d%d%d%d",&m0,&am,&cm,&rm);
 		vector<int> S, M;
 		S.push_back(s0);
 		for (int i = 0; i < n; i++) {
 			int snext = ( (long long)S[i] * as + cs) % rs;
 			S.push_back(snext);
 		}
 		M.push_back(m0);
 		for (int i = 0; i < n; i++) {
 			int mnext = ( (long long)M[i] * am + cm) % rm;
 			M.push_back(mnext);
 		}
 		/* maximum range */
 		range[0].first = S[0];
 		range[0].second = S[0] + d;
 		mark[S[0]]++;
 		mark[S[0]+d+1]--;
 		for (int i = 1; i < n; i++) {
 			int manager = M[i] % i;
 			range[i].first = max(range[manager].first, S[i]);
 			range[i].second = min(range[manager].second, S[i]+d);
 			if (range[i].first <= range[i].second) {
 				mark[range[i].first] ++;
 				mark[range[i].second+1] --;
 			}
 		}
 		int cursum = 0;
 		int ans = 1;
 		for (int i = 0; i <= 2100000; i++) {
 			cursum += mark[i];
 			ans = max(ans, cursum);
 		}
 		printf("Case #%d: %d\n", testcase, ans);
 	}
 	return 0;
 }