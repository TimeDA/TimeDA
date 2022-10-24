#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <cassert>
 #include <cctype>
 #include <climits>
 #include <iostream>
 #include <fstream>
 #include <vector>
 #include <map>
 #include <stack>
 #include <set>
 #include <queue>
 #include <algorithm>
 using namespace std;
 
 #define all(c) (c).begin(),(c).end()
 #define present(c,x) (find(c.begin(),c.end(),x) != (c).end())
 #define pb push_back
 #define mp make_pair
 #define INIT(v,x) memset(v,x,sizeof(v))
 #define REP(i,n) for (int i=0;i<(int)(n);i++)
 #define traverse(v,it) for (typeof(v.begin()) it=v.begin();it!=v.end();it++)
 
 typedef pair<int,int> PII;
 typedef long long int64;
 
 int tests;
 int n;
 int a[2000],b[2000];
 int x[2000];
 
 int u[2000];
 int done;
 void solve(int i) {
 	if (done) return;
 	if (i==n) {
 		int ok=1;
 		for (int j=n-1;j>=0;j--) {
 			int b2=1;
 			for (int k=j+1;k<n;k++) {
 				if (x[j]>x[k]) b2=max(b2,b[k]+1);
 			}
 			if (b2!=b[j]) { ok=0; break; }
 		}
 		if (ok) done=1;
 	} else {
 		for (int v=max(a[i],b[i])-1;v<n;v++) if (!u[v]) {
 			int a2=1;
 			REP (j,i) {
 				if (x[j]<v) a2=max(a2,a[j]+1);
 			}
 			if (a2==a[i]) {
 				x[i]=v;
 				u[v]=1;
 				solve(i+1);
 				if (done) break;
 				u[v]=0;
 			}
 		}
 	}
 }
 
 int main() {
 	freopen("C-small-attempt0.in","r",stdin);
 	freopen("C-small-attempt0.out","w",stdout);
     scanf("%d",&tests);
     REP (test,tests) {
     	cerr << test << endl;
     	scanf("%d",&n);
     	REP (i,n) scanf("%d",&a[i]);
     	REP (i,n) scanf("%d",&b[i]);
 		INIT(u,0);
 		done=0;
     	solve(0);
     	assert(done);
 		printf("Case #%d:", test+1);
 		REP (i,n) printf(" %d",x[i]+1);
 		printf("\n");
 	}
     return 0;
 }
