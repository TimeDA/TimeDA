#include <bits/stdc++.h>
 using namespace std;
 #define int long long
 const int mod = 1000000000+7;
 const long double pi = 3.1415926535897932384626433832795028841971;
 
 void put_case(){
 	static int t = 1;
 	cout << "Case #" << t++ << ": ";
 }
 
 int dp[1500][1500][2][2];
 int av[1500];
 
 int dfs(int a,int b,int c,int d){
 	if( a == 0 && b == 0 ) return d != c;
 	if( dp[a][b][c][d] != -1 ) return dp[a][b][c][d];
 	int elapsed = 1440 - a - b;
 	int ans = 1e9;
 	if( av[elapsed] != 1 && a > 0 ){
 		ans = min(ans,dfs(a-1,b,0,d) + (c!=0));
 	}
 	if( av[elapsed] != 2 && b > 0 ){
 		ans = min(ans,dfs(a,b-1,1,d) + (c!=1));
 	}
 	return dp[a][b][c][d] = ans;
 
 }
 
 signed main(){
 	int T;
 	cin >> T;
 	while(T--){
 		memset(dp,-1,sizeof(dp));
 		memset(av,0,sizeof(av));
 		int A,B;
 		cin >> A >> B;
 		for(int i = 0 ; i < A ; i++){
 			int a,b;
 			cin >> a >> b;
 			for(int j = a ; j < b ; j++)
 				av[j] |= 1;
 		}
 		for(int i = 0 ; i < B ; i++){
 			int a,b;
 			cin >> a >> b;
 			for(int j = a ; j < b ; j++)
 				av[j] |= 2, assert(av[j] != 3);
 		}
 		put_case();
 		cout << min(dfs(720,720,0,0),dfs(720,720,1,1)) << endl;
 
 	}
 }
