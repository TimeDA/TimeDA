#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

class P3 {
public:
	explicit P3(double x = 0.0, double y = 0.0, double z = 0.0) : x(x), y(y), z(z){}
	double x, y, z;
	P3 add(const P3& p) const { return P3(p.x+x, p.y+y, p.z+z); }
	P3 sub(const P3& p) const { return P3(x-p.x, y-p.y, z-p.z); }
	double dot(const P3& p) const { return x*p.x + y*p.y + z*p.z; }
	P3 cross(const P3& p) const { return P3(y*p.z-z*p.y, z*p.x-x*p.z, x*p.y-y*p.x); }
	P3 scale(const double s) const { return P3(s*x, s*y, s*z); }
};

vector<int> solveSmall(const vector<P3>& vp){
	const int N = vp.size();
	if(N > 10) return vector<int>();
	vector<int> res(N);
	for(int i=0;i<N;i++) res[i] = i;
	do {
		bool ok = true;
		for(int j=1;j+2<N;j++){
			P3 ab = vp[res[j+1]].sub(vp[res[j]]);
			P3 ac = vp[res[j+2]].sub(vp[res[j]]);
			P3 nrm = ab.cross(ac);
			nrm = nrm.scale(1.0/sqrt(nrm.dot(nrm)));
			if(nrm.y < 0.0) nrm = nrm.scale(-1.0);
			for(int k=0;k<j;k++){
				P3 v = vp[res[k]].sub(vp[res[j]]);
				if(v.dot(nrm) > 0.0) ok = false;
			}
			if(!ok) break;
		}
		if(ok) return res;
	} while(next_permutation(res.begin(), res.end()));
	return vector<int>();
}

int main(){
	int T; cin >> T;
	for(int t=1;t<=T;t++){
		int N; cin >> N;
		vector<P3> vp(N);
		for(auto& p : vp) cin >> p.x >> p.z >> p.y;
		printf("Case #%d:", t);
		vector<int> res = solveSmall(vp);
		for(const auto& t : res) cout << " " << t+1; cout << endl;
	}
}
