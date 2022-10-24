#include<cstdio>
 #include<iostream>
 #include<queue>
 #include<stack>
 #include<vector>
 #include<string>
 #include<algorithm>
 #include<map>
 #include<sstream>
 #include<cmath>
 #include<cctype>
 #include<cassert>
 #include<cstring>
 #include<cstdlib>
 
 using namespace std;
 
 const int debug = 0;
 #define DEBUG(x) cout<<">> "<<#x<<':'<<(x)<<endl
 const int inf = 1000000000;
 
 int main() {
 	int test, cases = 1;
 	cin >> test;
 	for (cases = 1; cases <= test; cases++) {
 		string s;
 		cin >> s;
 		int res = 0;
 		char last = '*';
 		for (int i = 0; i < s.size(); i++) {
 			if (s[i] != last) {
 				res++;
 				last = s[i];
 			}
 		}
 		if (last == '+') res--;
 		cout << "Case #" << cases << ": " << res << endl;
 	}
 	return 0;
 }
