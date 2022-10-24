#include <stdio.h>
 #include <algorithm>
 #include <string>
 #include <vector>
 
 using namespace std;
 
 string dat[10];
 
 int ans;
 int anscnt;
 int m,n;
 
 int assignments[10];
 
 int calcTrie(vector<string> &trieCalc)
 {
 	string prev;
 	int ret = 1;
 	for(int i = 0; i < trieCalc.size(); i++) {
 		int samecnt = 0;
 		for(int j = 0; j < prev.length() && j < trieCalc[i].length(); j++) {
 			if (prev[j] != trieCalc[i][j]) {
 				break;
 			}
 			samecnt++;
 		}
 		ret += trieCalc[i].length() - samecnt;
 		prev = trieCalc[i];
 	}
 	return ret;
 }
 
 void rec(int ind)
 {
 	if (ind == m) {
 		vector<int> cntserver(n);
 		for(int i = 0; i < m; i++) {
 			cntserver[assignments[i]]++;
 		}
 		if (*min_element(cntserver.begin(),cntserver.end()) == 0) return;
 		vector<vector<string>> setServer(n);
 		for(int i = 0; i < m; i++) {
 			setServer[assignments[i]].push_back(dat[i]);
 		}
 		int nodecnt = 0;
 		for(int i = 0; i < n; i++) {
 			nodecnt += calcTrie(setServer[i]);
 		}
 		if (nodecnt > ans) {
 			ans = nodecnt;
 			anscnt = 1;
 		} else if (nodecnt == ans) {
 			anscnt++;
 		}
 		return;
 	}
 
 	for(int i = 0; i < n; i++){
 		assignments[ind] = i;
 		rec(ind+1);
 	}
 }
 
 int main(){
 	int T;
 	scanf("%d",&T);
 	for(int testcase = 1; testcase <= T; testcase++) {
 		scanf("%d%d",&m,&n);
 		for(int i = 0;i < m; i++) {
 			char buffer[128];
 			scanf("%s",buffer);
 			dat[i] = buffer;
 		}
 		sort(dat, dat + m);
 		ans = anscnt = 0;
 		rec(0);
 		printf("Case #%d: %d %d\n", testcase, ans, anscnt);
 	}
 	return 0;
 }
