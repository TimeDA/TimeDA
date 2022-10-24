/*
 * Google Code Jam 2014
 * @author: Sohel Hafiz
 */
 
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
 		int n; cin >> n;
 		vector<double> p1, p2;
 		for (int i = 0; i < n; i++) {
 			double a; cin >> a; p1.push_back(a);
 		}
 		for (int i = 0; i < n; i++) {
 			double a; cin >> a; p2.push_back(a);
 		}
 		sort(p1.begin(), p1.end());
 		sort(p2.begin(), p2.end());
 		vector<double> pp2 = p2;
 		int answer1 = 0, answer2 = n;
 		for (int i = 0; i < n; i++) {
 			if (p1[i] > pp2[0]) {
 				answer1++;
 				pp2.erase(pp2.begin());
 			}
 			else {
 				pp2.pop_back();
 			}
 		}
 		sort(p2.begin(), p2.end());
 		for (int i = 0; i < n; i++) {
 			for (int j = 0; j < n; j++) {
 				if (p2[j] > p1[i]) {
 					answer2--;
 					p2[j] = -1;
 					break;
 			 	}
 			}
 		}
 		printf("Case #%d: %d %d\n", cases, answer1, answer2);
 	}
 	return 0;
 }
