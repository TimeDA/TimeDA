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

int X,Y;
string board[30];

int CNT = 0;
bool used[30][30];
bool good[30][30];

int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};

void dfs(int x, int y){
	if(x < 0 || x >= X || y < 0 || y >= Y || !good[x][y] || used[x][y]) return;
	used[x][y] = true;
	CNT++;
	int i;
	REP(i,4) dfs(x+dx[i], y+dy[i]);
}

int check(string s, int x, int y){
	int i,j;
	
	REP(i,X) REP(j,Y) good[i][j] = false;
	
	REP(i,X) REP(j,Y){
		if(i < x){
			if(j < y){
				good[i][j] = (board[i][j] == s[0] && board[i][j] != '?');
			} else {
				good[i][j] = (board[i][j] == s[1] && board[i][j] != '?');
			}
		} else {
			if(j < y){
				good[i][j] = (board[i][j] == s[2] && board[i][j] != '?');
			} else {
				good[i][j] = (board[i][j] == s[3] && board[i][j] != '?');
			}
		}
	}
	
	REP(i,X) REP(j,Y) used[i][j] = false;
	
	int ans = 0;
	
	REP(i,X) REP(j,Y) if(good[i][j] && !used[i][j]){
		CNT = 0;
		dfs(i, j);
		ans = max(ans, CNT);
	}
	
	return ans;
}
	
void main2(void){
	int i,j,k,l;
	
	cin >> X >> Y;
	REP(i,X) cin >> board[i];
	REP(i,X) board[i] += '?';
	board[X] = "";
	REP(i,Y+1) board[X] += '?';
	X++;
	Y++;
	
	int ans = 0;
	
	set <string> four;
	REP(i,X-1) REP(j,Y-1){
		string s = (string)("") + board[i][j] + board[i][j+1] + board[i+1][j] + board[i+1][j+1];
		if(four.find(s) != four.end()) continue;
		four.insert(s);
		REP(k,X+1) REP(l,Y+1){
			int tmp = check(s, k, l);
			ans = max(ans, tmp);
		}
	}
	
	cout << ans << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc + 1);
		main2();
	}
	return 0;
}
