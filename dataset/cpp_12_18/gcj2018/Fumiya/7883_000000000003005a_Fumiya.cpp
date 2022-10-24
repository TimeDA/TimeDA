#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

bool solve(){
	int R, C, H, V;
	cin >> R >> C >> H >> V;
	vector<string> w(R);
	for(int i=0;i<R;i++) cin >> w[i];
	vector< vector<int> > num(R, vector<int>(C+1, 0));
	int chocoNum = 0;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(w[i][j] == '@') ++chocoNum;
			num[i][j+1] = num[i][j] + (w[i][j] == '@' ? 1 : 0);
		}
	}
	if(chocoNum == 0) return true;
	if(chocoNum % ((H+1)*(V+1))) return false;
	vector<int> rowOwner(R, -1);
	int idx = 0;
	int rowTarget = chocoNum / (H+1);
	int sum = 0;
	for(int i=0;i<R;i++){
		sum += num[i][C];
		rowOwner[i] = idx;
		if(sum == rowTarget){
			++idx;
			sum = 0;
		} else {
			if(sum > rowTarget) return false;
		}
	}
	vector<int> colSum(H+1, 0);
	int target = chocoNum / (H+1) / (V+1);
	for(int i=0;i<C;i++){
		for(int j=0;j<R;j++){
			if(rowOwner[j] == -1) continue;
			colSum[rowOwner[j]] += (w[j][i] == '@' ? 1 : 0);
		}
		bool ok = true;
		for(int j=0;j<H+1;j++){
			if(colSum[j] > target) return false;
			if(colSum[j] < target) ok = false;
		}
		if(ok){
			for(int& t : colSum) t = 0;
		}
	}
	return true;
}

int main(){
	int T; cin >> T;
	for(int t=1;t<=T;t++){
		printf("Case #%d: %s\n", t, solve() ? "POSSIBLE" : "IMPOSSIBLE");
	}
}
