#include<cstdio>
 #include<iostream>
 #include<queue>
 #include<stack>
 #include<vector>
 #include<string>
 #include<algorithm>
 #include<map>
 #include<sstream>
 #include<cmath>
 #include<cctype>
 #include<cassert>
 #include<cstring>
 #include<cstdlib>
 
 using namespace std;
 
 // ------------- PRE-WRITTEN CODES ---------------------------------
 
 // defines and const
 #define DEBUG(x) cout<<">> "<<#x<<':'<<(x)<<endl
 const int inf = 1000000000;
 
 // input reading
 template<class T>
 vector<T> takeInput(int n) {
 	vector<T> list;
 	T a; int i;
 	for(i = 0; i < n; i++) { cin >> a; list.push_back(a); }
 	return list;
 }
 
 // math
 long long ncr[305][305] = {0};
 void gen_ncr(int n) {
 	int i, j;
 	for(i = 0; i <= n; i++) ncr[i][0] = 1;
 	for(i=1; i<=n; i++) for(j=1;j<=n;j++)  ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
 }
 
 double dis(double x1, double y1, double x2, double y2) {
 	return sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
 }
 
 // --------------- END of PRE-WRITTEN CODES --------------------------
 
 bool guar(int pos, int target, int total) {
 	//DEBUG(pos);  DEBUG(target); DEBUG(total);
 	if( target < 0 ) return false;
 	if( pos == 0 ) return true;
 	//if( target == total ) return false;
 
 	return guar( (pos - 1) / 2, target - total / 2, total / 2);
 }
 
 int poss(int pos, int target, int total) {
 	if( target < 0 ) return false;
 	if( pos == 0 ) return true;
 
 	int down = (total - pos - 2)  / 2;
 	if( pos != total - 1 )
 		return poss(total/2 - down - 1, target, total / 2);
 	else {
 		return poss(total / 2 - 1, target - total / 2, total / 2);
 	}
 
 }
 
 int main() {
 	int test, cases = 1;
 	cin >> test;
 	for( cases = 1; cases <= test; cases++) {
 		int n, p;
 		cin >> n >> p;
 
 		// guaranteed
 		int g = 0;
 		for(int i = 1; i < (1<<n); i++) {
 			//DEBUG(i);
 			if( guar(i, p - 1, 1<<n) ) g = i;
 			else break;
 		}
 
 		int possible = 0;
 		for(int i = 1; i < (1<<n); i++) {
 			if( poss(i, p - 1, 1<<n) ) possible = i;
 			else break;
 		}
 
 		printf("Case #%d: %d %d\n", cases, g, possible);
 	}
 	return 0;
 }
