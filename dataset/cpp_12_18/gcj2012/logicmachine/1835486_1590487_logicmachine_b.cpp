#include <iostream>
 #include <vector>
 #include <map>
 #include <string>
 #include <queue>
 #include <algorithm>
 #include <cstring>
 
 using namespace std;
 typedef pair<int, int> pii;
 
 const int dx[] = { 1, 0, -1, -1, 0, 1 };
 const int dy[] = { 1, 1, 0, -1, -1, 0 };
 
 const int COLOR_MASK = 0x0000ffff;
 const int CORNER_BIT = 0x00010000;
 const int CORNER_MASK = 0x003f0000;
 const int EDGE_BIT = 0x01000000;
 const int EDGE_MASK = 0x3f000000;
 
 int field[6000][6000];
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int caseNum = 1; caseNum <= T; ++caseNum){
 		memset(field, -1, sizeof(field));
 		int S, M;
 		cin >> S >> M;
 		int maxColor = 0, step = 0, cause = 0;
 		while(cause == 0 && step < M){
 			++step;
 			int x, y;
 			cin >> x >> y;
 			int newColor = maxColor, newParams = 0;
 			if(x == 1 && y == 1){
 				newParams |= (CORNER_BIT << 0);
 			}else if(x == S && y == 1){
 				newParams |= (CORNER_BIT << 1);
 			}else if(x == S * 2 - 1 && y == S){
 				newParams |= (CORNER_BIT << 2);
 			}else if(x == S * 2 - 1 && y == S * 2 - 1){
 				newParams |= (CORNER_BIT << 3);
 			}else if(x == S && y == S * 2 - 1){
 				newParams |= (CORNER_BIT << 4);
 			}else if(x == 1 && y == S){
 				newParams |= (CORNER_BIT << 5);
 			}else if(y == 1){
 				newParams |= (EDGE_BIT << 0);
 			}else if(x - y == S - 1){
 				newParams |= (EDGE_BIT << 1);
 			}else if(x == S * 2 - 1){
 				newParams |= (EDGE_BIT << 2);
 			}else if(y == S * 2 - 1){
 				newParams |= (EDGE_BIT << 3);
 			}else if(y - x == S - 1){
 				newParams |= (EDGE_BIT << 4);
 			}else if(x == 1){
 				newParams |= (EDGE_BIT << 5);
 			}
 			int colors[6] = { -1, -1, -1, -1, -1, -1 };
 			for(int i = 0; i < 6; ++i){
 				int nx = x + dx[i], ny = y + dy[i];
 				if(nx < 1 || ny < 1){ continue; }
 				if(nx - ny >= S || ny - nx >= S){ continue; }
 				if(nx >= S * 2 || ny >= S * 2){ continue; }
 				if(field[nx][ny] == -1){ continue; }
 				int p = field[nx][ny];
 				newParams |= p & ~COLOR_MASK;
 				colors[i] = p & COLOR_MASK;
 				newColor = min(newColor, colors[i]);
 			}
 			for(int j = 0; j < 6; ++j){
 				int cmask = 0;
 				for(int i = 0; i < 6; ++i){
 					int nx = x + dx[i], ny = y + dy[i];
 					if(nx < 1 || ny < 1){ continue; }
 					if(nx - ny >= S || ny - nx >= S){ continue; }
 					if(nx >= S * 2 || ny >= S * 2){ continue; }
 					if((field[nx][ny] & COLOR_MASK) != colors[j]){ continue; }
 					cmask |= (1 << i);
 				}
 				if(cmask != 0x3f){
 					while(cmask & 1){ cmask = ((cmask << 1) | (cmask >> 5)) & 0x3f; }
 					int ringCheck = 0;
 					while(cmask != 0){
 						while((cmask & 1) == 0){ cmask >>= 1; }
 						while((cmask & 1) == 1){ cmask >>= 1; }
 						++ringCheck;
 					}
 					if(ringCheck >= 2){ cause |= 1; }
 				}
 			}
 			newParams |= newColor;
 			field[x][y] = newParams;
 			if(__builtin_popcount(newParams & CORNER_MASK) >= 2){ cause |= 2; }
 			if(__builtin_popcount(newParams & EDGE_MASK) >= 3){ cause |= 4; }
 			if(newColor == maxColor){ ++maxColor; }
 			queue<pii> q;
 			for(int i = 0; i < 6; ++i){
 				int nx = x + dx[i], ny = y + dy[i];
 				if(nx < 1 || ny < 1){ continue; }
 				if(nx - ny >= S || ny - nx >= S){ continue; }
 				if(nx >= S * 2 || ny >= S * 2){ continue; }
 				if(field[nx][ny] == -1){ continue; }
 				if(field[nx][ny] != newParams){
 					q.push(pii(nx, ny));
 					field[nx][ny] = newParams;
 				}
 			}
 			while(!q.empty()){
 				int x = q.front().first, y = q.front().second;
 				q.pop();
 				for(int i = 0; i < 6; ++i){
 					int nx = x + dx[i], ny = y + dy[i];
 					if(nx < 1 || ny < 1){ continue; }
 					if(nx - ny >= S || ny - nx >= S){ continue; }
 					if(nx >= S * 2 || ny >= S * 2){ continue; }
 					if(field[nx][ny] == -1){ continue; }
 					if(field[nx][ny] != newParams){
 						q.push(pii(nx, ny));
 						field[nx][ny] = newParams;
 					}
 				}
 			}
 /*for(int i = 1; i < S * 2; ++i){
 	for(int j = 1; j < S * 2; ++j){
 		cout << field[i][j] << " ";
 	}
 	cout << endl;
 }*/
 		}
 		for(int i = step; i < M; ++i){
 			int x, y;
 			cin >> x >> y;
 		}
 		cout << "Case #" << caseNum << ": ";
 		switch(cause){
 			case 0: cout << "none"; break;
 			case 1: cout << "ring"; break;
 			case 2: cout << "bridge"; break;
 			case 3: cout << "bridge-ring"; break;
 			case 4: cout << "fork"; break;
 			case 5: cout << "fork-ring"; break;
 			case 6: cout << "bridge-fork"; break;
 			case 7: cout << "bridge-fork-ring"; break;
 		}
 		if(cause != 0){
 			cout << " in move " << step;
 		}
 		cout << endl;
 	}
 	return 0;
 }
