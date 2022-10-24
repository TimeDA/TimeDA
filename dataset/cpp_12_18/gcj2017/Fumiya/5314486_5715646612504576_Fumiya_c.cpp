#include <iostream>
 #include <vector>
 #include <string>
 #include <algorithm>
 #include <cstring>
 #include <cstdio>
 
 using namespace std;
 
 void solveSmall(const vector<string>& vs){
 	int R = vs.size(), C = vs[0].size();
 	vector<string> s = vs;
 	for(int i=0;i<R;i++){
 		for(int j=0;j<C;j++) if(s[i][j] == '|' || s[i][j] == '-') s[i][j] = 'L';
 	}
 	static int dp[100][1<<15];
 	memset(dp, -1, sizeof(dp));
 	dp[0][0] = 0;
 	for(int i=0;i<C;++i){
 		for(int j=0;j<(1<<(3*R));++j){
 			if(dp[i][j] == -1) continue;
 			for(int k=0;k<(1<<R);k++){
 				bool ok = true;
 				bool find = false;
 				for(int l=0;l<R;l++){
 					if(s[l][i] == 'L'){
 						if(find) ok = false;
 						if(j&(1<<(3*l+1))) ok = false;
 						if(k&(1<<l)){
 							find = true;
 						} else {
 							if(j&(1<<(3*l+2))) ok = false;
 						}
 					} else if(s[l][i] == '#'){
 						if(j&(1<<(3*l))) ok = false;
 						find = false;
 					}
 				}
 				find = false;
 				for(int l=R-1;l>=0;l--){
 					if(s[l][i] == 'L'){
 						if(find) ok = false;
 						if(k&(1<<l)) find = true;
 					} else if(s[l][i] == '#'){
 						find = false;
 					}
 				}
 				if(!ok) continue;
 				int fill = 0;
 				find = false;
 				for(int l=0;l<R;l++){
 					if(s[l][i] == 'L' && (k&(1<<l))) find = true;
 					if(s[l][i] == '#') find = false;
 					if(s[l][i] == '.') if(find) fill |= (1 << l);
 				}
 				find = false;
 				for(int l=R-1;l>=0;l--){
 					if(s[l][i] == 'L' && (k&(1<<l))) find = true;
 					if(s[l][i] == '#') find = false;
 					if(s[l][i] == '.') if(find) fill |= (1 << l);
 				}
 				int nv = 0;
 				for(int l=0;l<R;l++){
 					if(j&(1<<(3*l))){
 						nv |= (1<<(3*l));
 					}
 					if(s[l][i] == '.' && !(fill&(1<<l))){
 						nv |= (1<<(3*l));
 					}
 					if(s[l][i] != '#'){
 						if(j&(1<<(3*l+1))) nv |= (1<<(3*l+1));
 						if(s[l][i] == 'L' && !(k&(1<<l))) nv |= (1<<(3*l+1));
 					}
 					if(s[l][i] == 'L') nv |= (1<<(3*l+2));
 				}
 				if(dp[i+1][nv] != -1) continue;
 				dp[i+1][nv] = 128 * j + k;
 			}
 		}
 	}
 	for(int i=0;i<(1<<(3*R));++i){
 		if(dp[C][i] == -1) continue;
 		bool ok = true;
 		for(int j=0;j<R;j++) if(i&(1<<(3*j))) ok = false;
 		if(!ok) continue;
 		int key = i;
 		for(int j=C-1;j>=0;j--){
 			int pre = dp[j+1][key]/128;
 			int mask = dp[j+1][key]%128;
 			for(int k=0;k<R;k++){
 				if(s[k][j] == 'L') s[k][j] = ((mask&(1<<k)) ? '|' : '-');
 			}
 			key = pre;
 		}
 		printf("POSSIBLE\n");
 		for(int j=0;j<s.size();j++) cout << s[j] << endl;
 		return;
 	}
 	printf("IMPOSSLBLE\n");
 }
 
 int main(){
 	int T; cin >> T;
 	for(int t=1;t<=T;++t){
 		int R, C; cin >> R >> C;
 		vector<string> mp(R);
 		for(int i=0;i<R;++i) cin >> mp[i];
 		printf("Case #%d: ", t);
 		solveSmall(mp);
 	}
 }
 
