#include<cstdio>
 #include<algorithm>
 
 using namespace std;
 
 const long long MA=4100100100100100100ll;
 
 int main()
 {
 	int TN;
 	scanf("%d",&TN);
 	for(int datano=0;datano<TN;datano++)
 	{
 		long long R,T;
 		scanf("%lld%lld",&R,&T);
 		long long lb=0,ub=min(2ll*1000000000,MA/(R*2-1));
 		if(R*2+1>T)
 		{
 			printf("Case #%d: 0\n",datano+1);
 			continue;
 		}
 		while(ub-lb>1)
 		{
 			long long mid=(ub+lb)/2;
 			long long tmp=mid*mid*2+(R*2-1)*mid;
 			if(tmp<=T) lb=mid;
 			else ub=mid;
 		}
 		printf("Case #%d: %lld\n",datano+1,lb);
 	}
 	return 0;
 }
