#include <iostream>
 #include <iomanip>
 #include <string>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 typedef long long ll;
 
 template <typename Function>
 int ternary_search(int l, int r, const Function &f){
 	while(l < r){
 		const int delta = (r - l);
 		const int cl = l + delta / 3, cr = l + 2 * delta / 3;
 		if(f(cl) <= f(cr)){
 			r = cr;
 		}else{
 			l = cl + 1;
 		}
 	}
 	return l;
 }
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	cout << setiosflags(ios::fixed) << setprecision(10);
 	int T;
 	cin >> T;
 	for(int caseNum = 1; caseNum <= T; ++caseNum){
 		int n, p, q, r, s;
 		cin >> n >> p >> q >> r >> s;
 		vector<ll> a(n);
 		for(int i = 0; i < n; ++i){
 			a[i] = (static_cast<ll>(i) * p + q) % r + s;
 		}
 		vector<ll> integral(n + 1);
 		for(int i = 0; i < n; ++i){
 			integral[i + 1] = integral[i] + a[i];
 		}
 		double answer = 0.0;
 		for(int i = 0; i < n; ++i){
 			const ll s0 = integral[i];
 			const int j = ternary_search(
 				i + 1, n,
 				[&](int p) -> ll {
 					const ll x = integral[p] - integral[i];
 					const ll y = integral[n] - integral[p];
 					return max(x, y);
 				});
 			const ll s1 = integral[j] - integral[i];
 			const ll s2 = integral[n] - integral[j];
 			const ll maxval = max({ s0, s1, s2 });
 			const ll sum = integral[n];
 			answer = max(answer, static_cast<double>(sum - maxval) / sum);
 		}
 		cout << "Case #" << caseNum << ": " << answer << endl;
 	}
 	return 0;
 }
 
