#include <bits/stdc++.h>
 #define MOD 1000000007
 using namespace std;
 typedef long long ll;
 ll fact[105],invfact[105];
 int cnt,child[200000],ch[200000][30];
 int mem1[200000];
 char str[1005][105];
 vector <int> adj[200000];
 int t,m,n,i;
 ll expo(ll b, int e){
 	if(e==1) return b;
 	ll ans=expo(b,e/2);
 	ans=(ans*ans)%MOD;
 	if(e%2==1) ans=(ans*b)%MOD;
 	return ans;
 }
 void addstr(int num, int len, int node, int pos){
 	child[node]++;
 	if(pos==len){
 		adj[node].push_back(++cnt);
 		adj[cnt].clear();
 		child[cnt]=1;
 		return;
 	}
 	if(ch[node][str[num][pos]-'A']<0){
 		int c=++cnt;
 		ch[node][str[num][pos]-'A']=c;
 		adj[c].clear();
 		adj[node].push_back(c);
 		addstr(num,len,c,pos+1);
 	}
 	else addstr(num,len,ch[node][str[num][pos]-'A'],pos+1);
 }
 int dfs1(int node){
 	if(adj[node].size()==0) return 0;
 	int ans=0;
 	for(int x=0;x<adj[node].size();x++) ans+=dfs1(adj[node][x]);
 	return ans+min(child[node],n);
 }
 ll dfs2(int node){
 	if(child[node]<=n) return (fact[n]*invfact[n-child[node]])%MOD;
 	for(int x=0;x<adj[node].size();x++){
 		if(child[adj[node][x]]>=n){
 			ll ans=1ll;
 			for(int y=0;y<adj[node].size();y++) ans*=dfs2(adj[node][y]);
 			return ans;
 		}
 	}
 	ll ans=0ll;
 	for(int x=n;x>0;x--){
 		ll temp=(((fact[n]*invfact[x])%MOD)*invfact[n-x])%MOD;
 		for(int y=0;y<adj[node].size();y++){
 			if(child[adj[node][y]]>x){temp=0ll;break;}
 			temp*=(fact[x]*invfact[x-child[adj[node][y]]])%MOD;
 			temp%=MOD;
 		}
 		if(temp==0ll) break;
 		else if((x&1)==(n&1)) ans+=temp;
 		else ans+=MOD-temp;
 		ans%=MOD;
 	}
 	return ans;
 }		
 int main(){
 	fact[0]=1ll;
 	invfact[0]=1ll;
 	for(int x=1;x<=100;x++){
 		fact[x]=(fact[x-1]*ll(x))%MOD;
 		invfact[x]=expo(fact[x],MOD-2);
 	}
 	scanf("%d\n",&t);
 	while(t--){
 		cnt=0;
 		memset(ch,-1,sizeof(ch));
 		memset(child,0,sizeof(child));
 		memset(mem1,0,sizeof(mem1));
 		adj[0].clear();
 		scanf("%d %d\n",&m,&n);
 		for(int x=0;x<m;x++){
 			gets(str[x]);
 			addstr(x,strlen(str[x]),0,0);
 		}
 		printf("Case #%d: %d %lld\n",++i,dfs1(0),dfs2(0));
 	}
 	return 0;
 }
