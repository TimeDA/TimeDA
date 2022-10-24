#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long LL;

const int MAXN=100000;
const int MAXM=200;

const LL INF=1000000000*(LL)MAXN;

int n,m,ans;
LL w[MAXN+1];
LL d[MAXN+1][MAXM+1];

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i];
}

void solve()
{
	m=200;
	d[0][0]=0;
	for(int i=1;i<=m;i++)
		d[0][i]=INF;
	for(int i=1;i<=n;i++)
	{
		d[i][0]=0;
		for(int j=1;j<=m;j++)
		{
			d[i][j]=INF;
			if(d[i-1][j]<d[i][j])
				d[i][j]=d[i-1][j];
			if(d[i-1][j-1]<=w[i]*6LL && d[i-1][j-1]+w[i]<d[i][j])
				d[i][j]=d[i-1][j-1]+w[i];
		}
	}
	ans=0;
	for(int i=1;i<=m;i++)
		if(d[n][i]<INF)
			ans=i;
}

int main(){
	int test;
	cin>>test;
	for(int cas=1;cas<=test;cas++)
	{
		init();
		solve();
		cout<<"Case #"<<cas<<": "<<ans<<"\n";
	}
}
