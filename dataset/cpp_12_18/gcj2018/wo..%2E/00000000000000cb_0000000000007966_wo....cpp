#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char ch[100];
int N;
int D;

int vals[100];

int solve(){
	N = strlen(ch);
	int tmp = 1;
	int cnt = 0;
	for(int i = 0; i < N; ++i){
		if(ch[i] == 'C') tmp *= 2;
		else vals[cnt++] = tmp;
	}
	int sum = 0;
	for(int i = 0; i < cnt; ++i) sum += vals[i];
	int ans = 0;
	if(D < cnt) return -1;
	while(D < sum){
		int cur = -1;
		for(int i = cnt - 1; i >= 1; --i){
			if(vals[i] != vals[i - 1]){
				cur = i;
				break;
			}
		}
		if(cur == -1) cur = 0;
		sum -= (vals[cur] / 2);
		vals[cur] /= 2;
		ans++;
	}
	return ans;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		scanf("%d%s", &D, ch);
		int ans = solve();
		printf("Case #%d: ", t + 1);
		if(ans == -1) printf("IMPOSSIBLE\n");
		else printf("%d\n", ans);
	}
	return 0;
}
