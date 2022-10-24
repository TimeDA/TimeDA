#include <iostream>
 #include <sstream>
 #include <fstream>
 #include <string>
 #include <vector>
 #include <deque>
 #include <queue>
 #include <stack>
 #include <set>
 #include <map>
 #include <algorithm>
 #include <functional>
 #include <utility>
 #include <bitset>
 #include <cmath>
 #include <cstdlib>
 #include <ctime>
 #include <cstdio>
 
 using namespace std;
 
 #define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
 #define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
 
 int X,Y,K;
 char board[60][60];
 int px[110],py[110];
 // 0: -, 1: |
 vector <pair <int, int> > beams[60][60];
 int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
 bool used[60][60][4];
 
 void init(void){
 	int i,j,k;
 	REP(i,X) REP(j,Y) REP(k,4) used[i][j][k] = false;
 }
 
 void dfs(int x, int y, int d){
 	if(x < 0 || x >= X || y < 0 || y >= Y || board[x][y] == '#' || used[x][y][d]) return;
 	used[x][y][d] = true;
 	dfs(x + dx[d], y + dy[d], (d ^ 2));
 	
 	if(board[x][y] == '/'){
 		dfs(x, y, (d ^ 1));
 	} else if(board[x][y] == '\\'){
 		dfs(x, y, (d ^ 3));
 	} else if(board[x][y] == '.'){
 		dfs(x, y, (d ^ 2));
 	}
 }
 
 bool check(void){
 	int i,j,cnt=0;
 	REP(i,K) REP(j,4) if(used[px[i]][py[i]][j]) cnt++;
 //	cerr << cnt << endl;
 	return (cnt == 1);
 }
 
 void add_beam(int ii, int jj){
 	int i,j,k;
 	
 	REP(i,X) REP(j,Y) if(board[i][j] == '.'){
 		bool found = false;
 		REP(k,4) if(used[i][j][k]) found = true;
 		if(found) beams[i][j].push_back(make_pair(ii, jj));
 	}
 }
 
 bool graph[210][210];
 
 int init_2sat(void){
 	int i,j;
 	REP(i,2*K) REP(j,2*K) graph[i][j] = (i == j);
 }
 
 void add_clause(int x, int t){ // cout << "clause: " << x << ' ' << t << endl;
 	graph[2*x+(t^1)][2*x+t] = true;
 }
 
 void add_clause(int x1, int t1, int x2, int t2){ // cout << "clause: " << x1 << ' ' << t1 << ' ' << x2 << ' ' << t2 << endl;
 	graph[2*x1+(t1^1)][2*x2+t2] = true;
 	graph[2*x2+(t2^1)][2*x1+t1] = true;
 }
 
 int root[210];
 int topo[210];
 
 bool solve_2sat(void){
 	int i,j,k,x;
 	int N = 2 * K;
 	
 	REP(k,N) REP(i,N) REP(j,N) if(graph[i][k] && graph[k][j]) graph[i][j] = true;
 	REP(i,N) if(graph[i][i^1] && graph[i^1][i]) return false;
 	
 //	cout << "A" << endl;
 	
 	REP(i,N) topo[i] = -1;
 	
 	REP(i,N){
 		REP(j,N) if(graph[i][j] && graph[j][i]) break;
 		root[i] = j;
 	}
 	
 	int pos = 0;
 	while(1){
 		int x = -1;
 		REP(i,N) if(topo[i] == -1 && root[i] == i){
 			bool good = true;
 			REP(j,N) if(root[j] == j && j != i && topo[j] == -1 && graph[i][j]) good = false;
 			if(good){
 				x = i;
 				break;
 			}
 		}
 		
 		if(x == -1) break;
 		
 		topo[x] = pos;
 		pos++;
 	}
 	
 //	REP(i,N) cout << i << ' ' << root[i] << ' ' << topo[root[i]] << endl;
 	
 //	REP(i,N) cout << topo[i] << ' ';
 //	cout << endl;
 
 //	REP(i,N) REP(j,N) if(graph[i][j]) cout << "edge" << i << ' ' << j << endl;
 	
 	REP(i,K) if(topo[root[2*i]] > topo[root[2*i+1]]){
 		board[px[i]][py[i]] = '|';
 	} else {
 		board[px[i]][py[i]] = '-';
 	}
 	
 	return true;
 }
 
 int cnt[60][60];
 
 void verify(void){
 	int i,j,k;
 	
 	REP(i,X) REP(j,Y) cnt[i][j] = 0;
 	
 	REP(i,X) REP(j,Y) if(board[i][j] == '-'){
 		for(k=j-1;k>=0;k--){
 			if(board[i][k] == '#') break;
 			if(board[i][k] != '.') cout << "WARNING" << endl;
 			cnt[i][k]++;
 		}
 		
 		for(k=j+1;k<Y;k++){
 			if(board[i][k] == '#') break;
 			if(board[i][k] != '.') cout << "WARNING" << endl;
 			cnt[i][k]++;
 		}
 	} else if(board[i][j] == '|'){
 		for(k=i-1;k>=0;k--){
 			if(board[k][j] == '#') break;
 			if(board[k][j] != '.') cout << "WARNING" << endl;
 			cnt[k][j]++;
 		}
 		
 		for(k=i+1;k<X;k++){
 			if(board[k][j] == '#') break;
 			if(board[k][j] != '.') cout << "WARNING" << endl;
 			cnt[k][j]++;
 		}
 	}
 	
 	REP(i,X) REP(j,Y) if(board[i][j] == '.' && cnt[i][j] == 0) cout << "WARNING" << endl;
 }
 
 void main2(void){
 	int i,j;
 	
 	cin >> X >> Y;
 	REP(i,X) scanf("%s", board[i]);
 	
 	K = 0;
 	REP(i,X) REP(j,Y) if(board[i][j] == '-' || board[i][j] == '|'){
 		px[K] = i;
 		py[K] = j;
 		K++;
 	}
 	
 	REP(i,X) REP(j,Y) beams[i][j].clear();
 	
 	init_2sat();
 	
 	REP(i,K) REP(j,2){ // beam i, direction j
 		init();
 		dfs(px[i], py[i], 1-j);
 		if(!check()){
 			add_clause(i, 1-j);
 			continue;
 		}
 		
 		init();
 		dfs(px[i], py[i], 3-j);
 		if(!check()){
 			add_clause(i, 1-j);
 			continue;
 		}
 		
 	//	cout << "good beam " << i << ' ' << j << endl;
 		
 		init();
 		dfs(px[i], py[i], 1-j);
 		dfs(px[i], py[i], 3-j);
 		add_beam(i, j);
 	}
 	
 	REP(i,X) REP(j,Y) if(board[i][j] == '.'){
 		if(beams[i][j].empty()){
 			cout << "IMPOSSIBLE" << endl;
 			return;
 		} else if(beams[i][j].size() == 1){
 			pair <int, int> p = beams[i][j][0];
 			add_clause(p.first, p.second);
 		} else if(beams[i][j].size() == 2){
 			pair <int, int> p = beams[i][j][0];
 			pair <int, int> q = beams[i][j][1];
 			add_clause(p.first, p.second, q.first, q.second);
 		} else {
 			cout << "WARNING" << endl;
 		}
 	}
 	
 	if(!solve_2sat()){
 		cout << "IMPOSSIBLE" << endl;
 	} else {
 		cout << "POSSIBLE" << endl;
 		REP(i,X){
 			board[i][Y] = '\0';
 			printf("%s\n", board[i]);
 		}
 	//	verify();
 	}
 }
 
 ////////////////////////////////////////////////////////////////////////////////////////////////////
 
 int main(void){
 	int TC,tc;
 	cin >> TC;
 	REP(tc,TC){
 		printf("Case #%d: ", tc + 1);
 		main2();
 	}
 	return 0;
 }
