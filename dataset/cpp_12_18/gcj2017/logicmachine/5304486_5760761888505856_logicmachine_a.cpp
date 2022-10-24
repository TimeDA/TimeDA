#include <iostream>
 #include <string>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int case_num = 1; case_num <= T; ++case_num){
 		int n, m;
 		cin >> n >> m;
 		vector<string> input(n);
 		for(int i = 0; i < n; ++i){ cin >> input[i]; }
 		vector<string> result(input);
 		while(true){
 			bool modified = false;
 			for(int c = 'A'; c <= 'Z'; ++c){
 				int ymin = n, ymax = 0, xmin = m, xmax = 0;
 				for(int i = 0; i < n; ++i){
 					for(int j = 0; j < m; ++j){
 						if(result[i][j] != c){ continue; }
 						ymin = min(ymin, i);
 						ymax = max(ymax, i + 1);
 						xmin = min(xmin, j);
 						xmax = max(xmax, j + 1);
 					}
 				}
 				if(xmin >= xmax || ymin >= ymax){ continue; }
 				bool l = (xmin > 0), r = (xmax < m), u = (ymin > 0), d = (ymax < n);
 				for(int j = xmin; j < xmax; ++j){
 					if(u && result[ymin - 1][j] != '?'){ u = false; }
 					if(d && result[ymax][j] != '?'){ d = false; }
 				}
 				if(u){ --ymin; }
 				if(d){ ++ymax; }
 				for(int i = ymin; i < ymax; ++i){
 					if(l && result[i][xmin - 1] != '?'){ l = false; }
 					if(r && result[i][xmax] != '?'){ r = false; }
 				}
 				if(l){ --xmin; }
 				if(r){ ++xmax; }
 				modified = (modified || l || r || u || d);
 				for(int i = ymin; i < ymax; ++i){
 					for(int j = xmin; j < xmax; ++j){ result[i][j] = c; }
 				}
 			}
 			if(!modified){ break; }
 		}
 		cout << "Case #" << case_num << ":" << endl;
 		for(int i = 0; i < n; ++i){ cout << result[i] << endl; }
 	}
 	return 0;
 }
 
