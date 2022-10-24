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

int tests;
int m;
int g[100];
int r1[100],r2[100];

int main() {
	//freopen("test.in","r",stdin);
	//freopen("test_wa.out","w",stdout);
	scanf("%d",&tests);
	//tests=10000;
	FOR (test,1,tests) {
		scanf("%d",&m);
		//m=2+rand()%99;
		//printf("m=%d\n",m);
		REP (i,m) {
			scanf("%d %d",&r1[i],&r2[i]);
			//r1[i]=1+rand()%m; r2[i]=1+rand()%m;
			//printf("%d %d\n",r1[i],r2[i]);
			r1[i]--;
			r2[i]--;
		}
		int64 sum=0;
		REP (i,m) {
			scanf("%d",&g[i]);
			//g[i]=rand()%101;
			//printf("%d ",g[i]);
			sum+=g[i];
		}
		//printf("\n");
		int64 lo=0, hi=2e9+1;
		while (hi-lo>1) {
			int64 k=(lo+hi)/2;
			//printf("try %d\n",k);
			int64 res=sum;
			int ok=1;
			int64 a[100];
			REP (i,m) a[i]=g[i];
			a[0]-=k;
			queue<int> q;
			int in[100];
			REP (i,m) in[i]=0;
			if (a[0]<0) { q.push(0); in[0]=1; }
			while (!q.empty()) {
				//printf("state: "); REP (i,m) printf("%I64d ",a[i]); printf("\n");
				int x=q.front(); q.pop();
				//printf("make %d\n",x);
				in[x]=0;
				if (a[x]>=0) continue;
				int am=abs(a[x]);

				res-=am;
				if (res<0) { ok=0; break; }

				int y=r1[x], z=r2[x];
				//if (y==x || z==x) { ok=0; break; }
				a[y]-=am;
				if (!in[y] && a[y]<0) { q.push(y); in[y]=1; }
				a[z]-=am;
				if (!in[z] && a[z]<0) { q.push(z); in[z]=1; }
				a[x]+=am;
			}
			if (ok) lo=k; else hi=k;
		}
		printf("Case #%d: %d\n",test,(int)lo);
	}
	return 0;
}
