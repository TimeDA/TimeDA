#include <iostream>
 #include <set>
 
 using namespace std;
 
 int main(){
 	int T;
 	cin >> T;
 	for(int caseNum = 1; caseNum <= T; ++caseNum){
 		int A, B;
 		cin >> A >> B;
 		int mask = 1, answer = 0;
 		for(int i = A; i > 0; i /= 10){ mask *= 10; }
 		for(int i = A; i <= B; ++i){
 			int p = i, q = i;
 			do {
 				q *= 10;
 				int msd = q / mask;
 				q %= mask;
 				p = ((p * 10) + msd) % mask;
 				if(i < p && p <= B){ ++answer; }
 			} while(p != i);
 		}
 		cout << "Case #" << caseNum << ": " << answer << endl;
 	}
 	return 0;
 }
 
