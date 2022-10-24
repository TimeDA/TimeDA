#include <cstring>
 #include <algorithm>
 #include <cstdlib>
 #include <vector>
 #include <map>
 #include <tuple>
 #include <cmath>
 
 using namespace std;
 
 struct vec {
     double x, y, z;
 } pos[1100], vel[1100];
 int n, s;
 
 struct p {
     int a, b;
     double dis;
 };
 vector<p> arr;
 
 bool operator<(const p &a, const p &b) {
     return (a.dis < b.dis);
 }
 
 double calc_dis(int a, int b) {
     double dd = 0.0;
     dd += (pos[a].x - pos[b].x) * (pos[a].x - pos[b].x);
     dd += (pos[a].y - pos[b].y) * (pos[a].y - pos[b].y);
     dd += (pos[a].z - pos[b].z) * (pos[a].z - pos[b].z);
     return sqrt(dd);
 }
 
 int g[1100];
 
 int getid(int id) {
     if (g[id] != id) g[id] = getid(g[id]);
     return g[id];
 }
 
 int main() {
     int tc;
     scanf("%d", &tc);
     for (int t = 1; t <= tc; t++) {
         scanf("%d%d", &n, &s);
         arr.clear();
         for (int i = 0; i < n; i++) {
             g[i] = i;
             scanf("%lf%lf%lf%lf%lf%lf", &pos[i].x, &pos[i].y, &pos[i].z, &vel[i].x, &vel[i].y, &vel[i].z);
             for (int j = 0; j < i; j++) {
                 p pp;
                 pp.a = i;
                 pp.b = j;
                 pp.dis = calc_dis(i, j);
                 arr.emplace_back(pp);
             }
         }
         
         sort(arr.begin(), arr.end());
 
         double ans = 0.0;
         int ptr = 0;
         while (getid(0) != getid(1)) {
             int ida = getid(arr[ptr].a);
             int idb = getid(arr[ptr].b);
             if (ida != idb) {
                 ans = arr[ptr].dis;
                 g[ida] = idb;
             }
             ptr++;
         }
         
         printf("Case #%d: %.9f\n", t, ans);
     }
 
     return 0;
 }
 
