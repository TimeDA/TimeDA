#include<cstdio>
 #include<queue>
 #include<algorithm>
 
 using namespace std;
 
 long long dis[1010][1010];
 
 int abs(int x){
 	if(x<0) return -x;
 	return x;
 }
 
 bool overlap(int a,int b,int c,int d){
 	if(a>c){
 		swap(a,c);
 		swap(b,d);
 	}
 	if(b>=c) return true;
 	return false;
 }
 
 int get(int a,int b,int c,int d){
 	int x=abs(a-d);
 	int y=abs(b-c);
 	return min(x,y)-1;
 }
 
 int get(int x00,int x01,int y00,int y01,int x10,int x11,int y10,int y11){
 	if(overlap(x00,x01,x10,x11)){
 		return get(y00,y01,y10,y11);
 	}else if(overlap(y00,y01,y10,y11)){
 		return get(x00,x01,x10,x11);
 	}else{
 	//	return get(y00,y01,y10,y11)+get(x00,x01,x10,x11);
 		return max(get(y00,y01,y10,y11),get(x00,x01,x10,x11));
 	}
 }
 
 int x0[1010],y0[1010],x1[1010],y1[1010];
 
 long long mdis[1010];
 bool used[1010];
 int N;
 
 void dijkstra(){
 	for(int i=0;i<1010;i++){
 		mdis[i]=1ll<<61;
 		used[i]=false;
 	}
 	mdis[0]=0;
 	while(true){
 		int v=-1;
 		for(int u=0;u<N;u++){
 			if((used[u]==false)&&(v==-1||mdis[u]<mdis[v])) v=u;
 		}
 		if(v==-1) break;
 		used[v]=true;
 		for(int u=0;u<N;u++){
 			mdis[u]=min(mdis[u],mdis[v]+dis[v][u]);
 		}
 	}
 }
 
 int main(){
 	int T;
 	scanf("%d",&T);
 	for(int datano=0;datano<T;datano++){
 		int W,H,B;
 		scanf("%d%d%d",&W,&H,&B);
 		N=B+2;
 		for(int i=1;i<=B;i++){
 			scanf("%d%d%d%d",x0+i,y0+i,x1+i,y1+i);
 		}
 		for(int i=1;i<=B;i++){
 			dis[0][i]=x0[i];
 			dis[i][0]=x0[i];
 			dis[i][B+1]=W-x1[i]-1;
 			dis[B+1][i]=W-x1[i]-1;
 			for(int j=i;j<=B;j++){
 				if(i==j){
 					dis[i][j]=0;
 					dis[j][i]=0;
 					continue;
 				}
 				dis[i][j]=get(x0[i],x1[i],y0[i],y1[i],x0[j],x1[j],y0[j],y1[j]);
 				dis[j][i]=dis[i][j];
 			}
 		}
 	/*	for(int i=0;i<=B+1;i++){
 			for(int j=0;j<=B+1;j++){
 				printf("%lld  ",dis[i][j]);
 			}
 			printf("\n");
 		}*/
 		dis[0][B+1]=W;
 		dijkstra();
 		printf("Case #%d: %lld\n",datano+1,mdis[B+1]);
 	}
 	return 0;
 }
