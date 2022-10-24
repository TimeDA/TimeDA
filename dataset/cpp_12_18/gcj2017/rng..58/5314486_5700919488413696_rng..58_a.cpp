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
 
 int N,P;
 int x[105];
 int freq[10];
 int dp[105][105][105][105];
 
 void main2(void){
 	int i;
 	
 	cin >> N >> P;
 	REP(i,N) cin >> x[i];
 	
 	REP(i,10) freq[i] = 0;
 	REP(i,N) freq[x[i] % P]++;
 	
 	int A = freq[0], B = freq[1], C = freq[2], D = freq[3];
 	int a,b,c,d;
 	
 	REP(a,A+1) REP(b,B+1) REP(c,C+1) REP(d,D+1){
 		dp[a][b][c][d] = 0;
 		if(a > 0) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a-1][b][c][d]);
 		if(b > 0) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b-1][c][d]);
 		if(c > 0) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c-1][d]);
 		if(d > 0) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c][d-1]);
 		if((b+2*c+3*d) % P == 0) dp[a][b][c][d]++;
 	}
 	
 	int ans = dp[A][B][C][D];
 	if((B+2*C+3*D) % P == 0) ans--;
 	
 	cout << ans << endl;
 }
 
 ////////////////////////////////////////////////////////////////////////////////////////////////////
 
 int main(void){
 	int TC,tc;
 	cin >> TC;
 	REP(tc,TC){
 		printf("Case #%d: ", tc + 1);
 		main2();
 	}
 	return 0;
 }
