#include <bits/stdc++.h>
 
 using namespace std;
 
 int pr[1100];
 int br[1100];
 int cntb[1100];
 int cntp[1100];
 
 vector<int> a, b;
 
 int match[1100];
 int rev[1100];
 int used[1100];
 
 int go(int id) {
 	used[id] = 1;
 	for (int i = 0; i < b.size(); ++i) {
 		if (rev[i] == -1 && a[id] != b[i]) {
 			match[id] = i;
 			rev[i] = id;
 			return 1;
 		}
 	}
 	for (int i = 0; i < b.size(); ++i) {
 		if (a[id] != b[i] && used[rev[i]] == 0) {
 			if (go(rev[i]) == 1) {
 				match[id] = i;;
 				rev[i] = id;
 				return 1;
 			}
 		}
 	}
 	return 0;
 }
 
 int main() {
 	int tc;
 	scanf("%d", &tc);
 	for (int t = 1; t <= tc; ++t) {
 		int n, c, m;
 		scanf("%d%d%d", &n, &c, &m);
 		memset(cntb, 0, sizeof(cntb));
 		memset(cntp, 0, sizeof(cntp));
 		a.clear();
 		b.clear();
 		for (int i = 0; i < m; ++i) {
 			scanf("%d%d", &pr[i], &br[i]);
 			cntb[br[i]]++;
 			cntp[pr[i]]++;
 			if (br[i] == 1) a.push_back(pr[i]);
 			else b.push_back(pr[i]);
 		}
 		if (a.size() > b.size()) swap(a, b);
 		int ma = 0;
 		memset(match, 0xff, sizeof(match));
 		memset(rev, 0xff, sizeof(rev));
 		for (int i = 0; i < a.size(); ++i) {
 			memset(used, 0, sizeof(used));
 			ma += go(i);
 		}
 		
 		int ans = max((int)b.size(), cntp[1]);
 		printf("Case #%d: %d %d\n", t, ans, max(0, (int)a.size() - (ans - (int)b.size()) - ma));
 	}
 	return 0;
 }
 
