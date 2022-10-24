#include <iostream>
 #include <vector>
 #include <string>
 #include <algorithm>
 #include <cstring>
 #include <cstdio>
 #include <stack>
 #include <queue>
 
 using namespace std;
 
 int dx[] = {-1, 0, 1, 0};
 int dy[] = {0, 1, 0, -1};
 
 int main(){
 	int T; cin >> T;
 	for(int test=1;test<=T;test++){
 		int R, C; cin >> R >> C;
 		vector<string> vs(R);
 		for(int i=0;i<R;i++) cin >> vs[i];
 		int res = 0;
 		for(int i=0;i<R;i++){
 			if(res == -1) break;
 			for(int j=0;j<C;j++){
 				if(res == -1) break;
 				if(vs[i][j] == '.') continue;
 				int dir = 0;
 				if(vs[i][j] == '^') dir = 0;
 				if(vs[i][j] == '>') dir = 1;
 				if(vs[i][j] == 'v') dir = 2;
 				if(vs[i][j] == '<') dir = 3;
 				int ok = 0;
 				for(int d=0;d<4;d++){
 					int x = i+dx[d], y = j+dy[d];
 					bool f = false;
 					while(0 <= x && x < R && 0 <= y && y < C){
 						if(vs[x][y] != '.') f = true;
 						x += dx[d];
 						y += dy[d];
 					}
 					if(f) ok |= (1<<d);
 				}
 				if((1<<dir)&ok) continue;
 				if(!ok) res = -1;
 				else ++res;
 			}
 		}
 		if(res != -1){
 			printf("Case #%d: %d\n", test, res);
 		} else {
 			printf("Case #%d: IMPOSSIBLE\n", test, res);
 		}
 	}
 }
