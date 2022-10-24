#include<bits/stdc++.h>
 
 using namespace std;
 
 // input reading
 template<class T>
 vector<T> takeInput(int n) {
 	vector<T> v;
 	T a;
 	for(int i = 0; i < n; i++) { cin >> a; v.push_back(a); }
 	return v;
 }
 
 struct Node {
 	string f;
 	int r, c;
 };
 
 int n, m;
 
 int main() {
 	int test;
 	cin >> test;
 	for (int cases = 1; cases <= test; cases++) {
 		cin >> n >> m;
 
 		int flag[105] = {0};
 		for (int i = 0; i < m; i++) {
 			string s;
 			int r, c;
 			cin >> s >> r >> c;
 			flag[c] = s[0];
 		}
 
 		vector<Node> vn;
 		bool yes = false;
 		int xIndex = -1;
 		for (int i = 1; i <= n; i++) {
 			if (flag[i] == 'o') yes = true;
 			else if (flag[i] == 'x') xIndex = i;
 		}
 		if (yes == false) {
 			Node node;
 			node.f = 'o';
 			if (xIndex == -1) {
 				node.r = node.c = 1;
 			} else {
 				node.r = 1;
 				node.c = xIndex;
 			}
 			vn.push_back(node);
 			flag[node.c] = 'o';
 		}
 		for (int i = 1; i <= n; i++) {
 			if (flag[i] == 0) {
 				Node node;
 				node.f = '+';
 				node.r = 1;
 				node.c = i;
 				vn.push_back(node);
 			}
 		}
 
 
 		if (flag[1] == 'o') {
 			for (int i = 2; i <= n; i++) {
 				Node node;
 				node.f = 'x';
 				node.r = node.c = i;
 				vn.push_back(node);
 			}
 		} else if (flag[n] == 'o') {
 			for (int i = 2, j = n - 1; i <= n; i++, j--) {
 				Node node;
 				node.f = 'x';
 				node.r = i; node.c = j;
 				vn.push_back(node);
 			}
 		} else {
 			int r, c;
 			r = c = n;
 			while (c >= 1) {
 				if (flag[c] == 'o') c--;
 				if (c == 0) break;
 				Node node;
 				node.f = 'x';
 				node.r = r;
 				node.c = c;
 				vn.push_back(node);
 				r--; c--;
 			}
 		}
 		for (int i = 2; i < n; i++) {
 			Node node;
 			node.f = '+';
 			node.r = n;
 			node.c = i;
 			vn.push_back(node);
 		}
 
 		int res = n + 1;
 		res += n - 1;
 		if(n > 1) res += n - 2;
 		cout << "Case #" << cases << ": ";
 		cout << res << " " << vn.size() << endl;
 		for (int i = 0; i < vn.size(); i++) {
 			cout << vn[i].f << " " << vn[i].r << " " << vn[i].c << endl;
 		}
 
 	}
 	return 0;
 }
