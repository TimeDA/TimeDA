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
 
 int _free[210];
 int box[210];
 vector <int> key[210];
 
 int diff[210];
 bool opened[210];
 vector <int> graph[210];
 bool visited[210];
 
 void dfs(int x){
 	int i;
 	visited[x] = true;
 	REP(i,graph[x].size()) if(!visited[graph[x][i]]) dfs(graph[x][i]);
 }
 
 bool check(int N){
 	int i,j;
 	
 	REP(i,210) graph[i].clear();
 	REP(i,N) if(!opened[i]) REP(j,key[i].size()) graph[box[i]].push_back(key[i][j]);
 	
 	REP(i,210) visited[i] = false;
 	REP(i,210) if(_free[i] > 0) dfs(i);
 	REP(i,N) if(!opened[i] && !visited[box[i]]) return false;
 	return true;
 }
 
 void main2(void){
 	int K,N,i,j,x,cnt;
 	
 	REP(i,210) _free[i] = 0;
 	REP(i,210) key[i].clear();
 	
 	cin >> K >> N;
 	REP(i,K){
 		cin >> x;
 		_free[x]++;
 	}
 	REP(i,N){
 		cin >> box[i] >> cnt;
 		REP(j,cnt){
 			cin >> x;
 			key[i].push_back(x);
 		}
 	}
 	
 	REP(i,210) diff[i] = _free[i];
 	REP(i,N) diff[box[i]]--;
 	REP(i,N) REP(j,key[i].size()) diff[key[i][j]]++;
 	REP(i,210) if(diff[i] < 0){
 		cout << " IMPOSSIBLE" << endl;
 		return;
 	}
 	
 	REP(i,N) opened[i] = false;
 	if(!check(N)){
 		cout << " IMPOSSIBLE" << endl;
 		return;
 	}
 	
 	REP(i,N){
 		REP(x,N) if(!opened[x] && _free[box[x]] > 0){
 			opened[x] = true;
 			_free[box[x]]--;
 			REP(j,key[x].size()) _free[key[x][j]]++;
 			if(check(N)){
 				cout << ' ' << x + 1;
 				break;
 			}
 			opened[x] = false;
 			_free[box[x]]++;
 			REP(j,key[x].size()) _free[key[x][j]]--;
 		}
 	}
 	cout << endl;
 }
 
 int main(void){
 	int TC,tc;
 	cin >> TC;
 	REP(tc,TC){
 		printf("Case #%d:", tc+1);
 		main2();
 	}
 	return 0;
 }
