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
 
 typedef long long ll;
 
 ll maxrank(int N, ll x){
 	if(x == 0) return 0;
 	return (1ll<<(N-1)) + maxrank(N-1, (x-1)/2);
 }
 
 ll minrank(int N, ll x){
 	if(x == (1ll<<N)-1) return x;
 	return minrank(N-1, (x+1)/2);
 }
 
 void main2(void){
 	int N;
 	ll P;
 	
 	cin >> N >> P;
 	
 	ll low = 0, high = (1ll<<N);
 	while(high-low > 1){
 		ll mid = (low + high) / 2;
 		if(maxrank(N, mid) < P) low = mid; else high = mid;
 	}
 	ll ans1 = low;
 	
 	low = 0; high = (1ll<<N);
 	while(high-low > 1){
 		ll mid = (low + high) / 2;
 		if(minrank(N, mid) < P) low = mid; else high = mid;
 	}
 	ll ans2 = low;
 	
 	cout << ans1 << ' ' << ans2 << endl;
 }
 
 int main(void){
 	int TC,tc;
 	cin >> TC;
 	REP(tc,TC){
 		printf("Case #%d: ", tc+1);
 		main2();
 	}
 	return 0;
 }
