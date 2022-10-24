#include<cstdio>
#include<algorithm>

using namespace std;

int C;
int a[110];

char ch[110][110];

int solve(){
	if(a[0] == 0 || a[C - 1] == 0) return -1;
	for(int i = 0; i < C + 5; ++i){
		for(int j = 0; j < C; ++j) ch[i][j] = '.';
		ch[i][C] = '\0';
	}
	int le = 0;
	for(int i = 0; i < C; ++i){
		if(a[i] == 0) continue;
		int ri = le + a[i] - 1;
		int r = 0;
		for(int c = le; c < i; ++c){
			ch[r][c] = '\\';
			r++;
		}
		r = 0;
		for(int c = ri; c > i; --c){
			ch[r][c] = '/';
			r++;
		}
		le = ri + 1;
	}
	for(int i = 0; i < C + 5; ++i){
		bool flg = false;
		for(int j = 0; j < C; ++j){
			if(ch[i][j] != '.'){
				flg = true;
			}
		}
		if(!flg) return i + 1;
	}
	return -2;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		scanf("%d", &C);
		for(int i = 0; i < C; ++i){
			scanf("%d", a + i);
		}
		int ans = solve();
		if(ans == -1){
			printf("Case #%d: IMPOSSIBLE\n", t + 1);
		}else{
			printf("Case #%d: %d\n", t + 1, ans);
			for(int i = 0; i < ans; ++i){
				printf("%s\n", ch[i]);
			}
		}
	}
	return 0;
}
