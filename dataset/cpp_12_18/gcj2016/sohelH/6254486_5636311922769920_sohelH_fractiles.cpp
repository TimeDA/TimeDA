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
 
 int main() {
 	int test, cases = 1;
 	cin >> test;
 	for (cases = 1; cases <= test; cases++) {
 		int k, c, s;
 		cin >> k >> c >> s;
 
 		if (c == 1) {
 			if (s < k) {
 				printf("Case #%d: IMPOSSIBLE\n", cases);
 			} else {
 				printf("Case #%d:", cases);
 				for (int i = 1; i <= k; i++) {
 					cout << " " << i;
 				}
 				cout << endl;
 			}
 		} else {
 			if (s < (k-1)) {
 				printf("Case #%d: IMPOSSIBLE\n", cases);
 			} else {
 				printf("Case #%d:", cases);
 				int start = 2;
 				if (k == 1) start = 1;
 				for (int i = start; i <= k; i++) {
 					cout << " " << i;
 				}
 				cout << endl;
 			}
 		}
 	}
 	return 0;
 }
