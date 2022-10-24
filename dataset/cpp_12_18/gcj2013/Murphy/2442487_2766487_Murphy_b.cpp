#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <string>
 #include <vector>
 #include <cmath>
 #include <algorithm>
 #include <cassert>
 #include <set>
 #include <map>
 #include <queue>
 #include <iostream>
 #include <fstream>
 using namespace std;
 #define pb push_back 
 #define REP(i,n) for(int i=0;i<(n);i++ )
 typedef long long LL;
 typedef pair<int, int> pii;
 
 LL N, P;
 LL B;
 
 LL best(LL k) {
 	if (k == B) {
 		return B + 1;
 	}
 	LL worst = B - k;
 	// cout<<"xxxxxx"<<k<<' '<<worst<<endl;
 	LL t = 1LL << N;
 	LL pos = 0;
 	while (1) {
 		if (worst) {
 			worst--; 
 			pos += t / 2;
 			t /= 2;
 			worst = worst / 2;
 		} else {
 			break;
 		}
 	}
 	return B + 1- pos;
 }
 
 LL worst(LL k) {
 	if (k == 0) {
 		return 1;
 	}
 	LL better = k;
 	LL t = 1LL << N;
 	LL pos = 1;
 	while (1) {
 		if (better) {
 			better--; pos += t / 2;
 			t /= 2;
 			better = (better ) / 2;
 		} else {
 			break;
 		}
 	}
 	return pos;
 }
 
 int main(){
     int caseNumber;
     //scanf("%d", &caseNumber);
     cin>>caseNumber;
     REP(caseN, caseNumber) {
     	cin>>N>>P;
     	LL a1, a2;
     	B = 1LL << N; B--;
     	LL left = 0, right = B;
     	while (left < right) {
     		LL m = (left + right + 1) / 2;
     		if (worst(m) <= P) {
     			left = m;
     		} else {
     			right = m - 1;
     		}
        	}
        	a1 = left;
     	left = 0, right = B;
     	while (left < right) {
     		LL m = (left + right + 1) / 2;
     		LL bm = best(m);
     		// cout<<m<<' '<<bm<<endl;
     		if (bm <= P) {
     			left = m;
     		} else {
     			right = m - 1;
     		}
        	}
        	a2 = left;
     	printf("Case #%d: %lld %lld\n", caseN + 1, a1, a2);
     }
     return 0;
 }