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
 
 int main() {
 	int test, cases = 1;
 	cin >> test;
 	for (cases = 1; cases <= test; cases++) {
 		int n, X;
 		cin >> n >> X;
 		vector<int> v;
 		for (int i = 0; i < n; i++) {
 			int a; cin >> a; v.push_back(a);
 		}
 		sort(v.begin(), v.end());
 		reverse(v.begin(), v.end());
 		int res = 0;
 		for (int i = 0; i < n; i++) {
 			if (v[i] == -1) continue;
 			int j;
 			for (j = i + 1; j < n; j++) {
 				if (v[j] == -1) continue;
 				if (v[i] + v[j] <= X) break;
 			}
 			if (j < n) {
 				res++;
 				v[i] = v[j] = -1;
 			} else {
 				res++;
 				v[i] = -1;
 			}
 		}
 		printf("Case #%d: %d\n", cases, res);
 	}
 	return 0;
 }
