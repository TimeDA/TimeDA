#include<stdio.h>
 #include<algorithm>
 //#define DEBUG
 #ifdef DEBUG
 #define CASET printf("Case #%d: \n",T)
 #define eprintf(...) printf(__VA_ARGS__)
 #else
 #define CASET printf("Case #%d: ",T)
 #define eprintf(...) 
 #endif
 struct E {
 	int val;
 	int index;
 	bool operator<(E x)const {
 		return val<x.val;
 	}
 } EE[1000001];
 int a[100001];
 int solve(){
 	int i,j,k;
 	int n,m;
 	scanf("%d",&n);
 	for(i=0;i<n;i++){
 		scanf("%d",&EE[i].val);
 		EE[i].index=i;
 	}
 	std::sort(EE,EE+n);
 	for(i=0;i<n;i++){
 		a[EE[i].index]=i;
 	}
 	int perm[11];
 	for(i=0;i<n;i++){
 		perm[i]=i;
 	}
 	int ans=10000;
 	do {
 		int inv=0;
 		for(i=0;i<n;i++){
 			for(j=i+1;j<n;j++){
 				if(perm[j]<perm[i])inv++;
 			}
 		}
 		for(i=1;i<n;i++){
 			if(a[perm[i]]<a[perm[i-1]])break;
 		}
 		for(;i<n;i++){
 			if(a[perm[i]]>a[perm[i-1]])break;
 		}
 		if(i==n&&inv<ans)ans=inv;
 	} while(std::next_permutation(perm,perm+n));
 	return ans;
 }
 int main(){
 	int T,TN=1000000;
 #ifndef DEBUG
 	scanf("%d",&TN);
 #endif
 	for(T=1;T<=TN;T++){
 		CASET;
 		int k=solve();
 		if(k==-1){
 			puts("NOT POSSIBLE");
 		} else {
 			printf("%d\n",k);
 		}
 	}
 }
