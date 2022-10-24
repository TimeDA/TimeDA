#include<cstdio>
 
 using namespace std;
 
 char ch[30][30];
 int H, W;
 
 void getRow(int i){
 	char prv = '?';
 	for(int j = 0; j < W; ++j){
 		if(ch[i][j] != '?'){
 			prv = ch[i][j];
 		}
 		ch[i][j] = prv;
 	}
 	for(int j = W - 1; j >= 0; --j){
 		if(ch[i][j] != '?'){
 			prv = ch[i][j];
 		}
 		ch[i][j] = prv;
 	}
 }
 
 void solve(){
 	for(int i = 0; i < H; ++i){
 		getRow(i);
 	}
 	for(int i = 1; i < H; ++i){
 		if(ch[i][0] == '?'){
 			for(int j = 0; j < W; ++j){
 				ch[i][j] = ch[i - 1][j];
 			}
 		}
 	}
 	for(int i = H - 2; i >= 0; --i){
 		if(ch[i][0] == '?'){
 			for(int j = 0; j < W; ++j){
 				ch[i][j] = ch[i + 1][j];
 			}
 		}
 	}
 }
 
 void input(){
 	scanf("%d%d", &H, &W);
 	for(int i = 0; i < H; ++i){
 		scanf("%s", ch[i]);
 	}
 }
 
 int main(){
 	int T;
 	scanf("%d", &T);
 	for(int datano = 0; datano < T; ++datano){
 		input();
 		solve();
 		printf("Case #%d:\n", datano + 1);
 		for(int i = 0; i < H; ++i){
 			printf("%s\n", ch[i]);
 		}
 	}
 	return 0;
 }
