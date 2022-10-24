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
const int N=1100;
const double Eps=1E-9;
struct T
{
	double x, y, z;
	T(double x, double y, double z): x(x), y(y), z(z) {}
	T() {}
};
T operator +(const T& a, const T& b) { return T(a.x+b.x, a.y+b.y, a.z+b.z); }
T operator -(const T& a, const T& b) { return T(a.x-b.x, a.y-b.y, a.z-b.z); }
T operator *(const T& a, double b) { return T(a.x*b, a.y*b, a.z*b); }
T operator /(const T& a, double b) { return T(a.x/b, a.y/b, a.z/b); }
void operator +=(T& a, const T& b) { a.x+=b.x; a.y+=b.y; a.z+=b.z; }
void operator -=(T& a, const T& b) { a.x-=b.x; a.y-=b.y; a.z-=b.z; }
void operator *=(T& a, double b) { a.x*=b; a.y*=b; a.z*=b; }
void operator /=(T& a, double b) { a.x/=b; a.y/=b; a.z/=b; }
double operator &(const T& a, const T& b) { return a.x*b.x+a.y*b.y+a.z*b.z; }
T operator *(const T& a, const T& b) { return T(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x); }
T operator |(const T& a, const T& b) { return b*((a&b)/(b&b)); }
T operator ^(const T& a, const T& b) { return (a|b)*2-a; }
double operator !(const T& a) { return sqrt(a&a); }
T operator -(const T& a) { return T(-a.x, -a.y, -a.z); }
bool operator <(const T& a, const T& b) { return a.x+Eps<b.x || (a.x-Eps<b.x && (a.y+Eps<b.y || (a.y-Eps<b.y && a.z+Eps<b.z))); }
bool operator ==(const T& a, const T& b) { return fabs(a.x-b.x)<Eps && fabs(a.y-b.y)<Eps && fabs(a.z-b.z)<Eps; }
int u[N], p[N], n;
T t[N];
pair <double, int> w[N];
const double Pi=acos(-1.0);
int sign(double x)
{
	if(x<0) return -1;
	if(x>0) return 1;
	return 0;
}
bool check(int a, int b, int c)
{
	int s0=sign((t[c]-t[a])*(t[b]-t[a])&(T(0, 0, -1)));
	for(int i=0; i<n; i++)
		if(!u[i] && i!=a && i!=b && i!=c)
		{
			int s1=sign((t[c]-t[a])*(t[b]-t[a])&(t[i]-t[a]));
			if(s1!=s0) 
				return 0;
		}
	return 1;
}
int findnext(int a, int b)
{
	T o=t[a];
	T i=t[b]-o;
	i/=!i;
	T j, k;
	for(int l=0; l<n; l++)
		if(!u[l]) { j=i*(t[l]-o); j/=!j; break; }
	k=i*j;
	int h=0;
	for(int l=0; l<n; l++)
		if(!u[l]) w[h++]=make_pair(atan2((t[l]-o)&k, (t[l]-o)&j), l);
	sort(w, w+h);
	for(int l=0; l+1<h; l++)
		if(w[l+1].first-w[l].first>Pi) 
		{
			if(check(a, b, w[l].second)) return w[l].second;
			else if(check(a, b, w[l+1].second)) return w[l+1].second;
		}
	if(w[0].first+2*Pi-w[h-1].first>Pi) 
	{
		if(check(a, b, w[0].second)) return w[0].second;
		else if(check(a, b, w[h-1].second)) return w[h-1].second;
	}
	return -1;
}
void solve()
{
	scanf("%d", &n);
	for(int i=0; i<n; scanf("%lf%lf%lf", &t[i].x, &t[i].y, &t[i].z), u[i]=0, i++);
	int a=0, b, c;
	for(int i=0; i<n; i++)
		if(t[i].z>t[a].z) a=i;
	p[0]=a;
	u[a]=1;
	for(b=0; b<n; b++)
		if(b!=a)
		{
			p[1]=b;
			u[b]=1;
			c=findnext(a, b);
			if(c!=-1) break;
			u[b]=0;
		}
	p[2]=c;
	u[c]=1;
	for(int i=3; i<n; i++)
	{
		a=b;
		b=c;
		c=findnext(a, b);
		p[i]=c;
		u[c]=1;
	}
	for(int i=0; i<n; printf(" %d", p[n-1-i]+1), i++);
	printf("\n");
}
int main()
{
	int tst;
	scanf("%d", &tst);
	for(int t=1; t<=tst; t++)
	{
		printf("Case #%d:", t);
		solve();
	}
	return 0;
}
