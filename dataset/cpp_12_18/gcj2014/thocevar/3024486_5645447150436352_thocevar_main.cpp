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
 
 int n,p,q,r,s;
 int t[1000000];
 
 int64 sum[1000000];
 
 inline int64 get(int a, int b) {
 	assert(b<n);
 	if (a>b) return 0;
 	else if (a>0) return sum[b]-sum[a-1];
 	else return sum[b];
 }
 
 int main() {
 	freopen("A-small-attempt2.in","r",stdin);
 	freopen("A-small-attempt2.out","w",stdout);
 	//freopen("A.in","r",stdin);
 	//freopen("A.out","w",stdout);
 	int tests;
 	scanf("%d",&tests);
 	FOR (test,1,tests) {
 		fprintf(stderr,"%d/%d\n",test,tests);
 		scanf("%d %d %d %d %d",&n,&p,&q,&r,&s);
 		REP (i,n) {
 			t[i]=((i*(int64)p + q)%r + s);
 			//cerr << t[i] << endl;
 		}
 		//cerr << endl;
 		int64 best=0;
 		int b;
 		// largest front
 		REP (i,n) {
 			sum[i]=t[i];
 			if (i>0) sum[i]+=sum[i-1];
 		}
 		b=0;
 		REP (a,n) {
 			b=max(a,b);
 			while (b+1<n && get(a,b+1)<=get(0,a-1)) b++;
 			if (get(a,b)<=get(0,a-1) && get(b+1,n-1)<=get(0,a-1)) {
 				//printf("%d %d: %d\n",a,b,get(a,n-1));
 				best=max(best, get(a,n-1));
 			}
 		}
 		// largest mid
 		b=0;
 		REP (a,n) {
 			b=max(a,b);
 			while (b+1<n && get(a,b)<get(0,a-1)) b++;
 			while (b+1<n && get(a,b)<get(b+1,n-1)) b++;
 			if (get(0,a-1)<=get(a,b) && get(b+1,n-1)<=get(a,b)) {
 				best=max(best, get(0,a-1)+get(b+1,n-1));
 				//printf("B %d %d: %d\n",a,b,get(0,a-1)+get(b+1,n-1));
 			}
 		}
 		// largest back
 		reverse(t,t+n);
 		REP (i,n) {
 			sum[i]=t[i];
 			if (i>0) sum[i]+=sum[i-1];
 		}
 		b=0;
 		REP (a,n) {
 			b=max(a,b);
 			while (b+1<n && get(a,b+1)<=get(0,a-1)) b++;
 			if (get(a,b)<=get(0,a-1) && get(b+1,n-1)<=get(0,a-1)) {
 				best=max(best, get(a,n-1));
 				//printf("C %d %d: %d\n",a,b,get(a,n-1));
 			}
 		}
 		printf("Case #%d: %.10f\n",test,1.0*best/get(0,n-1));
 	}
 	return 0;
 }
