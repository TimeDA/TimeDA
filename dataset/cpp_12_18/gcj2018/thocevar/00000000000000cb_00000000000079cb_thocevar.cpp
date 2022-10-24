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
		int n;
		scanf("%d",&n);
		vector<int> a,e,o;
		REP (i,n) {
			int x;
			scanf("%d",&x);
			a.push_back(x);
			if (i%2==0) e.push_back(x);
			else o.push_back(x);
		}
		sort(ALL(a));
		sort(ALL(e));
		sort(ALL(o));
		vector<int> b;
		REP (i,n) {
			if (i%2==0) b.push_back(e[i/2]);
			else b.push_back(o[i/2]);
		}
		int ind=-1;
		REP (i,n-1) {
			if (b[i]>b[i+1]) {
				ind = i;
				break;
			}
		}
		printf("Case #%d: ",test);
		if (ind==-1) printf("OK\n");
		else printf("%d\n",ind);
	}
	return 0;
}
