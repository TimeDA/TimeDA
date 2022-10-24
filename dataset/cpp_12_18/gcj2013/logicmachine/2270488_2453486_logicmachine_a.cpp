#include <iostream>
 #include <string>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 const char *MESSAGES[] = {
 	"X won", "O won", "Draw", "Game has not completed"
 };
 
 int main(){
 	int T = 0;
 	cin >> T;
 	for(int caseNum = 1; caseNum <= T; ++caseNum){
 		vector<string> field(4);
 		for(int i = 0; i < 4; ++i){ cin >> field[i]; }
 		int answer = -1;
 		for(int i = 0; i < 4; ++i){
 			bool xh_flag = true, oh_flag = true;
 			bool xv_flag = true, ov_flag = true;
 			for(int j = 0; j < 4; ++j){
 				if(field[i][j] != 'X' && field[i][j] != 'T'){ xh_flag = false; }
 				if(field[i][j] != 'O' && field[i][j] != 'T'){ oh_flag = false; }
 				if(field[j][i] != 'X' && field[j][i] != 'T'){ xv_flag = false; }
 				if(field[j][i] != 'O' && field[j][i] != 'T'){ ov_flag = false; }
 			}
 			if(xh_flag || xv_flag){ answer = 0; }
 			if(oh_flag || ov_flag){ answer = 1; }
 		}
 		bool xd0_flag = true, od0_flag = true;
 		bool xd1_flag = true, od1_flag = true;
 		for(int i = 0; i < 4; ++i){
 			if(field[i][i] != 'X' && field[i][i] != 'T'){ xd0_flag = false; }
 			if(field[i][i] != 'O' && field[i][i] != 'T'){ od0_flag = false; }
 			if(field[3 - i][i] != 'X' && field[3 - i][i] != 'T'){ xd1_flag = false; }
 			if(field[3 - i][i] != 'O' && field[3 - i][i] != 'T'){ od1_flag = false; }
 		}
 		if(xd0_flag || xd1_flag){ answer = 0; }
 		if(od0_flag || od1_flag){ answer = 1; }
 		if(answer < 0){
 			bool finished = true;
 			for(int i = 0; i < 4; ++i){
 				for(int j = 0; j < 4; ++j){
 					if(field[i][j] == '.'){ finished = false; }
 				}
 			}
 			answer = (finished ? 2 : 3);
 		}
 		cout << "Case #" << caseNum << ": " << MESSAGES[answer] << endl;
 	}
 	return 0;
 }
 
