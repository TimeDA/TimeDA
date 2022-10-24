#include <iostream>
 #include <vector>
 #include <algorithm>
 #include <iomanip>
 #include <utility>
 
 using namespace std;
 typedef pair<double, double> pdd;
 
 const double EPS = 1e-6;
 double pow2(double x){ return x * x; }
 
 unsigned int xor128(){ 
 	static unsigned int x = 123456789;
 	static unsigned int y = 362436069;
 	static unsigned int z = 521288629;
 	static unsigned int w = 88675123; 
 	unsigned int t;
 	t = x ^ (x << 11);
 	x = y; y = z; z = w;
 	return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
 }
 
 int main(){
 	cout << setiosflags(ios::fixed) << setprecision(7);
 	int T;
 	cin >> T;
 	for(int caseNum = 1; caseNum <= T; ++caseNum){
 		int N, W, L;
 		cin >> N >> W >> L;
 		vector<int> ir(N);
 		for(int i = 0; i < N; ++i){ cin >> ir[i]; }
 		vector<int> r = ir;
 		sort(r.begin(), r.end(), greater<int>());
 		vector<pdd> answer(N);
 		for(int i = 0; i < N; ++i){
 			while(true){
 				double x = static_cast<double>(W) * xor128() / 0xfffffffful;
 				double y = static_cast<double>(L) * xor128() / 0xfffffffful;
 				bool ok = true;
 				for(int j = 0; j < i; ++j){
 					double d = pow2(x - answer[j].first) + pow2(y - answer[j].second);
 					double d0 = pow2(r[i] + r[j] + EPS);
 					if(d < d0){ ok = false; break; }
 				}
 				if(ok){
 					answer[i] = pdd(x, y);
 					break;
 				}
 			}
 		}
 		cout << "Case #" << caseNum << ":";
 		for(int i = 0; i < N; ++i){
 			for(int j = 0; j < N; ++j){
 				if(ir[i] == r[j]){
 					r[j] = -1;
 					cout << " " << answer[j].first << " " << answer[j].second;
 					break;
 				}
 			}
 		}
 		cout << endl;
 	}
 	return 0;
 }