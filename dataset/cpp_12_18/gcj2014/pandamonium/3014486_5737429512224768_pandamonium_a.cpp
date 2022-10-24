#include <cstdio>
 #include <cstring>
 #include <algorithm>
 using namespace std;
 int ans,size[705];
 int i,t,n,c,s;
 int main(){
 	scanf("%d",&t);
 	while(t--){
 		ans=0;
 		scanf("%d %d",&n,&c);
 		for(int x=0;x<n;x++){
 			scanf("%d",&s);
 			size[s]++;
 		}
 		for(int x=c;x>=0;x--){
 			if(size[x]==0) continue;
 			if(x*2<=c){
 				ans+=size[x]/2;
 				size[x]%=2;
 			}
 			for(int y=min(c-x,x-1);y>=0;y--){
 				if(size[y]>=size[x]){
 					ans+=size[x];
 					size[y]-=size[x];
 					size[x]=0;
 				}
 				else if(size[y]>0){
 					size[x]-=size[y];
 					ans+=size[y];
 					size[y]=0;
 				}	
 				if(size[x]==0) break;
 			}
 			ans+=size[x];
 			size[x]=0;
 		}
 		printf("Case #%d: %d\n",++i,ans);
 	}
 	return 0;
 }	
