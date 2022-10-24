#include <cstdio>
 #include <vector>
 #include <cmath>
 #include <set>
 #include <map>
 #include <algorithm>
 #include <cstring>
 #include <string>
 #include <iostream>
 #include <cassert>
 #include <memory.h>
 using namespace std;
 
 #define forn(i, n) for (int i = 0; i < (int)(n); i++)
 #define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
 #define pb push_back
 typedef long long ll;
 typedef pair<int, int> pii;
 typedef long double ld;
 
 string items(const set<char>& ss) {
 	string res;
 	foreach(it, ss)
 		res += *it;
 	return res;
 }
 
 char a[7][7];
 
 string solve() {
 	forn(i, 4) scanf("%s", a[i]);
 
 	set<char> ss;
 	forn(i, 4) {
 		ss.clear();
 		forn(j, 4) ss.insert(a[i][j]);
 		if (items(ss) == "X" || items(ss) == "TX") return "X won";
 		if (items(ss) == "O" || items(ss) == "OT") return "O won";
 
 		ss.clear();
 		forn(j, 4) ss.insert(a[j][i]);
 		if (items(ss) == "X" || items(ss) == "TX") return "X won";
 		if (items(ss) == "O" || items(ss) == "OT") return "O won";
 	}
 
 	ss.clear();
 	forn(j, 4) ss.insert(a[j][j]);
 	if (items(ss) == "X" || items(ss) == "TX") return "X won";
 	if (items(ss) == "O" || items(ss) == "OT") return "O won";
 
 	ss.clear();
 	forn(j, 4) ss.insert(a[j][3-j]);
 	if (items(ss) == "X" || items(ss) == "TX") return "X won";
 	if (items(ss) == "O" || items(ss) == "OT") return "O won";
 
 	forn(i, 4) forn(j, 4)
 		if (a[i][j] == '.') return "Game has not completed";
 
 	return "Draw";
 }
 
 int main() {
 	int tc;
 	scanf("%d", &tc);
 	for (int q = 1; q <= tc; q++) {
 		printf("Case #%d: ", q);
 		printf("%s\n", solve().c_str());
 	}
 	return 0;
 }