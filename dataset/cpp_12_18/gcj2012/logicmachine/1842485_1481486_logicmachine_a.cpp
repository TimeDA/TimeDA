#include <iostream>
 #include <vector>
 #include <map>
 #include <algorithm>
 
 using namespace std;
 typedef pair<int, int> pii;
 
 int main(){
 	int T;
 	cin >> T;
 	for(int caseNum = 1; caseNum <= T; ++caseNum){
 		int N;
 		cin >> N;
 		vector<pii> vines;
 		int d0, l0;
 		for(int i = 0; i < N; ++i){
 			int d, l;
 			cin >> d >> l;
 			if(i == 0){
 				d0 = d;
 				l0 = l;
 			}else if(d > d0){
 				vines.push_back(pii(d, l));
 			}
 		}
 		int D;
 		cin >> D;
 		if(D <= d0 * 2){
 			cout << "Case #" << caseNum << ": YES" << endl;
 		}else{
 			sort(vines.begin(), vines.end());
 			vector<int> maxlen(vines.size());
 			int reached = 0;
 			for(int i = 0; i < vines.size(); ++i){
 				if(vines[i].first > d0 * 2){ break; }
 				maxlen[i] = min(vines[i].first - d0, vines[i].second);
 				++reached;
 			}
 			for(int i = 0; i < vines.size(); ++i){
 				if(i >= reached){ break; }
 				int d = vines[i].first, l = maxlen[i];
 				while(reached < vines.size()){
 					if(vines[reached].first > d + l){ break; }
 					maxlen[reached] =
 						min(vines[reached].first - d, vines[reached].second);
 					++reached;
 				}
 			}
 			bool answer = false;
 			for(int i = 0; i < reached; ++i){
 				if(vines[i].first + maxlen[i] >= D){
 					answer = true;
 				}
 			}
 			cout << "Case #" << caseNum << ": " << (answer ? "YES" : "NO") << endl;
 		}
 	}
 	return 0;
 }
