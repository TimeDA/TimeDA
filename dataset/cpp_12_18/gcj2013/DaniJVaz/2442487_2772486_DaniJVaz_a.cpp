#include <cstdio>
 #include <algorithm>
 #include <vector>
 
 typedef long long ll;
 
 using namespace std;
 
 struct point{
 	int id;
 	int n;
 	bool end;
 	point(int id=0, int n=0, bool end = false) : id(id), n(n), end(end) {}
 };
 
 struct card {
 	int o, e, p;
 	card(int o=0, int e=0, int p=0) : o(o), e(e), p(p) {}
 
 	bool operator < (const card & c2) const {
 		if (o != c2.o)
 			return o < c2.o;
 		else if (e != c2.e)
 			return e > c2.e;
 		else
 			return p > c2.p;
 	}
 };
 
 int main() {
 	int iC=0, nC;
 	scanf("%d", &nC);
 	for (iC=1; iC<=nC; iC++) {
 		int n, m;
 		scanf("%d %d", &n, &m);
 		vector<card> array;
 
 		for (int i=0; i<m; i++) {
 			card c;
 			scanf("%d %d %d", &c.o, &c.e, &c.p);
 			array.push_back(c);
 		}
 
 		ll losses = 0;
 		for (int i=0; i<(int) array.size(); i++) {
 			sort(array.begin(), array.end());
 			for (int j=i+1; j<m; j++) {
 				if (array[i].e >= array[j].o and array[i].e < array[j].e and array[i].o < array[j].o) {
 					ll p = min(array[i].p, array[j].p);
 					losses += p * (array[j].e-array[i].e) * (array[j].o-array[i].o);
 					losses %= 1000002013;
 
 					if (array[i].p == array[j].p) {
 						swap(array[i].e, array[j].e);
 					}
 					else if (array[i].p < array[j].p) {
 						card c = array[j];
 						c.p = p;
 						array[j].p -= p;
 						swap(array[i].e, c.e);
 						array.push_back(c);
 					}
 					else if (array[i].p > array[j].p) {
 						card c = array[i];
 						c.p -= p;
 						array[i].p = p;
 						swap(array[j].e, array[i].e);
 						array.push_back(c);
 					}
 				}
 			}
 			m = (int) array.size();
 		}
 
 		losses %= 1000002013;
 		printf("Case #%d: %I64d\n", iC, losses);
 	}
 	return 0;
 }