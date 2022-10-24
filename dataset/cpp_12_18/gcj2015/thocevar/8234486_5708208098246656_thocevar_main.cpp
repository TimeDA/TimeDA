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
 int r,c;
 char g[105][105];
 
 int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
 string ch = "^>v<";
 
 int main() {
 	freopen("A-small-attempt0.in","r",stdin);
 	freopen("A-small-attempt0.out","wb",stdout);
 	scanf("%d",&tests);
 	FOR (test,1,tests) {
 		scanf("%d %d",&r,&c);
 		REP (i,r) {
 			scanf("%s",&g[i]);
 		}
 		int st=0,imp=0;
 		REP (i,r) REP (j,c) if (g[i][j]!='.') {
 			int block[] = {0,0,0,0};
 			REP (d,4) {
 				int y=i+dir[d][0],x=j+dir[d][1];
 				while (0<=y && y<r && 0<=x && x<c) {
 					if (g[y][x]!='.') block[d]=1;
 					y+=dir[d][0];
 					x+=dir[d][1];
 				}
 			}
 			int d=ch.find(g[i][j]);
 			if (!block[d]) {
 				if (block[0]+block[1]+block[2]+block[3]>0) {
 					st++;
 				} else {
 					imp=1;
 				}
 			}
 		}
 		printf("Case #%d: ",test);
 		if (imp) printf("IMPOSSIBLE\n");
 		else printf("%d\n",st);
 	}
 	return 0;
 }
