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
 
 typedef long long int64;
 typedef pair<int64,int64> PII;
 
 int tests;
 
 string solve(int k, char w, int &r, int &p, int &s) {
 	if (k==0) {
 		r=0; p=0; s=0;
 		if (w=='R') r=1;
 		if (w=='P') p=1;
 		if (w=='S') s=1;
 		return string("")+w;
 	}
 	int r1,p1,s1,r2,p2,s2;
 	string a,b;
 	if (w=='R') {
 		a=solve(k-1,'R',r1,p1,s1);
 		b=solve(k-1,'S',r2,p2,s2);
 	}
 	if (w=='P') {
 		a=solve(k-1,'P',r1,p1,s1);
 		b=solve(k-1,'R',r2,p2,s2);
 	}
 	if (w=='S') {
 		a=solve(k-1,'S',r1,p1,s1);
 		b=solve(k-1,'P',r2,p2,s2);
 	}
 	r=r1+r2; p=p1+p2; s=s1+s2;
 	return min(a,b)+max(a,b);
 }
 
 int main() {
 	freopen("A-small-attempt0.in","r",stdin);
 	freopen("A-small-attempt0.out","wb",stdout);
 	cin >> tests;
 	FOR (test,1,tests) {
 		//cerr << test << endl;
 		printf("Case #%d: ",test);
 		int k,r,p,s;
 		scanf("%d %d %d %d",&k,&r,&p,&s);
 		string best = "IMPOSSIBLE";
 		for (char w : {'R','P','S'}) {
 			int r1,p1,s1;
 			string sol=solve(k,w,r1,p1,s1);
 			if (p1==p && r1==r && s1==s) {
 				if (best == "IMPOSSIBLE" || sol < best) best = sol;
 			}
 		}
 		cout << best << endl;
 	}
 	return 0;
 }
