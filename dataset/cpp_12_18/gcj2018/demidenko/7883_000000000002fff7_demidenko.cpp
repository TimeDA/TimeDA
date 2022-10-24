#include<bits/stdc++.h>
#define ALL(c) (c).begin(), (c).end()
using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e6+6;


void solve(int test){
	cout<<"Case #"<<test<<": ";
	
	int n, P, cur = 0;
	cin>>n>>P;
	vector<ld> d(n*250*2*2 + 5, -1);
	d[0] = 0;
	for(int i=0;i<n;++i){
		int w,h;
		cin>>w>>h;
		cur+=(w+h)*2;
		int f = min(w,h) * 2;
		ld r = hypotl(w,h) * 2;
		
		auto old = d;
		
		for(int s=0;s+f<d.size();++s) if(old[s]>=0){
			d[s+f] = max(d[s+f], old[s] + r);
		}
	}
	
	ld ans = cur, eps = 1e-9;
	for(int s=0;s<d.size() && cur+s<=P;++s) if(d[s]>=0){
		if(cur+d[s]-eps > P) ans = P;
		else ans = max(ans, cur+d[s]);
	}
	
	cout<<ans<<endl;
	
}

int main(){
	//freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.precision(9);cout<<fixed;
	
	int t;
	cin>>t;
	for(int i=1;i<=t;++i) solve(i);
	
	return 0;
}
