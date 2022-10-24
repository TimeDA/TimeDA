#include <algorithm>
 #include <vector>
 #include <map>
 #include <set>
 
 using namespace std;
 
 #include <stdio.h>
 
 double sol;
 
 long long B, N;
 vector<long long> X;
 void base(int n, long long tx) {
 	if (tx <= 0) return;
 	long long bb = B, nu;
 	vector<long long> nus;
 	nu = 0;
 	for (int i=0;i<n;i++) {
 		bb -= (tx - X[i]);
 		nu += (tx - X[i]);
 		nus.push_back(nu);
 	}
 	
 	if (bb < 0) return;
 	for (int i=n-1;i>=0;i--) {
 		long long bet = nus[i];
 		double g = (double)bet * 36.0 / (double)(i+1);
 		double tsol = g - (double)nu;
 		if (tsol > sol)
 			sol = tsol;
 
 		bb --;
 		nu ++;
 		if (bb < 0) break;
 	}
 }
 
 void betting( int n, long long mn, long long mx, long long sum) {
 	if (mn <= 0) mn = 1;
 	long long tet;
 	tet = (B + sum) / n;
 	if (tet > mx) tet = mx;
 	if (mn <= tet && tet <= mx) {
 		long long bet = tet * n - sum;
 		double g = (double)bet * 36.0 / (double)n;
 		double tsol = g - (double)bet;
 		if (tsol > sol) sol = tsol;
 		base(n, tet);
 		if (mn <= tet-1 && tet-1 <= mx) {
 			base(n, tet-1);
 		}
 	}
 
 }
 int main() {
 	freopen("A-small-attempt1.in","r",stdin);
 	freopen("A-small-attempt1.out","w",stdout);
 
 	int T;
 	scanf("%d",&T);
 	while (T-- > 0) {
 		scanf("%lld %lld", &B, &N);
 		X.clear();
 		for (int i=0;i<37;i++) {
 			long long x = 0;
 			if (i < N) {
 				scanf("%lld",&x);
 			}
 			X.push_back(x);
 		}
 		sort(X.begin(), X.end());
 
 		long long sum = X[0];
 		sol = 0.0;
 		for (int i=1;i<(int)X.size();i++) {
 			if (X[i] > X[i-1]) {
 				betting(i, X[i-1], X[i] - 1, sum);
 			}
 			sum += X[i];
 		}
 
 		static int cs = 1;
 		printf("Case #%d: %.12lf\n", cs ++, sol);
 	}
 	return 0;
 }