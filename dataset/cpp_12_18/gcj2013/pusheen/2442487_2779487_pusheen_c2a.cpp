#include<stdio.h>
 #include<algorithm>
 #include<vector>
 #include<queue>
 int a[100001];
 struct E {
 	int a,b;
 }e[10000001];
 int to[1111111];
 std::vector<int> adj[1000001];
 std::priority_queue<int,std::vector<int,std::allocator<int> >,std::greater<int> > Q;
 int main(){
 	int i,j,k;
 	int n,m;
 	static int lis[1000001],lds[1000001];
 	int T,TN;
 	scanf("%d",&TN);
 	for(T=1;T<=TN;T++){
 		m=0;
 		scanf("%d",&n);
 		for(i=0;i<n;i++){
 			scanf("%d",&lis[i]);
 		}
 		for(i=0;i<n;i++){
 			scanf("%d",&lds[n-i-1]);
 		}
 		for(i=0;i<n;i++)
 			for(k=1,j=i+1;j<n;j++){
 				if(lis[j]==lis[i])k=0;
 				if(lis[i]>=lis[j])
 					e[m++]=(E){j,i};
 				else if(k){
 					e[m++]=(E){i,j};
 				}
 			}
 		for(i=0;i<n;i++)
 			for(k=1,j=i+1;j<n;j++){
 				if(lds[j]==lds[i])k=0;
 				if(lds[i]>=lds[j])
 					e[m++]=(E){n-j-1,n-i-1};
 				else if(k){
 					e[m++]=(E){n-i-1,n-j-1};
 				}
 				
 			}
 
 		for(i=0;i<n;i++){
 			adj[i].clear();
 			to[i]=0;
 		}
 		for(i=0;i<m;i++){
 			adj[e[i].a].push_back(e[i].b);
 			to[e[i].b]++;
 		}
 		while(!Q.empty())Q.pop();
 		for(i=0;i<n;i++){
 			if(!to[i]){
 				Q.push(i);
 			}
 		}
 		j=0;
 		while(!Q.empty()){
 			k=Q.top();
 			a[k]=j++;
 			Q.pop();
 			for(i=0;i<adj[k].size();i++){
 				if(!--to[adj[k][i]]){
 					Q.push(adj[k][i]);
 				}
 			}
 		}
 		printf("Case #%d:",T);
 		for(i=0;i<n;i++){
 			printf(" %d",a[i]+1);
 		}
 		puts("");
 	}
 	
 }
