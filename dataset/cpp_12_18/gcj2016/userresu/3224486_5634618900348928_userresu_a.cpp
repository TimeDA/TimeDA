#include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <set>
 #include <map>
 #include <string>
 #include <cstring>
 using namespace std;
 
 char s[20001];
 void main2 () {
 	scanf("%s",s);
 	int n = strlen(s);
 	string t = "";
 	string p;
 	for (int j=0;j<n;++j) t += s[j];
 	int ans = 0;
 	while (t.size()) {
 		p = "";
 		for (int j=0;j<t.size();++j) {
 			if (p.size() && p[p.size()-1] == t[j]) {
 				p.pop_back();
 				ans += 10;
 			}
 			else p += t[j];
 		}
 		if (p.size() == t.size()) {
 			ans += 5 * (p.size()/2);
 			break;
 		}
 		t = p;
 	}
 	printf("%d\n",ans);
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
