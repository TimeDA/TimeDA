#include <cstdio>
 using namespace std;
 int dx[]={0,0,1,-1};
 int dy[]={1,-1,0,0};
 int t,r,c;
 char grid[105][105];
 int search(int x, int y, int d){
 	while(1){
 		x-=dx[d];
 		y-=dy[d];
 		if(x<0||x>=r||y<0||y>=c) return 0;
 		if(grid[x][y]!='.') return 1;
 	}
 	return 0;
 }
 int main(){
 	scanf("%d",&t);
 	for(int a=1;a<=t;a++){
 		printf("Case #%d: ",a);
 		bool fail=0;
 		int ans=0;
 		scanf("%d %d",&r,&c);
 		for(int x=0;x<r;x++) scanf("%s",grid[x]);
 		for(int x=0;x<r;x++){
 			for(int y=0;y<c;y++){
 				if(grid[x][y]!='.'){
 					if(grid[x][y]=='^'){
 						if(search(x,y,2)) continue;
 						else{
 							ans++;
 							for(int d=0;d<4;d++){
 								if(search(x,y,d)) break;
 								if(d==3) fail=1;
 							}
 							if(fail) break;
 						}
 					}
 					else if(grid[x][y]=='v'){
 						if(search(x,y,3)) continue;
 						else{
 							ans++;
 							for(int d=0;d<4;d++){
 								if(search(x,y,d)) break;
 								if(d==3) fail=1;
 							}
 							if(fail) break;
 						}
 					}
 					else if(grid[x][y]=='<'){
 						if(search(x,y,0)) continue;
 						else{
 							ans++;
 							for(int d=0;d<4;d++){
 								if(search(x,y,d)) break;
 								if(d==3) fail=1;
 							}
 							if(fail) break;
 						}
 					}
 					else if(grid[x][y]=='>'){
 						if(search(x,y,1)) continue;
 						else{
 							ans++;
 							for(int d=0;d<4;d++){
 								if(search(x,y,d)) break;
 								if(d==3) fail=1;
 							}
 							if(fail) break;
 						}
 					}
 				}
 			}
 			if(fail) break;
 		}
 		printf(fail?"IMPOSSIBLE\n":"%d\n",ans);
 	}	
 	return 0;
 }
