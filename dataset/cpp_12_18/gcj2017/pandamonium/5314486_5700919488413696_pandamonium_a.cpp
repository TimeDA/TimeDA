#include <bits/stdc++.h>
 using namespace std;
 int t,n,p,k,a[10];
 int main(){
 	scanf("%d",&t);
 	for(int tc=1;tc<=t;tc++){
 		scanf("%d %d",&n,&p);
 		memset(a,0,sizeof(a));
 		for(int x=0;x<n;x++){
 			scanf("%d",&k);
 			a[k%p]++;
 		}
 		if(p==2) printf("Case #%d: %d\n",tc,a[0]+(a[1]+1)/2);
 		else if(p==3){
 			if(a[1]==a[2]) printf("Case #%d: %d\n",tc,a[0]+a[1]);
 			else printf("Case #%d: %d\n",tc,a[0]+min(a[1],a[2])+(max(a[1],a[2])-min(a[1],a[2])-1)/3+1);
 		}
 		else{
 			int ans=a[0]+min(a[1],a[3]);
 			int k2=max(a[1],a[3])-min(a[1],a[3]);
 			int temp1=k2/4+a[2]/2;
 			if(a[2]%2==1&&k2%4==3) temp1+=2;
 			else if(a[2]%2==1||k2%4>0) temp1++;
 			int temp2=min(k2/2,a[2]);
 			if(a[2]*2<k2) temp2+=(k2-a[2]*2-1)/4+1;
 			else if(a[2]*2>k2){
 				int k3=a[2]-k2/2;
 				temp2+=k3/2;
 				if(k3%2==1||k2%2==1) temp2++;
 			}
 			printf("Case #%d: %d\n",tc,ans+max(temp1,temp2));
 		}
 	}	
 	return 0;
 }
