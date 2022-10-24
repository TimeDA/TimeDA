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
 
 int N,K;
 string s[1010];
 int group[1010];
 int BEST,CNT;
 
 void check(void){
 	int mask = 0;
 	int i,j,k;
 	
 	REP(i,N) mask |= (1<<group[i]);
 	if(mask != (1<<K)-1) return;
 	
 	int tmp = 0;
 	REP(i,K){
 		set <string> ss;
 		REP(j,N) if(group[j] == i) REP(k,s[j].length()+1) ss.insert(s[j].substr(0, k));
 		tmp += ss.size();
 	}
 	
 	if(tmp > BEST){
 		BEST = tmp;
 		CNT = 0;
 	}
 	
 	if(tmp == BEST) CNT++;
 }
 
 void dfs(int pos){
 	if(pos == N){
 		check();
 		return;
 	}
 	int i;
 	REP(i,K){
 		group[pos] = i;
 		dfs(pos+1);
 	}
 }
 
 void main2(void){
 	int i;
 	
 	cin >> N >> K;
 	REP(i,N) cin >> s[i];
 	
 	BEST = CNT = -1;
 	dfs(0);
 	
 	cout << BEST << ' ' << CNT << endl;
 }
 
 int main(void){
 	int TC,tc;
 	cin >> TC;
 	REP(tc,TC){
 		printf("Case #%d: ", tc+1);
 		main2();
 	}
 	return 0;
 }
