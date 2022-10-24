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
		vector<pair<int,char> > v;
		int s=0;
		REP (i,n) {
			int pi;
			scanf("%d",&pi);
			s+=pi;
			v.push_back({pi,'A'+i});
		}
		printf("Case #%d:",test);
		while (1) {
			sort(ALL(v)); reverse(ALL(v));
			if (v[0].first==0) break;
			if (v[0].first==v[1].first && v[0].first+v[1].first==s) {
				printf(" %c%c",v[0].second,v[1].second);
				v[0].first--; v[1].first--; s-=2;
			} else {
				printf(" %c",v[0].second);
				v[0].first--; s-=1;
			}
		}
		printf("\n");
	}
	return 0;
}
