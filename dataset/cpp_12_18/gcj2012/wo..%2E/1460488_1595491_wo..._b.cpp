#include<cstdio>
 #include<cstring>
 #include<algorithm>
 
 using namespace std;
 
 int main()
 {
 	freopen("b-small-attempt0.in","r",stdin);
 	freopen("b_out.txt","w",stdout);
 	int T;
 	scanf("%d",&T);
 	for(int data=1;data<=T;data++)
 	{
 		int n,sur,p;
 		scanf("%d",&n);
 		scanf("%d",&sur);
 		scanf("%d",&p);
 		int cnt[40];
 		memset(cnt,0,sizeof(cnt));
 		for(int i=0;i<n;i++)
 		{
 			int in;
 			scanf("%d",&in);
 			cnt[in]++;
 		}
 		int ans=0;
 		if(p>=2)
 		{
 			ans+=min(cnt[3*p-3]+cnt[3*p-4],sur);
 		}
 		for(int i=max(3*p-2,0);i<=30;i++)
 		{
 			ans+=cnt[i];
 		}
 		printf("Case #%d: %d\n",data,ans);
 	}
 	return 0;
 }
