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
 
 int c[1024];
 
 /*
 "o" to "0", "i" to "1", "e" to "3", "a" to "4", 
 "s" to "5", "t" to "7", "b" to "8" and/or "g" to "9"
 */
 
 int cnt[256];
 set<string> S;
 int res;
 
 void gao(char c1, char c2) {
 
 	string s2 = "  ";
 	s2[0] = c1; s2[1] = c2;
 	if (S.find(s2) == S.end()) {
 		S.insert(s2);
 		res++;
 	} else return;
 	cnt[c1]++;
 	cnt[c2]--;
 	//cout<<s2<<endl;
 	//printf("%c %c %d\n", c1, c2, res);
 }
 int main(){
     int caseNumber;
     scanf("%d", &caseNumber);
     //cin>>caseNumber;
     memset(c, 0, sizeof c);
     c['o'] = '0';c['i'] = '1';c['e'] = '3';c['a'] = '4';
     c['s'] = '5';c['t'] = '7';c['b'] = '8';c['g'] = '9';
     REP(caseN, caseNumber) {
     	int k;
     	string s;
     	cin>>k>>s;
     	S.clear();
     	res = 0;
     	memset(cnt, 0, sizeof cnt);
     	REP(i, s.size() - 1) {
     		char c1 = s[i], c2 = s[i + 1];
     		gao(c1, c2);
     		if (c[c1] != 0 && c[c2] == 0) {
     			gao(c[c1], c2);
     		}
     		if (c[c1] == 0 && c[c2] != 0) {
     			gao(c1, c[c2]);
     		}
     		if (c[c1] != 0 && c[c2] != 0) {
     			gao(c[c1], c2);
     			gao(c1, c[c2]);
     			gao(c[c1], c[c2]);
     		}
     	}
     	int res2 = 0;
     	REP(i, 256) {
     		if (cnt[i] > 0)
     			res2 += cnt[i];
     	}
     	if (res2) res2--;
     	printf("Case #%d: %d\n", caseN + 1, res + res2 + 1);
     }
     return 0;
 }