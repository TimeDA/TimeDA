#include <cstdio>
 #include <cstring>
 using namespace std;
 
 int T;
 char s[1002];
 int main () {
 	scanf("%d",&T);
 	for (int z=1;z<=T;++z) {
 		int x;
 		scanf("%s %d",s,&x);
 		int n = strlen(s), cnt = 0;
 		for (int j=0;j<n;++j) if (s[j] == '-') {
 			if (j + x <= n) {
 				++cnt;
 				for (int k=0;k<x;++k) s[j+k] = '+'+'-'-s[j+k];
 			}
 			else {
 				cnt = -1;
 				break;
 			}
 		}
 		printf("Case #%d: ",z);
 		if (cnt == -1) printf("IMPOSSIBLE\n");
 		else printf("%d\n",cnt);
 	}
 	return 0;
 }
