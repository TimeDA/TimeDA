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

int main() {
	//freopen("test.in","r",stdin);
	int tests;
	scanf("%d",&tests);
	FOR (test,1,tests) {
		int d,n;
		scanf("%d %d",&d,&n);
		double v=1e15;
		REP (i,n) {
			int k,s;
			scanf("%d %d",&k,&s);
			double t=1.0*(d-k)/s;
			v=min(v, d/t);
		}
		printf("Case #%d: %.9f\n",test,v);
	}
	return 0;
}
