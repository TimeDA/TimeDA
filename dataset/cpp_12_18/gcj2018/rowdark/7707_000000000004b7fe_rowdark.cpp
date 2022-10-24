#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int T,N;
vector<int> X,Y;
int main(){
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		scanf("%d",&N);
		X.clear();
		Y.clear();
		for(int i=1;i<=N;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			X.emplace_back(x);
			Y.emplace_back(y);
		}
		sort(X.begin(),X.end());
		sort(Y.begin(),Y.end());
		printf("Case #%d: %d\n",tt,(max(X.back()-X[0],Y.back()-Y[0])+1)/2);
	}
	return 0;
}
