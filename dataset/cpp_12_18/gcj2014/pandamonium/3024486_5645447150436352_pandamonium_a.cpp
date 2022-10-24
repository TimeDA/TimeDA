#include <cstdio>
 #include <algorithm>
 using namespace std;
 typedef long long ll;
 int t,n,i;
 ll p,q,r,s,a[1000005],sum;
 int main(){
 	scanf("%d",&t);
 	while(t--){
 		sum=0ll;
 		scanf("%d %lld %lld %lld %lld",&n,&p,&q,&r,&s);
 		if(n==1ll){
 			printf("Case #%d: 0.000000000\n",++i);
 			continue;
 		}
 		ll start=0ll,end;
 		for(int x=0;x<n;x++){
 			a[x]=(ll(x)*p+q)%r+s;
 			sum+=a[x];
 			start=max(start,a[x]);
 		}
 		end=sum;
 		if(n==2ll){
 			printf("Case #%d: %.9lf\n",++i,double(min(a[0],a[1]))/double(sum));
 			continue;
 		}
 		while(start<end){
 			ll m=(start+end)/2ll,tempsum=0ll,cnt=1ll;
 			for(int x=0;x<n;x++){
 				tempsum+=a[x];
 				if(tempsum>m){
 					tempsum=a[x];
 					cnt++;
 					if(cnt>3ll) break;
 				}
 			}
 			if(cnt<=3ll) end=m;
 			else start=m+1ll;
 		}
 		printf("Case #%d: %.9lf\n",++i,double(sum-start)/double(sum));
 	}
 	return 0;
 }
 				
