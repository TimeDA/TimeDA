#include <bits/stdc++.h>
 using namespace std;
 int t,k;
 char str[1005];
 int main(){
 	scanf("%d",&t);
 	for(int tc=1;tc<=t;tc++){
 		scanf("%s %d",str,&k);
 		int len=strlen(str);
 		int ans=0;
 		for(int x=0;x<len;x++){
 			if(str[x]=='-'){
 				if(x+k>len){
 					ans=-1;
 					break;
 				}
 				for(int y=x;y<x+k;y++){
 					if(str[y]=='-') str[y]='+';
 					else str[y]='-';
 				}
 				ans++;
 			}
 		}
 		printf(ans==-1?"Case #%d: IMPOSSIBLE\n":"Case #%d: %d\n",tc,ans);
 	}
 	return 0;
 }
