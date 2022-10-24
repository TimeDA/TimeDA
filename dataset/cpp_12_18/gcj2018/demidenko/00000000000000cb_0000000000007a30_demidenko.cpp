#include<bits/stdc++.h>
#define ALL(c) (c).begin(), (c).end()
using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e6+6;


void read(int &i, int &j){
	cout<<i<<' '<<j<<endl;
	cin>>i>>j;
}

bool a[1111][1111];

void solve(int test){
	//cout<<"Case #"<<test<<": ";
	
	memset(a, 0, sizeof a);
	
	int need;
	cin>>need;
	
	int qw, qh, qs = 1e9;
	for(int w=3;w<=need;++w)
	for(int h=3;h<=need;++h) if(w*h>=need){
		if(qs > w*h || qs==w*h && abs(w-h) < abs(qw-qh)){
			qs = w*h;
			qw = w;
			qh = h;
		}
	}
	
	for(int i=2;i<qw;++i)
	for(int j=2;j<qh;++j){
		for(;;){
			int cnt = 0;
			for(int dx=-1;dx<2;++dx)
			for(int dy=-1;dy<2;++dy) if(a[i+dx][j+dy]) ++cnt;
			if(cnt==9) break;
			int x = i, y = j;
			read(x,y);
			if(x==0 && y==0) return ;
			a[x][y] = true;
		}
	}
}

int main(){
	//freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);//cout.precision(12);cout<<fixed;
	
	
	int tn;
	cin>>tn;
	for(int ti=1;ti<=tn;++ti) solve(ti);
	
	
	
	
	return 0;
}

