#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <math.h>
#include <queue>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <ctime>
#include <unordered_map>
using namespace std;

#define ALL(c) (c).begin(),(c).end()
#define IN(x,c) (find(c.begin(),c.end(),x) != (c).end())
#define REP(i,n) for (int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for (int i=(a);i<=(b);i++)
#define INIT(a,v) memset(a,v,sizeof(a))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
template<class A, class B> A cvt(B x) { stringstream ss; ss<<x; A y; ss>>y; return y; }

typedef pair<int,int> PII;
typedef long long int64;

double pi=acos(-1);

int main() {
	//freopen("test.in","r",stdin);
	int tests;
	scanf("%d",&tests);
	FOR (test,1,tests) {
		double a;
		scanf("%lf",&a);
		double r=0.5*sqrt(2);
		double m=0,M=pi/4;
		REP (it,100) {
			double alpha=(m+M)/2;
			double w=2*r*cos(pi/4-alpha);
			if (w>a) M=alpha;
			else m=alpha;
		}
		printf("Case #%d:\n",test);
		printf("%.9lf %.9lf %.9lf\n",0.0,0.0,-0.5);
		printf("%.9lf %.9lf %.9lf\n",0.5*cos(-m),0.5*sin(-m),0.0);
		printf("%.9lf %.9lf %.9lf\n",0.5*cos(-pi/2-m),0.5*sin(-pi/2-m),0.0);
	}
	return 0;
}
