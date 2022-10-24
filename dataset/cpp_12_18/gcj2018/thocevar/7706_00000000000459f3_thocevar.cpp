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

int tests,R,B;
int f[40][501][501];

int solve(int r, int nr, int nb) {
	if (f[r][nr][nb]!=-1) return f[r][nr][nb];
	int rez=0,st=0;
	int nr0=nr, nb0=nb;
	for (int b=0;b<=min(nb,40);b++) {
		nr-=r;
		nb-=b;
		st++;
		if (nr<0 || nb<0) break;
		int s=st+solve(r+1,nr,nb);
		rez=max(rez,s);
	}
	f[r][nr0][nb0]=rez;
	return rez;
}

int main() {
	//freopen("test.in","r",stdin);
	scanf("%d",&tests);
	INIT(f,-1);
	FOR (test,1,tests) {
		int R,B;
		scanf("%d %d",&R,&B);
		int rez=solve(0,R,B)-1;
        printf("Case #%d: %d\n",test,rez);
	}
	return 0;
}
