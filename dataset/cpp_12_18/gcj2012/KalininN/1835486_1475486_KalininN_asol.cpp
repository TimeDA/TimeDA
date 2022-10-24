#include <iostream>
 #include <algorithm>
 #include <cmath>
 #include <cstring>
 #include <string>
 #include <vector>
 #include <cstdio>
 
 using namespace std;
 
 typedef long long ll;
 typedef long double ld;
 
 #ifdef WIN32
 #define LLD "%I64d"
 #else
 #define LLD "%lld"
 #endif
 
 struct tp
 {
 	int p,id;
 };
 
 inline bool operator<(tp a,tp b)
 {
 	return (a.p>b.p)||((a.p==b.p)&&(a.id<b.id));
 }
 
 const int maxn=205;
 
 tp t[maxn];
 int l[maxn];
 int n;
 
 int main()
 {
 	int NT=0;
 	scanf("%d",&NT);
 	for (int T=1;T<=NT;T++)
 	{
 		scanf("%d",&n);
 		for (int i=0;i<n;i++) scanf("%d",&l[i]);
 		for (int i=0;i<n;i++)
 		{
 			scanf("%d",&t[i].p);
 			t[i].id=i;
 		}
 		sort(t,t+n);
 		printf("Case #%d:",T);
 		for (int i=0;i<n;i++) printf(" %d",t[i].id);
 		printf("\n");
 	}
 	return 0;
 }