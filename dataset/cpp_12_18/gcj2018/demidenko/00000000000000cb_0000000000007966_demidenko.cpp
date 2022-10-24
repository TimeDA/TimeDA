#include<bits/stdc++.h>
#define ALL(c) (c).begin(), (c).end()
using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e6+6;

ll calc(string s){
	ll res = 0, cur = 1;
	for(char c : s) if(c=='S') res+=cur; else cur<<=1;
	return res;
}

void solve(int test){
	cout<<"Case #"<<test<<": ";
	int d;
	string s;
	cin>>d>>s;
	int ans = 0;
	while(calc(s) > d){
		int i = -1;
		for(int k=0;k+1<s.size();++k) if(s[k]=='C' && s[k+1]=='S'){
			i = k;
		}
		if(i==-1){
			cout<<"IMPOSSIBLE"<<endl;
			return ;
		}
		swap(s[i], s[i+1]);
		++ans;
	}
	cout<<ans<<endl;
}

int main(){
	//freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);//cout.precision(12);cout<<fixed;
	
	int tn;
	cin>>tn;
	for(int ti=1;ti<=tn;++ti) solve(ti);
	
	
	return 0;
}
