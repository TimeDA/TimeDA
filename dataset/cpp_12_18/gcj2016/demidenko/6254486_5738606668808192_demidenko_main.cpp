#include<iostream>
 #include<cstdio>
 #include<cstdlib>
 #include<algorithm>
 #include<vector>
 #include<string>
 #include<set>
 #include<map>
 #include<cmath>
 #include<memory.h>
 #include<assert.h>
 using namespace std;
 typedef long long ll;
 typedef long double ld;
 
 const int N = 1e6+6;
 
 ll sti(string s, int r){
 	ll res = 0;
 	for(char c : s) res = res*r+c-'0';
 	return res;
 }
 
 string its(int x, int r){
 	string res;
 	do{
 		res = char(x%r+'0') + res;
 		x/=r;
 	}while(x);
 	return res;
 }
 
 ll getdiv(ll x){
 	if(x<2) return 0;
 	for(ll i=2;i*i<=x;++i) if(x%i==0) return i;
 	return 0;
 }
 
 int main(){
 	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
 	
 	int n, m;
 	
 	cin>>n>>m;
 	
 	int n2 = 1<<(n-1);
 	vector<int> q;
 	for(int ms=1;ms<n2;ms+=2){
 		int x = ms+n2;
 		q.push_back(x);
 	}
 	
 	cout<<"Case #1:"<<endl;
 	
 	random_shuffle(q.begin(), q.end());
 	for(int x : q){
 		if(m==0) break;
 		string g = its(x, 2);
 		bool ok = true;
 		map<ll,ll> t;
 		for(int base=2;base<=10;++base){
 			ll a = sti(g, base);
 			ll b = getdiv(a);
 			if(!b){
 				ok=false;
 				break;
 			}
 			t[base] = b;
 		}
 		if(ok){
 			cout<<g;
 			for(auto p : t) cout<<' '<<p.second;
 			cout<<endl;
 			--m;
 		}
 	}
 	
 	
 	return 0;
 }
