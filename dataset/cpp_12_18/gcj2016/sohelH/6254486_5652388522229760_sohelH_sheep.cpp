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
 
 const int debug = 0;
 #define DEBUG(x) cout<<">> "<<#x<<':'<<(x)<<endl
 const int inf = 1000000000;
 
 int solve(int n) {
 	int A[10] = {0};
 	int cnt = 0;
 	int init = n;
 	while(true) {
 		int nn = n;
 		while (nn) {
 			int m = nn % 10;
 			if (A[m] == 0) {
 				A[m] = 1;
 				cnt++;
 			}
 			nn /= 10;
 		}
 		if (cnt == 10) {
 			return n;
 		}
 		n += init;
 	}
 	return -1; // should never come here
 }
 
 int main() {
 	int test, cases = 1;
 	cin >> test;
 	for (cases = 1; cases <= test; cases++) {
 		int n; cin >> n;
 		if (n == 0) {
 			cout << "Case #" << cases << ": INSOMNIA" << endl;
 		} else {
 			int res = solve(n);
 			cout << "Case #" << cases << ": " << res << endl;
 		}
 	}
 	return 0;
 }
