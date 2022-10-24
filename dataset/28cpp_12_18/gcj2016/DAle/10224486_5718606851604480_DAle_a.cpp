#include <iostream>
 #include <fstream>
 #include <algorithm>
 #include <string>
 #include <vector>
 #include <map>
 #include <set>
 #include <queue>
 #include <cstring>
 #include <cmath>
 #include <sstream>
 
 using namespace std;
 
 string getParents(char ch) {
 	if (ch == 'S') return "PS";
 	if (ch == 'P') return "PR";
 	if (ch == 'R') return "RS";
 }
 
 void msort(string& s, int l, int r) {
 	if (l+1 == r) return;
 	string ls = s.substr(l, (r-l) / 2);
 	string rs = s.substr(l + (r - l) / 2, (r - l) / 2);
 	if (rs < ls) {
 		for (int i = l; i < l + (r - l) / 2; ++i) {
 			swap(s[i], s[i + (r - l) / 2]);
 		}
 	}
 	msort(s, l, l + (r - l) / 2);
 	msort(s, l + (r - l) / 2, r);
 }
 
 string resolve(char ch, int n) {
 	string res; res += ch;
 	for (int i = 0; i < n; ++i) {
 		string nRes;
 		for (char ch : res) {
 			nRes += getParents(ch);
 		}
 		res = nRes;
 	}
 	msort(res, 0, res.size());
 	return res;
 }
 
 vector<int> countS(string& s) {
 	vector<int> res(3);
 	for (char ch : s) {
 		if (ch == 'R') ++res[0];
 		if (ch == 'P') ++res[1];
 		if (ch == 'S') ++res[2];
 	}
 	return res;
 }
 
 int main() {
 	ifstream ifs("a.in");
 	ofstream ofs("a.out");
 	int t;
 	ifs >> t;
 
 	for (int test = 0; test < t; ++test) {
 		int n, r, p, s;
 		ifs >> n >> r >> p >> s;
 		vector<int> res = { r, p, s };
 		string resStr;
 		string resS = resolve('S', n);
 		if (countS(resS) == res) resStr = resS;
 		string resP = resolve('P', n);
 		if (countS(resP) == res) resStr = (resStr.empty() ? resP : min(resStr, resP));
 		string resR = resolve('R', n);
 		if (countS(resR) == res) resStr = (resStr.empty() ? resR : min(resStr, resR));
 		ofs << "Case #" << test + 1 << ": " << (resStr.empty() ? "IMPOSSIBLE" : resStr) << endl;
 	}
 	return 0;
 }