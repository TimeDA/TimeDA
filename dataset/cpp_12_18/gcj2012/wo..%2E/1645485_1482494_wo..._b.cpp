#include<cstdio>
 #include<vector>
 #include<utility>
 #include<queue>
 #include<cstring>
 #include<algorithm>
 
 using namespace std;
 
 typedef pair<int,int> P;
 typedef pair<int,P> PP;
 
 bool done[1100];
 bool onedone[1100];
 int data[1100][2];
 
 int main()
 {
 	freopen("b_sm_out.txt","w",stdout);
 	int T;
 	scanf("%d",&T);
 	for(int datano=1;datano<=T;datano++)
 	{
 		int donenum=0;
 		int nowstar=0;
 		priority_queue<P,vector<P>,greater<P> > ones;
 		//1-star-rating small-first
 		//1-star,id
 		priority_queue<PP> one_todo;
 		//2-star-rating larger-first
 		//2-star,1-star,id
 		priority_queue<P,vector<P>,greater<P> > twos;
 		//2-star-rating smaller-first
 		//2-star,id
 		int N;
 		scanf("%d",&N);
 		for(int i=0;i<N;i++)
 		{
 			scanf("%d%d",&data[i][0],&data[i][1]);
 			ones.push(P(data[i][0],i));
 			twos.push(P(data[i][1],i));
 		}
 		memset(done,false,sizeof(done));
 		memset(onedone,false,sizeof(onedone));
 		int plays=0;
 		while(1)
 		{
 		while(!twos.empty()&&twos.top().first<=nowstar)
 		{
 			int id=twos.top().second;
 			//nowstar+=2;
 			if(onedone[id]) nowstar++;
 			else nowstar+=2;
 			donenum++;
 			plays++;
 			done[twos.top().second]=true;
 			twos.pop();
 		//	printf("two play\n");
 		}
 		if(donenum==N) break;
 		while(!ones.empty()&&ones.top().first<=nowstar)
 		{
 			if(done[ones.top().second]==true)
 			{
 				ones.pop();
 				continue;
 			}
 			int id=ones.top().second;
 	//		printf("%d\n",ones.top().first);
 			ones.pop();
 			one_todo.push(PP(data[id][1],P(data[id][0],id)));
 		}
 		int nxt=twos.top().first;
 		if(one_todo.empty()&&nxt>nowstar)
 		{
 			printf("Case #%d: Too Bad\n",datano);
 			goto nextdata;
 		}
 		while(!one_todo.empty()&&nxt>nowstar)
 		{
 			onedone[one_todo.top().second.second]=true;
 			one_todo.pop();
 			nowstar++;
 			plays++;
 			while(!ones.empty()&&ones.top().first<=nowstar)
 			{
 				if(done[ones.top().second]==true)
 				{
 					ones.pop();
 					continue;
 				}
 				int id=ones.top().second;
 	//			printf("%d\n",ones.top().first);
 				ones.pop();
 				one_todo.push(PP(data[id][1],P(data[id][0],id)));
 			}
 
 	//			printf("one play\n");
 		}
 		}
 		printf("Case #%d: %d\n",datano,plays);
 		nextdata:;
 	}
 	return 0;
 }
