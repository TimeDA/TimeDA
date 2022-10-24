#include<cstdio>
 #include<algorithm>
 using namespace std;
 typedef long long ll;
 bool canA(int N,ll P,ll K)
 {
 	for(int i=N-1;i>=0;i--)
 		if((P>>i)&1)
 		{
 			if(K==0)return 1;
 			K=(K-1)/2;
 		}else
 		{
 			if(K>0)return 0;
 		}
 	return 1;
 }
 bool canB(int N,ll P,ll K)
 {
 	for(int i=N-1;i>=0;i--)
 		if((P>>i)&1)
 		{
 			if(K<(1LL<<(i+1))-1)return 1;
 			K/=2;
 		}else
 		{
 			if(K==(1LL<<(i+1))-1)return 0;
 			K=((1LL<<i)-1)-((1LL<<(i+1))-1-K-1)/2;
 		}
 	return 1;
 }
 int main()
 {
 	int _;scanf("%d",&_);
 	for(int __=1;__<=_;__++)
 	{
 		int N;ll P;
 		scanf("%d%lld",&N,&P);P--;
 		ll L=0,R=(1LL<<N)-1;
 		ll A,B;
 		while(L<=R)
 		{
 			ll M=(L+R)/2;
 			if(canA(N,P,M))L=M+1;else R=M-1;
 		}
 		A=R;
 		L=0,R=(1LL<<N)-1;
 		while(L<=R)
 		{
 			ll M=(L+R)/2;
 			if(canB(N,P,M))L=M+1;else R=M-1;
 		}
 		B=R;
 		printf("Case #%d: %lld %lld\n",__,A,B);
 	}
 	return 0;
 }
