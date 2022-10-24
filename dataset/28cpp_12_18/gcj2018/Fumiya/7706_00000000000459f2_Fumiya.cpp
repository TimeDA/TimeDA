#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

vector<string> solve(const vector<int>& B){
	const int C = B.size();
	vector<int> assign(C);
	if(B[0] == 0 || B.back() == 0) return vector<string>();
	vector<int> rest = B;
	for(int i=0;i<C;i++){
		for(int j=0;j<C;j++){
			if(rest[j] > 0){
				assign[i] = j;
				--rest[j];
				break;
			}
		}
	}
	int line = 0;
	for(int i=0;i<C;i++) line = max(line, abs(assign[i] - i));
	vector<string> res(line + 1, string(C, '.'));
	int used = 0;
	for(int i=0;i<C;i++){
		if(B[i] == 0) continue;
		int left = used;
		int right = used+B[i]-1;
		for(int j=1;i-j>=left;j++){
			res[line-j][i-j] = '\\';
		}
		for(int j=1;i+j<=right;j++){
			res[line-j][i+j] = '/';
		}
		used += B[i];
	}
	return res;
}

int main(){
	int T; cin >> T;
	for(int t=1;t<=T;t++){
		int C; cin >> C;
		vector<int> B(C);
		for(auto& t : B) cin >> t;
		vector<string> result = solve(B);
		printf("Case #%d: ", t);
		if(result.empty()){
			printf("IMPOSSIBLE\n");
		} else {
			printf("%d\n", result.size());
			for(auto& s : result) cout << s << endl;
		}
	}
}
