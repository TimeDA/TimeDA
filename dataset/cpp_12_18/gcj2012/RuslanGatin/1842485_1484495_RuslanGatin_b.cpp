#pragma comment (linker, "/stack:128000000")
 #define _CRT_SECURE_NO_DEPRECATE
 
 #include <iostream>
 #include <cstdio>
 #include <vector>
 #include <string>
 #include <algorithm>
 #include <cmath>
 #include <queue>
 #include <deque>
 #include <set>
 #include <map>
 #include <memory.h>
 #include <cassert>
 #include <ctime>
 
 using namespace std;
 
 #define fo(a,b,c) for (int a = (b); a < (c); a++)
 #define fr(a,b) fo(a, 0, (b))
 #define fi(n) fr(i, (n))
 #define fj(n) fr(j, (n))
 #define fk(n) fr(k, (n))
 #define fd(a,b,c) for (int a = (b); a >= (c); a--)
 #define all(a) (a).begin(), (a).end()
 #define rall(a) (a).rbegin(), (a).rend()
 #define _(a,b) memset((a), (b), sizeof(a))
 #define __(a) memset((a), 0, sizeof(a))
 #define sz(a) (int)(a).size()
 #define mp make_pair
 #define pb push_back
 
 typedef long long lint;
 typedef unsigned long long ull;
 
 const int INF = 1000000000;
 const lint LINF = 4000000000000000000LL;
 const double eps = 1e-9;
 
 void prepare()
 {
 #ifdef _DEBUG
 	freopen("input.txt", "r", stdin);
 #else
 	freopen("b-small.in", "r", stdin);
 	freopen("b-small.out", "w", stdout);
 	//freopen("-large.in", "r", stdin);
 	//freopen("-large.out", "w", stdout);
 #endif
 }
 
 void panic(bool expression = false)
 {
 	if (!expression)
 	{
 		cerr << "PANIC!" << endl;
 		assert(false);
 	}
 }
 
 bool eq(double a, double b)
 {
 	return a - b < eps && b - a < eps;
 }
 
 int sgn(double x)
 {
 	if (eq(x, 0))
 		return 0;
 	return x < 0 ? -1 : 1;
 }
 
 struct Vec
 {
 	double x, y;
 
 	Vec(): x(0), y(0) {}
 
 	Vec(double x, double y): x(x), y(y) {}
 
 	Vec operator - (const Vec &v) const
 	{
 		return Vec(x - v.x, y - v.y);
 	}
 
 	Vec &operator -= (const Vec &v)
 	{
 		x -= v.x;
 		y -= v.y;
 		return *this;
 	}
 
 	Vec operator + (const Vec &v) const
 	{
 		return Vec(x + v.x, y + v.y);
 	}
 
 	Vec &operator += (const Vec &v)
 	{
 		x += v.x;
 		y += v.y;
 		return *this;
 	}
 
 	Vec operator * (const double &v) const
 	{
 		return Vec(x * v, y * v);
 	}
 
 	Vec &operator *= (const double &v)
 	{
 		x *= v;
 		y *= v;
 		return *this;
 	}
 
 	Vec operator / (const double &v) const
 	{
 		return Vec(x / v, y / v);
 	}
 
 	Vec &operator /= (const double &v)
 	{
 		x /= v;
 		y /= v;
 		return *this;
 	}
 
 	double operator * (const Vec &v) const
 	{
 		return x * v.x + y * v.y;
 	}
 
 	double operator % (const Vec &v) const
 	{
 		return x * v.y - y * v.x;
 	}
 
 	Vec rotate(double ang) const
 	{
 		return Vec(x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang));
 	}
 
 	double dist2() const
 	{
 		return x * x + y * y;
 	}
 
 	double dist() const
 	{
 		return sqrt(dist2());
 	}
 
 	void read()
 	{
 		scanf("%lf%lf", &x, &y);
 	}
 
 	void print()
 	{
 		printf("%.5lf %.5lf ", x, y);
 	}
 
 	bool operator < (const Vec &v) const
 	{
 		if (!eq(x, v.x))
 			return x < v.x;
 		return y < v.y - eps;
 	}
 
 	bool operator <= (const Vec &v) const
 	{
 		if (!eq(x, v.x))
 			return x < v.x;
 		return y <= v.y + eps;
 	}
 
 	bool operator == (const Vec &v) const
 	{
 		return eq(x, v.x) && eq(y, v.y);
 	}
 
 	bool operator != (const Vec &v) const
 	{
 		return !eq(x, v.x) || !eq(y, v.y);
 	}
 
 	bool operator > (const Vec &v) const
 	{
 		if (!eq(x, v.x))
 			return x > v.x;
 		return y > v.y + eps;
 	}
 
 	bool operator >= (const Vec &v) const
 	{
 		if (!eq(x, v.x))
 			return x > v.x;
 		return y >= v.y - eps;
 	}
 };
 
 struct Circle
 {
 	Vec c;
 	double r;
 	int id;
 
 	Circle(): r(0) {}
 
 	Circle(Vec c, double r) : c(c), r(r) {}
 
 	bool inside(const Circle &v)
 	{
 		return r <= v.r + eps && v.r - r >= (c - v.c).dist() - eps;
 	}
 
 	bool has_inters(const Circle &v)
 	{
 		double l = (c - v.c).dist();
 		return l <= r + v.r + eps && l >= fabs(r - v.r) - eps;
 	}
 
 	pair<Vec, Vec> intersect(const Circle &v)
 	{
 		Circle c1 = *this, c2 = v;
 		if (c1.r < c2.r)
 			swap(c1, c2);
 		double l = (c1.c - c2.c).dist();
 		double oh = (c1.r * c1.r + l * l - c2.r * c2.r) / (2.0 * l);
 		double hp = sqrt(c1.r * c1.r - oh * oh);
 		Vec n = Vec(c2.c.y - c1.c.y, c1.c.x - c2.c.x);
 		n = n * (hp / n.dist());
 		pair<Vec, Vec> res;
 		res.first = c1.c + (c2.c - c1.c) * (oh / (c2.c - c1.c).dist()) + n;
 		res.second = c1.c + (c2.c - c1.c) * (oh / (c2.c - c1.c).dist()) - n;
 		return res;
 	}
 
 	bool contains(const Vec &v) const
 	{
 		return (v - c).dist2() <= r * r + eps;
 	}
 
 	bool on_bound(const Vec &v) const
 	{
 		return eq((v - c).dist2(), r * r);
 	}
 
 	void read()
 	{
 		c.read();
 		scanf("%lf", &r);
 	}
 
 	void print()
 	{
 		c.print();
 		printf("%lf\n", r);
 	}
 
 	bool operator < (const Circle &v) const
 	{
 		return r > v.r;
 	}
 };
 
 const int maxn = 1005;
 
 int n;
 double w, h;
 Circle c[maxn];
 vector<int> g[maxn];
 Vec res[maxn];
 
 void read()
 {
 	scanf("%d", &n);
 	panic(n < maxn);
 	scanf("%lf%lf", &w, &h);
 	fi(n)
 	{
 		scanf("%lf", &c[i].r);
 		c[i].r += 1e-2;
 		c[i].id = i;
 	}
 }
 
 void init()
 {
 	fi(n)
 		g[i].clear();
 }
 
 bool inside(const Vec &p)
 {
 	return
 		p.x >= 0 - eps && p.x <= w + eps &&
 		p.y >= 0 - eps && p.y <= h + eps;
 }
 
 bool good(int cur)
 {
 	if (!inside(c[cur].c))
 		return false;
 	fi(cur)
 	{
 		if ((c[cur].c - c[i].c).dist() < c[cur].r + c[i].r - eps)
 			return false;
 	}
 	return true;
 }
 
 bool tryPlace1(int cur)
 {
 	fi(cur)
 	{
 		fj(sz(g[i]))
 		{
 			c[i].r += c[cur].r;
 			c[g[i][j]].r += c[cur].r;
 			pair<Vec, Vec> p = c[i].intersect(c[g[i][j]]);
 			c[i].r -= c[cur].r;
 			c[g[i][j]].r -= c[cur].r;
 
 			c[cur].c = p.first;
 			if (good(cur))
 			{
 				g[cur].pb(i);
 				g[cur].pb(j);
 				return true;
 			}
 			c[cur].c = p.second;
 			if (good(cur))
 			{
 				g[cur].pb(i);
 				g[cur].pb(j);
 				return true;
 			}
 		}
 	}
 	return false;
 }
 
 bool tryPlace2(int cur)
 {
 	c[cur].c = Vec(c[cur - 1].c.x + c[cur - 1].r + c[cur].r, 0);
 	if (good(cur))
 	{
 		g[cur].pb(cur - 1);
 		return true;
 	}
 	return false;
 }
 
 bool tryPlace3(int cur)
 {
 	c[cur].c = Vec(w, h);
 	return good(cur);
 }
 
 bool tryPlace4(int cur)
 {
 	fi(1000)
 	{
 		c[cur].c = Vec(rand() % (int)(w + 0.1), rand() % (int)(h + 0.1));
 		if (good(cur))
 			return true;
 	}
 	return false;
 }
 
 void solve(int test_num)
 {
 	cerr << test_num << endl;
 	printf("Case #%d: ", test_num);
 	
 	read();
 
 	bool rev = false;
 	if (w < h)
 	{
 		rev = true;
 		swap(w, h);
 	}
 
 	bool ok = false;
 	sort(c, c + n);
 	//reverse(c, c + n);
 	for (int iter = 0; !ok; iter++)
 	{
 		//cerr << "#" << iter <<endl;
 		init();
 		ok = true;
 		c[0].c = Vec(0, 0);
 		fo(i, 1, n)
 		{
 			if (!tryPlace2(i))
 			{
 				if (!tryPlace1(i))
 				{
 					if (!tryPlace3(i))
 					if (!tryPlace4(i))
 					{
 						ok = false;
 						break;
 					}
 				}
 			}
 		}
 		random_shuffle(c, c + n);
 	}
 
 	fi(n)
 		res[c[i].id] = c[i].c;
 	fi(n)
 	{
 		if (rev)
 			swap(res[i].x, res[i].y);
 		res[i].print();
 	}
 
 	fi(n)
 	{
 		if (!good(i))
 			panic(false);
 	}
 
 	printf("\n");
 }
 
 int main()
 {
 	prepare();
 	int number_of_tests;
 	scanf("%d\n", &number_of_tests);
 	fi(number_of_tests)
 		solve(i + 1);
 	return 0;
 }