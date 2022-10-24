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
 #define REP(i,n) for (int i=0;i<(n);i++)
 #define FOR(i,a,b) for (int i=(a);i<=(b);i++)
 #define FORD(i,a,b) for (int i=(a);i>=(b);i--)
 #define INIT(a,v) memset(a,v,sizeof(a))
 #define UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
 template<class A, class B> A cvt(B x) { stringstream ss; ss<<x; A y; ss>>y; return y; }
 
 typedef pair<int,int> PII;
 typedef long long int64;
 
 int N;
 int a[1005];
 PII s[1005];
 int f[1005][1005];
 int inf=1e9;
 
 int main() {
 	freopen("B-small-attempt1.in","r",stdin);
 	freopen("B-small-attempt1.out","w",stdout);
 	//freopen("B.in","r",stdin);
 	//freopen("B.out","w",stdout);
 	int tests;
 	cin >> tests;
 	FOR (test,1,tests) {
 		fprintf(stderr,"%d/%d\n",test,tests);
 		scanf("%d",&N);
 		REP (i,N) {
 			scanf("%d",&a[i]);
 			s[i]={a[i],i};
 		}
 		sort(s,s+N);
 		FOR (j,0,N) f[0][j]=inf;
 		f[0][0]=s[0].second;
 		f[0][1]=N-1-s[0].second;
 		FOR (i,1,N-1) {
 			int p=s[i].second;
 			FOR (j,0,N) f[i][j]=inf;
 			int b=0,c=0;
 			REP (j,i) {
 				if (s[j].second<p) b++;
 				if (s[j].second>p) c++;
 			}
 			//printf("b=%d c=%d\n",b,c);
 			FOR (j,0,i+1) {
 				if (j>0) {
 					f[i][j]=min(f[i][j], f[i-1][j-1]+(p-b));
 				}
 				f[i][j]=min(f[i][j], f[i-1][j]+(N-1-p-c));
 				//printf("%d %d: %d\n",i,j,f[i][j]);
 			}
 		}
 		int r=inf;
 		FOR (j,0,N) r=min(r,f[N-1][j]);
 		printf("Case #%d: %d\n",test,r);
 	}
 	return 0;
 }
