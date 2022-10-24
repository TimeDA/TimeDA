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
 #define DEBUG(x) cout<<">> "<<#x<<':'<<(x)<<endl
 const int inf = 1000000000;
 
 int total;
 int N, J;
 
 void dfs(int pos, vector<int> v) {
 	if (total == 0) return;
 	if (pos == N) {
 		if (v.back() == 0) return;
 		vector<int> res;
 		for (int base = 2; base <= 10; base++) {
 			const int last = 20;
 			long long val[last] = {0};
 			for (int i = 0; i < v.size(); i++) {
 				for (int j = 2; j < last; j++) {
 					val[j] = val[j] * base + v[i];
 					val[j] %= j;
 				}
 			}
 			for (int div = 2; div < last; div++) {
 				if (val[div] == 0) {
 					res.push_back(div);
 					break;
 				}
 			}
 			if (res.size() != base - 1) break;
 		}
 		if (res.size() == 9) {
 			for (int i = 0; i < v.size(); i++)
 				cout << v[i];
 			for (int i = 0; i < res.size(); i++)
 				cout << " " << res[i];
 			cout << endl;
 			total--;
 		}
 		return;
 	}
 	v.push_back(1);
 	dfs(pos + 1, v);
 	v.pop_back();
 	v.push_back(0);
 	dfs(pos + 1, v);
 }
 
 int main() {
 	int test, cases = 1;
 	cin >> test;
 	for (cases = 1; cases <= test; cases++) {
 		cin >> N >> J;
 		vector<int> v;
 		v.push_back(1);
 		total = J;
 		cout << "Case #" << cases << ":" << endl;
 		dfs(1, v);
 	}
 	return 0;
 }
