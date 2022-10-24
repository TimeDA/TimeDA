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
 
 #define N 10010
 int a[N], n, X;
 
 int main () {
 	int _; cin >> _;
 	for (int __ = 1; __ <= _; __ ++) {
 		int S = 0;
 		cin >> n >> X;
 		for (int i = 0; i < n; i ++) cin >> a[i];
 		sort(a,a+n); int lw = 0;
 		for (int i = n-1; i >= lw; i --) {
 			if (i == lw) {S ++; break;}
 			if (a[i] + a[lw] <= X) {lw ++;S ++;}
 			else {S ++;}
 		}
 		printf ("Case #%d: %d\n", __, S);
 	}
 	return 0; 
 }