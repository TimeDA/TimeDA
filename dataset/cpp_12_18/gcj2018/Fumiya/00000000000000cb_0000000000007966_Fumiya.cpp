#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(int D, const string& P){
	vector<int> power(31, 0);
	int charge = 0;
	long long dmgSum = 0;
	for(char c : P){
		if(c == 'C'){
			++charge;
		} else {
			++power[charge];
			dmgSum += (1LL << charge);
		}
	}
	if(dmgSum <= D){ cout << 0 << endl; return; }
	int res = 0;
	for(int i=30;i>0;i--){
		while(power[i]){
			++res;
			--power[i];
			++power[i-1];
			dmgSum -= (1LL << (i-1));
			if(dmgSum <= D){ cout << res << endl; return; }
		}
	}
	cout << "IMPOSSIBLE" << endl;
}

int main(){
	int T; cin >> T;
	for(int i=1;i<=T;i++){
		printf("Case #%d: ", i);
		int D;
		string P;
		cin >> D >> P;
		solve(D, P);
	}
}
