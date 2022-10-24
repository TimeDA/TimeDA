#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
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
 
 int f[2000001];
 int money,d,n;
 
 int main() {
 	freopen("C-small-attempt1.in","r",stdin);
 	freopen("C-small-attempt1.out","w",stdout);
 	int tests;
     scanf("%d",&tests);
     for (int test=1;test<=tests;test++) {
 		scanf("%d %d %d",&money,&d,&n);
 		//printf("%d %d %d\n",money,d,n);
 		vector<PII> v;
 		for (int i=0;i<n;i++) {
 			int p,s;
 			scanf("%d %d",&p,&s);
 			v.push_back(make_pair(p,s));
 		}
 		sort(v.begin(),v.end());
 		vector<PII> x;
 		x.push_back(v[0]);
 		for (int i=1;i<n;i++) {
 			int p0=x[x.size()-1].first, s0=x[x.size()-1].second;
 			int p1=v[i].first, s1=v[i].second;
 			if (s1>s0) {
 				if (p1==p0) x.pop_back();
 				x.push_back(v[i]);
 			}
 		}
 		int m=x.size();
 		memset(f,-1,sizeof(f));
 		f[0]=money;
 		int len=0;
 		for (int t=0;t<=money;t++) if (f[t]!=-1) {
 			len=t;
 			int a=f[t]-d;
 			if (a<=0) continue;
 			int items=0;
 			for (int i=0;i<m;i++) {
 				int k=a/x[i].first;
 				int l=(x[i].second+1)-items;
 				int buy=min(k,l);
 				items+=buy;
 				a-=buy*x[i].first;
 				if (a>f[t+items]) f[t+items]=a;
 			}
 		}
     	printf("Case #%d: %d\n",test,len);
     }
     return 0;
 }
