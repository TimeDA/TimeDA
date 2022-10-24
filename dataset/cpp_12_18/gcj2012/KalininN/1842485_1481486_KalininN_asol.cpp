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
 
 const int maxn=10005;
 const int inf=1e9;
 
 int d[maxn],ms[maxn],l[maxn];
 int n;
 
 int main()
 {
 	int NT=0;
 	scanf("%d",&NT);
 	for (int T=1;T<=NT;T++)
 	{
 		bool ans=false;
 		scanf("%d",&n);
 		for (int i=0;i<n;i++) scanf("%d%d",&d[i],&l[i]);
 		int D;
 		scanf("%d",&D);
 		for (int i=0;i<n;i++) ms[i]=inf;
 		ms[0]=0;
 		for (int i=0;i<n;i++)
 		{
 			int f=d[i]+(d[i]-ms[i]);
 			if (f>=D) ans=true;
 			for (int j=i+1;j<n && d[j]<=f;j++) ms[j]=min(ms[j],max(d[j]-l[j],d[i]));
 		}
 		printf("Case #%d: %s\n",T,ans ? "YES" : "NO");
 	}
 	return 0;
 }