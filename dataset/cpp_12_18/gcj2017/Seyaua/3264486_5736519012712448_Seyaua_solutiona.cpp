#include <iostream>
 #include <string>
 #include <cstring>
 #include <set>
 #include <map>
 #include <vector>
 
 using namespace std;
 
 void flip(string& s, int i, int k) {
 	if (i + k - 1 >= s.length()) {
 		return;
 	}
 	for (int j = i; j < i + k; ++j) {
 		if (s[j] == '-') {
 			s[j] = '+';
 		} else {
 			s[j] = '-';
 		}
 	}
 }
 
 int is_good(const string& s) {
 	for (char c : s) {
 		if (c == '-') {
 			return false;
 		}
 	}
 	return true;
 }
 
 void solve(int tcase) {
 	cout << "Case #" << tcase << ": ";
 
 	string s;
 	int k;
 	cin >> s >> k;
 
 	int res = 0;
 	for (int i = 0; i < s.length(); ++i) {
 		if (s[i] == '-') {
 			flip(s, i, k);
 			++res;
 		}
 	}
 	if (is_good(s)) {
 		cout << res << endl;
 	} else {
 		cout << "IMPOSSIBLE" << endl;
 	}
 }
 
 int main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	int tcase;
 	cin >> tcase;
 
 	for (int i = 0; i < tcase; ++i) {
 		solve(i + 1);
 	}
 
 	return 0;
 }
