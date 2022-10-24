#include <bits/stdc++.h>
 using namespace std;
 int t,r,c;
 char grid[30][30];
 string ans[30];
 int main(){
 	scanf("%d",&t);
 	for(int tc=1;tc<=t;tc++){
 		printf("Case #%d:\n",tc);
 		int anscurr=-1;
 		scanf("%d %d",&r,&c);
 		for(int x=0;x<r;x++){
 			scanf("%s",grid[x]);
 			int curr=-1;
 			for(int y=0;y<c;y++){
 				if(grid[x][y]>='A'&&grid[x][y]<='Z'){
 					curr=y;
 					break;
 				}
 			}
 			ans[x]="";
 			if(curr>=0){
 				for(int y=0;y<c;y++){
 					if(grid[x][y]>='A'&&grid[x][y]<='Z') curr=y;
 					ans[x]+=grid[x][curr];
 				}
 				if(anscurr==-1) anscurr=x;
 			}
 		}
 		for(int x=0;x<r;x++){
 			if(ans[x]!="") anscurr=x;
 			printf("%s\n",ans[anscurr].c_str());
 		}
 	}
 	return 0;
 }
