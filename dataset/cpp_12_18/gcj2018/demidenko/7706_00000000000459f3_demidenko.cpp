#include<bits/stdc++.h>
#define ALL(c) (c).begin(), (c).end()
using namespace std;
using ll = long long;
using ld = long double;

const int N = 505;
int d[N][N], inf = 1e9;

int solve(int n, int m){
	
	for(int i=0;i<=n;++i)
	for(int j=0;j<=m;++j) d[i][j] = -inf;
	
	d[0][0] = 0;
	for(int x=0;x<=n;++x)
	for(int y=0;y<=m;++y) if(x||y){
		for(int i=n;i>=x;--i)
		for(int j=m;j>=y;--j){
			d[i][j] = max(d[i][j], d[i-x][j-y]+1);
		}
		
		/*for(int i=0;i<=n;++i){
			for(int j=0;j<=m;++j) if(d[i][j]<0) cout<<"- "; else cout<<d[i][j]<<' ';
			cout<<endl;
		}*/
	}
	
	return d[n][m];
}

void solve(int test){
	cout<<"Case #"<<test<<": ";
	int n, m;
	cin>>n>>m;
	cout<<d[n][m]<<endl;
}

vector<int> compress(vector<int> a){
	vector<int> b = {a[0]};
	vector<int> c = {1};
	for(int i=1;i<a.size();++i) if(a[i]==b.back()) ++c.back();
	else{
		b.push_back(a[i]);
		c.push_back(1);
	}
	return c;
}

int main(){
	//freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);//cout.precision(12);cout<<fixed;
	
	int L = 500;
	solve(L,L);
	/*return 0;
	for(int n=0;n<=L;++n){
		cerr<<n<<"..."<<endl;
		//cout<<"{";
		for(int m=0;m<=L;++m){
			cout<<solve(n,m);
			//if(m==L) cout<<"}";
			cout<<",";
		}
		cout<<endl;
	}
	return 0;*/
	
	int T;
	cin>>T;
	for(int t=1;t<=T;++t) solve(t);
	
	return 0;
}
