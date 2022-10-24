#include <cstdio>
 #include <cstring>
 #include <cassert>
 #include <iostream>
 #include <string>
 #include <vector>
 #include <map>
 #include <queue>
 #include <set>
 #include <algorithm>
 #define REP(i, n) for(int i = 0; i < (int)(n); ++i)
 using namespace std;
 typedef long long ll;
 
 double readReal() {
   double x;
   scanf("%lf", &x);
   return x;
 }
 
 struct K {
   double v, x;
 };
 
 K vs[110];
 
 const double EPS = 1e-8;
 
 int main(void) {
   int nCase;
   scanf("%d", &nCase);
   REP(iCase, nCase){
     int n; scanf("%d", &n);
     K target;
     target.v = readReal();
     target.x = readReal();
     REP(i, n){
       vs[i].v = readReal();
       vs[i].x = readReal();
     }
     
     printf("Case #%d: ", iCase+1);
     if(n == 1){
       if(vs[0].x != target.x){
 	puts("IMPOSSIBLE");
       }else{
 	printf("%.10f\n", double(target.v) / vs[0].v);
       }
       continue;
     }
     
     if(n == 2){
       if((vs[0].x < target.x && vs[1].x < target.x) ||
 	 (vs[0].x > target.x && vs[1].x > target.x)){
 	puts("IMPOSSIBLE");
 	continue;
       }
       double res = 1e20;
       REP(i, 2){
 	if(vs[i].x == target.x){
 	  res = min(res, double(target.v) / vs[i].v);
 	}
       }
       if(vs[0].x != vs[1].x){
 	double t1 = (target.v * double(vs[1].x - target.x)) / (vs[0].v * double(vs[1].x-vs[0].x));
 	double t2 = (target.v * double(vs[0].x - target.x)) / (vs[1].v * double(vs[0].x-vs[1].x));
 	assert(t1 >= -EPS);
 	assert(t2 >= -EPS);
 	cerr << res << " " << t1 << " " << t2 << endl;
 	if(t1 >= 0 && t2 >= 0){
 	  res = min(res, max(t1, t2));
 	}
       }else{
 	assert(vs[0].x == target.x);
 	res = min(res, double(target.v) / (vs[0].v + vs[1].v));
       }
       
       printf("%.10f\n", res);
       continue;
     }
     
     puts("NOT IMPLEMENTED");
     //    assert(false);
   }
   return 0;
 }
