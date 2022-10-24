//spnauT17
#ifndef SPNAUT
#include<bits/stdc++.h>
#else
#include<spnaut>
#endif
#define FOR(i,a,b)for(int i##_=(b),i=(a);i<i##_;++i)
#define ROF(i,b,a)for(int i##_=(a),i=(b);i>i##_;--i)
#define REP2(a,b) a##b
#define REP1(a,b) REP2(a,b)
#define REP(n)for(int REP1(rep_,__LINE__)=(n);REP1(rep_,__LINE__)--;)
#define _1 first
#define _2 second
#define PB push_back
#define EB emplace_back
#define SZ(x)static_cast<int>((x).size())
#define ALL(x)begin(x),end(x)
#define MSET(m,v)memset(m,v,sizeof(m))
#define MAX_PQ(T)priority_queue<T>
#define MIN_PQ(T)priority_queue<T,vector<T>,greater<T>>
#define IO {ios_base::sync_with_stdio(false);cin.tie(nullptr);}
#define cint1(a)int a;cin>>a
#define cint2(a,b)int a,b;cin>>a>>b
#define cint3(a,b,c)int a,b,c;cin>>a>>b>>c
constexpr char nl {'\n'};
using namespace std;using LL=int64_t;using PII=pair<int,int>;
using VI=vector<int>;using VL=vector<LL>;using VP=vector<PII>;
template<class A,class B>bool mina(A&x,B&&y){return y<x?(x=forward<B>(y),1):0;}
template<class A,class B>bool maxa(A&x,B&&y){return x<y?(x=forward<B>(y),1):0;}

class Vec3
{
public:
	double x,y,z;
	explicit Vec3(double xx=0, double yy=0, double zz=0) : x{xx}, y{yy}, z{zz} {}

#define op(o1,o2) Vec3 operator o1(Vec3 v) const {return move(Vec3(*this)o2 v);} Vec3& operator o2(Vec3 v) {x o2 v.x;y o2 v.y;z o2 v.z; return *this;}
	op(+,+=) op(-,-=)
#undef op
#define op(o1,o2) Vec3 operator o1(double s) const {return move(Vec3(*this)o2 s);} Vec3& operator o2(double s) {x o2 s;y o2 s;z o2 s;return *this;}
	op(*,*=) op(/,/=)
#undef op
	friend Vec3 operator* (double s, Vec3 v) {return v*s;}
	Vec3 operator-() const {return Vec3(-x,-y,-z);}
	double& operator[] (int p) noexcept {if(p==1) return y;if(p==2) return z;return x;}
	double operator[] (int p) const noexcept {if(p==1) return y;if(p==2) return z;return x;}

	inline double mag2() const {return (*this)*(*this);}
	inline double mag() const {return sqrt(mag2());}
	inline void normalize() {*this /= mag();}
	inline Vec3 rot90_2d() const {return Vec3(-y,x,z);}
	friend double ang2(Vec3 u, Vec3 v) {double c=u*v/sqrt(u.mag2()*v.mag2()); mina(c,1); maxa(c,-1); return acos(c);}
	friend double operator* (Vec3 u, Vec3 v) {return u.x*v.x + u.y*v.y + u.z*v.z;}
	friend Vec3 cross(Vec3 u, Vec3 v) {return Vec3(u.y*v.z-u.z*v.y, u.z*v.x-u.x*v.z, u.x*v.y-u.y*v.x);}
	friend double cross2d(Vec3 u, Vec3 v) {return u.x*v.y-u.y*v.x;}
	friend ostream& operator << (ostream &out, Vec3 v) {return out << '(' << v.x << ',' << v.y << ',' << v.z << ')';}
	friend istream& operator >> (istream &in, Vec3 &v) {return in >> v.x >> v.y >> v.z;}

	friend Vec3 lerp(Vec3 u, Vec3 v, double t) {return u + t*(v-u);}
	friend Vec3 slerp(Vec3 u, Vec3 v, double t)
	{
		double a = ang2(u,v);
		double s = sin(a);
		return (u*sin((1-t)*a) + v*sin(t*a)) / s;
	}
	friend bool intersect2d(Vec3 p, Vec3 u, Vec3 q, Vec3 v, double &s, double &t)
	{
		Vec3 u1 = u, v1 = v;
		u1.normalize();
		v1.normalize();
		if(fabs(u1*v1) < 1e-12) return 0;
		double c = cross2d(v,u);
		s = cross2d(p-q,v) / c;
		t = cross2d(p-q,u) / c;
		return 1;
	}
};

using P2t = double;
using P2 = pair<P2t,P2t>;
inline P2 operator- (P2 a, P2 b) {return P2(a._1-b._1,a._2-b._2);}
inline P2t cross(const P2 &a, const P2 &b) {return a._1 * b._2 - a._2 * b._1;}
using VP2 = vector<P2>;

// no collinear points, CCW, starting from min-x, then min-y
VI convexHull(const VP2& Z)
{
	auto turnLeft = [&Z](int a, int b, int c) -> int {return cross(Z[b]-Z[a], Z[c]-Z[a]) > 0;};

	int N = SZ(Z);
	VI P(N), H;

	FOR(i,0,N) P[i] = i;
	sort(ALL(P), [&Z](int a, int b) -> bool {return Z[a] < Z[b];});

	if(Z[P[0]]._1 == Z[P[N-1]]._1) // vertical line
	{
		H = {P[0], P[N-1]};
	}
	else
	{
		H.reserve(N);
		VI S(N);
		int s = 0, t = N-1, si;
		while(s+1 < N && Z[P[0]]._1 == Z[P[s+1]]._1) ++s;
		while(t  >  0 && Z[P[t]]._1 == Z[P[t-1]]._1) --t;

		si = 0;
		FOR(i,0,t+1)
		{
			int id = P[i];
			while(si >= 2) {if(turnLeft(S[si-2], S[si-1], id)) break; --si;}
			S[si++] = id;
		}
		FOR(i,0,si) H.PB(S[i]);

		si = 0;
		ROF(i,N-1,s-1)
		{
			int id = P[i];
			while(si >= 2) {if(turnLeft(S[si-2], S[si-1], id)) break; --si;}
			S[si++] = id;
		}
		FOR(i,0,si) if(!((i == 0 && t == N-1) || (i == si-1 && s == 0))) H.PB(S[i]);
	}

//	FOR(i,0,H.size()) printf("H %d : %d   %lld %lld\n", i+1, H[i]+1, Z[H[i]]._1, Z[H[i]]._2);
	return move(H);
}

using cube = array<Vec3,3>;

void output(const Vec3& v)
{
	cout << v[0] << ' ' << v[1] << ' ' << v[2] << nl;
}

double calc(const cube& V)
{
	VP2 P;
	for(int sx : {-1,1}) for(int sy : {-1,1}) for(int sz : {-1,1})
	{
		auto v3 = V[0] * sx + V[1] * sy + V[2] * sz;
		P.EB(v3[0], v3[2]);
	}

	auto CH = convexHull(P);
	const int n {SZ(CH)};
	double area {0};
	FOR(i,0,n)
	{
		const P2 u {P[CH[i]]};
		const P2 v {P[CH[(i + 1) % n]]};
		area += cross(u,v);
	}
	return abs(area) * 0.5;
}

auto rotate(const cube& V0, int axis, double t)
{
	auto V = V0;
	Vec3& a {V[(axis + 1) % 3]};
	Vec3& b {V[(axis + 2) % 3]};
	auto aa = slerp(a, b, t);
	auto bb = slerp(b, a, -t);
	a = aa;
	b = bb;
	return V;
}

void validate_cube(const cube& V)
{
	FOR(i,0,3) assert(abs(V[i].mag() - 0.5) < 1e-6);
	FOR(i,0,3)
	{
		auto& u = V[i];
		auto& v = V[(i + 1) % 3];
		constexpr auto PI = acos(-1);
		assert(abs(ang2(u,v) - PI/2) < 1e-6);
	}
}

cube solve(double A)
{
	cube V;
	FOR(i,0,3) V[i][i] = 0.5;

	if (A < 1.4) // or sqrt(2)
	{
		double lo {0};
		double hi {0.5};

		REP(100)
		{
			auto mid = (lo + hi) * 0.5;
			auto V_temp = rotate(V,0,mid);
			if (calc(V_temp) < A)
				lo = mid;
			else
				hi = mid;
		}

		V = rotate(V,0,lo);
		auto diff_all = abs(calc(V) - A);
		if (diff_all > 1e-6) clog << "failed for A = " << A << " : " << diff_all << endl;

		return V;
	}

	// simulated annealing
	double diff {0.5};
	constexpr double rat {0.8};
	auto V_best_all = V;
	double best_A_all {abs(calc(V_best_all) - A)};

	vector<cube> Vs {V};

	REP(100)
	{
		auto V_best = Vs[0];
		double best_A {abs(calc(V_best) - A)};
		const auto check = [&](cube V_temp)
		{
			validate_cube(V_temp);
			auto area_diff = abs(calc(V_temp) - A);
			if (mina(best_A, area_diff)) V_best = V_temp;
			if (mina(best_A_all, area_diff)) V_best_all = V_temp;
		};
		for(auto& Vs_i : Vs)
		{
			FOR(i,0,3) check(rotate(Vs_i,i,diff));
			FOR(i,0,3) FOR(j,0,3) if (i != j) check(rotate(rotate(Vs_i,i,diff),j,diff*0.5));
		}

		Vs.EB(V_best);
		diff *= rat;

//		cout << "area_diff : " << abs(calc(V_best_all) - A) << "   diff " << diff << nl;
	}

	V = V_best_all;
	auto diff_all = abs(calc(V) - A);
	if (diff_all > 1e-6) clog << "failed for A = " << A << " : " << diff_all << endl;
//	cout << "final_ans : " << abs(calc(V) - A) << nl;
	return V;
}

int main()
{
	IO;
	cout << fixed << setprecision(12);

//	double a0 {0};
//	for (double A = 1; A <= sqrt(3); A += 0.001)
//	{
//		if (A >= a0)
//		{
//			cout << "try " << A << endl;
//			a0 = A + 0.1;
//		}
//		solve(A);
//	}
//	return 0;

	cint1(TT);
	FOR(T,1,TT+1)
	{
		double A;
		cin >> A;
		const cube V = solve(A);
		cout << "Case #" << T << ':' << nl;
		FOR(i,0,3) output(V[i]);
		cout.flush();
	}

	return 0;
}