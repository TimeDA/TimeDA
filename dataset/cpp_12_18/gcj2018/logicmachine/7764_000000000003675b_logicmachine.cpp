#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> d(n), a(n), b(n);
	for(int i = 0; i < n; ++i){ cin >> d[i] >> a[i] >> b[i]; }
	vector<int> a_head(n), a_tail(n), b_head(n), b_tail(n);
	a_head[0] = b_head[0] = 0;
	for(int i = 1; i < n; ++i){
		a_head[i] = (d[i - 1] + a[i - 1] == d[i] + a[i]) ? a_head[i - 1] : i;
		b_head[i] = (d[i - 1] - b[i - 1] == d[i] - b[i]) ? b_head[i - 1] : i;
	}
	a_tail[n - 1] = b_tail[n - 1] = n;
	for(int i = n - 2; i >= 0; --i){
		a_tail[i] = (d[i + 1] + a[i + 1] == d[i] + a[i]) ? a_tail[i + 1] : (i + 1);
		b_tail[i] = (d[i + 1] - b[i + 1] == d[i] - b[i]) ? b_tail[i + 1] : (i + 1);
	}
	vector<int> length_table(n);
	for(int i = 0; i < n; ++i){
		if(a_head[i] != i){ continue; }
		int len = 0;
		if(a_tail[i] == n){
			len = n - i;
		}else if(b_head[a_tail[i]] <= i){
			len = 0;
		}else{
			const int j = a_tail[i];
			if(i == 0 || d[i - 1] - b[i - 1] != d[j] - b[j]){
				int k = b_tail[j];
				while(k < n){
					if(d[k] + a[k] == d[i] + a[i]){
						k = a_tail[k];
					}else if(d[k] - b[k] == d[j] - b[j]){
						k = b_tail[k];
					}else{
						break;
					}
				}
				len = k - i;
			}
		}
		length_table[i] = max(length_table[i], len);
	}
	for(int i = 0; i < n; ++i){
		if(b_head[i] != i){ continue; }
		int len = 0;
		if(b_tail[i] == n){
			len = n - i;
		}else if(a_head[b_tail[i]] <= i){
			len = 0;
		}else{
			const int j = b_tail[i];
			if(i == 0 || d[i - 1] + a[i - 1] != d[j] + a[j]){
				int k = a_tail[j];
				while(k < n){
					if(d[k] + a[k] == d[j] + a[j]){
						k = a_tail[k];
					}else if(d[k] - b[k] == d[i] - b[i]){
						k = b_tail[k];
					}else{
						break;
					}
				}
				len = k - i;
			}
		}
		length_table[i] = max(length_table[i], len);
	}
	const int max_len = *max_element(length_table.begin(), length_table.end());
	const int num_sol = count(length_table.begin(), length_table.end(), max_len);
	cout << max_len << " " << num_sol << endl;
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

