// spnauT
 //
 #include <bits/stdc++.h>
 using namespace std;
 #define FOR(i,a,b) for(int _b=(b),i=(a); i<_b; ++i)
 #define ROF(i,b,a) for(int _a=(a),i=(b); i>_a; --i)
 #define _1 first
 #define _2 second
 #define PB(x) push_back(x)
 #define MSET(m,v) memset(m,v,sizeof(m))
 #define MAX_PQ(T) priority_queue <T>
 #define MIN_PQ(T) priority_queue <T,vector<T>,greater<T>>
 typedef long long LL;
 typedef pair<int,int> PII;
 typedef vector<int> VI; typedef vector<LL> VL; typedef vector<PII> VP;
 template<typename A, typename B> inline bool mina(A &x, B y) {return(x>y)?(x=y,1):0;}
 template<typename A, typename B> inline bool maxa(A &x, B y) {return(x<y)?(x=y,1):0;}
 template<typename A, typename B> inline A geta(A &x, const B y) {A t=x;x=y;return t;}
 
 #define MAXN (104)
 
 typedef pair<double,double> PDD;
 typedef vector<PDD> VD;
 
 PDD P[MAXN]; // Rate, Celsius
 
 double calc(int l, int r, double v, double x)
 {
 //	auto cooler = [&x](PDD a) -> bool {return a._2 < x;};
 //	int m = distance(P, partition(P+l, P+r, cooler));
 //	printf("[%d, %d) %d : ", l, r, m);
 //	FOR(i,l,r) printf("  (%.2lf  %.2lf)", P[i]._1, P[i]._2);
 //	cout << endl;
 	return 0;
 }
 
 bool cmpf(PDD a, PDD b)
 {
 	return a._2 < b._2;
 }
 
 int main()
 {
 	int T;
 	int N;
 	double V, X;
 	cin >> T;
 	FOR(tt,1,T+1)
 	{
 		int gn = 0;
 		int ln = 0;
 
 		scanf("%d %lf %lf", &N, &V, &X);
 		FOR(i,0,N)
 		{
 			double r, c;
 			scanf("%lf %lf", &r, &c);
 			if(c > X) ++gn;
 			if(c < X) ++ln;
 			P[i] = PDD(r, c);
 		}
 
 		sort(P, P+N, cmpf);
 
 		printf("Case #%d: ", tt);
 		if(ln == N || gn == N) printf("IMPOSSIBLE\n");
 		else
 		{
 			double res;
 			if(ln == 0 || (ln == 1 && P[1]._2 == X))
 			{
 				double r = 0;
 				FOR(i,0,N) if(P[i]._2 == X) r += P[i]._1;
 				res = V / r;
 			}
 			else
 			{
 				double v1 = V * (X - P[1]._2) / (P[0]._2 - P[1]._2);
 				res = v1 / P[0]._1;
 			}
 
 //			double res = calc(0, N, V, X);
 			printf("%.9lf\n", res);
 		}
 	}
 
 	return 0;
 }
