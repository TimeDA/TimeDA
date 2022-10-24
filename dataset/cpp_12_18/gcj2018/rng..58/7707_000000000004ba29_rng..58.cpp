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

typedef long long ll;
#define MOD 1000000007ll
	
int N;
bool graph[60][60];
int p[60];
int h[10][60];
	
bool get_graph(int n){
	int i,j,k;
	
	N = n;
	REP(i,N) REP(j,N) graph[i][j] = false;
	
	REP(i,N) p[i] = i;
	p[N] = p[0];
	REP(i,N) graph[p[i]][p[i+1]] = graph[p[i+1]][p[i]] = true;
	
	random_shuffle(p, p+N);
	p[N] = p[0];
	REP(i,N){
		if(graph[p[i]][p[i+1]]) return false;
		graph[p[i]][p[i+1]] = graph[p[i+1]][p[i]] = true;
	}
	
	REP(i,N) h[0][i] = 1;
	
	REP(i,N) REP(j,i) REP(k,j) if(graph[i][j] && graph[j][k] && graph[k][i]){
		h[0][i]++;
		h[0][j]++;
		h[0][k]++;
	}
	
	REP(k,5) REP(i,N){
		ll x = 1;
		REP(j,N) if(graph[i][j]) x = x * (h[k][j] + 1) % MOD;
		h[k+1][i] = (int)x;
	}
	
	set <int> s;
	REP(i,N) s.insert(h[5][i]);
	
	// cout << s.size() << endl;
	
	return (s.size() == N);
}

/*
bool check(int n){
	int cnt = 0;
	cout << n << endl;
	while(!get_graph(n)) cnt++;
	cout << n << ' ' << cnt << endl;
}
*/

bool graph2[60][60];
int h2[10][60];

int f[60];

void main2(int n){
	int i,j,k;
	
	REP(i,60) REP(j,60) graph[i][j] = graph2[i][j] = false;
	REP(i,10) REP(j,60) h[i][j] = h2[i][j] = 0;
	REP(i,60) f[i] = 0;
	REP(i,60) p[i] = 0;
	N = n;
	
	while(1){
		bool b = get_graph(n);
		if(b) break;
	}
	
	printf("%d\n", n);
	REP(i,n) REP(j,n) if(i < j && graph[i][j]){
		printf("%d %d\n", i+1, j+1);
	}
	fflush(stdout);
	
	// cout << 'a' << endl;
	
	cin >> N; // cout << 'a' << endl;
	REP(i,N) REP(j,N) graph2[i][j] = false;
	REP(i,N*2){
		int a,b;
		scanf("%d%d", &a, &b);
		a--; b--;
		graph2[a][b] = graph2[b][a] = true;
	}
	
	// cout << 'a' << endl;
	
	REP(i,N) h2[0][i] = 1;
	
	REP(i,N) REP(j,i) REP(k,j) if(graph2[i][j] && graph2[j][k] && graph2[k][i]){
		h2[0][i]++;
		h2[0][j]++;
		h2[0][k]++;
	}
	
	REP(k,5) REP(i,N){
		ll x = 1;
		REP(j,N) if(graph2[i][j]) x = x * (h2[k][j] + 1) % MOD;
		h2[k+1][i] = (int)x;
	}
	
	// cout << 'a' << endl;
	
	REP(i,N) REP(j,N) if(h[5][i] == h2[5][j]) f[i] = j;
	
	REP(i,N){
		printf("%d", f[i] + 1);
		if(i == N-1) printf("\n"); else printf(" ");
	}
	fflush(stdout);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		int n,m;
		cin >> n >> m;
		// printf("Case #%d: ", tc + 1);
		main2(m);
	}
//	for(int i=10;i<=50;i++) check(i);
	return 0;
}
