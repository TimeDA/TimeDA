#include <stdio.h>
 #include <stdlib.h>
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
 #define all(c) (c).begin(),(c).end()
 #define present(c,x) (find(c.begin(),c.end(),x) != (c).end())
 #define pb push_back
 #define traverse(v,it) for (typeof(v.begin()) it=v.begin();it!=v.end();it++)
 using namespace std;
 template<class A, class B> A cvt(B x) { stringstream ss; ss<<x; A y; ss>>y; return y; }
 typedef long long int64;
 typedef pair<int,int> PII;
 
 int n,h[10],f[10];
 
 int getRand() {
 	return ((rand()<<15)^rand())%1000000000;
 }
 
 int main() {
 	//freopen("B.in","r",stdin);
 	freopen("C-small-attempt2.in","r",stdin);
 	freopen("C-small-attempt2.out","w",stdout);
 	srand(123);
 	int tests;
     scanf("%d",&tests);
     for (int test=1;test<=tests;test++) {
     	fprintf(stderr,"%d\n",test);
     	scanf("%d",&n);
     	vector<int> y;
     	for (int i=0;i<n-1;i++) scanf("%d",&h[i]);
     	printf("Case #%d:",test);
 
 		int ok=1;
     	stack<int> s;
     	s.push(n);
     	for (int i=0;i<n-1;i++) {
     		h[i]--;
     		while (s.top()==i) s.pop();
     		if (h[i]<=i || h[i]>s.top()) { ok=0; break; }
     		s.push(h[i]);
     	}
     	if (!ok) { printf(" Impossible\n"); continue; }
 
     	ok=0;
     	for (int it=1;it<=200;it++) {
     		y.clear();
 			for (int i=1;i<=n;i++) {
 				y.push_back(getRand());
 			}
 			sort(y.begin(),y.end());
 			do {
 				ok=1;
 				for (int i=0;i<n-1;i++) {
 					int k=i+1;
 					for (int j=i+2;j<n;j++) {
 						if ((int64)(y[j]-y[i])*(k-i)>(int64)(y[k]-y[i])*(j-i)) {
 							k=j;
 						}
 					}
 					if (k!=h[i]) { ok=0; break; }
 				}
 				if (ok) break;
 			} while (next_permutation(y.begin(),y.end()));
 			if (ok) break;
     	}
 
     	if (!ok) printf(" ?\n");
     	else {
     		for (int i=0;i<n;i++) printf(" %d",y[i]);
     		printf("\n");
     	}
 	}
     return 0;
 }
