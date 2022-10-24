#include <bits/stdc++.h>
 
 using namespace std;
 
 typedef pair<int, int> PII;
 typedef long long ll;
 
 #define fi first
 #define se second
 #define mp make_pair
 #define pb push_back
 #define pct __builtin_popcount
 
 #define N 110
 
 int n, m; 
 string a[N]; string b; 
 
 int main () {
 	int _; cin >> _; 
 	for (int __ = 1; __ <= _; __ ++) {
 		cin >> n >> m;
 		for (int i = 0; i < n; i ++) cin >> a[i];
 		cin >> b;
 		printf ("Case #%d: ", __);
 		bool F = true;
 		for (int i = 0; i < n; i ++)
 			if (a[i] == b) F = false;
 		if (!F) {
 			puts ("IMPOSSIBLE"); continue;
 		}
 		string s, t; 
 		for (int i = 0; i < m-1; i ++) s += "1";
 		s += "0?";
 		for (int i = 0; i < m-1; i ++) s += "1";
 		for (int i = 0; i < m-1; i ++) t += "0?";
 		if (t.empty()) t = "0";
 		printf("%s %s\n", s.c_str(), t.c_str());
 	}
 	return 0;
 }