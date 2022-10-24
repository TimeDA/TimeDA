#include<cstdio>
 #include<cstdlib>
 #include<vector>
 #include<string>
 #include<sstream>
 #include<iostream>
 #include<algorithm>
 
 using namespace std;
 
 int n;
 double v, x;
 vector<pair<double, double> > sources;
 
 bool possible(double t)
 {
     double minx = 0;
     double amount = v;
     for (int i = 0; i < n; i++)
     {
         double add = min(amount, sources[i].second * t);
         minx += add * sources[i].first;
         amount -= add;
         if (amount <= 0)
             break;
     }
     double maxx = 0;
     amount = v;
     for (int i = n - 1; i >= 0; i--)
     {
         double add = min(amount, sources[i].second * t);
         maxx += add * sources[i].first;
         amount -= add;
         if (amount <= 0)
             break;
     }
     return (x >= minx && x <= maxx);
 }
 
 int main()
 {
     int t, test;
     scanf("%d", &test);
     for (t = 0; t < test; t++)
     {
         scanf("%d %lf %lf", &n, &v, &x);
         double minr = 10000;
         double totalr = 0;
         vector<pair<double, double> > read;
         for (int i = 0; i < n; i++)
         {
             double r, c;
             scanf("%lf %lf", &r, &c);
             read.push_back(make_pair(c, r));
             minr = min(r, minr);
             totalr += r;
         }
         sort(read.begin(), read.end());
         sources.clear();
         double temp = read[0].first;
         double flow = 0;
         for (int i = 0; i < n; i++)
         {
             if (read[i].first != temp)
             {
                 sources.push_back(make_pair(temp, flow));
                 temp = read[i].first;
                 flow = read[i].second;
             }
             else
             {
                 flow += read[i].second;
             }
         }
         sources.push_back(make_pair(temp, flow));
         n = sources.size();
 
         if (x < sources[0].first || x > sources[n-1].first)
         {
             printf("Case #%d: IMPOSSIBLE\n", t+1);
             continue;
         }
 
         x *= v;
         double a = v / totalr;
         double b = v / minr;
         for (int i = 0; i < 200; i++)
         {
             double c = (a + b)/2;
             if (possible(c))
                 b = c;
             else
                 a = c;
         }
 
         printf("Case #%d: %lf\n", t+1, a);
     }
     return 0;
 }
