#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

using P = complex<double>;

double dot(const P& a, const P& b){ return real(conj(a)*b); }
double cross(const P& a, const P& b){ return imag(conj(a)*b); }
double angle(const P& a, const P& b){ return arg(conj(a)*b); }

vector<P> convexHull(vector<P> vp){
	if(vp.size() < 3) return vp;
	auto compare = [](const P& a, const P& b){
		return make_pair(real(a),imag(a)) < make_pair(real(b),imag(b));
	};
	sort(vp.begin(), vp.end(), compare);
	vector< pair<double,int> > vi;
	for(int i=1;i<vp.size();i++) vi.push_back(make_pair(angle(P(1,0),vp[i]-vp[0]), i));
	sort(vi.begin(), vi.end());
	vector<P> res(2);
	res[0] = vp[0]; res[1] = vp[vi[0].second];
	for(int i=1;i<vi.size();i++){
		P next = vp[vi[i].second];
		int sz = res.size();
		while(sz>=2 && cross(res[sz-1]-res[sz-2],next-res[sz-1]) < 1e-8){
			res.pop_back(); sz--;
		}
		res.push_back(next);
	}
	return res;
}

double polygonArea(const vector<P>& g){
	double res = 0.0;
	for(int i=0;i<g.size();i++)
		res += cross(g[i],g[(i+1)%g.size()]);
	return abs(0.5*res);
}

void solve(double A){
	double mtx[3][3];
	double l = 0.0, r = 0.25 * acos(-1.0);
	for(int _=0;_<1000;_++){
		double mid = 0.5 * (l + r);
		double s = sin(mid);
		double c = cos(mid);
		mtx[0][0] = 0.5 * c;
		mtx[0][1] = -0.5 * c * s;
		mtx[0][2] = 0.5 * s * s;
		mtx[1][0] = 0.5 * s;
		mtx[1][1] = 0.5 * c * c;
		mtx[1][2] = -0.5 * c * s;
		mtx[2][0] = 0;
		mtx[2][1] = 0.5 * s;
		mtx[2][2] = 0.5 * c;
		vector<P> g;
		for(int sx=-1;sx<=1;sx+=2){
			for(int sy=-1;sy<=1;sy+=2){
				for(int sz=-1;sz<=1;sz+=2){
					P p(sx * mtx[0][0] + sy * mtx[1][0] + sz * mtx[2][0],
					    sx * mtx[0][2] + sy * mtx[1][2] + sz * mtx[2][2]);
					g.push_back(p);
				}
			}
		}
		double area = polygonArea(convexHull(g));
		if(area < A) { l = mid; }
		else         { r = mid; }
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%.20lf%c", mtx[i][j], j==2 ? '\n' : ' ');
		}
	}
}

int main(){
	int T; cin >> T;
	for(int i=1;i<=T;i++){
		double A; cin >> A;
		printf("Case #%d:\n", i);
		solve(A);
	}
}

