#include<bits/stdc++.h>
 
 using namespace std;
 
 int dp[5][101][101][101];
 int n;
 int p;
 
 int memo(int leftOver, vector<int> v) {
 	if ( v[1] + v[2] + v[3] == 0) return 0;
 
 	if ( dp[leftOver][ v[1] ][ v[2] ][ v[3] ] != -1) return dp[leftOver][ v[1] ][ v[2] ][ v[3] ];
 
 	int res = 0;
 
 	for (int i = 1; i <= 3; i++) {
 		if (v[i] > 0) {
 			v[i]--;
 			int ll = leftOver;
 			while (ll < i) ll += p;
 			int k = memo(ll - i, v);
 			if (leftOver == 0) k++;
 			res = max(res, k);
 			v[i]++;
 		}
 	}
 	return dp[leftOver][ v[1] ][ v[2] ][ v[3] ] = res;
 }
 
 int main() {
 	int test;
 	cin >> test;
 	for (int cases = 1; cases <= test; cases++) {
 		cin >> n >> p;
 		vector<int> v;
 		for (int i = 0; i < 4; i++)
 			v.push_back(0);
 		for (int i = 0; i < n; i++) {
 			int a; cin >> a;
 			v[ a % p ]++;
 		}
 		memset(dp, -1, sizeof(dp));
 
 		int res = memo(0, v);
 		printf("Case #%d: %d\n", cases, res + v[0]);
 	}
 	return 0;
 }
