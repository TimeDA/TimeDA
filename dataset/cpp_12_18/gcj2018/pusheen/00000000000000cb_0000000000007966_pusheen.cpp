#include<stdio.h>
long long value(char *s){
	long long t=1,sum=0;
	for(int i=0;s[i];i++){
		if(s[i]=='C') t<<=1;
		else sum+=t;
	}
	return sum;
}
bool adj(char *s){
	int n=0;
	for(;s[n];n++);
	for(int i=n-1;i>0;i--){
		if(s[i]=='S'&&s[i-1]=='C'){
			s[i]='C';
			s[i-1]='S';
			return true;
		}
	}
	return false;
}
int main(){
	int T,TN;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		printf("Case #%d: ", T);
		long long n,cnt=0;
		char s[1001];
		scanf("%lld%s",&n,s);
		while(value(s)>n){
			if(!adj(s)) break;
			cnt++;
		}
		if(value(s)<=n){
			printf("%d\n",cnt);
		} else {
			printf("IMPOSSIBLE\n");
		}
	}
}
