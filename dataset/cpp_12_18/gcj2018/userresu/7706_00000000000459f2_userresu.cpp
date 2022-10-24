#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
using namespace std;
typedef long long ll;

int A[100001],B[10001],C[1000];
int gd[1000];
void main2 () {
	int N;
	int tmp = 1;
	scanf("%d",&N);
	for (int i=1;i<=N;++i) {
		int x;
		scanf("%d",&x);
		gd[i] = x;
		for (int j=1;j<=x;++j) A[tmp++] = i;
	}
	if (gd[1] == 0 || gd[N] == 0) {
		printf("IMPOSSIBLE\n");
		return;
	}
	for (int i=1;i<=N;++i) B[i] = 1;
	string s = "";
	for (int j=1;j<=N;++j) {
		for (int i=1;i<=N;++i) C[i] = 0;
		int tmp = 1;
		for (int i=1;i<=N;++i) {
			if (B[i] == 0) {
				s += ".";
				continue;
			}
			if (A[tmp] < i) {
				if (s[s.size()-1] == '\\') {
					printf("IMPOSSIBLE\n");
					return;
				}
				s+="/", C[i-1] += B[i];
			}
			else if (A[tmp] > i) s+="\\", C[i+1] += B[i];
			else s+=".", C[i] += B[i];
			tmp += B[i];
		}
		s+="\n";
		bool ok = 1;
		for (int i=1;i<=N;++i) if (B[i] != gd[i]) ok=0;
		if (ok) { 
			printf("%d\n%s\n",j,s.c_str());
			return;
		}
		for (int i=1;i<=N;++i) B[i] = C[i];
	}
	printf("IMPOSSIBLE\n");
}

int main () {
	int T = 1;
	scanf("%d",&T);
	for (int z=1;z<=T;++z) {
		printf("Case #%d: ", z);
		main2();
	}
	return 0;
}
