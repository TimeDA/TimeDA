#include <iostream>
 
 using namespace std;
 
 int main(void) {
 	
 	int tc;
 	cin >> tc;
 	
 	for(int t = 1; t <= tc; t++) {
 		int n;
 		cin >> n;
 		cout << "Case #" << t << ": ";
 		if (n == 0) {
 			cout << "INSOMNIA" << endl;
 		} else {
 			int ans;
 			int used[10] = {0};
 			int cnt = 0;
 			long long mul = 1;
 			while (cnt < 10) {
 				long long val = n * mul;
 				mul++;
 				ans = val;
 				while (val > 0) {
 					if (used[val % 10] == 0) {
 						used[val % 10] = 1;
 						cnt++;
 					}
 					val /= 10;
 				}
 			}
 			cout << ans << endl;
 		}
 	}
 	
 	return 0;
 }
