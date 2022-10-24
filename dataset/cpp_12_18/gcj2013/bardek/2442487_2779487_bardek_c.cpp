#include <cstdio>
 #include <algorithm>
 #include <vector>
 
 #define fru(j,n) for(int j=0;j<n;++j)
 #define tr(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
 #define x first
 #define y second
 
 using namespace std;
 
 typedef pair<int,int> pii;
 typedef long long LL;
 
 const int MAXN = 2001;
 int n;
 
 int A[MAXN],B[MAXN];
 
 vector<int> AMN[MAXN];
 vector<int> AW[MAXN];
 
 bool byl[MAXN];
 int per[MAXN];
 
 bool poprawny()
 {
 #define tab per
 	for(int i=0;i<n;i++)
 	{
 		int t=0;
 		for(int j=0;j<i;j++)if(tab[j]<tab[i])t=max(t,A[j]);
 		if(t+1!=A[i]) return 0;
 	}
 	for(int i=n-1;i>=0;i--)
 	{
 		int t=0;
 		for(int j=i+1;j<n;j++)if(tab[j]<tab[i])t=max(t,B[j]);
 		if(t+1!=B[i]) return 0;
 	}
 	fru(i,n) printf("%d%c",per[i],i==n-1?'\n':' ');
 	return 1;
 }
 
 bool jedz(int p)
 {
 	if(p==n) return poprawny();
 	int pocz=n,kon=n;
 	tr(it,AMN[p]) kon=min(kon,per[*it]-1);
 	if(AW[p].size()) tr(it,AW[p]) pocz=min(pocz,per[*it]);
 	else pocz=0;
 	pocz=max(pocz,A[p]+B[p]-1);
 	if(pocz>kon) return 0;
 	if(A[p]+B[p]==1)
 	{
 		pocz=1;kon=1;
 	}
 	for(int i=pocz;i<=kon;++i) if(!byl[i])
 	{
 		byl[i]=1;
 		per[p]=i;
 		if(jedz(p+1)) return 1;
 		byl[i]=0;
 	}
 	return 0;
 }
 
 
 void solve()
 {
 	scanf("%d",&n);
 	fru(i,n) scanf("%d",&A[i]);
 	fru(i,n) scanf("%d",&B[i]);
 	fru(i,n)
 	{
 		AW[i].clear();
 		AMN[i].clear();
 	}
 	fru(i,n) fru(j,i) 
 	{
 		if(A[j]+1==A[i]) AW[i].push_back(j);
 		if(A[j]>=A[i]) AMN[i].push_back(j);
 	}
 	/*	fru(i,n) for(int j=i+1;j<n;++j)
 		{
 		if(A[j]+1==A[i]) BW[i].
 		}*/
 	fru(i,n+1) byl[i]=0;
 	if(!jedz(0)) printf("NIE ZNALAZLEM!!!\n");
 }
 
 int main()
 {
 	int o;
 	scanf("%d",&o);
 	fru(oo,o)
 	{
 		printf("Case #%d: ",oo+1);
 		solve();
 	}
 	return 0;
 }
