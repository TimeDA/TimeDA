/*
 * Google Code Jam 2014
 * @author: Sohel Hafiz
 */
 
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
 
 vector<string> S[10];
 int n, m;
 vector<string> v;
 int vis[10];
 int maxFound;
 int total;
 
 int totalDistinctPrefix(vector<string> &v) {
 	map<string, bool> M;
 	for (int i = 0; i < v.size(); i++) {
 		string s = "";
 		for (int j = 0; j < v[i].size(); j++) {
 			s += v[i][j];
 			M[s] = 1;
 		}
 	}
 	return M.size() + 1;
 }
 
 void process() {
 	int sum = 0;
 	for (int i = 0; i < n; i++) {
 		sum += totalDistinctPrefix(S[i]);
 	}
 	if (sum > maxFound) {
 		maxFound = sum;
 		total = 1;
 	} else if (sum == maxFound) {
 		total++;
 	}
 }
 
 void dfs(int u, int d, int tot) {
 	if (d == n) {
 		if (tot != m) return;
 		process();
 		return;
 	}
 
 	for (int i = u + 1; i < m; i++) {
 		if (vis[i] == 0) {
 			S[d].push_back(v[i]);
 			vis[i] = 1;
 			dfs(i, d, tot + 1);
 			S[d].pop_back();
 			vis[i] = 0;
 		}
 	}
 	if (S[d].size())
 		dfs(-1, d + 1, tot);
 }
 
 int main() {
 	int test, cases = 1;
 	cin >> test;
 	for (int cases = 1; cases <= test; cases++) {
 		cin >> m >> n;
 		v.clear();
 		for (int i = 0; i < m; i++) {
 			string a; cin >> a; v.push_back(a);
 		}
 		sort(v.begin(), v.end());
 		for (int i = 0; i < n; i++) S[i].clear();
 		memset(vis, 0, sizeof(vis));
 		maxFound = 0;
 		total = 0;
 		dfs(-1, 0, 0);
 		printf("Case #%d: %d %d\n", cases, maxFound, total);
 
 	}
 	return 0;
 }
