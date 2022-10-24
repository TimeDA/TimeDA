#include <iostream>
 #include <vector>
 #include <algorithm>
 #include <cstdio>
 #include <cmath>
 
 using namespace std;
 
 int solve(){
 	int N, P; cin >> N >> P;
 	vector<int> g(N);
 	for(int i=0;i<N;i++) cin >> g[i];
 	vector< vector< pair<int,int> > > vp(N);
 	for(int i=0;i<N;i++){
 		for(int j=0;j<P;j++){
 			int p; cin >> p;
 			double low = p/1.1/g[i];
 			double high = p/0.9/g[i];
 			int l = ceil(low);
 			int h = floor(high);
 			if(l > h) continue;
 			vp[i].push_back(make_pair(l, h));
 		}
 		sort(vp[i].begin(), vp[i].end());
 	}
 	vector<int> idx(N, 0);
 	int res = 0;
 	while(true){
 		bool end = false;
 		for(int i=0;i<N;i++) if(vp[i].size() == idx[i]) end = true;
 		if(end) break;
 		int l = vp[0][idx[0]].first;
 		int h = vp[0][idx[0]].second;
 		for(int i=1;i<N;i++){
 			l = max(l, vp[i][idx[i]].first);
 			h = min(h, vp[i][idx[i]].second);
 		}
 		if(l <= h){
 			++res;
 			for(int i=0;i<N;i++) ++idx[i];
 		} else {
 			int minIdx = 0;
 			for(int i=1;i<N;i++){
 				if(vp[minIdx][idx[minIdx]] > vp[i][idx[i]]) minIdx = i;
 			}
 			++idx[minIdx];
 		}
 	}
 	return res;
 }
 
 int main(){
 	int T; cin >> T;
 	for(int t=1;t<=T;t++){
 		printf("Case #%d: %d\n", t, solve());
 	}
 }
