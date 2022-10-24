#include <iostream>
 #include <string>
 #include <cstring>
 #include <set>
 #include <map>
 #include <vector>
 #include <cmath>
 #include <algorithm>
 
 using namespace std;
 
 
 
 void solve(int tcase) {
 	cout << "Case #" << tcase << ": ";
 
 	long long n, k;
 	cin >> n >> k;
 
 	map<long long, long long> spaces;
 	spaces[-n] = 1;
 
 	long long entries = k;
 	while (entries > 0) {
 		auto cur = *spaces.begin();
 		spaces.erase(spaces.begin());
 		long long val = -cur.first;
 
 		long long nentries = cur.second;
 		
 		long long ls = val / 2;
 		long long rs = (val - 1) / 2;
 
 		if (nentries >= entries) {
 			cout << ls << " " << rs << endl;
 			return;
 		}
 		entries -= nentries;
 		spaces[-ls] += nentries;
 		spaces[-rs] += nentries;
 	}
 }
 
 int main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	int tcase;
 	cin >> tcase;
 
 	for (int i = 0; i < tcase; ++i) {
 		solve(i + 1);
 		cerr << i << endl;
 	}
 
 	return 0;
 }
