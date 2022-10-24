#include <iostream>
 
 using namespace std;
 typedef long long ll;
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int caseNum = 1; caseNum <= T; ++caseNum){
 		ll N, P;
 		cin >> N >> P;
 		cout << "Case #" << caseNum << ": ";
 		if(P == 1){
 			cout << "0 0" << endl;
 		}else if((1ll << N) == P){
 			cout << (1ll << N) - 1 << " " << (1ll << N) - 1 << endl;
 		}else{
 			ll y_team = 0, y_score = 0;
 			for(ll i = (1ll << (N - 1)), j = 2; i > 0; i >>= 1, j <<= 1){
 				if(y_score + i >= P){ break; }
 				y_team += j;
 				y_score += i;
 			}
 			ll z_team = (1ll << N) - 2, z_score = (1ll << N) - 1;
 			for(ll i = (1ll << (N - 1)), j = 2; i > 0; i >>= 1, j <<= 1){
 				if(z_score - i < P){ break; }
 				z_team -= j;
 				z_score -= i;
 			}
 			cout << y_team << " " << z_team << endl;
 		}
 	}
 	return 0;
 }
 
