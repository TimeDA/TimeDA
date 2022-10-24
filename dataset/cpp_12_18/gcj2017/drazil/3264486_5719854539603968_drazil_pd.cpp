#include <bits/stdc++.h>
 
 using namespace std;
 
 int n, m;
 
 vector<pair<int, int>> go_x(vector<pair<int, int>> xs) {
 	vector<pair<int, int>> ret = xs;
 	int used_x[110] = {0};
 	int used_y[110] = {0};
 	for (const auto &p : xs) {
 		used_x[p.first] = 1;
 		used_y[p.second] = 1;
 	}
 	int ptr_x = 1;
 	int ptr_y = 1;
 	while (ptr_x <= n && ptr_y <= n) {
 		while (used_x[ptr_x] == 1) ++ptr_x;
 		while (used_y[ptr_y] == 1) ++ptr_y;
 		if (ptr_x <= n && ptr_y <= n) {
 			ret.emplace_back(ptr_x++, ptr_y++);
 		}
 	}
 	return ret;
 }
 
 int match[210]; // used_A -> used_B
 int rmatch[210];
 int used_A[210]; // x + y
 int used_B[210]; // x - y + n
 int used[210];
 
 bool go(int id) {
 	if (used[id] == 0 && used_A[id] == 0) {
 		used[id] = 1;
 		int tar_s = max(id - n, 2 + n - id);
 		if ((id + tar_s - n) % 2 != 0) ++tar_s;
 		int tar_e = min(id + n - 2, 3 * n - id);
 		for (int tar = tar_s; tar <= tar_e; tar += 2) {
 			if (used_B[tar] == 0) {
 				match[id] = tar;
 				rmatch[tar] = id;
 				used_A[id] = 1;
 				used_B[tar] = 1;
 				return true;
 			}
 		}
 		for (int tar = tar_s; tar <= tar_e; tar += 2) {
 			if (used_B[tar] == 1) {
 				if (go(rmatch[tar])) {
 					match[id] = tar;
 					rmatch[tar] = id;
 					used_A[id] = 1;
 					used_B[tar] = 1;
 					return true;
 				}
 			}
 		}
 	}
 	return false;
 }
 
 vector<pair<int, int>> go_p(vector<pair<int, int>> ps) {
 	vector<pair<int, int>> ret = ps;
 	memset(used_A, 0, sizeof(used_A));
 	memset(used_B, 0, sizeof(used_B));
 	for (const auto &p : ps) {
 		used_A[p.first + p.second] = -1;
 		used_B[p.first - p.second + n] = -1;
 	}
 	memset(match, 0xff, sizeof(match));
 	for (int i = 2; i <= 2 * n; ++i) {
 		if (used_A[i] == 0) {
 			memset(used, 0, sizeof(used));
 			go(i);
 		}
 	}
 	for (int i = 2; i <= 2 * n; ++i) {
 		if (match[i] > 0) {
 			// x + y = i
 			// x - y + n = match[i]
 			// 2x + n = i + match[i]
 			// x = (i + match[i] - n) / 2
 			// y = i - x
 			int x = (i + match[i] - n) / 2;
 			int y = i - x;
 			ret.emplace_back(x, y);
 		}
 	}
 	return ret;
 }
 
 int main() {
 	int t;
 	scanf("%d", &t);
 	for (int tc = 1; tc <= t; ++tc) {
 		scanf("%d%d", &n, &m);
 		map<pair<int, int>, char> ord;
 		for (int i = 0; i < m; ++i) {
 			char str[5];
 			int x, y;
 			scanf("%s%d%d", str, &x, &y);
 			ord[{x, y}] = str[0];
 		}
 		vector<pair<int, int>> xs, ps;
 		for (const auto &p : ord) {
 			if (p.second != 'x') {
 				ps.push_back(p.first);
 			}
 			if (p.second != '+') {
 				xs.push_back(p.first);
 			}
 		}
 		xs = go_x(xs);
 		ps = go_p(ps);
 		map<pair<int, int>, char> final;
 		int ans = xs.size() + ps.size();
 		for (const auto &p : xs) {
 			final[p] = 'x';
 		}
 		for (const auto &p : ps) {
 			if (final.find(p) != final.end()) {
 				final[p] = 'o';
 			} else {
 				final[p] = '+';
 			}
 		}
 		map<pair<int, int>, char> modified;
 		for (const auto &p : final) {
 			if (ord.find(p.first) == ord.end() || ord[p.first] != final[p.first]) {
 				modified[p.first] = p.second;
 			}
 		}
 		printf("Case #%d: %d %d\n", tc, ans, (int)modified.size());
 		for (const auto &p : modified) {
 			printf("%c %d %d\n", p.second, p.first.first, p.first.second);
 		}
 	}
 	return 0;
 }
 
