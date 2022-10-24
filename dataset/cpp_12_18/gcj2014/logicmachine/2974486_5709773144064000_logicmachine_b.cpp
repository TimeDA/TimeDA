#include <iostream>
 #include <iomanip>
 #include <limits>
 
 using namespace std;
 
 int main(){
 	int T;
 	cin >> T;
 	cout << setiosflags(ios::fixed) << setprecision(7);
 	for(int caseNum = 1; caseNum <= T; ++caseNum){
 		double c, f, x;
 		cin >> c >> f >> x;
 		double speed = 2.0, time = 0.0;
 		double answer = x / speed;
 		while(time < answer){
 			const double t = c / speed;
 			speed += f;
 			time += t;
 			answer = min(answer, time + x / speed);
 		}
 		cout << "Case #" << caseNum << ": " << answer << endl;
 	}
 	return 0;
 }
 
