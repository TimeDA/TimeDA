#include<cstdio>
 #include<utility>
 #include<vector>
 #include<algorithm>
 
 using namespace std;
 
 typedef pair<int,int> P;
 
 int main()
 {
 	freopen("a_sm_out.txt","w",stdout);
 	int T;
 	scanf("%d",&T);
 	for(int datano=1;datano<=T;datano++)
 	{
 		int N;
 		scanf("%d",&N);
 		int data[220];
 		vector<P> vec;
 		int sum=0;
 		for(int i=0;i<N;i++)
 		{
 			scanf("%d",data+i);
 			vec.push_back(P(data[i],i));
 			sum+=data[i];
 		}
 		sort(vec.begin(),vec.end());
 		double ans[220];
 		for(int i=0;i<N;i++)
 		{
 			double lb=0,ub=100;
 			for(int loop=0;loop<60;loop++)
 			{
 				double mid=(lb+ub)/2;
 				double border=mid*sum/100+data[i];
 				double sup=0;
 				for(int j=0;j<N;j++)
 				{
 					if(vec[j].second==i) continue;
 					if(vec[j].first>border) break;
 					sup+=(border-vec[j].first)/sum;
 				}
 				if(sup+mid/100>1) ub=mid;
 				else lb=mid;
 			}
 			ans[i]=lb;
 		}
 		printf("Case #%d: ",datano);
 		for(int i=0;i<N;i++)
 		{
 			printf("%f%c",ans[i],i==(N-1)?'\n':' ');
 		}
 	}
 	return 0;
 }
