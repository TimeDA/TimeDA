#include<bits/stdc++.h>
#define ALL(c) (c).begin(), (c).end()
using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e6+6;


void solve(int test){
	cout<<"Case #"<<test<<": ";
	int n;
	cin>>n;
	vector<int> a, b;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		if(i&1) b.push_back(x);
		else a.push_back(x);
	}
	sort(ALL(a));
	sort(ALL(b));
	bool ok = true;
	for(int i=1, x=a[0], ka=1, kb=0;i<n;++i){
		int y = i%2 ? b[kb++] : a[ka++];
//		cout<<x<<"?"<<y<<endl;
		if(x>y){
			cout<<i-1<<endl;
			return ;
		}
		x = y;
	}
	cout<<"OK"<<endl;
}

int main(){
	//freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);//cout.precision(12);cout<<fixed;
	
	int tn;
	cin>>tn;
	for(int ti=1;ti<=tn;++ti) solve(ti);
	
	
	return 0;
}
