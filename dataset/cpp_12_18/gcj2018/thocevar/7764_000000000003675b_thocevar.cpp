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

int inf=1e9;

int s;
int d[100000],a[100000],b[100000];

int main() {
	//freopen("test.in","r",stdin);
	int tests;
	scanf("%d",&tests);
	FOR (test,1,tests) {
		scanf("%d",&s);
		int r=0, nr=0;
		REP (i,s) {
			scanf("%d %d %d",&d[i],&a[i],&b[i]);
			int x=d[i]+a[i];
			int y=inf;
			int stx=0;
			for (int j=i;j>=0;j--) {
				if (d[j]+a[j]==x) { stx++; }
				else if (y==inf) {
					stx++;
					y=d[j]-b[j];
				} else if (y==d[j]-b[j]) {
					stx++;
				} else {
					break;
				}
			}

			x=inf;
			y=d[i]-b[i];
			int sty=0;
			for (int j=i;j>=0;j--) {
				if (d[j]-b[j]==y) { sty++; }
				else if (x==inf) {
					sty++;
					x=d[j]+a[j];
				} else if (x==d[j]+a[j]) {
					sty++;
				} else {
					break;
				}
			}

			int st=max(stx,sty);
			if (st>r) { r=st; nr=1; }
			else if (st==r) { nr++; }
		}
		printf("Case #%d: %d %d\n",test,r,nr);
	}
	return 0;
}
