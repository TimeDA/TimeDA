#include <cstdio>
 #include <vector>
 #include <cmath>
 #include <set>
 #include <sstream>
 #include <map>
 #include <algorithm>
 #include <cstring>
 #include <string>
 #include <iostream>
 #include <cassert>
 #include <memory.h>
 #include <unordered_set>
 using namespace std;
 
 #define forn(i, n) for (int i = 0; i < (int)(n); i++)
 #define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
 #define pb push_back
 typedef long long ll;
 typedef pair<int, int> pii;
 typedef long double ld;
 
 struct Indexer {
 	map<string, int> mm;
 
 	int get(const string& key) {
 		if (mm.find(key) != mm.end()) return mm[key];
 		int id = mm.size();
 		mm[key] = id;
 		return id;
 	}
 };
 
 char s[1000010];
 vector<int> sent[210];
 
 void solve() {
 	int n;
 	scanf("%d", &n);
 	gets(s);
 	Indexer mw;
 	forn(i, n) {
 		gets(s);
 		sent[i].clear();
 		istringstream iss(s);
 		string word;
 		while (iss >> word) {
 			sent[i].push_back(mw.get(word));
 		}
 	}
 
 	vector<int> cf(mw.mm.size()), ce(mw.mm.size());
 	forn(i, sent[0].size()) ce[sent[0][i]]++;
 	forn(i, sent[1].size()) cf[sent[1][i]]++;
 	int res = 1 << 30;
 	forn(mask, 1 << (n - 2)) {
 		forn(i, n - 2) {
 			bool fra = mask & (1 << i);
 			for (int w: sent[i+2])
 				if (fra) cf[w]++;
 				else ce[w]++;
 		}
 		int common = 0;
 		forn(i, mw.mm.size())
 			if (ce[i] > 0 && cf[i] > 0)
 				common++;
 		forn(i, n - 2) {
 			bool fra = mask & (1 << i);
 			for (int w: sent[i+2])
 				if (fra) cf[w]--;
 				else ce[w]--;
 		}
 		if (common < res)
 			res = common;
 	}
 	printf("%d\n", res);
 }
 
 int main() {
 	int tc;
 	scanf("%d", &tc);
 	for (int q = 1; q <= tc; q++) {
 		fprintf(stderr, "solving test %d...\n", q);
 		printf("Case #%d: ", q);
 		solve();
 	}
 	return 0;
 }
