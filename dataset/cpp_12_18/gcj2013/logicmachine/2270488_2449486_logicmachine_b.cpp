#include <iostream>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 int main(){
 	int T;
 	cin >> T;
 	for(int caseNum = 1; caseNum <= T; ++caseNum){
 		int n, m;
 		cin >> n >> m;
 		vector< vector<int> > lawn(n, vector<int>(m));
 		for(int i = 0; i < n; ++i){
 			for(int j = 0; j < m; ++j){ cin >> lawn[i][j]; }
 		}
 		vector<bool> h_done(n), v_done(m);
 		int h_remains = n, v_remains = m;
 		while(h_remains > 0 && v_remains > 0){
 			int minval = 100;
 			for(int i = 0; i < n; ++i){
 				if(h_done[i]){ continue; }
 				for(int j = 0; j < m; ++j){
 					if(v_done[j]){ continue; }
 					minval = min(minval, lawn[i][j]);
 				}
 			}
 			bool modified = false;
 			for(int i = 0; i < n; ++i){
 				if(h_done[i]){ continue; }
 				bool accept = true;
 				for(int j = 0; accept && j < m; ++j){
 					if(v_done[j]){ continue; }
 					if(lawn[i][j] != minval){ accept = false; }
 				}
 				if(accept){
 					h_done[i] = true;
 					--h_remains;
 					modified = true;
 				}
 			}
 			for(int j = 0; j < m; ++j){
 				if(v_done[j]){ continue; }
 				bool accept = true;
 				for(int i = 0; accept && i < n; ++i){
 					if(h_done[i]){ continue; }
 					if(lawn[i][j] != minval){ accept = false; }
 				}
 				if(accept){
 					v_done[j] = true;
 					--v_remains;
 					modified = true;
 				}
 			}
 			if(!modified){ break; }
 		}
 		bool answer = (h_remains == 0 || v_remains == 0);
 		cout << "Case #" << caseNum << ": " << (answer ? "YES" : "NO") << endl;
 	}
 	return 0;
 }
 
