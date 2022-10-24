#include <iostream>
 #include <string>
 #include <cstring>
 #include <set>
 #include <map>
 #include <vector>
 #include <cstdio>
 #include <bitset>
 #include <queue>
 #include <algorithm>
 
 using namespace std;
 
 vector<vector<int> > cons = {
 	{0, 0, 1, 1, 1, 0},
 	{0, 0, 0, 0, 1, 0},
 	{1, 0, 0, 0, 1, 1},
 	{1, 0, 0, 0, 0, 0},
 	{1, 1, 1, 0, 0, 0},
 	{0, 0, 1, 0, 0, 0}
 };
 
 using State = vector<int>;
 using FState = pair<State, pair<int, int>>;
 
 map<FState, FState> results;
 
 FState mkstate(State cur, int x, int y) {
 	return make_pair(cur, make_pair(x, y));
 }
 
 void rec(FState cur, const vector<int>& limits, FState prev) {
 	if (results.count(cur)) {
 		return;
 	}
 	results[cur] = prev;
 
 	State nst = cur.first;
 	int lst = cur.second.second;
 	int fst = cur.second.first;
 	for (int i = 0; i < 6; ++i) {
 		if (nst[i] + 1 <= limits[i] && cons[i][lst]) {
 			nst[i] += 1;
 			rec(mkstate(nst, fst, i), limits, cur);
 			nst[i] -= 1;
 		}
 	}
 }
 
 void solve2(int tcase) {
 	cout << "Case #" << tcase << ": ";
 
 	int n;
 	vector<int> c(6);
 	cin >> n >> c[0] >> c[1] >> c[2] >> c[3] >> c[4] >> c[5];
 
 	results.clear();
 	
 	for (int i = 0; i < 6; ++i) {
 		if (c[i] > 0) {
 			State cur(6);
 			cur[i] = 1;
 			rec(mkstate(cur, i, i), c, mkstate({0, 0, 0, 0, 0, 0}, -1, -1));
 		}
 	}
 
 	for (int i = 0; i < 6; ++i) {
 		for (int j = 0; j < 6; ++j) {
 			FState cur = mkstate(c, i, j);
 			if (!cons[i][j]) {
 				continue;
 			}
 
 			if (results.count(cur)) {
 				vector<int> res;
 				while (true) {
 					res.push_back(cur.second.second);
 					cur = results[cur];
 					if (cur.second.first == -1) {
 						break;
 					}
 				}
 				string strgood = "ROYGBV";
 				for (int j = 0; j < res.size(); ++j) {
 					cout << strgood[res[j]];
 				}
 				cout << endl;
 				return;
 			}
 		}
 	}
 	cout << "IMPOSSIBLE" << endl;
 }
 
 
 void solve(int tcase) {
 	cout << "Case #" << tcase << ": ";
 
 	int n;
 	vector<int> c(6);
 	cin >> n >> c[0] >> c[1] >> c[2] >> c[3] >> c[4] >> c[5];
 
 	vector<pair<int, char>> cur;
 	cur.push_back(make_pair(c[0], 'R'));
 	cur.push_back(make_pair(c[2], 'Y'));
 	cur.push_back(make_pair(c[4], 'B'));
 
 	sort(cur.begin(), cur.end());
 
 	reverse(cur.begin(), cur.end());
 
 	if (cur[0].first > cur[1].first + cur[2].first) {
 		cout << "IMPOSSIBLE" << endl;
 		return;
 	}
 
 	vector<string> cols(cur[0].first, "");
 	int cp = 0;
 	for (int i = 0; i < cur[0].first; ++i) {
 		cols[cp % cols.size()] += cur[0].second;
 		++cp;
 	}
 	for (int i = 0; i < cur[1].first; ++i) {
 		cols[cp % cols.size()] += cur[1].second;
 		++cp;
 	}
 	for (int i = 0; i < cur[2].first; ++i) {
 		cols[cp % cols.size()] += cur[2].second;
 		++cp;
 	}
 
 	string res = "";
 	for (int i = 0; i < cols.size(); ++i) {
 		res += cols[i];
 	}
 	cout << res << endl;
 }
 
 int main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	int tests;
 	cin >> tests;
 
 	for (int i = 1; i <= tests; ++i) {
 		cerr << "Starting tcase: " << i << endl;
 		solve(i);
 	}
 
 	return 0;
 }