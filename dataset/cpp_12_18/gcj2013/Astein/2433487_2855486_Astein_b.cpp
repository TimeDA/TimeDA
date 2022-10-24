#include <vector>
 #include <cstdio>
 
 using namespace std;
 
 struct Point {
 	int x, y;
 };
 
 int n;
 vector<Point> a;
 int order[15], ret[15];
 double maxarea;
 int c[15];
 
 #define EPSILON 0.000000001
 #define abs(x) (((x) < 0) ? -(x) : (x))
 
 inline double det(double x11, double x12, double x21, double x22)
 {
    return x11 * x22 - x12 * x21;
 }
 
 inline double vec(double x11, double x12, double x21, double x22)
 {
    return x11 * x21 + x12 * x22;
 }
 
 inline bool isBetween(double x0, double x1, double x2)
 {
    return x1 < x2 ? (x1 - EPSILON < x0 && x0 < x2 + EPSILON) : 
                 (x2 - EPSILON < x0 && x0 < x1 + EPSILON);
 }
 
 inline bool isOnSegment(Point p, Point a, Point b)
 {
    //printf("det = %.12lf\n", (abs(det(p.x - a.x, p.y - a.y, b.x - a.x, b.y - a.y))));
    return (abs(det(p.x - a.x, p.y - a.y, b.x - a.x, b.y - a.y)) < EPSILON) && 
       isBetween(p.x, a.x, b.x) && isBetween(p.y, a.y, b.y);
 }
 
 int getCrossP(Point a, Point b, Point p, Point q, Point& cp)
 {
    double mdet = det(b.x - a.x, p.x - q.x, b.y - a.y, p.y - q.y);
    if (abs(mdet) < EPSILON) 
 	 {
 	 	 if (isOnSegment(p, a, b)) return 1;
 	 	 if (isOnSegment(q, a, b)) return 1;
 	 	 if (isOnSegment(a, p, q)) return 1;
 	 	 if (isOnSegment(b, p, q)) return 1;
 		 return 0; // no intersection here
 	 }
    double t1 = det(p.x - a.x, p.x - q.x, p.y - a.y, p.y - q.y) / mdet;
    double t2 = det(b.x - a.x, p.x - a.x, b.y - a.y, p.y - a.y) / mdet;
    if (t1 < -EPSILON || t1 > 1 + EPSILON || t2 < -EPSILON || t2 > 1 + EPSILON) return -1; // no intersection here
    // Now we have new intersection point
    cp.x = p.x + t2 * (q.x - p.x);
    cp.y = p.y + t2 * (q.y - p.y);
    return 1;
 }
 
 void backtr(int k) {
 	if (k == n) {
 		// check self-intersect
 		bool ispos = true;
 		Point cp;
 		for (int i = 0; i < n; ++i) {
 			for (int j = i + 1; j < n; ++j) {
 				if ((j + 1) % n == i) continue;
 				if ((i + 1) % n == j) continue;
 				if (getCrossP(a[order[i]], a[order[(i + 1) % n]],
 							a[order[j]], a[order[(j + 1) % n]], cp) == 1) { ispos = false; break; }
 
 				// Point[order[i]] - Point[order[(i + 1) % n]]
 				// Point[order[j]] - Point[order[(j + 1) % n]]
 			}
 		}
 		if (ispos) {
 			double area = 0;
 			for (int i = 0; i < n; ++i) {
 				int j = (i + 1) % n;
 				area += (a[order[i]].x * a[order[j]].y) - (a[order[i]].y * a[order[j]].x);
 			}
 			area = abs(area);
 			if (area > maxarea) {
 				maxarea = area;
 				for (int i = 0; i < n; ++i)
 					ret[i] = order[i];
 			}
 		}
 		return;
 	}
 	for (int i = 1; i < n; ++i) {
 		if (c[i] == 0) {
 			c[i] = 1;
 			order[k] = i;
 			backtr(k + 1);
 			c[i] = 0;
 		}
 	}
 }
 
 
 int main() {
 	int T;
 	scanf("%d", &T);
 
 	for (int cn = 1; cn <= T; ++cn) {
 		scanf("%d", &n);
 		a.resize(n);
 		for (int i = 0; i < n; ++i)
 			scanf("%d%d", &a[i].x, &a[i].y);
 		order[0] = 0;
 		c[0] = 1;
 		maxarea = -1;
 		backtr(1);
 		printf("Case #%d:", cn);
 		for (int i = 0; i < n; ++i)
 			printf(" %d", ret[i]);
 		printf("\n");
 	}
 }
