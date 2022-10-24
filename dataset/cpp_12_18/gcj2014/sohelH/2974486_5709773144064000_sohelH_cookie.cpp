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
 		double C, F, X;
 		cin >> C >> F >> X;
 
 		double res = X / 2;
 
 		int cnt = 1000000;
 		int multiple = 0;
 		double tm = 0;
 		while (cnt--) {
 			tm += C / (2.0 + F * multiple);
 			res = min(res, tm + X / (F*(multiple+1) + 2));
 			//cout << tm + X / (F*(multiple+1) + 2) << endl;
 			multiple++;
 		}
 		printf("Case #%d: %.7lf\n", cases, res);
 	}
 	return 0;
 }
