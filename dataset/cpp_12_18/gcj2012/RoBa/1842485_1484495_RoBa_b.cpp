#include <cstdio>
 #include <string>
 #include <cmath>
 using namespace std;
 
 const double eps = 1e-8;
 const int MAXN = 1024;
 const double INF = 1e10;
 
 struct CC {
     double x, y;
     double r;
 } cc[MAXN+4];
 
 double r[MAXN];
 int W, L;
 
 inline double dis(double x1, double y1, double x2, double y2) {
     return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
 }
 
 void rotate(int flg,double x1,double y1,double cosd,double sind,double &x,double &y){
 	if(!flg) {sind = -sind;}
 	x = x1 * cosd - y1 * sind;
 	y = x1 * sind + y1 * cosd;
 }
 
 int put(int flg, double x1, double y1, double r1, double x2, double y2, double r2, double outr, double &outx, double &outy)
 {
     double c = dis(x1, y1, x2, y2);
     double a = r1 + outr, b = r2 + outr;
     // printf("a:%lf b:%lf c:%lf\n",a,b,c);
     if (a + b - c < eps || a + c - b < eps || b + c - a < eps)
         return 0;
     double cosa = (a * a + c * c - b * b) / (2*a*c);
     double sina = sqrt(1 - cosa * cosa);
     double tx, ty;
     rotate(flg, x2-x1, y2-y1, cosa, sina, tx, ty);
     // printf("tx:%f ty:%f\n",tx,ty);
     outx = x1 + tx / c * a;
     outy = y1 + ty / c * a;
     // printf("tx2:%f ty2:%f\n",tx,ty);
     return 1;
 }
 
 int inter(int i, int j) {
     if (cc[j].x < 0 || cc[j].x > W || cc[j].y < 0 || cc[j].y > L) return 1;
     double d = dis(cc[i].x, cc[i].y, cc[j].x, cc[j].y);
     // printf("d:%f\n",d);
     if (d - cc[i].r - cc[j].r > eps) return 0;
     return 1;
 }
 
 int main() {
     freopen("B-small.in","r",stdin);
     freopen("B-small.out","w",stdout);
     int T, ca, n;
     int i, j, k, p;
     scanf("%d",&T);
     for (ca = 1 ; ca <= T ; ++ca) {
         scanf("%d%d%d",&n,&W,&L);
         for (i = 0 ; i < n ; i++) {
             scanf("%lf",&r[i]);
             // inp[i].id = i;
         }
         // sort(inp, inp+n, cmp);
         cc[0].x = -INF; cc[0].y = L/2.0; cc[0].r = INF;
         cc[1].x = W + INF; cc[1].y = L/2.0; cc[1].r = INF;
         cc[2].x = W/2.0; cc[2].y = -INF; cc[2].r = INF;
         cc[3].x = W/2.0; cc[3].y = L+INF; cc[3].r = INF;
         int cur = 4;
         for (i = 0 ; i < n ; i++) {
             for (j = 0 ; j < 4 ; j++)
                 cc[j].r = INF - r[i];
             for (j = 0 ; j < cur ; j++) {
                 for (k = j + 1 ; k < cur ; k++) {
                     cc[cur].r = r[i];
                     if (put(0, cc[j].x, cc[j].y, cc[j].r,
                         cc[k].x, cc[k].y, cc[k].r,
                         r[i], cc[cur].x, cc[cur].y)) {
                         // printf("i:%d j:%d k:%d (%lf,%lf)\n", i, j, k, cc[cur].x, cc[cur].y);
                         int flg = 1;
                         for (p = 0 ; p < cur ; p++) {
                             if (inter(p, cur)) {flg = 0; break;}
                         }
                         if (flg) {goto out;}
                     }
                     if (put(1, cc[j].x, cc[j].y, cc[j].r,
                         cc[k].x, cc[k].y, cc[k].r,
                         r[i], cc[cur].x, cc[cur].y)) {
                         // printf("===:%d j:%d k:%d (%lf,%lf)\n", i, j, k, cc[cur].x, cc[cur].y);
                         int flg = 1;
                         for (p = 0 ; p < cur ; p++) {
                             if (inter(p, cur)) {flg = 0; break;}
                         }
                         if (flg) {goto out;}
                     }
                 }
             }
 out:
             ++cur;
         }
         // printf("cur:%d\n",cur);
         printf("Case #%d:",ca);
         for (i = 4 ; i < cur ; ++i)
             printf(" %.5lf %.5lf", cc[i].x, cc[i].y);
         printf("\n");
     }
     return 0;
 }
 /*
 1
 1 10 10
 1
 */
