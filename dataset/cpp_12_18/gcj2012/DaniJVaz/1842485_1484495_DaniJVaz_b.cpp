#include <cstdio>
 #include <cstdlib>
 #include <map>
 
 using namespace std;
 
 /*
  * Assuming the circles are squares, we throw away 4/pi of the area, but are still able to colocate all the students
  */
 
 struct student {
 	int radius;
 	double x, y;
 	int ind;
 };
 
 int sortR (const void * a, const void * b) {
 	if (((student*) b)->radius != ((student*) a)->radius)
 		return ((student*) b)->radius - ((student*) a)->radius;
 	else
 		return ((student*) a)->ind - ((student*) b)->ind;
 }
 
 int sortI (const void * a, const void * b) {
 	return ((student*) a)->ind - ((student*) b)->ind;
 }
 
 /*
 2
 2 6 6
 1 1
 3 320 2
 4 3 2
 */
 int main() {
 	int iC, nC;
 	scanf("%d", &nC);
 	for (iC = 1; iC <= nC; iC++) {
 		int n, w, l;
 		scanf("%d %d %d", &n, &w, &l);
 
 		student arr[n];
 		for (int i=0; i<n; i++) {
 			scanf("%d", &arr[i].radius);
 			arr[i].ind = i;
 			arr[i].x = arr[i].y = 0;
 		}
 
 		map<double, double> steps; // Describes the landscape
 		map<double, double>::iterator it, it2;
 		steps[0] = 0;
 
 		qsort(arr, n, sizeof(student), sortR);
 
 		double start = 0;
 		for (int i=0; i<n; i++) {
 			if (start != 0 and start + arr[i].radius > w)
 				start = 0;
 
 			it = steps.upper_bound(start);
 			it--;
 			//printf("Hi %d\n", arr[i].ind);
 
 			while (it->second != 0 and it->second + arr[i].radius > l) {
 				it++;
 				start = it->first;
 			}
 
 			if (start == 0)
 				arr[i].x = 0;
 			else
 				arr[i].x = start + arr[i].radius;
 
 			if (it->second == 0)
 				arr[i].y = 0;
 			else
 				arr[i].y = it->second + arr[i].radius;
 
 			start = arr[i].x + arr[i].radius;
 
 			it = steps.upper_bound(arr[i].x - arr[i].radius);
 			if (it != steps.begin())
 				it--;
 
 			if (it->second < arr[i].y + arr[i].radius) {
 				double val = it->second;
 				if (it->first < arr[i].x - arr[i].radius)
 					it++;
 
 				for (; it!=steps.end() and it->first<arr[i].x + arr[i].radius;) {
 					//printf("Erasing %lf %lf...\n", it->first, it->second);
 					it2 = it;
 					it++;
 					steps.erase(it2);
 				}
 
 				if (it == steps.end() or it->first != arr[i].x + arr[i].radius)
 					steps[arr[i].x + arr[i].radius] = val;
 
 				steps[arr[i].x - arr[i].radius] = arr[i].y + arr[i].radius;
 			}
 
 			/*for (it=steps.begin(); it!=steps.end(); it++)
 				printf("(%lf, %lf) ", it->first, it->second);
 			printf("%lf\n", start);  //*/
 		}
 
 		qsort(arr, n, sizeof(student), sortI);
 		printf("Case #%d:", iC);
 		for (int i=0; i<n; i++)
 			printf(" %lf %lf", arr[i].x, arr[i].y);
 		printf("\n");
 	}
 	return 0;
 }
