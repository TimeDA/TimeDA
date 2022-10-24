#include <iostream>
 #include <string>
 #include <cstring>
 #include <set>
 #include <map>
 #include <vector>
 #include <bitset>
 #include <queue>
 #include <algorithm>
 #include <cstdio>
 #pragma comment(linker, "/STACK:256000000")
 
 using namespace std;
 
 void solve(int tcase) {
 	cout << "Case #" << tcase << ": ";
 	string s;
 	cin >> s;
 
 	vector<pair<char, int>> cur;
 
 	int score = 0;
 
 	int total = 0;
 
 	for (int i = 0; i < s.size(); ++i) {
 		if (cur.size() == 0) {
 			cur.push_back(make_pair(s[i], 10));
 			++total;
 		} else if (s[i] == cur.back().first) {
 			score += cur.back().second;
 			cur.pop_back();
 		} else if (total == s.size() / 2) {
 			score += (cur.back().first == s[i]) ? cur.back().second : (cur.back().second - 5);
 			cur.pop_back();
 		} else {
 			cur.push_back(make_pair(s[i], 10));
 			++total;
 		}
 	}
 	cout << score << endl;
 }
 
 int main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	int t;
 	cin >> t;
 
 	for (int i = 0; i < t; ++i) {
 		solve(i + 1);
 	}
 
 	return 0;
 }