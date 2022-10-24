#include<stdio.h>
 #include<algorithm>
 int main(){
 	int i,j,k;
 	int T,TN;
 	scanf("%d",&TN);
 	for(T=1;T<=TN;T++){
 		int n,m;
 		scanf("%d%d",&n,&m);
 		char map[101][101];
 		bool used[101][101]={{false}};
 		for(i=0;i<n;i++)scanf("%s",map[i]);
 		k=0;
 		for(i=0;i<n;i++){
 			for(j=0;j<m;j++){
 				int x=i,y=j;
 				int tt=n*m+10,ttt=0;
 				int lastx=i,lasty=j;
 				int dir=0;
 				while(tt--){
 					if(map[x][y]=='.'){
 						if(!dir){
 							tt=-1;
 							break;
 						}
 					} else {
 						lastx=x;
 						lasty=y;
 					}
 					if(map[x][y]=='<'){
 						dir=1;
 					} else if(map[x][y]=='>'){
 						dir=2;
 					} else if(map[x][y]=='^'){
 						dir=3;
 					} else if(map[x][y]=='v'){
 						dir=4;
 					}
 					if(dir==1){
 						if(y==0) break;
 						y--;
 					} else if(dir==2){
 						if(y==m-1)break;
 						y++;
 					} else if(dir==3){
 						if(x==0)break;
 						x--;
 					} else if(dir==4){
 						if(x==n-1)break;
 						x++;
 					}
 					ttt++;
 				}
 				if(tt<=0)continue;
 				int p;
 				for(p=0;p<n;p++){
 					if(p!=lastx&&map[p][lasty]!='.')break;
 				}
 				if(p<n){
 					used[lastx][lasty]=1;
 					continue;
 				}
 				for(p=0;p<m;p++){
 					if(p!=lasty&&map[lastx][p]!='.')break;
 				}
 				if(p<m){
 					used[lastx][lasty]=1;
 					continue;
 				}
 				k=-1;
 			}
 		}
 		if(k>=0){
 			k=0;
 			for(i=0;i<n;i++){
 				for(j=0;j<m;j++){
 					if(used[i][j])k++;
 				}
 			}
 			printf("Case #%d: %d\n",T,k);
 		} else {
 			printf("Case #%d: IMPOSSIBLE\n",T);
 		}
 	}
 }
