#include <iostream>
 #include <string>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	const int goal = (1 << 10) - 1;
 	int T;
 	cin >> T;
 	for(int case_num = 1; case_num <= T; ++case_num){
 		int n;
 		cin >> n;
 		if(n == 0){
 			cout << "Case #" << case_num << ": INSOMNIA" << endl;
 			continue;
 		}
 		int status = 0, x = n;
 		while(true){
 			int y = x;
 			while(y > 0){
 				status |= (1 << (y % 10));
 				y /= 10;
 			}
 			if(status == goal){ break; }
 			x += n;
 		}
 		cout << "Case #" << case_num << ": " << x << endl;
 	}
 	return 0;
 }
 
