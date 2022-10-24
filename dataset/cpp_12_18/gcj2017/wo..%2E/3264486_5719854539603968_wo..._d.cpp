#include<cstdio>
 #include<algorithm>
 
 using namespace std;
 
 bool is_nonplus[110][110];
 bool is_nonx[110][110];
 int N;
 
 bool valid[110][110];
 
 bool init_nonp[110][110];
 bool init_nonx[110][110];
 
 void set_invalid_diag(int i, int j){
 	for(int k = 0; k < N; ++k){
 		int l = i + j - k;
 		if(l >= 0 && l < N){
 			valid[k][l] = false;
 		}
 		l = k + j - i;
 		if(l >= 0 && l < N){
 			valid[k][l] = false;
 		}
 	}
 }
 
 void solve(){
 	for(int i = 0; i < N; ++i){
 		for(int j = 0; j < N; ++j){
 			is_nonplus[i][j] = init_nonp[i][j];
 			is_nonx[i][j] = init_nonx[i][j];
 		}
 	}
 	
 	// +
 	for(int i = 0; i < N; ++i){
 		for(int j = 0; j < N; ++j){
 			valid[i][j] = true;
 		}
 	}
 	for(int i = 0; i < N; ++i){
 		for(int j = 0; j < N; ++j){
 			if(is_nonplus[i][j]){
 				for(int k = 0; k < N; ++k){
 					valid[i][k] = false;
 					valid[k][j] = false;
 				}
 			}
 		}
 	}
 	for(int i = 0; i < N; ++i){
 		for(int j = 0; j < N; ++j){
 			if(valid[i][j]){
 				is_nonplus[i][j] = true;
 				for(int k = 0; k < N; ++k){
 					valid[i][k] = false;
 					valid[k][j] = false;
 				}
 			}
 		}
 	}
 	
 	// x
 	for(int i = 0; i < N; ++i){
 		for(int j = 0; j < N; ++j){
 			valid[i][j] = true;
 		}
 	}
 	for(int i = 0; i < N; ++i){
 		for(int j = 0; j < N; ++j){
 			if(is_nonx[i][j]){
 				set_invalid_diag(i, j);
 			}
 		}
 	}
 	for(int i = 0; i < N; ++i){
 		int s = i;
 		for(int j = 0; j < s; ++j){
 			if(valid[j][s - j]){
 				is_nonx[j][s - j] = true;
 				set_invalid_diag(j, s - j);
 			}
 		}
 		s = 2 * N - 2 - i;
 		for(int j = 0; j < N; ++j){
 			int k = s - j;
 			if(k >= N) continue;
 			if(valid[j][k]){
 				is_nonx[j][k] = true;
 				set_invalid_diag(j, k);
 			}
 		}
 	}
 }
 
 char get(bool p, bool x){
 	if(p & x){
 		return 'o';
 	}
 	if(p) return '+';
 	if(x) return 'x';
 	fprintf(stderr, "error\n");
 	return ' ';
 }
 
 void output(int datano){
 	int sum = 0;
 	int cnt = 0;
 	for(int i = 0; i < N; ++i){
 		for(int j = 0; j < N; ++j){
 			if(is_nonplus[i][j]) sum++;
 			if(is_nonx[i][j]) sum++;
 			
 			if((is_nonplus[i][j] != init_nonp[i][j]) || (is_nonx[i][j] != init_nonx[i][j])){
 				cnt++;
 			}
 		}
 	}
 	printf("Case #%d: %d %d\n", datano + 1, sum, cnt);
 	for(int i = 0; i < N; ++i){
 		for(int j = 0; j < N; ++j){
 			if((is_nonplus[i][j] != init_nonp[i][j]) || (is_nonx[i][j] != init_nonx[i][j])){
 				char ch = get(is_nonx[i][j], is_nonplus[i][j]);
 				printf("%c %d %d\n", ch, i + 1, j + 1);
 			}
 		}
 	}
 }
 
 void input(){
 	int M;
 	scanf("%d%d", &N, &M);
 	for(int i = 0; i < N; ++i){
 		for(int j = 0; j < N; ++j){
 			init_nonp[i][j] = false;
 			init_nonx[i][j] = false;
 		}
 	}
 	for(int i = 0; i < M; ++i){
 		char ch[2];
 		int I, J;
 		scanf("%s%d%d", ch, &I, &J);
 		if(ch[0] != '+'){
 			init_nonp[I - 1][J - 1] = true;
 		}
 		if(ch[0] != 'x'){
 			init_nonx[I - 1][J - 1] = true;
 		}
 	}
 }
 
 int main(){
 	int T;
 	scanf("%d", &T);
 	for(int datano = 0; datano < T; ++datano){
 		input();
 		solve();
 		output(datano);
 	}
 	return 0;
 }
