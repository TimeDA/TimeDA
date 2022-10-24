#include <iostream>
 #include <sstream>
 #include <string>
 #include <vector>
 #include <deque>
 #include <queue>
 #include <set>
 #include <map>
 #include <algorithm>
 #include <functional>
 #include <utility>
 #include <cmath>
 #include <cstdlib>
 #include <ctime>
 #include <cstdio>
 
 using namespace std;
 
 #define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
 #define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
 
 typedef long long ll;
 
 ll x[10010],len[10010];
 ll D;
 ll dp[10010];
 
 void main2(void){
 	int N,i,j;
 	
 	cin >> N;
 	REP(i,N) cin >> x[i] >> len[i];
 	cin >> D;
 	
 	REP(i,N) dp[i] = -1;
 	dp[0] = x[0];
 	
 	REP(i,N) if(dp[i] != -1) for(j=i+1;j<N;j++) if(x[j] <= x[i] + dp[i]) dp[j] = max(dp[j], min(len[j], x[j] - x[i]));
 	
 	bool ans = false;
 	REP(i,N) if(dp[i] != -1 && x[i] + dp[i] >= D) ans = true;
 	cout << (ans ? "YES" : "NO") << endl;
 }
 
 int main(void){
 	int T,t;
 	cin >> T;
 	REP(t,T){
 		printf("Case #%d: ",t+1);
 		main2();
 	}
 	return 0;
 }
