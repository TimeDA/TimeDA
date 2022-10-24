#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:100000000")
#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;
const double eps=1E-9;
struct P
{ 
	double x, y;
	P(double x=0, double y=0): x(x), y(y) {}
};
P operator +(P a, P b) { return P(a.x+b.x, a.y+b.y); }
P operator -(P a, P b) { return P(a.x-b.x, a.y-b.y); }
P operator *(P a, double b) { return P(a.x*b, a.y*b); }
double operator &(P a, P b) { return a.x*b.x+a.y*b.y; }
double operator *(P a, P b) { return a.x*b.y-a.y*b.x; }
double operator !(P a) { return sqrt(a&a); }
P operator ~(P a) { return P(-a.y, a.x); }
bool operator <(P a, P b) { return a.x+eps<b.x || (a.x-eps<b.x && a.y+eps<b.y); }
bool operator ==(P a, P b) { return fabs(a.x-b.x)<eps && fabs(a.y-b.y)<eps; }
struct T
{ 
	double x, y, z;
	T(double x=0, double y=0, double z=0): x(x), y(y), z(z) {}
};
T operator +(T a, T b) { return T(a.x+b.x, a.y+b.y, a.z+b.z); }
T operator -(T a, T b) { return T(a.x-b.x, a.y-b.y, a.z-b.z); }

vector <P> conv(vector <P> m)
{
	int i, j, k;
	vector <P> d(m.size()), r;
	sort(m.begin(), m.end());
	m.resize(unique(m.begin(), m.end())-m.begin());
	if(m.size()<2) return m;
	for(k=1; k>=-1; r.insert(r.end(), d.begin(), d.begin()+j-1), k-=2)
		for(j=0, i=k==1?0:m.size()-1; i<m.size() && i>=0; )
			if(j<2 || (d[j-1]-d[j-2])*(m[i]-d[j-2])>eps) { d[j++]=m[i]; i+=k; }
			else j--;
	return r;
}
double area(vector <P> m)
{
	double s=0;
	for(int i=2; i<m.size(); s+=(m[i-1]-m[0])*(m[i]-m[0]), i++);
	return s/2;
}
void run()
{
	double a;
	scanf("%lf", &a);
	int L=100;
	const double pi=acos(-1.0);
	double l1=0, r1=pi/4, l2=0, r2=pi/2;
	for(int it=0; it<10; it++)
	{
		double bs=1E20, b1, b2;
		for(int i=0; i<=L; i++)
			for(int j=0; j<=L; j++)
			{
				double a1=l1+(r1-l1)*i/L;
				double a2=l2+(r2-l2)*j/L;
				T x(cos(a1), sin(a1)*sin(a2), sin(a1)*cos(a2));
				T y(0, cos(-a2), sin(-a2));
				T z(cos(a1+pi/2), sin(a1+pi/2)*sin(a2), sin(a1+pi/2)*cos(a2));
				vector <P> v;
				for(int k=0; k<8; k++)
				{
					T t(0, 0);
					if(k&1) t=t+x;
					else t=t-x;
					if(k&2) t=t+y;
					else t=t-y;
					if(k&4) t=t+z;
					else t=t-z;
					v.push_back(P(t.x/2, t.y/2));
				}
				double s=area(conv(v));
				if(fabs(s-a)<fabs(bs-a)) { bs=s; b1=a1; b2=a2; }
			}
		double d1=(r1-l1)/L;
		l1=b1-d1;
		r1=b1+d1;
		double d2=(r2-l2)/L;
		l2=b2-d2;
		r2=b2+d2;
	}
	T x(cos(l1), sin(l1)*sin(l2), sin(l1)*cos(l2));
	T y(0, cos(-l2), sin(-l2));
	T z(cos(l1+pi/2), sin(l1+pi/2)*sin(l2), sin(l1+pi/2)*cos(l2));
	printf("%.13lf %.13lf %.13lf\n", x.x/2, x.z/2, x.y/2);
	printf("%.13lf %.13lf %.13lf\n", y.x/2, y.z/2, y.y/2);
	printf("%.13lf %.13lf %.13lf\n", z.x/2, z.z/2, z.y/2);
}
int main()
{
	int tst;
	scanf("%d", &tst);
	for(int t=1; t<=tst; t++)
	{
		printf("Case #%d:\n", t);
		run();
	}
    return 0;
}
