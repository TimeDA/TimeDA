#include <cstdio>
 #include <vector>
 #include <algorithm>
 #include <thread>
 
 using namespace std;
 
 struct solver
 {
 	int Y,n;
 	int p[30];
 	int s[30];
 
 	double ans;
 	void answer()
 	{
 		int desiredup = 0;
 		for (int i = 0; i < n; i++) {
 			if (p[i] > 0) {
 				desiredup++;
 			}
 		}
 		vector<int> caught;
 		double ans = 1e60;
 		for (int dirb = 0; dirb < (1<<n); dirb++){
 			caught.assign(n, 0);
 			double curp = 0;
 			double curtime = 0;
 			int upcnt = 0;
 			for (int i = 0; i < n; i++) {
 				if (dirb & (1<<i)) {
 					upcnt++;
 				}
 			}
 			if (upcnt != desiredup) continue;
 			for (int dir = 0; dir < n; dir++) {
 				int upper = 0;
 				if (dirb & (1<<dir)) upper = 1;
 
 				double mintime = 1e60;
 				int minv = -1;
 				for (int i = 0; i < n; i++) {
 					if (caught[i]) continue;
 					double calc;
 					if (upper && p[i] > 0) {
 						calc = (p[i]+s[i]*curtime - curp) / (double)(Y-s[i]);
 						if (calc < mintime) {
 							mintime = calc;
 							minv = i;
 						}
 					}
 					if (!upper && p[i] < 0) {
 						calc = (curp - (p[i]-s[i]*curtime)) / (double)(Y-s[i]);
 						if (calc < mintime) {
 							mintime = calc;
 							minv = i;
 						}
 					}
 				}
 				if (minv >= 0) {
 					caught[minv] = 1;
 					if (upper) {
 						curp += mintime * Y;
 					} else {
 						curp -= mintime * Y;
 					}
 				}
 				curtime += mintime;
 				if (curtime >= ans) break;
 			}
 			ans = min(ans, curtime);
 		}
 		this->ans = ans;
 	}
 } instance[4];
 
 void answer(solver *s)
 {
 	s->answer();
 }
 int main(){
 	int T;
 	scanf("%d",&T);
 	for (int testcase = 1; testcase <= T; testcase+=4) {
 		fprintf(stderr,"Processing %d\n", testcase);
 		if (testcase + 1 > T) {
 			for (int tt = 0; tt < 1; tt++) {
 				scanf("%d%d",&instance[tt].Y,&instance[tt].n);
 				for (int i = 0; i < instance[tt].n; i++) scanf("%d",&instance[tt].p[i]);
 				for (int i = 0; i < instance[tt].n; i++) scanf("%d",&instance[tt].s[i]);
 			}
 			instance[0].answer();
 			printf("Case #%d: %.10f\n", testcase, instance[0].ans);
 		} else {
 			int left = min(4,T-testcase+1);
 			vector<thread> threads;
 			for (int tt = 0; tt < left; tt++) {
 				scanf("%d%d",&instance[tt].Y,&instance[tt].n);
 				for (int i = 0; i < instance[tt].n; i++) scanf("%d",&instance[tt].p[i]);
 				for (int i = 0; i < instance[tt].n; i++) scanf("%d",&instance[tt].s[i]);
 
 				threads.emplace_back(answer, &instance[tt]);
 			}
 			for (int tt = 0; tt < left; tt++) {
 				threads[tt].join();
 				printf("Case #%d: %.10f\n", testcase+tt, instance[tt].ans);
 			}
 		}
 	}
 	return 0;
 }