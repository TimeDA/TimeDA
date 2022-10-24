#include <cstdio>
 #include <algorithm>
 using namespace std;
 
 void solve(int cs)
 {
     double c, f, x;
     scanf("%lf %lf %lf", &c, &f, &x);
     double ans = 1e100;
     double cur = 0;
     double pro = 2;
     while (true)
     {
         if (cur > ans)
             break;
         ans = min(ans, cur + x / pro);
         cur += c / pro;
         pro += f;
     }
     printf("Case #%d: %.10lf\n", cs, ans);
 }
 
 int main()
 {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++)
         solve(i + 1);
 }
