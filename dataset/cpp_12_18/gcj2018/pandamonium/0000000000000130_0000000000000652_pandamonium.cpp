#include <bits/stdc++.h>
using namespace std;
int t;
typedef long long ll;
ll n,k;
map<ll,ll>m;
int main(){
	scanf("%d",&t);
	for(int tc=1;tc<=t;tc++){
		scanf("%lld %lld",&n,&k);
		m.clear();
		m[n]=1ll;
		while(k){
			auto i=m.rbegin();
			ll v=i->first;
			if(i->second>=k){
				printf("Case #%d: %lld %lld\n",tc,v/2ll,(v-1ll)/2ll);
				break;
			}
			k-=i->second;
			m[v/2ll]+=i->second;
			m[(v-1ll)/2ll]+=i->second;
			m.erase(i->first);
		}
	}
	return 0;
}	