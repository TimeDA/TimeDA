#include <iostream>
 #include <vector>
 #include <string>
 #include <cstdio>
 
 using namespace std;
 
 string make(int a, int b, int N, int R, int P, int S){
 	vector<int> cur, prev;
 	cur.push_back(a);
 	cur.push_back(b);
 	for(int i=1;i<N;i++){
 		prev = cur;
 		cur.clear();
 		for(int j=0;j<prev.size();j++){
 			for(int k=0;k<2;k++) cur.push_back((prev[j]+k)%3);
 		}
 	}
 	int cnt[3] = {0, 0, 0};
 	for(int i=0;i<cur.size();i++) cnt[cur[i]]++;
 	if(P != cnt[0] || R != cnt[1] || S != cnt[2]) return "";
 	vector<string> vs;
 	for(int i=0;i<cur.size();i++){
 		switch(cur[i]){
 			case 0: vs.push_back("P"); break;
 			case 1: vs.push_back("R"); break;
 			case 2: vs.push_back("S"); break;
 		}
 	}
 	for(int i=0;i<N;i++){
 		vector<string> next;
 		for(int j=0;j<vs.size();j+=2){
 			if(vs[j] < vs[j+1]) next.push_back(vs[j] + vs[j+1]);
 			else next.push_back(vs[j+1] + vs[j]);
 		}
 		vs = next;
 	}
 	return vs[0];
 }
 
 int main(){
 	int T; cin >> T;
 	for(int t=1;t<=T;t++){
 		int N, R, P, S;
 		cin >> N >> R >> P >> S;
 		string res = "";
 		for(int i=0;i<3;i++){
 			string s = make(i, (i+1)%3, N, R, P, S);
 			if(s == "") continue;
 			if(res == "") res = s;
 			else res = min(res, s);
 		}
 		printf("Case #%d: ", t);
 		if(res == "") cout << "IMPOSSIBLE" << endl;
 		else cout << res << endl;
 	}
 
 }
