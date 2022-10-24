#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

inline int iround(int x, int n){
	const int t = 200 * x / n;
	return (t + (t % 2)) / 2;
}

void solve(){
	int n, l;
	cin >> n >> l;
	vector<int> a(n);
	for(int i = 0; i < l; ++i){ cin >> a[i]; }
	int k = 1;
	for(; k < n; ++k){
		if((200 * k / n) % 2 == 1){ break; }
	}
	int sum = 0, rem = n;
	vector<int> b(n);
	for(int i = 0; i < n; ++i){
		const int x = a[i];
		if((200 * x / n) % 2 == 1){
			b[i] = 0;
		}else{
			int lo = 0, hi = k;
			while(lo < hi){
				const int c = lo + (hi - lo) / 2;
				if((200 * (x + c) / n) % 2 == 0){
					lo = c + 1;
				}else{
					hi = c;
				}
			}
			b[i] = lo;
		}
		sum += 100 * x / n;
		rem -= x;
	}
	sort(b.begin(), b.end());
	for(int i = 0; i < n; ++i){
		if(b[i] <= rem){
			rem -= b[i];
			sum += 100 * b[i] / n + 1;
		}
	}
	sum += 100 * rem / n;
	cout << sum << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int case_num = 1; case_num <= T; ++case_num){
		cout << "Case #" << case_num << ": ";
		solve();
	}
	return 0;
}

