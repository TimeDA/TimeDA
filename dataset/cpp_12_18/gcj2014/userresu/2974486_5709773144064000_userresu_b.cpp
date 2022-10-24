#include <cstdio>
 #include <algorithm>
 using namespace std;
 
 double C,F,X;
 int main () {
     freopen("input.in","r",stdin);
     freopen("output.out","w",stdout);
     int T;
     scanf("%d",&T);
     for (int z=1;z<=T;++z) {
     scanf("%lf %lf %lf",&C,&F,&X);
     double rate=2,minT=100000.0,mytime=0;
     for (int i=0;mytime<minT;++i) {
         minT=min(minT,mytime+X/rate);
         mytime += C/rate;
         rate+=F;
     }
     printf("Case #%d: %.7lf\n",z,minT);
 }
     return 0;
 }
