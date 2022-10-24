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
 
 const int maxn=2005;
 const int inf=1e9;
 
 vector <int> from[maxn];
 int ans[maxn];
 int nx[maxn];
 bool sett[maxn];
 int n;
 
 void go(int cur,int curh,int was,int wash)
 {
 	ans[cur]=curh;
 	sett[cur]=true;
 	if (from[cur].size()==0) return;
 	int first=from[cur][0];
 	ll h=(((ll)(curh))*(was-first)-((ll)(wash))*(cur-first))/(was-cur);
 	for (int i=0;i<from[cur].size();i++) go(from[cur][i],h,cur,curh);
 }
 
 int main()
 {
 	int NT=0;
 	scanf("%d",&NT);
 	for (int T=1;T<=NT;T++)
 	{
 		scanf("%d",&n);
 		memset(sett,0,sizeof(sett));
 		for (int i=0;i<n;i++) from[i].resize(0);
 		for (int i=0;i<n-1;i++)
 		{
 			scanf("%d",&nx[i]);
 			nx[i]--;
 			from[nx[i]].push_back(i);
 		}
 		bool can=true;
 		for (int i=0;i<n-1;i++)
 		{
 			for (int j=i+1;j<n-1;j++)
 			{
 				if (nx[i]>j && nx[j]>nx[i]) can=false;
 			}
 		}
 		if (!can)
 		{
 			printf("Case #%d: Impossible\n",T);
 			continue;
 		}
 		for (int i=n-1;i>=0;i--)
 		{
 			if (!sett[i]) go(i,inf,i+1,inf+1);
 		}
 		for (int i=0;i<n-1;i++)
 		{
 			double maxa=-inf;
 			int maxj=0;
 			for (int j=i+1;j<n;j++) if ((ans[j]-ans[i])*1.0/(j-i)>maxa+1e-7)
 			{
 				maxa=(ans[j]-ans[i])*1.0/(j-i);
 				maxj=j;
 			}
 			assert(maxj==nx[i]);
 		}
 		printf("Case #%d:",T,ans);
 		for (int i=0;i<n;i++) printf(" %d",ans[i]);
 		printf("\n");
 	}
 	return 0;
 }