#include <iostream>
 #include <string>
 
 using namespace std;
 
 int main(void) {
 	
 	int tc;
 	cin >> tc;
 	
 	for (int t = 1; t <= tc; t++) {
 		string str;
 		cin >> str;
 		int cnt = 1;
 		for (int i = 1; i < str.size(); i++) {
 			if (str[i] != str[i - 1]) cnt++;
 		}
 		int ans = cnt - 1;
 		if (str[0] == '+') cnt++;
 		ans += cnt % 2;
 		cout << "Case #" << t << ": " << ans << endl;
 	}
 	
 	return 0;
 }
