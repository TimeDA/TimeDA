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
 
 string getres(char c, int n, int r, int p, int s) {
 	vector<char> cur;
 	cur.push_back(c);
 	for (int i = 0; i < n; ++i) {
 		vector<char> ncur;
 		for (int j = 0; j < cur.size(); ++j) {
 			if (cur[j] == 'R') {
 				ncur.push_back('R');
 				ncur.push_back('S');
 			} else if (cur[j] == 'P') {
 				ncur.push_back('P');
 				ncur.push_back('R');
 			} else if (cur[j] == 'S') {
 				ncur.push_back('S');
 				ncur.push_back('P');
 			}
 		}
 		cur = ncur;
 	}
 
 	vector<string> res;
 	for (int i = 0; i < cur.size(); ++i) {
 		string s = "";
 		s += cur[i];
 		res.push_back(s);
 	}
 
 	for (int i = 0; i < n; ++i) {
 		for (int j = 0; j + 1 < res.size(); j += 2) {
 			if (res[j] > res[j + 1]) {
 				swap(res[j], res[j + 1]);
 			}
 		}
 		vector<string> nres;
 		for (int j = 0; j + 1 < res.size(); j += 2) {
 			nres.push_back(res[j] + res[j + 1]);
 		}
 		res = nres;
 	}
 
 	string ans = res[0];
 	int cntr = 0, cntp = 0, cnts = 0;
 
 	for (int i = 0; i < ans.size(); ++i) {
 		if (ans[i] == 'R') ++cntr;
 		if (ans[i] == 'P') ++cntp;
 		if (ans[i] == 'S') ++cnts;
 	}
 
 	if (cntr == r && cntp == p && cnts == s) {
 		return ans;
 	} else {
 		return "";
 	}
 }
 
 void solve(int tcase) {
 	cout << "Case #" << tcase << ": ";
 
 	int r, p, s;
 	int n;
 	cin >> n >> r >> p >> s;
 
 	vector<string> res;
 
 	string res1 = getres('R', n, r, p, s);
 	string res2 = getres('S', n, r, p, s);
 	string res3 = getres('P', n, r, p, s);
 
 	if (res1 != "") res.push_back(res1);
 	if (res2 != "") res.push_back(res2);
 	if (res3 != "") res.push_back(res3);
 
 	sort(res.begin(), res.end());
 	if (res.size() == 0) {
 		cout << "IMPOSSIBLE" << endl;
 	} else {
 		cout << res[0] << endl;
 	}
 }
 
 int main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	int t;
 	scanf("%d", &t);
 
 	for (int i = 1; i <= t; ++i) {
 		cerr << i << endl;
 		solve(i);
 	}
 
 	return 0;
 }