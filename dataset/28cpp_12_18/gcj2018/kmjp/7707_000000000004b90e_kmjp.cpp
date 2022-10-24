#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T,testcase;
int N,K;
int A[303],B[303],C[303],D[303];
vector<int> E[303];
vector<int> R;
int vis[303];

void dfs(int cur) {
	if(vis[cur]) return;
	vis[cur]=1;
	R.push_back(cur+1);
	FORR(e,E[cur]) dfs(e);
}
void solve(int TC) {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i]>>B[i]>>C[i]>>D[i];
		E[i].clear();
	}
	FOR(y,N) FOR(x,N) if(x!=y) {
		if(A[x]==A[y]&&B[x]==B[y]) E[x].push_back(y);
		if(A[x]==C[y]&&B[x]==D[y]) E[x].push_back(y);
		if(C[x]==A[y]&&D[x]==B[y]) E[x].push_back(y);
		if(C[x]==C[y]&&D[x]==D[y]) E[x].push_back(y);
	}
	
	R.clear();
	ZERO(vis);
	dfs(0);
	
	
	_P("Case #%d:",TC);
	FORR(r,R) _P(" %d",r);
	_P("\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0);
	
	cin>>T;
	for(testcase=1;testcase<=T;testcase++) solve(testcase);
	return 0;
}
