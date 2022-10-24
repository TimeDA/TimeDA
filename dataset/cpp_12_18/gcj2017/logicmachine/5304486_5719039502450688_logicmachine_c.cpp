#include <iostream>
 #include <string>
 #include <vector>
 #include <algorithm>
 #include <queue>
 #include <tuple>
 
 using namespace std;
 using tiiii = tuple<int, int, int, int>;
 static const int INF = 1000000000;
 static int dp[101][101][101][101];
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int case_num = 1; case_num <= T; ++case_num){
 		int hd, ad, hk, ak, b, d;
 		cin >> hd >> ad >> hk >> ak >> b >> d;
 		for(int i1 = 0; i1 <= hd; ++i1){
 			for(int i2 = 0; i2 <= max(ad, hk); ++i2){
 				for(int i3 = 0; i3 <= hk; ++i3){
 					for(int i4 = 0; i4 <= ak; ++i4){
 						dp[i1][i2][i3][i4] = INF;
 					}
 				}
 			}
 		}
 		queue<tiiii> q;
 		auto update = [&](int i1, int i2, int i3, int i4, int v) -> void {
 			if(v < dp[i1][i2][i3][i4]){
 				dp[i1][i2][i3][i4] = v;
 				q.emplace(i1, i2, i3, i4);
 			}
 		};
 		dp[hd][ad][hk][ak] = 0;
 		q.emplace(hd, ad, hk, ak);
 		while(!q.empty()){
 			const auto t = q.front();
 			q.pop();
 			const int cur_hd = get<0>(t);
 			const int cur_ad = get<1>(t);
 			const int cur_hk = get<2>(t);
 			const int cur_ak = get<3>(t);
 			const int cur_turn = dp[cur_hd][cur_ad][cur_hk][cur_ak];
 			// attack
 			if(cur_hk <= cur_ad){
 				update(0, 0, 0, 0, cur_turn + 1);
 			}else if(cur_hd > cur_ak){
 				update(
 					cur_hd - cur_ak, cur_ad,
 					cur_hk - cur_ad, cur_ak,
 					cur_turn + 1);
 			}
 			// buff
 			if(cur_hd > cur_ak){
 				update(
 					cur_hd - cur_ak, min(cur_ad + b, hk),
 					cur_hk, cur_ak, cur_turn + 1);
 			}
 			// cure
 			if(hd > cur_ak){
 				update(hd - cur_ak, cur_ad, cur_hk, cur_ak, cur_turn + 1);
 			}
 			// debuff
 			if(cur_hd > max(cur_ak - d, 0)){
 				update(
 					cur_hd - max(cur_ak - d, 0), cur_ad,
 					cur_hk, max(cur_ak - d, 0), cur_turn + 1);
 			}
 		}
 		const int answer = dp[0][0][0][0];
 		cout << "Case #" << case_num << ": ";
 		if(answer >= INF){
 			cout << "IMPOSSIBLE" << endl;
 		}else{
 			cout << answer << endl;
 		}
 	}
 	return 0;
 }
 
