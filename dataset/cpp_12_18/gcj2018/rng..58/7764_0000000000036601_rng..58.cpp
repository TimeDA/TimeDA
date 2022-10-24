#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define INF (1<<29)
	
int X;
int N;
int x[100010];

int get_percent(int x){
	int tmp = x * 200 / X;
	return (tmp + 1) / 2;
}

int get_minx(int p){
	if(p == 0) return 0;
	if(p > 100) return INF;
	return ((2 * p - 1) * X + 199) / 200;
}

int dp[210];
int cost[110];

int dp2[210];

void main2(void){
	int i,j;
	
	cin >> X >> N;
	REP(i,N) scanf("%d", &x[i]);
	
	REP(i,210) dp[i] = INF;
	dp[0] = 0;
	
	int already = 0;
	int sumx = 0;
	
	REP(i,N){
		int p = get_percent(x[i]);
		already += p;
		sumx += x[i];
		
		int C = ((X > 200) ? 1 : (100 - p));
		for(int c=1;c<=C;c++) cost[c] = get_minx(p+c) - x[i];
		
		for(j=200;j>=0;j--) for(int c=1;c<=C;c++) if(j+c <= 200) dp[j+c] = min(dp[j+c], dp[j] + cost[c]);
	}
	
	// REP(i,210) cout << dp[i] << ' '; cout << endl;
	
	REP(i,210) dp2[i] = INF;
	dp2[0] = 0;
	REP(i,210) for(j=1;j<=100;j++) if(i+j <= 200) dp2[i+j] = min(dp2[i+j], dp2[i] + get_minx(j));
	
	// cout << already << endl;
	
	int ans = 0;
	REP(i,210) REP(j,210) if(sumx + dp[i] + dp2[j] <= X) ans = max(ans, already + i + j);
	
	cout << ans << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc + 1);
		main2();
	}
	return 0;
}
