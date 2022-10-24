#include<stdio.h>
#include<math.h>
#include<algorithm>
long long x[1001],y[1001],z[1001];
long long X[1001],Y[1001],Z[1001];
void solve(){
	int n;
	scanf("%d",&n);
	int s[1001];
	int i,j,k;
	for(i=0;i<n;i++){
		scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
		s[i]=i;
	}
	do {
		for(i=0;i<n;i++){
			X[i]=x[s[i]];
			Y[i]=y[s[i]];
			Z[i]=z[s[i]];
		}
		for(i=2;i<n;i++){
			long long x1=X[i]-X[i-1];
			long long y1=Y[i]-Y[i-1];
			long long z1=Z[i]-Z[i-1];
			long long x2=X[i]-X[i-2];
			long long y2=Y[i]-Y[i-2];
			long long z2=Z[i]-Z[i-2];
			long long XX = y1*z2-y2*z1;
			long long YY = z1*x2-z2*x1;
			long long ZZ = x1*y2-x2*y1;
			for(j=0;j<i-2;j++){
				long long V = XX*(X[i]-X[j])+YY*(Y[i]-Y[j])+ZZ*(Z[i]);
				if(V >= 0 && ZZ <= 0) goto failed;
				if(V <= 0 && ZZ >= 0) goto failed;
				if(V <= 0 && ZZ <= 0 && V >= ZZ*Z[j]) goto failed;
				if(V >= 0 && ZZ >= 0 && V <= ZZ*Z[j]) goto failed;
			}
		}
		for(i=0;i<n;i++){
			printf("%d%c",s[i]+1," \n"[i==n-1]);
		}
		return;
		failed:;
			
		
	} while(std::next_permutation(s,s+n));
}
int main(){
	int T,TN;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		printf("Case #%d: ", T);
		solve();
	}
}