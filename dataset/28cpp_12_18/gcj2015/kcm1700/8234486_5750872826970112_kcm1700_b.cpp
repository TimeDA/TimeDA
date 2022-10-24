#include <cstdio>
 #include <algorithm>
 #include <vector>
 
 using namespace std;
 
 double dat[102][2]; // R, C
 int n;
 double V, X;
 double c[102];
 
 struct data
 {
 	double ci, ulimit;
 	double curu;
 };
 
 int sf(const data &a, const data &b) {
 	return a.ci < b.ci;
 }
 
 bool check(double T)
 {
 	vector<data> D;
 	double limsum = 0;
 	for (int i = 0; i < n; i++) {
 		data d;
 		d.ci = c[i] - X;
 		d.ulimit = T * dat[i][0] / V;
 		limsum += d.ulimit;
 		D.emplace_back(d);
 	}
 	if (limsum < 1) return false;
 	sort(D.begin(), D.end(), sf);
 	double sumlow = 0, sumhigh = 0;
 	{
 		double uremain = 1;
 		for (int i = 0; i < n; i++) {
 			if (uremain <= D[i].ulimit) {
 				sumlow += uremain * D[i].ci;
 				uremain = 0;
 				break;
 			}
 			else {
 				sumlow += D[i].ulimit * D[i].ci;
 				uremain -= D[i].ulimit;
 			}
 		}
 	}
 	{
 		double uremain = 1;
 		for (int i = n-1; i >= 0; i--) {
 			if (uremain <= D[i].ulimit) {
 				sumhigh += uremain * D[i].ci;
 				uremain = 0;
 				break;
 			}
 			else {
 				sumhigh += D[i].ulimit * D[i].ci;
 				uremain -= D[i].ulimit;
 			}
 		}
 	}
 	return sumlow <= 0 && 0 <= sumhigh;
 }
 
 int main()
 {
 	int TT;
 	scanf("%d", &TT);
 	for (int testcase = 1; testcase <= TT; testcase++)
 	{
 		scanf("%d%lf%lf", &n, &V, &X);
 		for (int i = 0; i < n; i++) {
 			scanf("%lf%lf", &dat[i][0], &dat[i][1]);
 			c[i] = dat[i][1];
 		}
 		double low = 0, high = 1e30;
 		double ans = -1;
 		for (int magic = 0; magic < 150; magic++)
 		{
 			double mid = (low + high) / 2;
 			if (check(mid)) {
 				ans = mid;
 				high = mid;
 			}
 			else {
 				low = mid;
 			}
 		}
 		if (ans < 0) {
 			printf("Case #%d: IMPOSSIBLE\n", testcase);
 			continue;
 		}
 		printf("Case #%d: %.10f\n", testcase, ans);
 	}
 	return 0;
 }