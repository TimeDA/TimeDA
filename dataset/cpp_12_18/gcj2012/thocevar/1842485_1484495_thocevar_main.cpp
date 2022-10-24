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
 
 int n,r[1000];
 int w,h;
 int xp[1000],yp[1000];
 
 int main() {
 	//freopen("B.in","r",stdin);
 	freopen("B-small-attempt0.in","r",stdin);
 	freopen("B-small-attempt0.out","w",stdout);
 	int tests;
     scanf("%d",&tests);
     for (int test=1;test<=tests;test++) {
     	fprintf(stderr,"%d\n",test);
     	scanf("%d %d %d",&n,&w,&h);
     	vector<PII> s;
     	for (int i=0;i<n;i++) {
     		scanf("%d",&r[i]);
     		s.push_back(make_pair(r[i],i));
     	}
     	sort(s.begin(),s.end());
     	reverse(s.begin(),s.end());
     	int x=-s[0].first,y=0,d=s[0].first;
     	for (int i=0;i<n;i++) {
     		x+=s[i].first;
     		if (x>w) {
     			x=0;
     			y+=d+s[i].first;
     			d=s[i].first;
     		}
     		if (y>h) fprintf(stderr,"FAIL\n");
     		xp[s[i].second]=x;
     		yp[s[i].second]=y;
     		x+=s[i].first;
     	}
     	printf("Case #%d:",test);
     	for (int i=0;i<n;i++) {
     		printf(" %d %d",xp[i],yp[i]);
     	}
     	printf("\n");
 	}
     return 0;
 }
