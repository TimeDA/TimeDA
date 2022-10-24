#include <bits/stdc++.h>
 
 using namespace std;
 
 int dpt[110][110][110][110];
 int used[110][110][110][110];
 int b, d, mh;
 
 void go(int, int, int, int);
 
 void update(int hd, int ad, int hk, int ak, int &tar) {
 	go(hd, ad, hk, ak);
 	int v = dpt[hd][ad][hk][ak];
 	if (v >= 0) {
 		++v;
 		if (tar == -1) tar = v;
 		else tar = min(tar, v);
 	}
 }
 
 void go(int hd, int ad, int hk, int ak) {
 	if (used[hd][ad][hk][ak] == 0) {
 		used[hd][ad][hk][ak] = 1;
 		dpt[hd][ad][hk][ak] = -1;
 		if (hk == 0) dpt[hd][ad][hk][ak] = 0;
 		else if (hd == 0) dpt[hd][ad][hk][ak] = -1;
 		else if (ad >= hk) {
 			dpt[hd][ad][hk][ak] = 1;
 		} else {
 			update(max(0, mh - ak), ad, hk, ak, dpt[hd][ad][hk][ak]);
 			update(max(0, hd - ak), ad, max(0, hk - ad), ak, dpt[hd][ad][hk][ak]);
 			update(max(0, hd - ak), ad + b, hk, ak, dpt[hd][ad][hk][ak]);
 			update(max(0, hd - ak), ad, hk, max(0, ak - d), dpt[hd][ad][hk][ak]);
 		}
 	}
 }
 
 int main() {
 	int tc;
 	scanf("%d", &tc);
 	for (int t = 1; t <= tc; ++t) {
 		int hd, ad, hk, ak;
 		scanf("%d%d%d%d%d%d", &hd, &ad, &hk, &ak, &b, &d);
 		mh = hd;
 		memset(used, 0, sizeof(used));
 		go(hd, ad, hk, ak);
 		if (dpt[hd][ad][hk][ak] == -1) {
 			printf("Case #%d: IMPOSSIBLE\n", t);
 		} else {
 			printf("Case #%d: %d\n", t, dpt[hd][ad][hk][ak]);
 		}
 		fprintf(stderr, "%d\n", t);
 	}
 	return 0;
 }
 
