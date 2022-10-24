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
 
 #define H 1000000000
 
 int next[2010];
 int h[2010];
 
 bool dfs(int slope, int L, int R){
 	int i;
 	
 	for(i=L+1;i<R;i++) if(next[i] > R) return false;
 	
 	int x = L+1;
 	while(x < R){
 		h[x] = h[R] - (R-x) * slope;
 		int y = next[x];
 		x = y;
 	}
 	
 	x = L+1;
 	while(x < R){
 		int y = next[x];
 		if(!dfs(slope+1, x, y)) return false;
 		x = y;
 	}
 	
 	return true;
 }
 
 void main2(void){
 	int N,i;
 	
 	cin >> N;
 	for(i=1;i<N;i++) cin >> next[i];
 	
 	h[N] = H;
 	bool ans = dfs(0,0,N);
 	
 	if(ans){
 		for(i=1;i<=N;i++) cout << ' ' << h[i];
 		cout << endl;
 	} else {
 		cout << " Impossible" << endl;
 	}
 }
 
 int main(void){
 	int T,t;
 	cin >> T;
 	REP(t,T){
 		printf("Case #%d:",t+1);
 		main2();
 	}
 	return 0;
 }
