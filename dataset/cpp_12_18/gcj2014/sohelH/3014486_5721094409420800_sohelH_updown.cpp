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
 
 int minSwap(vector<int> source, vector<int> target) {
 	map<int, int> M; M.clear();
 	for (int i = 0; i < target.size(); i++)
 		M[ target[i] ] = i + 1;
 	int res = 0;
 	for (int i = 0; i < source.size(); i++) {
 		for (int j = 1; j < source.size(); j++) {
 			if (M[ source[j-1] ] > M[ source[j] ]) {
 				swap(source[j-1], source[j]);
 				res++;
 			}
 		}
 	}
 	return res;
 }
 
 int main() {
 	int test, cases = 1;
 	cin >> test;
 	for (cases = 1; cases <= test; cases++) {
 		int n;
 		vector<int> v;
 		cin >> n;
 		for (int i = 0; i < n; i++) {
 			int a; cin >> a; v.push_back(a);
 		}
 		vector<int> w;
 		w = v;
 		sort(w.begin(), w.end());
 
 		int k = n - 1;
 		int res = 1000000000;
 		for (int i = 0; i < (1<<k); i++) {
 			vector<int> L, R;
 			for (int j = 0; j < k; j++) {
 				if (i & (1<<j)) L.push_back(w[j]);
 				else R.push_back(w[j]);
 			}
 			sort(L.begin(), L.end());
 			sort(R.begin(), R.end()); reverse(R.begin(), R.end());
 			vector<int> A;
 			for (int j = 0; j < L.size(); j++) A.push_back(L[j]);
 			A.push_back(w.back());
 			for (int j = 0; j < R.size(); j++) A.push_back(R[j]);
 			res = min(res, minSwap(v, A)) ;
 		}
 		printf("Case #%d: %d\n", cases, res);
 
 	}
 	return 0;
 }
