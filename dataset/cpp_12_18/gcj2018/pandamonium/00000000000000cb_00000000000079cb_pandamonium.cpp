#include <bits/stdc++.h>
using namespace std;
int t,n,a[4][100004];
int main(){
	scanf("%d",&t);
	for(int tc=1;tc<=t;tc++){
		printf("Case #%d: ",tc);
		scanf("%d",&n);
		for(int x=0;x<n;x++) scanf("%d",&a[x&1][x>>1]);
		sort(a[0],a[0]+((n+1)>>1));
		sort(a[1],a[1]+(n>>1));
		for(int x=0;x<n;x++){
			if(x==n-1) printf("OK\n");
			else if(a[x&1][x>>1]>a[!(x&1)][(x+1)>>1]){
				printf("%d\n",x);
				break;
			}
		}
	}
	return 0;
}
