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
 int a[N], n;
 
 int main () {
 	int _; cin >> _;
 	for (int __ = 1; __ <= _; __ ++) {
 		cin >> n;
 		for (int i = 0; i < n; i ++) cin >> a[i];
 		int S = 0;
 		for (int i = 0; i < n; i ++) {
 			int l = 0, r = 0;
 			for (int j = 0; j < i; j ++) 
 				if (a[j] > a[i]) l ++;
 			for (int j = i+1; j < n; j ++) 
 				if (a[j] > a[i]) r ++;
 			S += min(l,r);
 		}
 		printf ("Case #%d: %d\n", __, S);
 	}
 	return 0; 
 }