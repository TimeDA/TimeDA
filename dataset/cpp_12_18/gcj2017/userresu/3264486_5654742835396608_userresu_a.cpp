#include <cstdio>
 #include <map>
 using namespace std;
 typedef long long ll;
 
 
 map<ll,ll> mp;
 int main () {
 	int T;
 	scanf("%d",&T);
 	for (int z=1;z<=T;++z) {
 	ll N, K;
 	scanf("%lld %lld",&N,&K);
 	--K;
 	mp.clear();
 	mp[N] = 1;
 	while (1) {
 		map<ll,ll>::iterator I = mp.end();
 		--I;
 		if (I->second <= K) {
 			K -= I->second;
 			int x = (I->first-1)/2, y = I->first - 1 - x;
 			mp[x] += I->second;
 			mp[y] += I->second;
 			mp.erase(I);
 		}
 		else {
 			printf("Case #%d: %lld %lld\n",z,I->first / 2, (I->first-1)/2);
 			break;
 		}
 	}}
 	return 0;
 }
