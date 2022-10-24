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
int b[100];

int t[200][100];

int main() {
	//freopen("test.in","r",stdin);
	scanf("%d",&tests);
	FOR (test,1,tests) {
        scanf("%d",&n);
        REP (i,n) scanf("%d",&b[i]);
        INIT(t,'.');
        int i=0,lo=-1,ok=1;
        REP (j,n) {
        	while (b[j]>0) {
        		int y=0;
        		if (i<j) {
					for (int x=i;x<j;x++,y++) {
						if (x==0 || x==n-1) ok=0;
						t[y][x]='\\';
						lo=max(lo,y);
					}
        		}
        		if (i>j) {
					for (int x=i;x>j;x--,y++) {
						if (x==0 || x==n-1) ok=0;
						t[y][x]='/';
						lo=max(lo,y);
					}
        		}
        		i++;
        		b[j]--;
        	}
        }

        printf("Case #%d: ",test);
        if (!ok) printf("IMPOSSIBLE\n");
        else {
			printf("%d\n",lo+2);
			REP (y,lo+2) {
				REP (x,n) {
					printf("%c",t[y][x]);
				}
				printf("\n");
			}
        }
	}
	return 0;
}
