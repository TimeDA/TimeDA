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
 
 int N,C,Q;
 int x[1010],color[1010];
 
 int freq[1010];
 int cap[1010];
 
 int check(int K){
 	int i,j,ans=0;
 	
 	REP(i,N) cap[i] = K;
 	
 	REP(i,Q){
 		for(j=x[i];j>=0;j--) if(cap[j] > 0) break;
 		if(j == -1) return -1;
 		cap[j]--;
 		if(j != x[i]) ans++;
 	}
 	
 	return ans;
 }
 
 void main2(void){
 	int i;
 	
 	cin >> N >> C >> Q;
 	REP(i,Q){
 		cin >> x[i] >> color[i];
 		x[i]--;
 		color[i]--;
 	}
 	
 	REP(i,C) freq[i] = 0;
 	REP(i,Q) freq[color[i]]++;
 	
 	sort(x, x + Q);
 	int low = 0, high = 1000;
 	while(high - low > 1){
 		int mid = (low + high) / 2;
 		if(check(mid) != -1) high = mid; else low = mid;
 	}
 	
 	int K = high;
 	REP(i,C) K = max(K, freq[i]);
 	
 	int ans = check(K);
 	cout << K << ' ' << ans << endl;
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
