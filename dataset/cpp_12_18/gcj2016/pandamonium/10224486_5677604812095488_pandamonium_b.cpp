#include <bits/stdc++.h>
 #define EPS 0.00000000000001
 using namespace std;
 int t,n,k,a,b;
 typedef long double ld;
 typedef __uint128_t ll;
 double prob;
 ll p[20],ans;
 vector <int> v[20][20];
 vector <ll> p2;
 int main(){
 	for(int x=1;x<=16;x++){
 		for(int y=0;y<(1<<x);y++){
 			int cnt=0;
 			for(int z=0;z<x;z++){
 				if((1<<z)&y) cnt++;
 			}
 			v[x][cnt].push_back(y);
 		}
 	}
 	scanf("%d",&t);
 	for(int c=1;c<=t;c++){
 		printf("Case #%d: ",c);
 		scanf("%d %d",&n,&k);
 		for(int x=0;x<n;x++){
 			scanf("%d.%d",&a,&b);
 			p[x]=ll(a*100+b);
 		}
 		ans=ll(0);
 		for(int x=0;x<v[n][k].size();x++){
 			p2.clear();
 			for(int y=0;y<n;y++){
 				if((1<<y)&v[n][k][x]) p2.push_back(p[y]);
 			}
 			ll sum=ll(0);
 			for(int y=0;y<v[k][k/2].size();y++){
 				ll temp=ll(1);
 				for(int z=0;z<k;z++){
 					if((1<<z)&v[k][k/2][y]) temp*=p2[z];
 					else temp*=(ll(100)-p2[z]);
 				}
 				sum+=temp;
 			}
 			if(sum>ans) ans=sum;
 		}
 		ll div=ll(1);
 		for(int x=0;x<k;x++) div*=ll(100);
 		ll ans2=ans%div;
 		while(ans2>ll(1000000000)) ans2/=ll(10);
 		printf("%lld.%lld\n",(long long)(ans/div),(long long)(ans2));
 	}
 	return 0;
 }
