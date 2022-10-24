#include <iostream>
 #include <string>
 #include <vector>
 
 using namespace std;
 
 int main(){
 	int T;
 	cin >> T;
 	for(int caseNum = 1; caseNum <= T; ++caseNum){
 		int r, c, m;
 		cin >> r >> c >> m;
 		const int e = r * c - m;
 		vector<string> result(r, string(c, '.'));
 		if(e == 1){
 			for(int i = 0; i < r; ++i){ result[i] = string(c, '*'); }
 			result[0][0] = 'c';
 		}else if(r == 1){
 			for(int i = e; i < c; ++i){ result[0][i] = '*'; }
 			result[0][0] = 'c';
 		}else if(c == 1){
 			for(int i = e; i < r; ++i){ result[i][0] = '*'; }
 			result[0][0] = 'c';
 		}else{
 			bool done = false;
 			result.assign(r, string(c, '*'));
 			for(int h = 2; !done && h <= r; ++h){
 				for(int w = 2; !done && w <= c; ++w){
 					if(w * h > e){ continue; }
 					const int remains = e - w * h;
 					int right = 0, bottom = 0;
 					if(w * h == e){
 						done = true;
 					}else if(remains != 1 && remains <= w + h){
 						if(h == r){
 							if(remains <= h){ done = true; right = remains; }
 						}else if(w == c){
 							if(remains <= w){ done = true; bottom = remains; }
 						}else{
 							if(remains <= h){
 								done = true;
 								right = remains;
 							}else if(remains == h + 1){
 								done = true;
 								right = remains - 2;
 								bottom = 2;
 							}else{
 								done = true;
 								right = h;
 								bottom = remains - h;
 							}
 						}
 					}
 					if(done){
 						for(int i = 0; i < h; ++i){
 							for(int j = 0; j < w; ++j){
 								result[i][j] = '.';
 							}
 						}
 						for(int i = 0; i < right; ++i){
 							result[i][w] = '.';
 						}
 						for(int i = 0; i < bottom; ++i){
 							result[h][i] = '.';
 						}
 						result[0][0] = 'c';
 					}
 				}
 			}
 		}
 		cout << "Case #" << caseNum << ":" << endl;
 		if(result[0][0] != 'c'){
 			cout << "Impossible" << endl;
 		}else{
 			for(int i = 0; i < r; ++i){ cout << result[i] << endl; }
 		}
 	}
 	return 0;
 }
 
