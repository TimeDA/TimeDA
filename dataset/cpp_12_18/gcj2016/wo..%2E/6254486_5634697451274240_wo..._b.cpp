#include<cstdio>
 #include<cstring>
 
 using namespace std;
 
 int N;
 int bits[110];
 int tmp[110];
 
 void flip(int l){
 	//printf("flip %d\n", l);
 	for(int i = 0; i <= l; ++i){
 		tmp[l - i] = bits[i] ^ 1;
 	}
 	for(int i = 0; i <= l; ++i){
 		bits[i] = tmp[i];
 	}
 }
 
 void getNxt(){
 	if(bits[0] == 1){
 		for(int i = 0; i < N - 1; ++i){
 			if(bits[i] == 1 && bits[i + 1] == 0){
 				flip(i);
 				return;
 			}
 		}
 	}else{
 		for(int i = 0; i < N - 1; ++i){
 			if(bits[i] == 0 && bits[i + 1] == 1){
 				flip(i);
 				return;
 			}
 		}
 	}
 	flip(N - 1);
 }
 
 bool check(){
 	for(int i = 0; i < N; ++i){
 		if(bits[i] == 0) return false;
 	}
 	return true;
 }
 
 int solve(){
 	int cnt = 0;
 	while(true){
 		if(check()) break;
 		cnt++;
 		getNxt();
 	}
 	return cnt;
 }
 
 int main(){
 	int T;
 	scanf("%d", &T);
 	for(int datano = 0; datano < T; ++datano){
 		char ch[110];
 		scanf("%s", ch);
 		N = strlen(ch);
 		for(int i = 0; i < N; ++i){
 			bits[i] = ch[i] == '+' ? 1 : 0;
 		}
 		int ans = solve();
 		printf("Case #%d: %d\n", datano + 1, ans);
 	}
 	return 0;
 }
