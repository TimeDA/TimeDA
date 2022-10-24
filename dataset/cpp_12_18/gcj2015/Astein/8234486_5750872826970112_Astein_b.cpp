#include <cstdio>
 #include <vector>
 
 using namespace std;
 
 #define max(a, b) (((a) > (b)) ? (a) : (b))
 
 double calc(double V, double X, vector<double> r, vector<double> c)
 {
 	int N = r.size();
 	if (N == 1)
 	{
 		if (X != c[0])
 			return -1;
 		return V / r[0];
 	}
 
 	if (X < c[0] && X < c[1]) return -1;
 	if (X > c[0] && X > c[1]) return -1;
 
 	if (X == c[0] && X == c[1]) return V / (r[0] + r[1]);
 	if (X == c[0]) return V / r[0];
 	if (X == c[1]) return V / r[1];
 
 	if (X > c[0])
 	{
 		swap(r[0], r[1]);
 		swap(c[0], c[1]);
 	}
 	// c[0] < X < c[1]
 
 	double c0v = (V * (c[1] - X)) / (c[1] - c[0]);
 	return max(c0v / r[0], (V - c0v) / r[1]);
 }
 
 int main()
 {
 	freopen("b.in", "r", stdin);
 	freopen("b.out", "w", stdout);
 	int T;
 	scanf("%d", &T);
 	for (int cn = 1; cn <= T; ++cn)
 	{
 		int N;
 		double V, X;
 		scanf("%d%lf%lf", &N, &V, &X);
 		
 		vector<double> r(N), c(N);
 		for (int i = 0; i < N; ++i)
 			scanf("%lf%lf", &r[i], &c[i]);
 
 		double ret = calc(V, X, r, c);
 		if (ret < 0)
 		{
 			printf("Case #%d: IMPOSSIBLE\n", cn);
 		}
 		else
 		{
 			printf("Case #%d: %.10lf\n", cn, ret);
 		}
 	}
 	return 0;
 }