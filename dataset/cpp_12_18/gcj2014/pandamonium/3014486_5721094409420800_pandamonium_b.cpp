#include <bits/stdc++.h>
 using namespace std;
 int ans,minans,a[1005],tmp[1005],orig[1005],num[1005];
 int i,t,n;
 void mergesort(int s, int e){
 	if(e-s<=1) return;
 	int h=(e+s)/2;
 	mergesort(s,h);
 	mergesort(h,e);
 	int x=s,y=h,z=s;
 	while(x<h&&y<e){
 		if(a[x]<=a[y]){
 			tmp[z]=a[x];
 			z++,x++;
 		}
 		else{
 			tmp[z]=a[y];
 			z++,y++;
 			ans+=h-x;
 		}
 	}
 	while(x<h){
 		tmp[z]=a[x];
 		z++,x++;
 	}
 	while(y<e) {
 		tmp[z]=a[y];
 		z++,y++;
 	}
 	for(int i=s;i<e;++i) a[i]=tmp[i];
 }
 int main(){
 	scanf("%d",&t);
 	while(t--){
 		scanf("%d",&n);
 		minans=n*n;
 		for(int x=0;x<n;x++){
 			scanf("%d",&orig[x]);
 			num[x]=orig[x];
 		}
 		sort(num,num+n);
 		do{
 			bool fail=0,dec=0;
 			for(int x=1;x<n;x++){
 				if(num[x]>num[x-1]){
 					if(dec){fail=1;break;}
 				}
 				else dec=1;
 			}
 			if(fail) continue;
 			for(int x=0;x<n;x++){
 				for(int y=0;y<n;y++){
 					if(orig[x]==num[y]){a[x]=y;break;}
 				}
 			}
 			ans=0;
 			for(int x=0;x<n;x++){
 				printf("%d %d\n",num[x],a[x]);
 			}
 			mergesort(0,n);
 			printf("%d\n",ans);
 			minans=min(minans,ans);
 		}while(next_permutation(num,num+n));
 		printf("Case #%d: %d\n",++i,minans);
 	}
 	return 0;
 }		
