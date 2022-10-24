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

int dp[510][510];
	
void pre(void){
	int r,b,i,j;
	
	REP(r,100) REP(b,100) if(r > 0 || b > 0) if(r * (r + 1) / 2 * (b + 1) <= 500 && b * (b + 1) / 2 * (r + 1) <= 500){
		for(i=509;i>=0;i--) for(j=509;j>=0;j--) if(i >= r && j >= b) dp[i][j] = max(dp[i][j], dp[i-r][j-b] + 1);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void){
	pre();
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc + 1);
		int r,b;
		cin >> r >> b;
		cout << dp[r][b] << endl;
	}
	return 0;
}
