#include <iostream>
 #include <string>
 #include <cstring>
 #include <cstdio>
 #include <set>
 #include <map>
 #include <vector>
 #include <algorithm>
 #include <queue>
 #include <bitset>
 #include <cmath>
 
 using namespace std;
 
 const int maxN = 210;
 
 char a[maxN][maxN];
 int b[maxN][maxN];
 
 string dirs = "v^><";
 
 int dx[] = {1, -1, 0, 0};
 int dy[] = {0, 0, 1, -1};
 
 bool is_in(int x, int y, int r, int c) {
 	return x >= 0 && x < r && y >= 0 && y < c;
 }
 
 int fd(char c) {
 	for (int i = 0; i < 4; ++i) {
 		if (dirs[i] == c) {
 			return i;
 		}
 	}
 }
 
 long long hashword(const string& word) {
 	long long ret = 0;
 	for (int i = 0; i < word.size(); ++i) {
 		ret *= 1000003;
 		ret += (word[i] - 'a' + 253);
 	}
 	return ret;
 }
 
 map<string, int> res;
 
 int mapword(string& word) {
 	if (res.count(word)) {
 		return res[word];
 	}
 	return res[word] = res.size();
 }
 
 
 vector <int> parseline(char* line) {
 	int n = strlen(line);
 	vector<int> ret;
 	string cur = "";
 	line[n] = ' ';
 	for (int i = 0; i <= n; ++i) {
 		if (line[i] == ' ') {
 			if (cur != "") {
 				ret.push_back(mapword(cur));
 				cur = "";
 			}
 		} else {
 			cur += line[i];
 		}
 	}
 	return ret;
 }
 
 char sl[5000];
 
 bool canen(vector <string>& cur, set<string>& en, set<string>& fr) {
 }
 
 bool canfr(vector <string>& cur, set<string>& en, set<string>& fr) {
 }
 
 /*void addvec(vector <long long>& a, vector<long long>& b) {
 	for (int i = 0; i < b.size(); ++i) {
 		a.push_back(b[i]);
 	}
 }*/
 
 void solve(int tcase) {
 	printf("Case #%d: ", tcase);
 	int n;
 	scanf("%d\n", &n);
 	set<int> enline;
 	set<int> frline;
 	bitset<5000> ens;
 	bitset<5000> frs;
 
 	vector <vector<int> > other;
 
 	for (int i = 0; i < n; ++i) {
 		gets(sl);
 		vector <int> cur = parseline(sl);
 		if (i == 0) {
 			for (int j = 0; j < cur.size(); ++j) {
 				ens[cur[j]] = 1;
 			}
 		}
 		if (i == 1) {
 			for (int j = 0; j < cur.size(); ++j) {
 				frs[cur[j]] = 1;
 			}
 		}
 		other.push_back(cur);
 	}
 
 	int ans = 1000000;
         //cerr << (n - 2) << endl;
 	for (int i = 0; i < (1 << (n - 2)); ++i) {
 		bitset<5000> ca = ens;
 		bitset<5000> cb = frs;
 		for (int j = 0; j < n - 2; ++j) {
 			if (i & (1 << j)) {
 				for (int k = 0; k < other[j + 2].size(); ++k) {
 					ca[other[j + 2][k]] = 1;
 				}
 			} else {
 				for (int k = 0; k < other[j + 2].size(); ++k) {
 					cb[other[j + 2][k]] = 1;
 				}
 			}
 		}
 
 		ans = min(ans, (int)(ca & cb).count());
 	}
 	cout << ans << endl;
 }
 
 int main() {
 	freopen("input.txt", "r", stdin);
 	freopen("GCJ2015R2.txt", "w", stdout);
 
 	int t;
 	scanf("%d\n", &t);
 
 	for (int i = 1; i <= t; ++i) {
 		cerr << i << endl;
 		solve(i);
 	}
 
 
 	return 0;
 }
 
