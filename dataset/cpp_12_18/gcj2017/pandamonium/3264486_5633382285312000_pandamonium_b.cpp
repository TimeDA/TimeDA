#include <bits/stdc++.h>
 using namespace std;
 int t;
 char str[25];
 int main(){
 	scanf("%d",&t);
 	for(int tc=1;tc<=t;tc++){
 		scanf("%s",str);
 		int len=strlen(str);
 		for(int x=1;x<len;x++){
 			if(str[x]<str[x-1]){
 				for(int y=x;y<len;y++) str[y]='9';
 				for(int y=x-1;y>=0;y--){
 					if(y==0){
 						str[y]--;
 						if(str[y]=='0') str[y]='#';
 					}
 					else if(str[y]-1>=str[y-1]){
 						str[y]--;
 						break;
 					}
 					else{
 						str[y]='9';
 					}
 				}
 				break;
 			}
 		}
 		printf("Case #%d: ",tc);
 		if(str[0]=='#') printf("%s\n",str+1);
 		else printf("%s\n",str);
 	}
 	return 0;
 }
 
