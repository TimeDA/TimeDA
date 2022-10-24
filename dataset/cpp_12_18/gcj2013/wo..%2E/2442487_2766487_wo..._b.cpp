#include<cstdio>
 #include<algorithm>
 
 using namespace std;
 
 long long solve(int N,long long K)
 {
 //	printf("AAA%d %lld\n",N,K);
 	if(K==(1ll<<N)) return (1ll<<N)-1;
 	long long place=1;
 	long long ma=0;
 	for(int i=1;i<N;i++)
 	{
 		place+=1ll<<(N-i);
 		if(place<=K) ma=max(ma,(1ll<<(i+1))-2);
 	//	printf("i=%d,place=%lld\n",i,place);
 	//	if(place>K) return (1ll<<i)-2;
 	}
 	return ma;
 }
 
 int main()
 {
 	int T;
 	scanf("%d",&T);
 	for(int datano=0;datano<T;datano++)
 	{
 		long long N,P;
 		scanf("%lld%lld",&N,&P);
 		long long ans1=solve(N,P);
 		long long ans2=solve(N,(1ll<<N)-(P));
 		ans2=(1ll<<N)-ans2-2;
 		ans2=max(ans2,ans1);
 		printf("Case #%d: %lld %lld\n",datano+1,ans1,ans2);
 	}
 	return 0;
 }
