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
 
 const int debug = 0;
 const int inf = 1000000000;
 
 int n;
 vector<string> v;
 
 struct Node {
 	int r, c;
 };
 
 vector<Node> vn;
 int zero;
 
 int vis[5];
 bool yes;
 vector<string> tmp;
 vector<int> p;
 void dfs(int u) {
 	if (u == n) return;
 	if (!yes) return;
 	bool ok = false;
 	for (int i = 0; i < n; i++) {
 		if (vis[i] == 0 && tmp[ p[u] ][ i] == '1') {
 			vis[i] = 1;
 			ok = true;
 			dfs(u + 1);
 			vis[i] = 0;
 		}
 	}
 	if (!ok) yes = false;
 }
 
 bool ok(int state) {
 	tmp.clear();
 	for (int i = 0; i < v.size(); i++) tmp.push_back(v[i]);
 
 	for (int i = 0; i < zero; i++) {
 		if (state & (1<<i)) {
 			int r = vn[i].r;
 			int c = vn[i].c;
 			tmp[r][c] = '1';
 		}
 	}
 
 	if (debug) {
 		cout << "tmp: " << endl;
 		for (int i = 0; i < tmp.size(); i++)
 			cout << tmp[i] << endl;
 	}
 
 	p.clear();
 	for (int i = 0 ; i < n; i++) p.push_back(i);
 
 	do {
 		for (int i = 0; i < n; i++) vis[i] = 0;
 		yes = true;
 		dfs(0);
 		if (!yes) return false;
 	}while(next_permutation(p.begin(), p.end()));
 	return true;
 
 }
 
 int main() {
 	int test, cases = 1;
 	cin >> test;
 	for (cases = 1; cases <= test; cases++) {
 		cin >> n;
 		v.clear();
 		for (int i = 0; i < n; i++) {
 			string s; cin >> s;
 			v.push_back(s);
 		}
 
 		zero = 0;
 		vn.clear();
 		for (int i = 0; i < n; i++)
 			for (int j = 0; j < n; j++) {
 				if (v[i][j] == '0') {
 					zero++;
 					Node node;
 					node.r = i; node.c = j;
 					vn.push_back(node);
 				}
 			}
 
 		int res = inf;
 		for (int i = 0; i < (1<<zero); i++) {
 			int cnt = __builtin_popcount(i);
 			if (debug) cout << "cnt: " << cnt << endl;
 			if (cnt > res) continue;
 			if ( ok(i) ) {
 				res = min(res, cnt);
 			}
 		}
 		printf("Case #%d: %d\n", cases, res);
 
 	}
 	return 0;
 }
