#include <iostream>
 #include <string>
 
 using namespace std;
 
 int main(void) {
 	
 	int tc;
 	cin >> tc;
 	
 	for (int t = 1; t <= tc; t++) {
 		int k, c, s;
 		cin >> k >> c >> s;
 		cout << "Case #" << t << ":";
 		for (int i = 0; i < k; i++) cout << ' ' << i + 1;
 		cout << endl;
 	}
 	
 	return 0;
 }
