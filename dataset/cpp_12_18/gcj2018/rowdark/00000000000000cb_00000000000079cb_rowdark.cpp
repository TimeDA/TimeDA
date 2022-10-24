#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int T,N;
vector<int> V[2];
int getIndex(int x){
	return V[x&1][x>>1];
}
int main(){
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		scanf("%d",&N);
		V[0].clear(),V[1].clear();
		for(int i=0;i<N;++i){
			static int x;
			scanf("%d",&x);
			V[i&1].emplace_back(x);
		}
		sort(V[0].begin(),V[0].end());
		sort(V[1].begin(),V[1].end());
		int err=N;
		for(int i=0;i<N-1;++i){
			if(getIndex(i)>getIndex(i+1)){
				err=i;
				break;
			}
		}
		printf("Case #%d: ",tt);
		if(err==N) printf("OK\n");
		else printf("%d\n",err);
	}
	return 0;
}
