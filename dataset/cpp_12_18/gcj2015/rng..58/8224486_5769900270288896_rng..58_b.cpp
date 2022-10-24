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
 
 int a[10][10];
 
 int brute(int X, int Y, int K){
 	int mask,i,j,ans=10000;
 	int N = X * Y;
 	
 	REP(mask,(1<<N)) if(__builtin_popcount(mask) == K){
 		REP(i,X) REP(j,Y){
 			int k = i * Y + j;
 			if(mask&(1<<k)) a[i][j] = 1; else a[i][j] = 0;
 		}
 		int cnt = 0;
 		REP(i,X) REP(j,Y-1) if(a[i][j] && a[i][j+1]) cnt++;
 		REP(i,X-1) REP(j,Y) if(a[i][j] && a[i+1][j]) cnt++;
 		ans = min(ans, cnt);
 	}
 	
 	return ans;
 }
 
 void main2(void){
 	int X,Y,K;
 	cin >> X >> Y >> K;
 	cout << brute(X, Y, K) << endl;
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
