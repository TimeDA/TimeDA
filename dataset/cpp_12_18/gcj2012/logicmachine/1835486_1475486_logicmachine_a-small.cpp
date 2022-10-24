#include <iostream>
 #include <vector>
 #include <string>
 #include <algorithm>
 #include <utility>
 
 using namespace std;
 typedef pair<int, int> pii;
 
 int main(){
 	int T;
 	cin >> T;
 	for(int caseNum = 1; caseNum <= T; ++caseNum){
 		int N;
 		cin >> N;
 		vector<int> L(N);
 		for(int i = 0; i < N; ++i){ cin >> L[i]; }
 		vector<int> P(N);
 		for(int i = 0; i < N; ++i){ cin >> P[i]; }
 		vector<pii> pp(N);
 		for(int i = 0; i < N; ++i){ pp[i] = pii(100 - P[i], i); }
 		sort(pp.begin(), pp.end());
 		cout << "Case #" << caseNum << ":";
 		for(int i = 0; i < N; ++i){
 			cout << " " << pp[i].second;
 		}
 		cout << endl;
 	}
 	return 0;
 }
