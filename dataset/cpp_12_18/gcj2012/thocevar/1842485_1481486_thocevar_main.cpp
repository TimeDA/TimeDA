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
 
 int n,D;
 int d[10000],l[10000],f[10000];
 
 int main() {
 	freopen("A-small-attempt0.in","r",stdin);
 	freopen("A-small-attempt0.out","w",stdout);
 	int tests;
     scanf("%d",&tests);
     for (int test=1;test<=tests;test++) {
     	//fprintf(stderr,"%d\n",test);
     	scanf("%d",&n);
     	for (int i=0;i<n;i++) scanf("%d %d",&d[i],&l[i]);
     	scanf("%d",&D);
     	f[0]=d[0];
     	for (int i=1;i<n;i++) {
     		f[i]=-1;
     		for (int j=0;j<i;j++) {
     			if (d[i]<=d[j]+f[j]) {
     				f[i]=max(f[i], min(d[i]-d[j], l[i]));
     			}
     		}
     	}
     	int ok=0;
     	for (int i=0;i<n;i++) if (f[i]!=-1 && D<=d[i]+f[i]) ok=1;
     	printf("Case #%d: ",test);
     	if (ok) printf("YES\n"); else printf("NO\n");
 	}
     return 0;
 }
