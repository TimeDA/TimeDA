#include <cstdio>
 #include <cmath>
 #include <vector>
 #include <queue>
 
 using namespace std;
 
 int x[1005], y[1005], z[1005];
 
 double dist(int a, int b)
 {
   int dx = x[a] - x[b];
   int dy = y[a] - y[b];
   int dz = z[a] - z[b];
   return sqrt(dx * dx + dy * dy + dz * dz);
 }
 
 int n;
 
 bool test(double x)
 {
   queue<int> Q;
   vector<int> check(n, 0);
   Q.push(0);
   check[0] = 1;
   while (!Q.empty())
   {
     if (check[1] == 1) break;
     int now = Q.front(); Q.pop();
     for (int i = 0; i < n; ++i)
     {
       if (check[i] == 1) continue;
       if (dist(now, i) <= x)
       {
         Q.push(i);
         check[i] = 1;
       }
     }
   }
   return check[1] == 1;
 }
 
 int main()
 {
   int T;
   scanf("%d", &T);
   for (int cn = 1; cn <= T; ++cn)
   {
     int s;
     scanf("%d%d", &n, &s);
     for (int i = 0; i < n; ++i)
     {
       int v1, v2, v3;
       scanf("%d%d%d%d%d%d", &x[i], &y[i], &z[i], &v1, &v2, &v3);
     }
 
 		double left = 0, right = dist(0, 1), ret = right, mid;
 		for (int loop = 0; loop < 100; ++loop)
 		{
 			mid = (left + right) / 2;
 			if (test(mid))
 			{
 				right = mid;
 			}
 			else
 			{
 				left = mid;
 			}
 		}
 		printf("Case #%d: %.10lf\n", cn, left);
   }
 }
 
