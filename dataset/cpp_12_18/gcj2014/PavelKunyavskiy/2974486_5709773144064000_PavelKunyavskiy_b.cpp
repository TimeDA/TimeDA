//#include <iostream>
 #include <fstream>
 #include <vector>
 #include <set>
 #include <map>
 #include <cstring>
 #include <string>
 #include <cmath>
 #include <cassert>
 #include <ctime>
 #include <algorithm>
 #include <sstream>
 #include <list>
 #include <queue>
 #include <deque>
 #include <stack>
 #include <cstdlib>
 #include <cstdio>
 #include <iterator>
 #include <functional>
 #include <bitset>
 #define mp make_pair
 #define pb push_back
 
 #ifdef LOCAL
 #define eprintf(...) fprintf(stderr,__VA_ARGS__)
 #else
 #define eprintf(...)
 #endif
 
 #define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
 #define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)
 
 #if ( _WIN32 || __WIN32__ )
     #define LLD "%I64d"
 #else
     #define LLD "%lld"
 #endif
 
 using namespace std;
 
 #define TASKNAME "B"
 #define TASKMOD "small"
 
 typedef long long ll;
 typedef long double ld;
 
 void PreCalc(){
 }
 
 void solve(){
 	double C, F, X;
 	scanf("%lf %lf %lf",&C,&F,&X);
 	double cost = 0;
 	double ans = X / 2.0;
 	double speed = 2.0;
 	for (int i = 0; i <= 1e6; i++) {
 		cost += C / speed;
 		speed += F;
 		ans = min(ans, cost + X / speed);
 	}
 	printf("%.18lf\n", ans);
 }
 
 
 int main(){
   freopen(TASKNAME"-"TASKMOD".in","r",stdin);
   freopen(TASKNAME"-"TASKMOD".out","w",stdout);
 	
   PreCalc();
   TIMESTAMP(PreCalc);	
 
   char buf[1000];
   int testNum;
   gets(buf);
   sscanf(buf,"%d",&testNum);
 
   for (int testId = 1; testId <= testNum; testId++){
   	if (testId <= 20 || testId >= testNum - 20 || testId % 10 == 0)
 	  	TIMESTAMPf("Test %d",testId);
   	printf("Case #%d: ",testId);
   	solve();                        
   }
       
   TIMESTAMP(end);
   return 0;
 }