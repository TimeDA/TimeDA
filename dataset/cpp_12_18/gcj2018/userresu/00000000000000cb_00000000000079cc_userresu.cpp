#include <cstdio>
#include <cmath>
using namespace std;

double P[3][3], Q[3][3];
inline double dist (double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1-y2)*(y1-y2));
}
int main () {
	int T;
	scanf("%d",&T);
	for (int z=1;z<=T;++z) {
		double A;
		scanf("%lf",&A);
		if (A <= sqrt(2)) {
			double v[3][3];
			v[0][0] = 0.5, v[0][1] = -0.5, v[0][2] = 0.5;
			v[1][0] = 0.5, v[1][1] = -0.5, v[1][2] = -0.5;
			v[2][0] = -0.5, v[2][1] = 0.5, v[2][2] = -0.5;
			double lo = 0, hi = M_PI/4;
			while (hi - lo > 1e-9) {
				double m = (lo + hi)/2;
				P[0][0] = cos(m);
				P[0][1] = -sin(m);
				P[1][0] = sin(m);
				P[1][1] = cos(m);
				P[2][2] = 1;
				
				double t[3][3];
				for (int i=0;i<3;++i) {
					for (int a=0;a<3;++a) {
						t[i][a] = 0;
						for (int b=0;b<3;++b) t[i][a] += P[a][b] * v[i][b];
					}
				}
				double area = dist(t[0][0], t[0][2], t[1][0], t[1][2]) * dist(t[1][0], t[1][2], t[2][0], t[2][2]);
				if (area <= A) lo = m;
				else hi = m;
			}
			v[0][0] = 0.5, v[0][1] = 0, v[0][2] = 0;
			v[1][0] = 0, v[1][1] = 0.5, v[1][2] = 0;
			v[2][0] = 0, v[2][1] = 0, v[2][2] = 0.5;
			P[0][0] = cos(lo);
			P[0][1] = -sin(lo);
			P[1][0] = sin(lo);
			P[1][1] = cos(lo);
			P[2][2] = 1;
			double t[3][3];
			for (int i=0;i<3;++i) {
				for (int a=0;a<3;++a) {
					t[i][a] = 0;
					for (int b=0;b<3;++b) t[i][a] += P[a][b] * v[i][b];
				}
			}
			printf("Case #%d:\n", z);
			for (int k=0;k<3;++k) printf("%.9lf %.9lf %.9lf\n", t[k][0], t[k][1], t[k][2]);
		}
		else {
			double v[6][3];
			v[0][0] = 0.5, v[0][1] = -0.5, v[0][2] = 0.5;
			v[1][0] = 0.5, v[1][1] = -0.5, v[1][2] = -0.5;
			v[2][0] = -0.5, v[2][1] = 0.5, v[2][2] = 0.5;
			v[3][0] = -0.5, v[3][1] = 0.5, v[3][2] = -0.5;
			v[4][0] = 0.5, v[4][1] = 0.5, v[4][2] = 0.5;
			v[5][0] = -0.5, v[5][1] = -0.5, v[5][2] = -0.5;
			P[0][0] = cos(M_PI/4);
			P[0][1] = -sin(M_PI/4);
			P[1][0] = sin(M_PI/4);
			P[1][1] = cos(M_PI/4);
			P[2][2] = 1;
			double t[6][3];
			for (int i=0;i<6;++i) {
				for (int a=0;a<3;++a) {
					t[i][a] = 0;
					for (int b=0;b<3;++b) t[i][a] += P[a][b] * v[i][b];
				}
			}
			double lo = 0, hi = M_PI/4;
			while (hi - lo > 1e-9) {
				double m = (lo + hi)/2;
				Q[0][0] = 1;
				Q[1][1] = cos(m);
				Q[1][2] = -sin(m);
				Q[2][1] = sin(m);
				Q[2][2] = cos(m);
				
				double s[6][3];
				for (int i=0;i<6;++i) {
					for (int a=0;a<3;++a) {
						s[i][a] = 0;
						for (int b=0;b<3;++b) s[i][a] += Q[a][b] * t[i][b];
					}
				}
				double area = 0.5 * (dist(s[4][0], s[4][2], s[5][0], s[5][2]) + dist(s[0][0], s[0][2], s[1][0], s[1][2])) * dist(s[1][0], s[1][2], s[3][0], s[3][2]);
				if (area <= A) lo = m;
				else hi = m;
			}
			v[0][0] = 0.5, v[0][1] = 0, v[0][2] = 0;
			v[1][0] = 0, v[1][1] = 0.5, v[1][2] = 0;
			v[2][0] = 0, v[2][1] = 0, v[2][2] = 0.5;
			Q[0][0] = 1;
			Q[1][1] = cos(lo);
			Q[1][2] = -sin(lo);
			Q[2][1] = sin(lo);
			Q[2][2] = cos(lo);
			for (int i=0;i<3;++i) {
				for (int a=0;a<3;++a) {
					t[i][a] = 0;
					for (int b=0;b<3;++b) t[i][a] += P[a][b] * v[i][b];
				}
			}
			for (int i=0;i<3;++i) {
				for (int a=0;a<3;++a) {
					v[i][a] = 0;
					for (int b=0;b<3;++b) v[i][a] += Q[a][b] * t[i][b];
				}
			}
			printf("Case #%d:\n", z);
			for (int k=0;k<3;++k) printf("%.9lf %.9lf %.9lf\n", v[k][0], v[k][1], v[k][2]);
		}
	}
	return 0;
}
