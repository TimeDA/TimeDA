#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
#define RI(x) scanf("%d", &x)
#define PB push_back
using namespace std;

int n, a[100005], b[100005];

void ssort(int a[], int s, int n){
	int t = 0;
	for (int i=s; i<n; i+=2) b[t++] = a[i];
	sort(b, b + t);
	t = 0;
	for (int i=s; i<n; i+=2) a[i] = b[t++];
}

int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d: ", TC);
	RI(n);
	FOR(i,0,n) RI(a[i]);
	ssort(a, 0, n);
	ssort(a, 1, n);
	
	FOR(i,0,n-1) if (a[i] > a[i+1]){
		printf("%d\n", i);
		goto NEXT;
	}
	puts("OK");
	NEXT:;
}return 0;}