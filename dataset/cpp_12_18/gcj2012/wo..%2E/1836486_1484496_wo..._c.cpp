#include<cstdio>
 #include<vector>
 #include<utility>
 #include<algorithm>
 
 using namespace std;
 
 typedef pair<int,int> P;
 
 vector<P> sums;
 vector<int> a,aa;
 
 int main()
 {
 	freopen("c_sm_out.txt","w",stdout);
 	int T;
 	scanf("%d",&T);
 	for(int datano=1;datano<=T;datano++)
 	{
 		int N;
 		scanf("%d",&N);
 		int data[22];
 		for(int i=0;i<N;i++)
 		{
 			scanf("%d",data+i);
 		}
 		//vector<P> sums;
 		//vector<int> a,aa;
 		sums.clear();a.clear();aa.clear();
 		for(int i=0;i<(1<<N);i++)
 		{
 			int tmp=0;
 			for(int j=0;j<N;j++)
 			{
 				if((i>>j)%2==1)
 				{
 					tmp+=data[j];
 				}
 			}
 			sums.push_back(P(tmp,i));
 		}
 		sort(sums.begin(),sums.end());
 		bool flg=false;
 		for(int i=1;i<(1<<N);i++)
 		{
 			if(sums[i-1].first==sums[i].first)
 			{
 				int b=sums[i-1].second,bb=sums[i].second;
 				int c=b&bb;
 				b=b&(~c),bb=bb&(~c);
 				if(b==0||bb==0) continue;
 				flg=true;
 				for(int j=0;j<N;j++)
 				{
 					if((b&(1<<j))!=0) a.push_back(data[j]);
 					if((bb&(1<<j))!=0) aa.push_back(data[j]);
 				}
 				break;
 			}
 		}
 		if(flg==false)
 		{
 			printf("Case #%d:\n",datano);
 			printf("Impossible\n");
 		}
 		else
 		{
 			printf("Case #%d:\n",datano);
 			int an=a.size();
 			for(int i=0;i<an;i++)
 			{
 				printf("%d%c",a[i],i==an-1?'\n':' ');
 			}
 			int aan=aa.size();
 			for(int i=0;i<aan;i++)
 			{
 				printf("%d%c",aa[i],i==aan-1?'\n':' ');
 			}
 		}
 	}
 	return 0;
 }
