#include<bits/stdc++.h>
#define ALL(c) (c).begin(), (c).end()
using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e6+6;

int cnt(vector<string> &s, int ax, int bx, int ay, int by){
	int res = 0;
	for(int i=ax;i<=bx;++i)
	for(int j=ay;j<=by;++j) if(s[i][j]=='@') ++res;
	return res;
}


void solve(int test){
	cout<<"Case #"<<test<<": ";
	
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	
	int c = 0;
	vector<string> s(n);
	for(auto &r : s){
		cin>>r;
		for(char x : r) if(x=='@') ++c;
	}
	
	
	bool ans = false;
	
	
	if(c%(a+1)==0 && c%(b+1)==0 && c%((a+1)*(b+1))==0){
		int qa = c / (a+1);
		int qb = c / (b+1);
		vector<int> rows, cols;
		rows.push_back(-1);
		cols.push_back(-1);
		bool ok = true;
		for(int i=0;i<n;++i){
			int f = cnt(s, rows.back()+1, i, 0, m-1);
			if(f>qa){
				ok = false;
				break;
			}
			if(f==qa){
				rows.push_back(i);
			}
		}
		for(int j=0;j<m;++j){
			int f = cnt(s, 0, n-1, cols.back()+1, j);
			if(f>qb){
				ok = false;
				break;
			}
			if(f==qb){
				cols.push_back(j);
			}
		}
		//for(int i : rows) cout<<i<<' '; cout<<endl;
		//for(int i : cols) cout<<i<<' '; cout<<endl;
		if(ok ){
			int q = c / (a+1) / (b+1);
			for(int i=1;i<rows.size();++i)
			for(int j=1;j<cols.size();++j){
				int f = cnt(s, rows[i-1]+1, rows[i], cols[j-1]+1, cols[j]);
				if(f!=q){
					ok = false;
					break;
				}
			}
			if(ok) ans = true;
		}
		
	}
	
	if(ans) cout<<"POSSIBLE"<<endl;
	else cout<<"IMPOSSIBLE"<<endl;
}

int main(){
	//freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);//cout.precision(12);cout<<fixed;
	
	int t;
	cin>>t;
	for(int i=1;i<=t;++i) solve(i);
	
	return 0;
}
