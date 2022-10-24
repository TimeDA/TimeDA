#include <cstdio>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 /*
  * The expected time is T/p, so we order the levels by expected time so we can pass first the levels with more expected time
  * The exception are the 0 probability levels, that go to the end
  */
 
 struct level {
 	int ind, time, prob;
 };
 
 bool operator < (const level & a, const level & b) {
 	if (a.prob == 0 and b.prob == 0)
 		return a.ind < b.ind;
 	else if (a.prob == 0)
 		return false;
 	else if (b.prob == 0)
 		return true;
 	else if (a.time / double (1-a.prob/100.0L) != b.time / double (1-b.prob/100.0L))
 		return a.time / double (1-a.prob/100.0L) > b.time / double (1-b.prob/100.0L);
 	return a.ind < b.ind;
 }
 
 int main() {
 	int iC, nC;
 	scanf("%d", &nC);
 	for (iC = 1; iC <= nC; iC++) {
 		int n;
 		scanf("%d", &n);
 
 		vector<level> array(n);
 		for (int i=0; i<n; i++) {
 			array[i].ind = i;
 			scanf("%d", &array[i].time);
 		}
 
 		for (int i=0; i<n; i++){
 			scanf("%d", &array[i].prob);
 			//printf("%d %d %d\n", array[i].ind, array[i].time, array[i].prob);
 		}
 
 		sort(array.begin(), array.end());
 		printf("Case #%d:", iC);
 		for (int i=0; i<n; i++) {
 			printf(" %d", array[i].ind);
 		}
 		printf("\n");
 	}
 	return 0;
 }
