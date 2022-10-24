#include <algorithm>
 #include <string>
 #include <vector>
 #include <map>
 #include <queue>
 #include <set>
 using namespace std;
 
 #include <math.h>
 #include <stdio.h>
 double V, X;
 
 vector<pair<double, double> > D;
 int n;
 
 bool gete = false;
 double get(double t, bool rev) {
 	double remain = V;
 	double res = 0.0;
 	for (int a = 0; a < n; a++) {
 		int i = a;
 		if (rev) i = n - a - 1;
 
 		double C = D[i].first;
 		double R = D[i].second;
 
 		double Vi = R * t;
 
 		double put = min(remain, Vi);
 		remain -= put;
 		res += put * C;
 	}
 	if (remain > 0.0) {
 		gete = true;
 	}
 	return res;
 }
 double solve() {
 	double s, e;
 	s = 0.0; e = 1.0e12;
 	double w = 0;
 	while (e - s > 1.0e-9) {
 		double m = (s + e) / 2.0;
 
 		gete = false;
 		double mn = get(m, false);
 		double mx = get(m, true);
 
 		if (gete ||
 			!(mn <= w && w <= mx)) {
 			s = m;
 		}
 		else {
 			if (e - s < 1.0e-8) {
 				s = s;
 			}
 			e = m;
 		}
 	}
 	return (s + e) / 2.0;
 }
 int main(){
 	freopen("B-small-attempt1.in", "r", stdin);
 	freopen("B-small-attempt1.out", "w", stdout);
 	int T;
 	scanf("%d", &T);
 	for (int cs = 1; cs <= T; cs++) {
 		scanf("%d", &n);
 		scanf("%lf %lf", &V, &X);
 		double mC = 0.0, MC = 0.0;
 		D.clear();
 		for (int i = 0; i < n; i++) {
 			double R, C;
 			scanf("%lf %lf", &R, &C);
 			C -= X;
 			D.push_back(make_pair(C, R));
 			if (i == 0 || mC > C) mC = C;
 			if (i == 0 || MC < C) MC = C;
 		}
 		sort(D.begin(), D.end());
 		bool pos = true;
 		double sol = 0.0;
 		if (mC > 0.0 || 0.0 > MC) {
 			pos = false;
 		}
 		else {
 			sol = solve();
 		}
 		printf("Case #%d: ", cs);
 		if (!pos) {
 			printf("IMPOSSIBLE");
 		}
 		else {
 			printf("%.9lf", sol);
 		}
 		printf("\n");
 	}
 
 	return 0;
 }