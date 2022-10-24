#include <iostream>
 #include <cassert>
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
 
 struct tr
 {
 	int r,id;
 };
 
 inline bool operator <(tr a,tr b)
 {
 	return a.r<b.r;
 }
 
 struct tans
 {
 	int x,y;
 };
 
 const int maxn=1005;
 
 tans ans[maxn];
 tr r[maxn];
 int n,w,l;
 
 int main()
 {
 	int NT=0;
 	scanf("%d",&NT);
 	for (int T=1;T<=NT;T++)
 	{
 		scanf("%d%d%d",&n,&w,&l);
 		for (int i=0;i<n;i++)
 		{
 			scanf("%d",&r[i].r);
 			r[i].id=i;
 		}
 		sort(r,r+n);
 		reverse(r,r+n);
 		int curw=-r[0].r;
 		int curl=l;
 		int curadd=0;
 		for (int i=0;i<n;i++)
 		{
 			if (curl+r[i].r>l)
 			{
 				curw+=curadd+r[i].r;
 				curl=-r[i].r;
 				curadd=r[i].r;
 			}
 			curl+=r[i].r;
 			ans[r[i].id].x=curw;
 			ans[r[i].id].y=curl;
 			curl+=r[i].r;
 			assert(curw<=w);
 		}
 		printf("Case #%d:",T);
 		for (int i=0;i<n;i++) printf(" %d %d",ans[i].x,ans[i].y);
 		printf("\n");
 	}
 	return 0;
 }