#include <bits/stdc++.h>
using namespace std;
int t,n;
double d,k,s;
int main(){
	scanf("%d",&t);
	for(int tc=1;tc<=t;tc++){
		scanf("%lf %d",&d,&n);
		double ans=1e9;
		for(int x=0;x<n;x++){
			scanf("%lf %lf",&k,&s);
			double tim=d*s/(d-k);
			if(!x||ans-tim>1e-12) ans=tim;
		}
		printf("Case #%d: %lf\n",tc,ans);
	}
	return 0;
}	