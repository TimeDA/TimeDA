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
 
 int main() {
 	int test, cases = 1;
 	cin >> test;
 	for (cases = 1; cases <= test; cases++) {
 		int res1; cin >> res1; res1--;
 		vector< vector<int> > grid1;
 		for (int i = 0; i < 4; i++) {
 			vector<int> row;
 			for (int j = 0; j < 4; j++) {
 				int a; cin >> a; row.push_back(a);
 			}
 			grid1.push_back(row);
 		}
 
 		int res2; cin >> res2; res2--;
 		vector< vector<int> > grid2;
 		for (int i = 0; i < 4; i++) {
 			vector<int> row;
 			for (int j = 0; j < 4; j++) {
 				int a; cin >> a; row.push_back(a);
 			}
 			grid2.push_back(row);
 		}
 
 		int possible[17] = {0};
 		for (int i = 0; i < 4; i++) {
 			possible[ grid1[res1][i] ]++;
 			possible[ grid2[res2][i] ]++;
 		}
 		int two = 0, res = -1;
 		for (int i = 1; i <= 16; i++)
 			if (possible[i] == 2) two++, res = i;
 
 		cout << "Case #" << cases << ": ";
 		if (two == 1) cout << res << endl;
 		else if (two > 1) cout << "Bad magician!" << endl;
 		else cout << "Volunteer cheated!" << endl;
 	}
 	return 0;
 }
