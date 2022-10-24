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

int tests,n;
int a[4][4];

int b[4][4];
int best;
void solve(int i, int j, int c) {
	if (c>=best) return;
	if (j==n) { i++; j=0; }
	if (i==n) {
		best=c;
	} else {
		for (int k=-n-1;k<=n;k++) {
			if (k==0) continue;
			int val=k;
			if (k==-n-1) val=a[i][j];
			if (k==a[i][j]) continue;
			b[i][j]=val;
			int c2=c+(b[i][j]!=a[i][j]);
			if (c2>=best) continue;
			int ok=1;
			for (int l=0;l<j;l++) if (b[i][l]==val) { ok=0; break; }
			if (!ok) continue;
			for (int l=0;l<i;l++) if (b[l][j]==val) { ok=0; break; }
			if (!ok) continue;
			solve(i,j+1,c2);
		}
	}
}

int main() {
	//freopen("test.in","r",stdin);
	scanf("%d",&tests);
	//int tests=100;
	FOR (test,1,tests) {
        scanf("%d",&n);
        //n=4;
        REP (i,n) REP (j,n) {
        	//a[i][j]=1+rand()%n;
			scanf("%d",&a[i][j]);
		}
        best=n*n;
        solve(0,0,0);
        printf("Case #%d: %d\n",test,best);
	}
	return 0;
}
