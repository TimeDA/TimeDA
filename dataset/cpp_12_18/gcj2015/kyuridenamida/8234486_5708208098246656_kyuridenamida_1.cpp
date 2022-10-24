#include <bits/stdc++.h>
 using namespace std;
 
 int putCase(){
 	static int n = 1;
 	cout << "Case #" << n++ << ": ";
 }
 struct NODE{
 	int x,y;
 };
 int dx[] = {-1,0,1,0};
 int dy[] = {0,1,0,-1};
 string d = "<v>^";
 char c[100][100];
 int l;
 int nextX[100][100][4];
 int nextY[100][100][4];
 int deg[100][100];
 int main(){
 	int T;
 	cin >> T;
 	while(T--){
 		memset(nextX,-1,sizeof(nextX));
 		memset(nextY,-1,sizeof(nextY));
 		memset(deg,0,sizeof(deg));
 		memset(c,0,sizeof(c));
 		int H,W;
 		cin >> H >> W;
 		for(int i = 0 ; i < H ; i++)
 			for(int j = 0 ; j < W ; j++)
 				cin >> c[i][j];
 		for(int i = 0 ; i < H ; i++){
 			for(int j = 0 ; j < W ; j++){
 				if( d.find(c[i][j]) == -1 ) continue;
 				for(int a = 0 ; a < 4 ; a++){
 					int x = j + dx[a], y = i + dy[a];
 					while( x >= 0 && y >= 0 && y < H && x < W && c[y][x] == '.'){
 						x += dx[a];
 						y += dy[a];
 					}
 					if( x >= 0 && y >= 0 && y < H && x < W && c[y][x] != '.'){
 						nextX[i][j][a] = x;
 						nextY[i][j][a] = y;
 					}
 				}
 			}
 		}
 		int flag = 0;
 		int ans = 0;
 		
 		int chg = 0;
 		while(true){
 			chg = 0;
 			for(int i = 0 ; i < H ; i++){
 				for(int j = 0 ; j < W ; j++){
 					if( d.find(c[i][j]) == -1 ) continue;
 					
 					int cnt = 0;
 					int id;
 					for(int a = 0 ; a < 4 ; a++){
 						if( nextX[i][j][a] == -1 ) cnt++;
 						else id = a;
 					}
 					if( cnt == 4 ) {
 						flag = 1;
 						break;
 					}
 					int a = d.find(c[i][j]);	
 					if( nextX[i][j][a] == -1 ){
 						c[i][j] = d[id];
 						ans++;
 						chg = 1;
 					}
 				}
 			}
 			if(!chg) break;
 		}
 		putCase();
 		if( flag ) cout << "IMPOSSIBLE" << endl;
 		else cout << ans << endl;
 				
 	}
 }