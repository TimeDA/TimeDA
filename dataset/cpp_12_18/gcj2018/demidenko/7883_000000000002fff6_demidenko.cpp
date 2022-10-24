#include<bits/stdc++.h>
#define ALL(c) (c).begin(), (c).end()
using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e6+6;


void solve(int test){
	cout<<"Case #"<<test<<": ";
	
	int n, b, m;
	cin>>n>>b>>m;
	
	vector<int> qb(m), qs(m), qp(m);
	for(int i=0;i<m;++i) cin>>qb[i]>>qs[i]>>qp[i];
	
	ll l = 0, r = 3e18;
	while(l<r){
		ll t = (l+r) / 2;
		
		vector<ll> v;
		for(int i=0;i<m;++i) if(qp[i]<t){
			ll cur = qb[i];
			cur = min(cur, (t-qp[i]) / qs[i]);
			v.push_back(cur);
		}
		sort(ALL(v));
		reverse(ALL(v));
		ll g = 0;
		for(int i=0;i<n && i<v.size();++i) g+=v[i];
		if(g<b) l = t+1; else r = t;
	}
	
	cout<<r<<endl;
	
}

int main(){
	//freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);//cout.precision(12);cout<<fixed;
	
	int t;
	cin>>t;
	for(int i=1;i<=t;++i) solve(i);
	
	return 0;
}
