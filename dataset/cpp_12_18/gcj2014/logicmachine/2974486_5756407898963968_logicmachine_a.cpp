#include <iostream>
 #include <algorithm>
 
 using namespace std;
 
 int read_set(){
 	int r, answer = 0;
 	cin >> r;
 	for(int i = 1; i <= 4; ++i){
 		for(int j = 0; j < 4; ++j){
 			int x;
 			cin >> x;
 			if(i == r){ answer |= (1 << x); }
 		}
 	}
 	return answer;
 }
 
 int main(){
 	int T;
 	cin >> T;
 	for(int caseNum = 1; caseNum <= T; ++caseNum){
 		const int a = read_set();
 		const int b = read_set();
 		const int c = a & b;
 		cout << "Case #" << caseNum << ": ";
 		if(c == 0){
 			cout << "Volunteer cheated!" << endl;
 		}else if(__builtin_popcount(c) != 1){
 			cout << "Bad magician!" << endl;
 		}else{
 			cout << __builtin_ctz(c) << endl;
 		}
 	}
 	return 0;
 }
 
