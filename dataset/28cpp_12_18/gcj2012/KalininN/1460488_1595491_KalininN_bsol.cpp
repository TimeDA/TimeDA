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
 
 const int maxn=105;
 
 int ans[maxn][maxn];
 int t[maxn];
 
 inline int getbest(int t,int k)
 {
 	int t1=t/3;
 	int t2=(t-t1)/2;
 	int t3=t-t1-t2;
 	return t3+k;
 }
 
 int main()
 {
 	int NT=0;
 	scanf("%d",&NT);
 	for (int T=1;T<=NT;T++)
 	{
 		cerr << T << endl;
 		int n,s,p;
 		scanf("%d%d%d",&n,&s,&p);
 		for (int i=0;i<n;i++) scanf("%d",&t[i]);
 		memset(ans,0,sizeof(ans));
 		ans[0][0]=(getbest(t[0],0)>=p);
 		if (t[0]%3!=1 && t[0]>=3) ans[0][1]=(getbest(t[0],1)>=p);
 		else ans[0][1]=0;
 // 		cout << ans[0][0] << ' ' << ans[0][1] << endl;
 		for (int i=1;i<n;i++)
 		{
 // 			cout << "i=" << i << endl;
 			ans[i][0]=ans[i-1][0]+(getbest(t[i],0)>=p);
 // 			cout << ans[i][0] << endl;
 			for (int j=1;j<=min(i+1,s);j++)
 			{
 // 				cout << "j=" << j << endl;
 				if (t[i]%3!=1 && t[i]>=3) ans[i][j]=max(ans[i][j],ans[i-1][j-1]+(getbest(t[i],1)>=p));
 				else ans[i][j]=ans[i-1][j];
 				ans[i][j]=max(ans[i][j],ans[i-1][j]+(getbest(t[i],0)>=p));
 // 				cout << ans[i][j] << endl;
 			}
 		}
 		printf("Case #%d: %d\n",T,ans[n-1][s]);
 	}
 	return 0;
 }
