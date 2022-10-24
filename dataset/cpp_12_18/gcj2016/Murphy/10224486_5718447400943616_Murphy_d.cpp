#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <string>
 #include <vector>
 #include <cmath>
 #include <algorithm>
 #include <cassert>
 #include <set>
 #include <map>
 #include <queue>
 #include <iostream>
 #include <fstream>
 using namespace std;
 #define pb push_back 
 #define REP(i,n) for(int i=0;i<(n);i++ )
 typedef long long LL;
 typedef pair<int, int> pii;
 
 string s[6];
 int g[16][16];
 vector<int> o;
 bool done[40];
 int N;
 
 bool dfs(int pos) {
 	if (pos == N) return true;
 	int per = o[pos];
 	bool jobs = false;
 	REP(i, N) if (g[i][per] && !done[i]) {
 		jobs = true;
 		done[i] = 1;
 		if (!dfs(pos + 1)) return false;
 		done[i] = 0;
 	}
 	return jobs;
 }
 
 bool gao() {
 	memset(done, 0, sizeof done);
 	bool res = dfs(0);
 	return res;
 }
 
 int main(){
     int caseNumber;
     //scanf("%d", &caseNumber);
     cin>>caseNumber;
     REP(caseN, caseNumber) {
     	cin>>N; 
     	REP(i, N) cin>>s[i];
     	int res = 1024;
     	REP(I, 1<<(N * N)) {
     		bool good = true;
     		int cost = 0;
     		REP (i, N) REP(j, N) {
     			g[i][j] = s[i][j] - '0';
     			int can = ((1<<(i * N + j)) & I) != 0;
     			if (can) {
     				if (!g[i][j]) {
     					g[i][j] = 1;cost++;}
     			} else if (g[i][j]) good = false;
     		}
     		if (good) {
     			vector<int> oo; REP(i, N) oo.pb(i);
     			do {
     				o = oo;
     				bool always = gao();
     				good &= always;
     			} while (next_permutation(oo.begin(), oo.end()));
     			// cout<<I<<' '<<good<<' '<<cost<<endl;
     		}
     		if (good) res = min(res, cost);
     	}
     	printf("Case #%d: %d\n", caseN + 1, res);
     }
     return 0;
 }