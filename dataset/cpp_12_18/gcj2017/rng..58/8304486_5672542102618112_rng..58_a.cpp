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
 
 set <string> ss;
 set <string> good;
 
 bool sorted(string s){
 	string t = s;
 	sort(t.begin(), t.end());
 	return (s == t);
 }
 
 int C[20][20];
 
 void pre(void){
 	int i,j;
 	REP(i,20) REP(j,i+1){
 		if(j == 0 || j == i) C[i][j] = 1;
 		else C[i][j] = C[i-1][j-1] + C[i-1][j];
 	}
 }
 
 int count_perm(string s){
 	int i,j;
 	int N = s.length();
 	int tot = N;
 	int ans = 1;
 	
 	REP(i,N+1){
 		int cnt = 0;
 		REP(j,N) if(s[j] == (char)('0' + i)) cnt++;
 		ans *= C[tot][cnt];
 		tot -= cnt;
 	}
 	
 	return ans;
 }
 
 void dfs(string s, bool first = true){
 	if(ss.find(s) != ss.end()) return;
 	ss.insert(s);
 	
 	if(sorted(s) && !first) good.insert(s);
 	
 	int i,j;
 	int N = s.length();
 	
 	int sum = 0;
 	REP(i,N) sum += s[i] - '0';
 	if(sum > N) return;
 	
 	string t;
 	REP(i,N-sum) t += '0';
 	for(i=1;i<=N;i++) REP(j,s[i-1]-'0') t += (char)('0' + i);
 	
 	int t_sum = 0;
 	REP(i,N) t_sum += t[i] - '0';
 	
 	if(t_sum <= N){
 		do {
 			dfs(t, false);
 		} while(next_permutation(t.begin(), t.end()));
 	} else {
 		dfs(t, false);
 	}
 }
 
 void main2(void){
 	int i;
 	
 	ss.clear();
 	good.clear();
 	
 	string s;
 	cin >> s;
 	
 	dfs(s);
 	
 	int ans = 0;
 	snuke(good,itr){
 		string t = (*itr);
 		ans += count_perm(t);
 	}
 	
 	sort(s.begin(),s.end());
 	if(good.find(s) == good.end()) ans++;
 	
 	cout << ans << endl;
 }
 
 ////////////////////////////////////////////////////////////////////////////////////////////////////
 
 int main(void){
 	pre();
 	int TC,tc;
 	cin >> TC;
 	REP(tc,TC){
 		printf("Case #%d: ", tc + 1);
 		main2();
 	}
 	return 0;
 }
