#include <bits/stdc++.h>
 
 using namespace std;
 
 struct node {
 	int a, b;
 	bool operator<(const node &rhs) const {
 		if (a == rhs.a) return (b < rhs.b);
 		else return (a < rhs.a);
 	}
 } arr[110][110];
 int req[110];
 int ptr[110];
 
 bool test(int val, int s) {
 	return (s > 0 && val * 10 >= s * 9 && val * 10 <= s * 11);
 }
 
 node calc(int val, int req) {
 	node n;
 	n.a = val * 10 / (req * 11) + (((val * 10) % (req * 11) == 0) ? 0 : 1);
 	n.b = val * 10 / (req * 9);
 	return n;
 }
 
 int main() {
 	int tc;
 	scanf("%d", &tc);
 	for (int t = 1; t <= tc; ++t) {
 		int n, p;
 		scanf("%d%d", &n, &p);
 		for (int i = 0; i < n; ++i) {
 			scanf("%d", &req[i]);
 		}
 		for (int i = 0; i < n; ++i) {
 			for (int j = 0; j < p; ++j) {
 				int val;
 				scanf("%d", &val);
 				arr[i][j] = calc(val, req[i]);
 			}
 			sort(arr[i], arr[i] + p);
 		}
 		for (int i = 0; i < n; ++i) ptr[i] = 0;
 		int ans = 0;
 		bool ok = true;
 		while (ok) {
 			int low = 0;
 			int mi = 0, ma = 100000000;
 			for (int i = 0; i < n; ++i) {
 				mi = max(mi, arr[i][ptr[i]].a);
 				ma = min(ma, arr[i][ptr[i]].b);
 				if (arr[i][ptr[i]] < arr[low][ptr[low]]) low = i;
 			}
 			if (mi > 0 && mi <= ma) {
 				++ans;
 				for (int i = 0; i < n; ++i) ++ptr[i];
 			} else ++ptr[low];
 			for (int i = 0; i < n; ++i) {
 				if (ptr[i] == p) {
 					ok = false;
 					break;
 				}
 			}
 		}
 		printf("Case #%d: %d\n", t, ans);
 	}
 	return 0;
 }
 
