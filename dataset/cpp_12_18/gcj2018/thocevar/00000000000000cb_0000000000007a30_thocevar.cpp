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

int t[8][25];

int full(int i, int j) {
	REP (di,3) REP (dj,3) if (t[i+di][j+dj]==0) return 0;
	return 1;
}

int main() {
	//freopen("test.in","r",stdin);
	int tests;
	scanf("%d",&tests);
	FOR (test,1,tests) {
		int a;
		scanf("%d",&a);
		int h,w;
		if (a==20) { h=4; w=5; }
		if (a==200) { h=8; w=25; }
		INIT(t,0);
		for (int i=0;i<h;i+=3) {
			if (i+3>h) i=h-3;
			for (int j=0;j<w;j+=3) {
				if (j+3>w) j=w-3;
				while (!full(i,j)) {
					printf("%d %d\n",i+2,j+2); fflush(stdout);
					int x,y;
					scanf("%d %d",&y,&x);
					if (x==0 && y==0) goto done;
					y--; x--;
					t[y][x]=1;
				}
			}
		}
		done:;
	}
	return 0;
}
