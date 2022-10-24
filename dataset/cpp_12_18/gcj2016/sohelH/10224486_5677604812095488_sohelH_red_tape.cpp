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
 
 int n, K;
 vector<double> v;
 
 int main() {
 	int test, cases = 1;
 	cin >> test;
 	for (cases = 1; cases <= test; cases++) {
 		cin >> n >> K;
 		v.clear();
 		for (int i = 0; i < n; i++) {
 			double a; cin >> a; v.push_back(a);
 		}
 		double tie = 0;
 		for (int i = 0; i < (1<<n); i++) {
 			if (__builtin_popcount(i) != K) continue;
 
 			vector<int> p;
 			for (int j = 0; j < n; j++)
 				if (i & (1<<j)) p.push_back(j);
 			string s;
 			for (int j = 0; j < K/2; j++) s += "0";
 			for (int j = 0; j < K/2; j++) s += "1";
 			double sum = 0;
 			do {
 				double tt = 1;
 				for (int j = 0; j < K; j++) {
 					if (s[j] == '0') tt *= (1.0 - v [ p[j] ]);
 					else tt *= v[ p[j] ];
 				}
 				sum += tt;
 
 			}while (next_permutation(s.begin(), s.end()));
 			tie = max(tie, sum);
 		}
 		printf("Case #%d: %.10lf\n",cases, tie);
 	}
 	return 0;
 }
