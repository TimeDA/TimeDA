#include <cstdio>
 #include <cstring>
 #include <queue>
 using namespace std;
 int t,ncnt,x,y,n;
 int a[2005],b[2005],curr;
 int cnt2=0,ans[2005],cnt[2005];
 bool more[2005][2005],inq[2005];
 priority_queue <int, vector<int>, greater<int> > pq;
 int main(){
 	scanf("%d",&t);
 	while(t--){
 		memset(more,0,sizeof(more));
 		memset(cnt,0,sizeof(cnt));
 		scanf("%d",&n);
 		for(x=0;x<n;x++){
 			scanf("%d",&a[x]);
 			for(y=0;y<x;y++){
 				if(a[y]>=a[x]){
 					more[y][x]=1;
 					cnt[y]++;
 				}
 			}
 		}
 		for(x=0;x<n;x++){
 			scanf("%d",&b[x]);
 			for(y=0;y<x;y++){
 				if(b[y]<=b[x]){
 					more[x][y]=1;
 					cnt[x]++;
 				}
 			}
 		}
 		memset(ans,-1,sizeof(ans));
 		memset(inq,0,sizeof(inq));
 		ncnt=1;
 		while(!pq.empty()) pq.pop();
 		for(x=0;x<n;x++){
 			if(cnt[x]==0&&ncnt>=a[x]&&ncnt>=b[x]){
 				pq.push(x);
 				inq[x]=1;
 			}
 		}
 		while(!pq.empty()){
 			curr=pq.top();
 			pq.pop();
 			ans[curr]=ncnt;
 			ncnt++;
 			for(x=0;x<n;x++){
 				if(more[x][curr]){
 					more[x][curr]=0;
 					cnt[x]--;
 				}
 			}
 			for(x=0;x<n;x++){
 				if(cnt[x]==0&&!inq[x]&&ncnt>=a[x]&&ncnt>=b[x]){
 					if(a[x]>1){
 						bool fail=0;
 						for(y=0;y<x;y++){
 							if(ans[y]>0&&a[y]==a[x]-1) break;
 							if(y==x-1) fail=1;
 						}
 						if(fail) continue;
 					}
 					if(b[x]>1){
 						bool fail=0;
 						for(y=x+1;y<n;y++){
 							if(ans[y]>0&&b[y]==b[x]-1) break;
 							if(y==n-1) fail=1;
 						}
 						if(fail) continue;
 					}
 					pq.push(x);
 					inq[x]=1;
 				}
 			}
 		}
 		cnt2++;
 		printf("Case #%d:",cnt2);
 		for(x=0;x<n;x++) printf(" %d",ans[x]);
 		printf("\n");
 	}
 	return 0;
 }
