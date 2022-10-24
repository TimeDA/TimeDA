#include <iostream>
 #include <string>
 #include <vector>
 #include <set>
 #include <algorithm>
 
 using namespace std;
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int caseNum = 1; caseNum <= T; ++caseNum){
 		int n, x;
 		cin >> n >> x;
 		vector<int> a(n);
 		for(int i = 0; i < n; ++i){ cin >> a[i]; }
 		sort(a.begin(), a.end());
 		int answer = 0;
 		while(!a.empty()){
 			vector<int>::iterator it =
 				upper_bound(a.begin(), a.end(), x - a[0]);
 			int k = 0;
 			if(it != a.begin()){ k = it - a.begin() - 1; }
 			int tail = 0;
 			for(int i = 1; i < a.size(); ++i){
 				if(i != k){ a[tail++] = a[i]; }
 			}
 			a.resize(tail);
 			++answer;
 		}
 		cout << "Case #" << caseNum << ": " << answer << endl;
 	}
 	return 0;
 }
 
