#include<cstdio>
 #include<string>
 #include<algorithm>
 
 using namespace std;
 
 string tree[10000];
 int memo[10000];
 
 int N, R, P, S;
 
 string chs = "PRS";
 
 string gen(int n, int seed){
 	memo[n] = seed;
 	memo[n + 1] = (seed + 1) % 3;
 	tree[n] = chs[seed];
 	tree[n + 1] = chs[(seed + 1) % 3];
 	int prv = 1;
 	for(int i = n + 2; i < n * 2; ++i){
 		int j = n - i;
 		if(j == prv * 2) prv *= 2;
 		memo[i] = (memo[i - prv] + 1) % 3;
 		tree[i] = chs[memo[i]];
 	}
 	for(int i = n - 1; i >= 1; --i){
 		if(tree[i * 2] > tree[i * 2 + 1]) tree[i] = tree[i * 2 + 1] + tree[i * 2];
 		else tree[i] = tree[i * 2] + tree[i * 2 + 1];
 	}
 	int r = 0, p = 0, s = 0;
 	for(int i = 0; i < tree[1].size(); ++i){
 		if(tree[1][i] == 'R') r++;
 		else if(tree[1][i] == 'P') p++;
 		else s++;
 	}
 	if(p == P && r == R && s == S) return tree[1];
 	else return "";
 }
 
 void solve(int tnum){
 	int n = P + R + S;
 	string cand0 = gen(n, 0);
 	string cand1 = gen(n, 1);
 	string cand2 = gen(n, 2);
 	string ans = cand0;
 	if(cand1 != "" && (ans == "" || ans > cand1)) ans = cand1;
 	if(cand2 != "" && (ans == "" || ans > cand2)) ans = cand2;
 	if(ans == "") ans = "IMPOSSIBLE";
 	printf("Case #%d: %s\n", tnum, ans.c_str());
 }
 
 int main(){
 	int T;
 	scanf("%d", &T);
 	for(int datano = 0; datano < T; datano++){
 		scanf("%d%d%d%d", &N, &R, &P, &S);
 		solve(datano + 1);
 	}
 	return 0;
 }
