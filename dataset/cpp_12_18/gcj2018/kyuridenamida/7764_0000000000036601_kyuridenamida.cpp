#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;


int N,L;
int C[100010];

void solve(int t){
	memset(C,0,sizeof(C));

	scanf("%d%d",&N, &L);
	int S = N;
	int ans = 0;
	for(int i = 0 ; i < L ; i++) scanf("%d", &C[i]), S -= C[i], ans += C[i] * 100 / N;
	ans += S * (100 / N);
	
	int diff = 100 % N;
	
	if(diff > 0){
		for(int i = 0 ; i < 100010 ; i++){
			C[i] = (N+1) / 2 - C[i] * 100 % N;	
			if( C[i] < 0 ) C[i] = 0;
			C[i] = (C[i] + diff - 1) / diff;	
		}
		sort(C, C + 100010);
		for(int i = 0 ; i < 100010 ; i++){
			if( S >= C[i] ){
				S -= C[i];
				ans++;
			}
		}
	}
	printf("Case #%d: %d\n", t, ans);
}
int main(){
	int T;
	scanf("%d",&T);
	for(int i = 0 ; i < T ; i++) solve(i+1);
}