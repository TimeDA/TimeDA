#include<stdio.h>
#include<algorithm>
int solve(int *a, int n){
	static int s[1000002], b[1000002], c[1000002], t[1000002];
	int B=0, C=0;
	int i;
	for(i=0;i<n;i++){
		s[i]=a[i];
		if(i%2) c[C++]=a[i];
		else b[B++]=a[i];
	}
	std::sort(s,s+n);
	std::sort(b,b+B);
	std::sort(c,c+C);
	B=0, C=0;
	for(i=0;i<n;i++){
		if(i%2){
			if(s[i]!=c[C++]) return i;
		} else {
			if(s[i]!=b[B++]) return i;
		}
	}
	return n;
}
int s[1000002];
int main(){
	int T,TN;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		printf("Case #%d: ", T);
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&s[i]);
		}
		int k=solve(s, n);
		if(k==n){
			puts("OK");
		} else {
			printf("%d\n", k);
		}
	}
}