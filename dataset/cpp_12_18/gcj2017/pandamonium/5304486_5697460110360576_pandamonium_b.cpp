#include <bits/stdc++.h>
 using namespace std;
 int t,n,p,a[55],k;
 int sum[55][1100005];
 typedef long long ll;
 int main(){
 	scanf("%d",&t);
 	for(int tc=1;tc<=t;tc++){
 		scanf("%d %d",&n,&p);
 		for(int x=0;x<n;x++) scanf("%d",&a[x]);
 		memset(sum,0,sizeof(sum));
 		for(int x=0;x<n;x++){
 			for(int y=0;y<p;y++){
 				scanf("%d",&k);
 				int lo=(k*10-1)/(11*a[x])+1;
 				int hi=(k*10)/(9*a[x]);
 				printf("%d %d\n",lo,hi);
 				if(lo<=hi){
 					sum[x][lo]+=1;
 					sum[x][hi+1]+=-1;
 				}
 			}
 			for(int y=1;y<=1100000;y++){
 				sum[x][y]+=sum[x][y-1];
 			}	
 			for(int y=1;y<=1100000;y++){
 				if(x) sum[x][y]=min(sum[x][y],sum[x-1][y]);
 			}	
 			printf("\n");
 		}
 		int ans=0;
 		for(int y=1;y<=1100000;y++) ans+=sum[n-1][y];
 		printf("Case #%d: %d\n",tc,ans);
 	}
 	return 0;	
 }
