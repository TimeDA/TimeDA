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
 
 int n;
 int l[1000],p[1000];
 
 bool comp(int i1, int i2) {
 	int x1=-l[i2]*p[i1];
 	int x2=-l[i1]*p[i2];
 	if (x1==x2) return i1<i2;
 	else return x1<x2;
 }
 
 int main() {
 	freopen("A-small-attempt0.in","r",stdin);
 	freopen("A-small-attempt0.out","w",stdout);
 	int tests;
     scanf("%d",&tests);
     for (int test=1;test<=tests;test++) {
     	scanf("%d",&n);
     	for (int i=0;i<n;i++) scanf("%d",&l[i]);
     	for (int i=0;i<n;i++) scanf("%d",&p[i]);
     	vector<int> v;
     	for (int i=0;i<n;i++) v.push_back(i);
     	sort(v.begin(),v.end(),comp);
     	printf("Case #%d:",test);
     	for (int i=0;i<n;i++) {
     		printf(" %d",v[i]);
     	}
     	printf("\n");
     }
     return 0;
 }
