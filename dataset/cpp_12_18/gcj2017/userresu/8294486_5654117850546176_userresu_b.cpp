#include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <queue>
 #include <set>
 #include <map>
 #include <string>
 using namespace std;
 
 void main2 () {
 	int N, R,O,Y,G,B,V;
 	scanf("%d %d %d %d %d %d %d",&N,&R,&O,&Y,&G,&B,&V);
 	if (R < G || Y < V || B < O) {
 		printf("IMPOSSIBLE\n");
 		return;
 	}
 	else if (R == G && Y+V+B+O == 0) {
 		for (int i=0;i<R;++i) printf("RG");
 		printf("\n");
 		return;
 	}
 	else if (Y == V && R + G + B + O == 0) {
 		for (int i=0;i<Y;++i) printf("YV");
 		printf("\n");
 		return;
 	}
 	else if (B == O && R + G + Y + V == 0) {
 		for (int i=0;i<B;++i) printf("BO");
 		printf("\n");
 		return;
 	}
 	R -= G;
 	Y -= V;
 	B -= O;
 	pair<int,char> x[3];
 	x[0] = make_pair(R, 'R');
 	x[1] = make_pair(Y, 'Y');
 	x[2] = make_pair(B, 'B');
 	sort(x,x+3);
 	if (x[0].first + x[1].first < x[2].first) {
 		printf("IMPOSSIBLE\n");
 		return;
 	}
 	vector<string> v(x[2].first);
 	for (int i=0;i<x[2].first;++i) v[i] = "";
 	for (int i=0;i<x[0].first;++i) v[i] += x[0].second;
 	for (int i=x[2].first-1;i>=x[2].first-x[1].first;--i) v[i] += x[1].second;
 	string s = "";
 	for (int i=0;i<x[2].first;++i) {
 		s += x[2].second;
 		s += v[i];
 	}
 	int doneR=0, doneY=0, doneB = 0;
 	string t = "";
 	for (int i=0;i<s.size();++i) {
 		if (s[i] == 'R') {
 			if (!doneR) {
 				doneR = 1;
 				for (int j=0;j<G;++j) t += "RG";
 			}
 		}
 		else if (s[i] == 'Y') {
 			if (!doneY) {
 				doneY = 1;
 				for (int j=0;j<V;++j) t += "YV";
 			}
 		}
 		else {
 			if (!doneB) {
 				doneB = 1;
 				for (int j=0;j<O;++j) t += "BO";
 			}
 		}
 		t += s[i];
 	}
 	int cnt[256];
 	for (int i=0;i<256;++i) cnt[i] = 0;
 	for (int i=0;i<t.size();++i) ++cnt[t[i]];
 	if (cnt['R'] != R + G || cnt['Y'] != Y + V || cnt['B'] != B + O || cnt['G'] != G || cnt['V'] != V || cnt['O'] != O) printf("IMPOSSIBLE\n");
 	else printf("%s\n",t.c_str());
 }
 
 int main () {
 	int T = 1;
 	scanf("%d",&T);
 	for (int z=1;z<=T;++z) {
 		printf("Case #%d: ",z);
 		main2();
 	}
 	return 0;
 }
