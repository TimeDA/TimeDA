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

int T,tcase;
int N;
vector<int> C[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	for(tcase=1;tcase<=T;tcase++) {
		cin>>N;
		int S=0;
		C[0].clear();
		FOR(i,N) cin>>x, C[x].push_back('A'+i);
		_P("Case #%d:",tcase);
		for(i=1000;i>0;i--) {
			while(C[i].size()) {
				_P(" %c",C[i].back());
				C[i-1].push_back(C[i].back());
				C[i].pop_back();
				if(C[i].size()==1) {
					_P("%c",C[i].back());
					C[i-1].push_back(C[i].back());
					C[i].pop_back();
				}
			}
		}
		
		_P("\n");
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
