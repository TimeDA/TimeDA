#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <iostream>
 #include <sstream>
 #include <vector>
 #include <string>
 #include <math.h>
 #include <queue>
 #include <list>
 #include <algorithm>
 #include <map>
 #include <set>
 #include <stack>
 #define all(c) (c).begin(),(c).end()
 #define present(c,x) (find(c.begin(),c.end(),x) != (c).end())
 #define pb push_back
 #define traverse(v,it) for (typeof(v.begin()) it=v.begin();it!=v.end();it++)
 using namespace std;
 template<class A, class B> A cvt(B x) { stringstream ss; ss<<x; A y; ss>>y; return y; }
 typedef long long int64;
 typedef pair<int,int> PII;
 
 int n,k,m;
 string s;
 
 map<char,vector<char> > cm;
 vector<int> next[1000];
 
 int prev[1000],vis[1000];
 int aug(int id) {
 	if (id==-1) return 1;
 	if (vis[id]) return 0;
 	vis[id]=1;
 	for (int i=0;i<next[id].size();i++) {
 		int id2=next[id][i];
 		if (aug(prev[id2])) {
 			prev[id2]=id;
 			return 1;
 		}
 	}
 	return 0;
 }
 
 int main() {
 	freopen("D-small-attempt0.in","r",stdin);
 	freopen("D-small-attempt0.out","w",stdout);
 	for (char c='a';c<='z';c++) cm[c].push_back(c);
 	cm['o'].push_back('0');
 	cm['i'].push_back('1');
 	cm['e'].push_back('3');
 	cm['a'].push_back('4');
 	cm['s'].push_back('5');
 	cm['t'].push_back('7');
 	cm['b'].push_back('8');
 	cm['g'].push_back('9');
 	int tests;
     cin >> tests;
     for (int test=1;test<=tests;test++) {
 		cin >> k;
 		cin >> s;
 		n=s.size();
 		set<string> all;
 		for (int i=0;i+1<n;i++) {
 			string x=s.substr(i,2);
 			for (int j0=0;j0<cm[x[0]].size();j0++) {
 				for (int j1=0;j1<cm[x[1]].size();j1++) {
 					string y="";
 					y+=cm[x[0]][j0];
 					y+=cm[x[1]][j1];
 					all.insert(y);
 				}
 			}
 		}
 		vector<string> cc(all.begin(),all.end());
 		m=cc.size();
 		for (int i=0;i<m;i++) next[i].clear();
 		for (int i=0;i<m;i++) {
 			for (int j=0;j<m;j++) if (i!=j) {
 				if (cc[i][1]==cc[j][0]) next[i].push_back(j);
 			}
 		}
 		int st=0;
 		memset(prev,-1,sizeof(prev));
 		for (int i=0;i<m;i++) {
 			memset(vis,0,sizeof(vis));
 			st+=aug(i);
 		}
 		if (st==m) st--;
     	printf("Case #%d: %d\n",test,m+(m-st));
     }
     return 0;
 }
