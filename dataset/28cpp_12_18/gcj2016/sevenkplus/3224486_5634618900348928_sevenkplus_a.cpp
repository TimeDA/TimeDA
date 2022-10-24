#include <bits/stdc++.h>
 
 using namespace std;
 
 typedef pair<int, int> PII;
 typedef long long ll;
 
 #define fi first
 #define se second
 #define mp make_pair
 #define pb push_back
 #define pct __builtin_popcount
 
 #define N 200010
 
 string s; int n; 
 char a[N]; 
 
 int main () {
 	int _; cin >> _; 
 	for (int __ = 1; __ <= _; __ ++) {
 		cin >> s; 
 		n = (int) s.length(); 
 		int S = 0; int L = 0; 
 		for (int i = 0; i < n; i ++) {
 			if (L > 0 && a[L-1] == s[i]) {S ++; L --;}
 			else a[L++] = s[i]; 
 		}
 		printf ("Case #%d: %d\n", __, S*10+L/2*5);
 	}
 	return 0;
 }