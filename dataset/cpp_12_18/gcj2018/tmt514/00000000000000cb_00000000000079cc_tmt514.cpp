// by tmt514
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <ctgmath>
#include <iomanip>
#define SZ(x) ((int)(x).size())
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
typedef long long LL;
typedef long double LD;
class Point3D;
typedef Point3D Plane;
typedef Point3D Vector;

const LD EPS = 1e-10;

class Point3D {
	public:
		LD x, y, z;
		Point3D(LD _x=0, LD _y=0, LD _z=0): x(_x), y(_y), z(_z) {}
		Point3D operator + (const Point3D a) const {
			return Point3D(x+a.x, y+a.y, z+a.z);
		}
		Point3D operator - (const Point3D a) const {
			return Point3D(x-a.x, y-a.y, z-a.z);
		}
		Point3D operator ^ (const Point3D a) const {
			return Point3D(y*a.z-z*a.y, z*a.x-x*a.z, x*a.y-y*a.x);
		}
		Point3D operator * (const LD k) const {
			return Point3D(k*x, k*y, k*z);
		}
		Point3D& operator /= (const LD k) {
			x /= k;
			y /= k;
			z /= k;
			return *this;
		}
		LD operator * (const Point3D a) const {
			return x*a.x+y*a.y+z*a.z;
		}
		LD norm() const {
			return sqrtl((*this)*(*this));
		}
		Point3D project(const Plane p) const {
			// At=B;
			LD A = p.x*p.x+p.y*p.y+p.z*p.z;
			LD B = x*p.x+y*p.y+z*p.z;
			LD t = B / A;
			return Point3D(x-t*p.x, y-t*p.y, z-t*p.z);
		}
		LD getAngle(const Vector v) const {
			return acosl((*this)*v / v.norm() / (*this).norm());
		}
		Point3D rotateWrtPlane(const Plane p, const LD angle) {
			Point3D proj = project(p);
			Point3D dif = (*this) - proj;

			//cout << "projected: " << proj << endl;
			//cout << "diff     : " << dif << endl;

			Point3D ov = (fabsl(p.x) < EPS? Point3D(1, 0, 0): Point3D( -(p.y+p.z)/p.x, 1, 1));
			Point3D ow = (p ^ ov);
			ov /= ov.norm();
			ow /= ow.norm();

			LD eqX = proj*ov;
			LD eqY = proj*ow;

			LD rtX = cosl(angle) * eqX - sinl(angle) * eqY;
			LD rtY = sinl(angle) * eqX + cosl(angle) * eqY;

			return ov*rtX + ow*rtY + dif;
		}
		friend ostream& operator << (ostream& out, const Point3D &p) {
			out << fixed << setprecision(12) << p.x << " " << p.y << " " << p.z;
			return out;
		}
		bool operator<(const Point3D &a) const {
			if(fabsl(x-a.x) > EPS) return x<a.x;
			if(fabsl(y-a.y) > EPS) return y<a.y;
			if(fabsl(z-a.z) > EPS) return z<a.z;
			return false;
		}
		bool operator>(const Point3D &a) const {
			if(fabsl(x-a.x) > EPS) return x>a.x;
			if(fabsl(y-a.y) > EPS) return y>a.y;
			if(fabsl(z-a.z) > EPS) return z>a.z;
			return false;
		}
		Point3D& operator += (const Point3D &a) {
			x+=a.x;
			y+=a.y;
			z+=a.z;
			return *this;
		}
		Point3D& operator -= (const Point3D &a) {
			x-=a.x;
			y-=a.y;
			z-=a.z;
			return *this;
		}
		

};

bool rightTurn(Point3D P, Point3D Q, Point3D R) {
	return ((R-Q)^(Q-P)).z > EPS;
}
bool leftTurn(Point3D P, Point3D Q, Point3D R) {
	return ((R-Q)^(Q-P)).z < -EPS;
}

LD getArea(Point3D P, Point3D Q, Point3D R) {
	vector<Point3D> points, pu, pd;
	for(int i=0;i<8;i++) {
		Point3D x(0,0,0);
		if(i&1) x+=P; else x-=P;
		if(i&2) x+=Q; else x-=Q;
		if(i&4) x+=R; else x-=R;
		points.push_back(x);
	}
	sort(points.begin(), points.end());
	for(int i=0;i<SZ(points);i++)
		if(!(points[i] < points[i+1]) && !(points[i] > points[i+1])) {
			points.erase(points.begin() + i);
			--i;
		}
	
	pu = points;
	pd = points;
	for(int i=2;i<SZ(pu);i++) {
		if(i>=2 && !rightTurn(pu[i-2], pu[i-1], pu[i])) {
			pu.erase(pu.begin()+i-1);
			i-=2;
		}
	}
	for(int i=2;i<SZ(pd);i++) {
		if(i>=2 && !leftTurn(pd[i-2], pd[i-1], pd[i])) {
			pd.erase(pd.begin()+i-1);
			i-=2;
		}
	}
/*
	cout << "convex hull" << endl;
	for(int i=0;i<SZ(points);i++) cout << "  -- " << points[i] << endl;
	cout << "------------" << endl;
	for(int i=0;i<SZ(pd);i++) cout << "  -- " << pd[i] << endl;
	for(int i=SZ(pu)-1;i>=0;i--) cout << "  -- " << pu[i] << endl;*/




	LD area = 0;
	for(int i=0;i+1<SZ(pd);i++) {
		area += pd[i].x*pd[i+1].y-pd[i].y*pd[i+1].x;
	}
	for(int i=SZ(pu)-1;i>0;i--) {
		area += pu[i].x*pu[i-1].y-pu[i].y*pu[i-1].x;
	}
	if(area<0) area=-area;
	return area/2;
}

#include <cassert>
void solve() {
	long double A;
	cin >> A;
	
	LD angle = Point3D(.5, .5, .5).getAngle(Point3D(0, 0, 1));
	Plane plane(1, -1, 0), retP, retQ, retR;
	LD l = 0., r = angle, m;
	Point3D P(0.5, 0, 0), Q(0, 0.5, 0), R(0, 0, 0.5);
	
	//LD AA = getArea(P, Q, R);
	//cout << "area = " << AA << endl;
	
	for(int t=0;t<100;t++) {
		m=(l+r)/2;
		retP=P.rotateWrtPlane(plane, m);
		retQ=Q.rotateWrtPlane(plane, m);
		retR=R.rotateWrtPlane(plane, m);

		LD AA = getArea(retP, retQ, retR);
		//cerr << "angle = " << m << ", area = " << AA << ", A = " << A << endl;
		if (AA > A) r = m;
		else l = m;
	}

	/*
	assert(fabsl(getArea(retP, retQ, retR)-A) < 1e-6);
	assert(fabsl(retP.norm()-0.5) < EPS);
	assert(fabsl(retQ.norm()-0.5) < EPS);
	assert(fabsl(retR.norm()-0.5) < EPS);*/
	static int cs = 0;
	printf("Case #%d:\n", ++cs);
	cout << retP << endl;
	cout << retQ << endl;
	cout << retR << endl;
}

int main(void) {
	int T;
	cin >> T;
	while(T--) solve();
  return 0;
}
