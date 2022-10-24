#include<stdio.h>
#include<algorithm>
long long M[1001],S[1001],P[1001];
int x,y,n;
long long R[1001];
bool check(long long t){
	int i,k=0;
	for(i=0;i<n;i++){
		if(t<P[i]+S[i]) continue;
		R[k++]=std::min(M[i],(t-P[i])/S[i]);
	}
	std::sort(R,R+k);
	std::reverse(R,R+k);
	long long c=0;
	for(i=0;i<k&&i<x;i++){
		c+=R[i];
	}
	return c>=y;
}
long long solve(){
	scanf("%d%d%d",&x,&y,&n);
	int i,j;
	for(i=0;i<n;i++){
		scanf("%lld%lld%lld",&M[i],&S[i],&P[i]);
	}
	long long min=1,max=4000000000000000000LL,mid;
	while(min<max){
		mid=(min+max)/2;
		//printf("check %lld: ",mid);
		if(check(mid)){
			//puts("ok");
			max=mid;
		} else {
			//puts("fail");
			min=mid+1;
		}
	}
	return max;
}
int main(){
	int T,TN;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		printf("Case #%d: ", T);
		printf("%lld\n",solve());
	}
}