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
 
 char winner(char a, char b) {
 	if (a > b) swap(a, b);
 	if(a == 'P' && b == 'R') return 'P';
 	if(a == 'P' && b == 'S') return 'S';
 	if(a == 'R' && b == 'S') return 'R';
 	assert(false);
 }
 
 bool ok(string s) {
 	while(true) {
 		string ss = "";
 		for (int i = 0; i < s.size(); i += 2) {
 			if (s[i] == s[i+1]) return false;
 			ss += winner(s[i], s[i+1]);
 		}
 		s = ss;
 		if (s.size() == 1) return true;
 	}
 	return true;
 }
 
 int main() {
 	int test, cases = 1;
 	cin >> test;
 	for (cases = 1; cases <= test; cases++) {
 		int n, r, p, s;
 		cin >> n >> r >> p >> s;
 		string ss = "";
 		for (int i = 0; i < p; i++) ss += "P";
 		for (int i = 0; i < r; i++) ss += "R";
 		for (int i = 0; i < s; i++) ss += "S";
 		bool yes = false;
 		do {
 			if (ok(ss)) {
 				printf("Case #%d: %s\n", cases, ss.c_str());
 				yes = true;
 				break;
 			}
 		}while(next_permutation(ss.begin(), ss.end()));
 		if (!yes) {
 			printf("Case #%d: IMPOSSIBLE\n", cases);
 		}
 	}
 	return 0;
 }
