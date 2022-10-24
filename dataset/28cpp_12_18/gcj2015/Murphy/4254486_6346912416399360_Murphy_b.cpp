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
 
 int a[1024], b[1024];
 int x[2014], y[1024], r[1024];
 
 int main(){
     int caseNumber;
     //scanf("%d", &caseNumber);
     cin>>caseNumber;
     REP(caseN, caseNumber) {
     	memset(a, 0, sizeof a); memset(b, 0, sizeof b);
     	memset(y, 0, sizeof y);
     	int N, K;
     	cin>>N>>K;
     	int best = 0;
     	REP(i, N-K+1) {
     		cin>>r[i];
     		if (i) {
     			x[i] = r[i] - r[i - 1];
     			// x[i] -= x[i - 1];
     			int target = i % K;
     			int z = y[target] + x[i];
     			y[target] = z;
     			a[target] = max(a[target], z);
     			b[target] = min(b[target], z);
     			best = max(best, a[target] - b[target]);
     			// cout<<i<<' '<<x[i]<<' '<<target<<' '<<y[target]<<' '<<z<<' '<<a[target]<<' '<<b[target]<<endl;
     		}
     	}
     	int m1 = 0, m2 = 0, idx = 0;
     	REP(i, K)
     		if (best == a[i] - b[i]) {
     			idx = i;
     			break;
     		}
     		// cout<<idx<<endl;
     	REP(i, K) {
     		m2 += a[i] - a[idx];
     		m1 += b[i] - b[idx];
     		// cout<<i<<' '<<a[i]<<' '<<b[i]<<' '<<a[idx]<<' '<<b[idx]<<endl;
     		// md += best - (a[i] - b[i]);
     	}
     	r[0] %= K;
     	// cerr<<r[0]<<' '<<m1<<' '<<m2<<endl;
     	int ok = 0;
     	for (int i = m1; i <= m2; i++) if ((i + r[0]) % K == 0) {
     		ok = 1; break;
     	}
     	best += 1 - ok;
     	// if (m1<= -K || m2 >= K || m1 <= r[0] && r[0] <= m2) ; else best++;
     	printf("Case #%d: %d\n", caseN + 1, best);
     }
     return 0;
 }