#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <assert.h>
 #include <iostream>
 #include <sstream>
 #include <vector>
 #include <string>
 #include <math.h>
 #include <queue>
 #include <list>
 #include <algorithm>
 #include <map>
 #include <set>
 #include <stack>
 #include <ctime>
 using namespace std;
 
 #define ALL(c) (c).begin(),(c).end()
 #define IN(x,c) (find(c.begin(),c.end(),x) != (c).end())
 #define REP(i,n) for (int i=0;i<(int)(n);i++)
 #define FOR(i,a,b) for (int i=(a);i<=(b);i++)
 #define INIT(a,v) memset(a,v,sizeof(a))
 #define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
 template<class A, class B> A cvt(B x) { stringstream ss; ss<<x; A y; ss>>y; return y; }
 
 typedef pair<int,int> PII;
 typedef long long int64;
 
 int tests,n;
 
 int64 calcHash(string s) {
 	int64 h=0;
 	while (s.size()<10) s+="|";
 	for (char c : s) h=h*37+(c-'a');
 	return h;
 }
 
 int main() {
 	freopen("C-small-attempt4.in","r",stdin);
 	freopen("C-small-attempt4.out","wb",stdout);
 	cin >> tests;
 	FOR (test,1,tests) {
 		cerr << test << endl;
 		string line,w;
 		cin >> n;
 		getline(cin,line);
 		vector<vector<int64> > sent;
 		REP (i,n) {
 			getline(cin,line);
 			stringstream ss(line);
 			vector<int64> words;
 			while (ss >> w) {
 				words.push_back(calcHash(w));
 			}
 			sent.push_back(words);
 		}
 		int sol=1e9;
 		int st0=0;
 		map<int64,char> lang0;
 		for (int64 w : sent[0]) lang0[w]|=1;
 		for (int64 w : sent[1]) lang0[w]|=2;
 		for (auto kv : lang0) if (kv.second==3) st0++;
 
 		for (int m=0;m<(1<<(n-2));m++) {
 			map<int64,char> lang;
 			int st=st0;
 			REP (i,n-2) {
 				if (m&(1<<i)) {
 					for (int64 w : sent[2+i]) lang[w]|=1;
 				} else {
 					for (int64 w : sent[2+i]) lang[w]|=2;
 				}
 			}
 			for (auto kv : lang) if (kv.second==3) st++;
 			for (auto kv : lang) {
 				int64 k=kv.first;
 				char v=kv.second;
 				if (v==2 && lang0[k]==1) st++;
 				if (v==1 && lang0[k]==2) st++;
 				if (v==3 && lang0[k]==3) st--;
 			}
 			sol=min(sol,st);
 		}
 		printf("Case #%d: %d\n",test,sol);
 	}
 	return 0;
 }
