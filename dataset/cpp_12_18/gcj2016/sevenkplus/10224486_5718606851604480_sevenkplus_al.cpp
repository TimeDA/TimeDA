#include <bits/stdc++.h>
 
 using namespace std;
 
 typedef pair<int, int> PII;
 typedef long long ll;
 
 #define fi first
 #define se second
 #define mp make_pair
 #define pb push_back
 #define pct __builtin_popcount
 
 #define M 10000
 
 string f[13][3][3][3];
 
 int win (int x, int y) {
 	if (y == (x+1)%3) return y;
 	if (x == y) return -1;
 	return x;
 }
 
 string ff(int n, int c, int A, int B) {
 	int C = (1<<n) -A-B;
 	if (abs(A-B) >= 2 || abs(B-C) >= 2 || abs(C-A) >= 2) return "";
 	int ca = B-A+1, cb = C-A+1;
 	if (n == 0) {
 		if (c == 0 && A != 0) return "R"; 
 		if (c == 1 && B != 0) return "P"; 
 		if (c == 2 && C != 0) return "S";
 		return "";
 	}
 	int ha = (1<<n-1); 
 	if (f[n][c][ca][cb] != "W") return f[n][c][ca][cb];
 	string s = "";
 	for (int c1 = 0; c1 < 3; c1 ++)
 		for (int c2 = 0; c2 < 3; c2 ++)
 			if (win(c1, c2) == c) {
 				for (int A1 = 0; A1 <= A; A1 ++)
 					for (int B1 = max(ha-A1-C, 0); B1 <= B && B1 <= ha-A1; B1 ++) {
 						string t1 = ff(n-1,c1,A1,B1);
 						string t2 = ff(n-1,c2,A-A1,B-B1);
 						if (t1 == "" || t2 == "") continue;
 						string t = t1+t2; 
 						if (s == "") s = t; else s = min(s, t); 
 					}
 			}
 	//cout << n << c << A << B << C << s << endl;
 	f[n][c][ca][cb] = s;
 	return s;
 }
 
 int main () {
 	for (int i = 0; i <= 12; i ++) 
 		for (int j = 0; j < 3; j ++)
 			for (int A = 0; A < 3; A ++)
 				for (int B = 0; B < 3; B ++)
 					f[i][j][A][B] = "W";
 	int _; cin >> _;
 	for (int __ = 1; __ <= _; __ ++) {
 		int n, A, B ,C; 
 		cin >> n >> A >> B >> C; 
 		printf ("Case #%d: ", __);
 		bool F = false;
 		string s = "";
 		for (int i = 0; i < 3; i ++) {
 			string t = ff(n,i,A,B); 
 			//cout << t << endl;
 			if (t == "") continue; 
 			if (s == "") s = t; else s = min(s, t); 
 		}
 		if (s == "") puts ("IMPOSSIBLE");
 		else cout << s << endl;
 	}
 	return 0;
 }