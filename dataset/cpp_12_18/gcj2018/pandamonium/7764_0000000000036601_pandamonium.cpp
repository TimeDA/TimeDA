#include <bits/stdc++.h>
using namespace std;
int t,n,l,k,dp[100004];
vector <pair<int,int> > v;
unordered_map<int,int> cnt;
int main(){
	scanf("%d",&t);
	for(int tc=1;tc<=t;tc++){
		scanf("%d %d",&n,&l);
		int tot=n;
		v.clear();
		for(int x=1;x<=n;x++){
			if(n<=250&&x*100%n>=(n+1)/2||x*100%n>=(n+1)/2&&(x-1)*100%n<(n+1)/2) v.emplace_back(x,n-x*100%n);
		}
		cnt.clear();
		for(int x=0;x<l;x++){
			scanf("%d",&k);
			tot-=k;
			cnt[k]++;
		}
		int val,indiv;
		if(100%n>=(n+1)/2) indiv=(n-100%n);
		else indiv=-tot*(100%n);
		val=tot*indiv;
		cnt[0]=tot;
		memset(dp,0,sizeof(dp));
		for(auto i:cnt){
			int cur;
			if(i.first*100%n>=(n+1)/2) cur=n-i.first*100%n;
			else cur=-i.first*100%n;
			val+=cur*i.second;
			for(auto j:v){
				int c=j.first-i.first,s=j.second-cur-indiv,num=i.second;
				if(c<=0||s<=0) continue;
				for(int x=1;num;x<<=1){
					if(x<=num){
						for(int w=tot;w>=c*x;w--) dp[w]=max(dp[w],dp[w-c*x]+s*x);
						num-=x;
					}
					else{
						for(int w=tot;w>=c*num;w--) dp[w]=max(dp[w],dp[w-c*num]+s*num);
						num=0;
					}
				}
			}
		}
		printf("Case #%d: %d\n",tc,100+(val+dp[tot])/n);
	}
	return 0;
}