#include <iostream>
 #include <vector>
 #include <string>
 #include <algorithm>
 #include <cstring>
 #include <cstdio>
 #include <stack>
 #include <queue>
 
 using namespace std;
 
 int river[1000][4000];
 int dx[] = {1, 0, -1, 0};
 int dy[] = {0, 1, 0, -1};
 
 int main(){
 	int T; cin >> T;
 	for(int test=1;test<=T;test++){
 		int W, H, B; cin >> W >> H >> B;
 		memset(river, 0, sizeof(river));
 		for(int i=0;i<B;i++){
 			int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
 			for(int j=x1;j<=x2;j++){
 				for(int k=y1;k<=y2;k++){
 					river[j][k] = -1;
 				}
 			}
 		}
 		int res = 0;
 		for(int i=0;i<W;i++){
 			if(river[i][0]==-1) continue;
 			int x = i, y = 0, dir = 1;
 			while(true){
 				if(river[x][y]&(1<<dir)) break;
 				river[x][y] |= 1<<dir;
 				if(y == H-1){ res++; break; }
 				for(int j=0;j<4;j++){
 					int ndir = (dir+5-j)%4;
 					int nx = x+dx[ndir];
 					int ny = y+dy[ndir];
 					if(nx < 0 || W <= nx || ny < 0 || H <= ny || river[nx][ny]==-1) continue;
 					x = nx, y = ny, dir = ndir;
 					break;
 				}
 			}
 			for(int j=0;j<W;j++)
 				for(int k=0;k<H;k++)
 					if(river[j][k]) river[j][k] = -1;
 		}
 		printf("Case #%d: %d\n", test, res);
 	}
 }
