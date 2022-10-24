#include <iostream>
 
 using namespace std;
 
 unsigned long long Factor(unsigned long long val, int x) {
 	unsigned long long n = 0;
 	unsigned long long mul = 1;
 	while (val > 0) {
 		if ((val & 1ULL) == 1ULL) {
 			n += mul;
 		}
 		mul *= x;
 		val >>= 1;
 	}
 	for (mul = 2; mul * mul <= n && mul <= 1000; mul++)
 		if (n % mul == 0) return mul;
 	return 1ULL;
 }
 
 void print_binary(unsigned long long val, int m) {
 	for (int digit = m - 1; digit >= 0; digit--) {
 		if ((val & (1ULL << digit)) != 0ULL) cout << '1';
 		else cout << '0';
 	}
 }
 
 int main(void) {
 	
 	int tc;
 	int n, m;
 	
 	cin >> tc >> m >> n;
 	
 	int cnt = 0;
 	
 	cout << "Case #1:" << endl;
 	
 	for (unsigned long long x = 0; cnt < n; x++) {
 		unsigned long long val = (1ULL << (m - 1)) | (x << 1) | 1ULL;
 		unsigned long long arr[9];
 		bool good = true;
 		for (int i = 2; i <= 10 && good; i++) {
 			if ((arr[i - 2] = Factor(val, i)) == 1) good = false;
 		}
 		if (good) {
 			print_binary(val, m);
 			for (int i = 0; i < 9; i++) cout << ' ' << arr[i];
 			cout << endl;
 			cnt++;
 		}
 	}
 	
 	return 0;
 }
