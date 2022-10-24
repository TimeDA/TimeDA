#include<cstdio>
 #include<algorithm>
 
 using namespace std;
 
 double prob[100100];
 double cor[100100];
 
 int main()
 {
 	freopen("a_out.txt","w",stdout);
 	int T;
 	scanf("%d",&T);
 	for(int datano=1;datano<=T;datano++)
 	{
 		int A,B;
 		cor[0]=1;
 		scanf("%d%d",&A,&B);
 		for(int i=1;i<=A;i++)
 		{
 			scanf("%lf",prob+i);
 			cor[i]=cor[i-1]*prob[i];
 		}
 		double ans=10010010;
 		for(int i=1;i<=A;i++)
 		{
 			ans=min(ans,(A-i)+(B-i)+1+(B+1)*(1-cor[i]));
 		}
 		ans=min(ans,(double)1+B+1);
 		printf("Case #%d: %f\n",datano,ans);
 	}
 	return 0;
 }
