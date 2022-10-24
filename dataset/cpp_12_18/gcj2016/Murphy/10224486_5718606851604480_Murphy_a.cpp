#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <string>
 #include <vector>
 #include <cmath>
 #include <algorithm>
 #include <cassert>
 #include <set>
 #include <map>
 #include <queue>
 #include <iostream>
 #include <fstream>
 using namespace std;
 #define pb push_back 
 #define REP(i,n) for(int i=0;i<(n);i++ )
 typedef long long LL;
 typedef pair<int, int> pii;
 
 bool gao(string s) {
 	if (s.size() == 1) return true;
 	string p;
 	for (int i = 0; i < s.size(); i += 2) {
 		char c = s[i];
 		char d = s[i + 1];
 		if (c == d) return false;
 		if (c>d) swap(c, d);
 		//p r s
 		if (c == 'P' && d == 'R') p += 'P';
 		if (c == 'R' && d == 'S') p += 'R';
 		if (c == 'P' && d == 'S') p += 'S';
 	}
 	return gao(p);
 }
 
 
 int main(){
     int caseNumber;
     //scanf("%d", &caseNumber);
     cin>>caseNumber;
     REP(caseN, caseNumber) {
     	int P, R, S, N; cin>>N>>R>>P>>S;
     	string s;
     	string res;
     	REP(i, P) s += 'P';
     	REP(i, R) s += 'R';
     	REP(i, S) s += 'S';
     	// cout<<res<<' '<<s<<'x'<<s.size()<<endl;
     	do {
   			bool good = gao(s);
     		if (good) 
     			if (res == "" || s < res) res = s; 
     	} while (next_permutation(s.begin(), s.end()));
     	if (res == "") 
     	printf("Case #%d: IMPOSSIBLE\n", caseN + 1);
     		else
     	printf("Case #%d: %s\n", caseN + 1, res.c_str());
     }
     return 0;
 }