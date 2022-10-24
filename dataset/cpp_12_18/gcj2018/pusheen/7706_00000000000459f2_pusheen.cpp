#include<stdio.h>
#include<math.h>
#include<algorithm>

int a[1001];
char map[1001][1001];
void solve(){
	int n;
	scanf("%d",&n);
	
	
	// NO RETURN / continue BEFORE input DONE
	
	int i,j,k;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	if(!a[0] || !a[n-1]) {
		puts("IMPOSSIBLE");
		return;
	}
	a[0]--;
	a[n-1]--;
	int m=1;
	int row=0;
	for(i=0;i<=n+n;i++){
		for(j=0;j<n;j++){
			map[i][j]='.';
		}
		map[i][j]=0;
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<a[i];j++){
			if(m>i){
				if(row < m-i) row = m-i;
				for(k=0;k<m-i;k++){
					map[k][m-k] = '/';
				}
			}
			if(m<i){
				if(row < i-m) row = i-m;
				for(k=0;k<i-m;k++){
					map[k][m+k] = '\\';
				}
			}
			m++;
		}
		
	}
	printf("%d\n",row+1);
	for(i=0;i<=row;i++){
		puts(map[i]);
	}
}
int main(){
	int T,TN;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		printf("Case #%d: ", T);
		solve();
	}
}