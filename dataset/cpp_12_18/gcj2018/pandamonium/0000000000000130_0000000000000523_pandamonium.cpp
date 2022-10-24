#include <bits/stdc++.h>
using namespace std;
int t,a,b,n;
char str[20];
int main(){
	scanf("%d",&t);
	for(int tc=0;tc<t;tc++){
		scanf("%d %d",&a,&b);
		a++;
		scanf("%d",&n);
		while(1){
			int m=(a+b)/2;
			printf("%d\n",m);
			fflush(stdout);
			scanf("%s",str);
			if(str[0]=='C') break;
			if(str[4]=='S') a=m+1;
			else b=m-1;
		}
	}
	return 0;
}