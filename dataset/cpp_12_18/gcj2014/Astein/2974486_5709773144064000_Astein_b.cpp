#include <cstdio>
 
 using namespace std;
 
 int main()
 {
 	int T;
 	scanf("%d", &T);
 	for (int cn = 1; cn <= T; ++cn) {
 		double c, f, x;
 		scanf("%lf%lf%lf", &c, &f, &x);
 
 		double ret = x / 2.0;
 		double r = 0;
 		double speed = 2.0;
 		double last = 1e99;
 		for (int numf = 1; ; ++numf)
 		{
 			r = r + (c / speed);
 			speed += f;
 			double cur = r + x / speed;
 			if (ret > cur) ret = cur;
 			if (cur > last) break;
 			last = r + x / speed;
 		}
 		printf("Case #%d: %.10lf\n", cn, ret);
 	}
 }
