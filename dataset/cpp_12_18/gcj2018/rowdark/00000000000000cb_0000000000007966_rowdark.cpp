#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
int T,D,N;
char P[32];
vector<int> S;
int main(){
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		scanf("%d%s",&D,P);
		printf("Case #%d: ",tt);
		S.clear();
		N=strlen(P);
		int tmp=1,sum=0;
		for(int i=0;i<N;++i){
			if(P[i]=='C') tmp*=2;
			else sum+=tmp,S.emplace_back(tmp);
		}
		if(S.size()>D){
			printf("IMPOSSIBLE\n");
		}
		else{
			int ans=0;
			while(sum>D){
				for(int i=int(S.size())-1,j=S.back();sum>D&&i!=-1&&S[i]==j;--i){
					S[i]/=2;
					sum-=S[i];
					ans++;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
