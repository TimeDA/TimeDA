#include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <set>
 #include <map>
 #include <string>
 using namespace std;
 
 char s[1000];
 void main2 () {
 	int n, m;
 	scanf("%d %d",&n,&m);
 	for (int i=0;i<=n;++i) scanf("%s",s);
 	for (int i=0;i<m;i+=2) printf("01");
 	printf("0 ");
 	for (int i=0;i<m;++i) printf("?");
 	printf("\n");
 }
 
 int main () {
 	int T = 1;
 	scanf("%d",&T);
 	for (int z=1;z<=T;++z) {
 		printf("Case #%d: ",z);
 		main2();
 	}
 	return 0;
 }
