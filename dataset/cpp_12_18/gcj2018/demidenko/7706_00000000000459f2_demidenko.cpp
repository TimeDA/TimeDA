#include<bits/stdc++.h>
#define ALL(c) (c).begin(), (c).end()
using namespace std;
using ll = long long;
using ld = long double;



void solve(int test){
	cout<<"Case #"<<test<<": ";
	int n;
	cin>>n;
	vector<int> a(n);
	for(int &x : a) cin>>x;
	if(a[0]==0 || a.back()==0){
		cout<<"IMPOSSIBLE"<<endl;
	}else{
		vector<int> w(n);
		int l = 0;
		for(int i=0;i<n;++i) if(a[i]){
			for(int k=0;k<a[i];++k) w[l++] = i;
		}
		
		/*for(int i=0;i<n;++i) if(a[i] && w[i]!=i){
			cout<<"IMPOSSIBLE"<<endl;
			return ;
		}*/
		
		int mx = 0;
		for(int i=0;i<n;++i){
			mx = max(mx, abs(i-w[i]));
		}
		
		
		vector<string> ans(mx+1, string(n,'.'));
		
		for(int i=0;i<n;++i){
			int d = abs(i-w[i]);
			if(d>0){
				int x = mx-d;
				int y = i;
				for(int k=0;k<d;++k){
					ans[x][y] = (i<w[i] ? '\\' : '/');
					if(i<w[i]) ++y; else --y;
					++x;
				}
			}
		}
		
		
		cout<<mx+1<<endl;
		for(auto s : ans) cout<<s<<endl;
	}
}

int main(){
	//freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);//cout.precision(12);cout<<fixed;
	
	int T;
	cin>>T;
	for(int t=1;t<=T;++t) solve(t);
	
	return 0;
}
