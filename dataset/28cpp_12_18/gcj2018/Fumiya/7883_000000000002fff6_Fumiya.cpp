#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

long long solve(){
	int R, C; long long B;
	cin >> R >> B >> C;
	vector<long long> M(C), S(C), P(C);
	for(int i=0;i<C;i++) cin >> M[i] >> S[i] >> P[i];
	long long low = 0, high = (1LL << 62);
	while(high - low > 1){
		long long mid = (low+high+1)/2;
		vector<int> cap(C);
		for(int i=0;i<C;i++){
			if(M[i]*S[i]+P[i] <= mid){
				cap[i] = M[i];
			} else {
				cap[i] = max(0LL, (mid - P[i])/S[i]);
			}
		}
		sort(cap.rbegin(), cap.rend());
		long long rest = B;
		for(int i=0;i<R;i++){
			rest -= cap[i];
			if(rest <= 0) break;
		}
		if(rest <= 0) high = mid;
		else          low = mid;
	}
	return high;
}

int main(){
	int T; cin >> T;
	for(int t=1;t<=T;t++){
		printf("Case #%d: %lld\n", t, solve());
	}
}

