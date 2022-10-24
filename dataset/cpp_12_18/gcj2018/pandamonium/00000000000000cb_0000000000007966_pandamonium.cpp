#include <bits/stdc++.h>
using namespace std;
int t,d,len;
char str[32];
inline int score(){
	int ans=0,pwr=1;
	for(int x=0;x<len;x++) str[x]=='C'?pwr<<=1:ans+=pwr;
	return ans;
}
int main(){
	scanf("%d",&t);
	for(int tc=0;tc<t;tc++){
		scanf("%d %s",&d,str);
		len=strlen(str);
		int cnt=0;
		while(score()>d){
			bool fail=0;
			for(int x=len-1;x>=0;x--){
				if(!x) fail=1;
				else if(str[x]=='S'&&str[x-1]=='C'){
					swap(str[x],str[x-1]);
					break;
				}
			}
			if(fail) break;
			cnt++;
		}
		if(score()>d) printf("Case #%d: IMPOSSIBLE\n",tc+1);
		else printf("Case #%d: %d\n",tc+1,cnt);
	}
	return 0;
}
