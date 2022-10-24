#include <cstdio>
 #include <cstring>
 #include <algorithm>
 using namespace std;
 
 const int MAXN = 200;
 
 int n;
 double x, v;
 double xx[MAXN], vv[MAXN];
 double a[3][MAXN] , t[MAXN];
 
 void init() 
 {
     scanf("%d %lf %lf", &n, &v, &x);
     for (int i = 1; i <= n; ++i) 
         scanf("%lf %lf", &vv[i], &xx[i]);
 }
 
 void solve()
 {
     int b = 0;
     for (int i = 1; i <= n; ++i)
     {
         if (xx[i] <= x) b |= 1;
         if (xx[i] >= x) b |= 2;
     }
     if (b != 3) { printf("IMPOSSIBLE\n"); return;}
     b = 0;
     for (int i = 1; i <= n; ++i) {
         if (xx[i] < x) b |= 1;
         if (xx[i] > x) b |= 2;
     }
     if (b != 3) {
         double s = 0;
         for (int i = 1; i <= n; ++i) if (xx[i] == x) s += vv[i];
         printf("%.9lf\n", v / s);
         return;
     }
 
     double l = 0.0 , r = 1e+10 , m;
     double cv , cx , hv , hx , wv;
     for (int ii = 1; ii <= 200; ++ii)
     {
         m = (l+r) * 0.5;
         cv = cx = hv = hx  = wv = 0.0;
         for (int i = 1; i <= n; ++i)
         {
             if (xx[i] == x) wv += m * vv[i];
             else if (xx[i] < x)
             {
                 cv += m * vv[i];
                 cx += m * vv[i] * xx[i];
             }
             else
             {
                 hv += m * vv[i];
                 hx += m * vv[i] * xx[i];
             }
         }
         cx /= cv;
         hx  /=  hv;
         double hv2  = (cx * cv - x * cv) / (x - hx);
         double cv2 = (hx * hv - x * hv) / (x - cx);
         if ((hv  >=  hv2 && cv + hv2 + wv >= v) ||
              (cv >= cv2 && cv2 + hv + wv >= v))
             r = m;
         else
             l = m;
     }
     
     printf("%.9lf\n", (l+r)*0.5);
 }
 
 int main()
 {
    int ii, tt;
    scanf("%d", &tt);
    for (ii = 1; ii <= tt; ++ii)
    {
       init();
       printf("Case #%d: ", ii);
       solve();
    }
    return 0;
 }
