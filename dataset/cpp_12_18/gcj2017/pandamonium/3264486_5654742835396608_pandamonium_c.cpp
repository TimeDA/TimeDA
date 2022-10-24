#include <bits/stdc++.h>
 using namespace std;
 int t;
 typedef long long ll;
 typedef pair<ll,ll> ii;
 ll n,k;
 map <ll,ll> mp;
 int main(){
 	scanf("%d",&t);
 	for(int tc=1;tc<=t;tc++){
 		scanf("%lld %lld",&n,&k);
 		ll s=1ll,e=n;
 		while(s<e){
 			ll m=(s+e)/2ll+1ll,ppl=0ll;
 			mp.clear();
 			mp[-n]=1ll;
 			while(!mp.empty()){
 				ii b=(*mp.begin());
 				mp.erase(mp.begin());
 				b.first=-b.first;
 				ppl+=b.second;
 				if(b.first%2ll){
 					if(b.first/2ll>=m){
 						mp[-b.first/2ll]+=2ll*b.second;
 					}
 				}
 				else{
 					if(b.first/2ll>=m){
 						mp[-b.first/2ll]+=b.second;
 					}
 					if((b.first-1ll)/2ll>=m){
 						mp[-(b.first-1ll)/2ll]+=b.second;
 					}
 				}
 			}
 			if(ppl>=k) s=m;
 			else e=m-1ll;
 		}
 		printf("Case #%d: %lld %lld\n",tc,s/2ll,(s-1ll)/2ll);
 	}
 	return 0;
 }
