#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
long long const limit=~0ULL>>2;
long long LL,RR;
int T,R,B,C;
struct Cashier{
	int M,S,P;
	void read(){
		scanf("%d%d%d",&M,&S,&P);
	}
}tmp;
vector<Cashier> CashSet;
bool check(long long mid){
	vector<long long> V;
	for(auto &&x:CashSet){
		V.emplace_back(min((long long)x.M,max(0LL,(mid-x.P)/x.S)));
	}
//	printf("%lld\n",mid);
//	for(auto &&x:V) printf("%lld ",x);
//	printf("\n");
	sort(V.begin(),V.end(),[&](long long x,long long y){return x>y;});
	long long sum=0;
	for(int i=0;i<R;++i){
		sum+=V[i];
	}
	return sum>=B;
}
int main(){
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		scanf("%d%d%d",&R,&B,&C);
		CashSet.clear();
		for(int i=0;i<C;++i){
			tmp.read();
			CashSet.emplace_back(tmp);
		}
		LL=0,RR=limit;
		while(LL+1!=RR){
			long long mid=(LL+RR)>>1;
			if(check(mid)) RR=mid;
			else LL=mid;
		}
		printf("Case #%d: %lld\n",tt,RR);
	}
	return 0;
}
