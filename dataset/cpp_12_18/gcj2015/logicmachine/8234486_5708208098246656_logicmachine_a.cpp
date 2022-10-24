#include <iostream>
 #include <string>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 static const int dx[] = { 1, 0, -1, 0 };
 static const int dy[] = { 0, -1, 0, 1 };
 inline int c2d(const int c){
 	switch(c){
 		case '>': return 0;
 		case '^': return 1;
 		case '<': return 2;
 		case 'v': return 3;
 	}
 	return -1;
 }
 inline bool between(int a, int b, int c){
 	return a <= b && b < c;
 }
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int case_num = 1; case_num <= T; ++case_num){
 		int n, m;
 		cin >> n >> m;
 		vector<string> field(n);
 		for(int i = 0; i < n; ++i){ cin >> field[i]; }
 		bool possible = true;
 		int answer = 0;
 		for(int i = 0; i < n; ++i){
 			for(int j = 0; j < m; ++j){
 				if(field[i][j] == '.'){ continue; }
 				int flags = 0;
 				for(int d = 0; d < 4; ++d){
 					int y = i + dy[d], x = j + dx[d];
 					while(between(0, y, n) && between(0, x, m)){
 						if(c2d(field[y][x]) >= 0){
 							flags |= (1 << d);
 							break;
 						}
 						y += dy[d]; x += dx[d];
 					}
 				}
 				if(flags == 0){ possible = false; }
 				if((flags & (1 << c2d(field[i][j]))) == 0){
 					++answer;
 				}
 			}
 		}
 		cout << "Case #" << case_num << ": ";
 		if(!possible){
 			cout << "IMPOSSIBLE" << endl;
 		}else{
 			cout << answer << endl;
 		}
 	}
 	return 0;
 }
 
