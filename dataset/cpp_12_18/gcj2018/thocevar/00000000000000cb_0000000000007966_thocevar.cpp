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
	cin >> tests;
	FOR (test,1,tests) {
		int d;
		string seq;
		cin >> d >> seq;
		int c=0,s=0;
		int f[33]={};
		int D=0;
		REP (i,seq.size()) {
			if (seq[i]=='C') c++;
			else {
				f[c]++;
				D+=1<<c;
				s++;
			}
		}
		printf("Case #%d: ",test);
		if (s>d) {
			printf("IMPOSSIBLE\n");
		} else {
			int st=0;
			while (D>d) {
				int i=32;
				while (f[i]==0) i--;
				f[i]--; i--; f[i]++;
				D-=1<<i;
				st++;
			}
			printf("%d\n",st);
		}
	}
	return 0;
}
