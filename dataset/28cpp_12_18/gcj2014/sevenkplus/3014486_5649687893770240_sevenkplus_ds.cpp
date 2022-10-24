#include <cstdio>
 #include <cstring>
 #include <string>
 #include <iostream>
 #include <sstream>
 #include <map>
 #include <set>
 #include <vector>
 #include <queue>
 #include <bitset>
 #include <numeric>
 #include <ctime>
 #include <cassert>
 #include <algorithm>
 
 using namespace std;
 
 typedef pair<int, int> PII;
 typedef long long ll;
 
 #define fi first
 #define se second
 #define mp make_pair
 #define pb push_back
 #define pct __builtin_popcount
 
 #define N 1010
 int m, n; string s[N];
 int S, T;
 
 int gg(vector<string> a) {
 	sort(a.begin(), a.end());
 	int S = 1 + (int)a[0].length();
 	for (int i = 1; i < (int) a.size(); i ++) {
 		int j = 0;
 		while (j < (int) a[i-1].length() && j < (int) a[i].length() && a[i-1][j] == a[i][j]) j ++;
 		S += (int) a[i].length() - j;
 	}
 	return S;
 }
 
 void ff(int x, vector<vector<string> > A) {
 	if (x == m) {
 		int nS = 0;
 		for (int i = 0; i < n; i ++) {
 			if (A[i].empty()) return;
 			nS += gg(A[i]);
 		}
 		if (nS > S) {
 			S = nS; T = 1;
 		} else
 		if (nS == S) {
 			T ++;
 		}
 		return;
 	}
 	for (int i = 0; i < n; i ++) {
 		vector<vector<string> > B = A;
 		B[i].pb(s[x]);
 		ff(x+1,B);
 	}
 }
 
 int main () {
 	int _; cin >> _;
 	for (int __ = 1; __ <= _; __ ++) {
 		cin >> m >> n;
 		for (int i = 0; i < m; i ++) cin >> s[i];
 		S = T = 0;
 		ff(0,vector<vector<string> >(n,vector<string>())); 
 		printf ("Case #%d: %d %d\n", __, S, T);
 	}
 	return 0; 
 }