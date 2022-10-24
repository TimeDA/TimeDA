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
 
 int N;
 double D;
 double x[1010],v[1010];
 
 void main2(void){
 	int i;
 	
 	cin >> D >> N;
 	REP(i,N) cin >> x[i] >> v[i];
 	
 	double maxt = 0.0;
 	REP(i,N) maxt = max(maxt, (D - x[i]) / v[i]);
 	
 	double ans = D / maxt;
 	printf("%.9f\n", ans);
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
