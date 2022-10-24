#include <iostream>
 #include <vector>
 #include <string>
 #include <cstdio>
 #include <cstring>
 
 using namespace std;
 
 int mask[30][30][30][30];
 
 void solve(vector<string>& vs, int lx, int ly, int hx, int hy){
 	int m = mask[lx][ly][hx][hy];
 	if(m&(m-1)){
 		for(int i=lx+1;i<hx;i++){
 			int m1 = mask[lx][ly][i][hy];
 			int m2 = mask[i][ly][hx][hy];
 			if(m1&m2) continue;
 			if(!m1) continue;
 			if(!m2) continue;
 			solve(vs, lx, ly, i, hy);
 			solve(vs, i, ly, hx, hy);
 			return;
 		}
 		for(int i=ly+1;i<hy;i++){
 			int m1 = mask[lx][ly][hx][i];
 			int m2 = mask[lx][i][hx][hy];
 			if(m1&m2) continue;
 			if(!m1) continue;
 			if(!m2) continue;
 			solve(vs, lx, ly, hx, i);
 			solve(vs, lx, i, hx, hy);
 			return;
 		}
 	} else {
 		int c = -1;
 		for(int i=0;i<26;i++){
 			if(m&(1<<i)) c = i;
 		}
 		for(int i=lx;i<hx;i++){
 			for(int j=ly;j<hy;j++) vs[i][j] = c+'A';
 		}
 	}
 }
 
 int main(){
 	int T; cin >> T;
 	for(int t=1;t<=T;t++){
 		memset(mask, 0, sizeof(mask));
 		int R, C; cin >> R >> C;
 		vector<string> vs(R);
 		for(int i=0;i<R;i++) cin >> vs[i];
 		for(int i=0;i<R;i++){
 			for(int j=0;j<C;j++){
 				if(vs[i][j] != '?') mask[i][j][i+1][j+1] = (1 << (vs[i][j] - 'A'));
 			}
 			for(int d=1;d<C;d++){
 				for(int j=0;j+d<C;j++){
 					mask[i][j][i+1][j+d+1] = mask[i][j][i+1][j+1]|mask[i][j+1][i+1][j+d+1];
 				}
 			}
 		}
 		for(int d=1;d<R;d++){
 			for(int i=0;i+d<R;i++){
 				for(int j=0;j<C;j++){
 					for(int j2=j;j2<C;j2++){
 						mask[i][j][i+d+1][j2+1] = mask[i][j][i+1][j2+1]|mask[i+1][j][i+d+1][j2+1];
 					}
 				}
 			}
 		}
 		solve(vs, 0, 0, R, C);
 		printf("Case #%d:\n", t);
 		for(int i=0;i<R;i++) cout << vs[i] << endl;
 	}
 }
 
