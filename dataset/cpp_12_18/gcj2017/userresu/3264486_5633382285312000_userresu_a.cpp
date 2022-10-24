#include <cstdio>
 #include <vector>
 #include <algorithm>
 using namespace std;
 typedef long long ll;
 
 int T;
 int main () {
 	scanf("%d",&T);
 	for (int z=1;z<=T;++z) {
 		ll x;
 		scanf("%lld",&x);
 		printf("Case #%d: ",z);
 		vector<int> a;
 		while (x) {
 			a.push_back(x%10);
 			x /= 10;
 		}
 		reverse(a.begin(),a.end());
 		for (int i=a.size();i>=0;--i) {
 			bool ok = 1;
 			for (int j=1;j<i;++j) if (a[j] < a[j-1]) {
 				ok = 0;
 				break;
 			}
 			if (!ok || i != a.size() && i && a[i]-1 < a[i-1]) continue;
 			for (int j=0;j<i;++j) printf("%d",a[j]);
 			if (i != a.size() && a[i]-1) printf("%d",a[i]-1);
 			for (int j=i+1;j<a.size();++j) printf("9");
 			break;
 		}
 		printf("\n");
 	}
 	return 0;
 }
