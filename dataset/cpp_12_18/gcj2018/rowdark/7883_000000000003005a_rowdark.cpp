#include<stdio.h>
#include<vector>
using namespace std;
char s[111][111];
int sum[111][111];
int R,C,H,V,T;
bool check(){
	int tot=sum[R][C];
	if(tot%((H+1)*(V+1))!=0) return false;
	if(!tot) return true;
	vector<int> RC,CC;
	RC.push_back(0);
	CC.push_back(0);
	{
		int step=tot/(H+1);
		for(int now=step,i=1;now<=tot;now+=step){
			while(sum[i][C]<now) ++i;
			if(sum[i][C]!=now) return false;
			RC.push_back(i);
		}
	}
	{
		int step=tot/(V+1);
		for(int now=step,i=1;now<=tot;now+=step){
			while(sum[R][i]<now) ++i;
			if(sum[R][i]!=now) return false;
			CC.push_back(i);
		}
	}
	int block=tot/(V+1)/(H+1);
	for(int i=1;i<=H+1;++i) for(int j=1;j<=V+1;++j){
		if(sum[RC[i]][CC[j]]-sum[RC[i]][CC[j-1]]-sum[RC[i-1]][CC[j]]+sum[RC[i-1]][CC[j-1]]!=block) return false;
	}
/*	printf("\nRC: ");
	for(auto &&x:RC) printf("%d ",x);
	printf("\nCC: ");
	for(auto &&x:CC) printf("%d ",x);
	printf("\n");*/
	return true;
}
int main(){
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		scanf("%d%d%d%d",&R,&C,&H,&V);
		for(int r=1;r<=R;++r){
			scanf("%s",s[r]+1);
		}
		for(int r=1;r<=R;++r) for(int c=1;c<=C;++c){
			sum[r][c]=sum[r-1][c]+sum[r][c-1]-sum[r-1][c-1]+(s[r][c]=='@');
		}
		printf("Case #%d: %s\n",tt,check()?"POSSIBLE":"IMPOSSIBLE");
	}
	return 0;
}
