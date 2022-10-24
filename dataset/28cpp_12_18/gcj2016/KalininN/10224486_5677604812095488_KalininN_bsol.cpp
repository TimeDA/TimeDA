#include <bits/stdc++.h>
 
 using namespace std;
 
 using ll = long long;
 using ld = long double;
 using D = double;
 using uint = unsigned int;
 
 #ifdef WIN32
     #define LLD "%I64d"
 #else
     #define LLD "%lld"
 #endif
 
 #define pb push_back
 #define mp make_pair
 #define all(x) x.begin(),x.end()
 #define fi first
 #define se second
 
 const int maxn = 205;
 
 vector<int> used, unused;
 double pr[maxn], x[maxn];
 int n, k;
 int p[maxn];
 bool use[maxn];
 
 inline void calc()
 {
 	for (int i = 0; i <= k / 2; i++) pr[i] = 0;
 	pr[0] = 1;
 	for (auto t : used)
 	{
 		for (int j = k / 2; j > 0; j--) pr[j] = pr[j] * (1 - x[t]) + pr[j - 1] * x[t];
 		pr[0] *= (1 - x[t]);
 	}
 }
 
 void findbest()
 {
 	calc();
 	pair<double, int> best = {-1, -1};
 	for (int i = 0; i < (int)unused.size(); i++) best = max(best, {pr[k / 2] * (1 - x[unused[i]]) + pr[k / 2 - 1] * x[unused[i]], i});
 	swap(unused[best.se], unused.back());
 	used.pb(unused.back());
 	unused.pop_back();
 }
 
 int main()
 {
     int NT = 0;
     scanf("%d", &NT);
     for (int T = 1; T <= NT; T++)
     {
         printf("Case #%d:", T);
         scanf("%d%d", &n, &k);
 		for (int i = 0; i < n; i++)
 		{
 			scanf("%lf", &x[i]);
 		}
 		double answer = 0;
 		for (int IT = 0; IT < 200; IT++)
 		{
 			for (int i = 0; i < n; i++) p[i] = i;
 			random_shuffle(p, p + n);
 			for (int i = 0; i < n; i++) use[i] = false;
 			for (int i = 0; i < k; i++) use[p[i]] = true;
 			used.clear();
 			unused.clear();
 			for (int i = 0; i < n; i++)
 			{
 				if (use[i]) used.pb(i);
 				else unused.pb(i);
 			}
 			for (int IT2 = 0; IT2 < 100; IT2++)
 			{
 				int x = rand() % k;
 				swap(used[x], used[k - 1]);
 				unused.push_back(used.back());
 				used.pop_back();
 				findbest();
 			}
 			calc();
 			answer = max(answer, pr[k / 2]);
 		}
 		printf(" %.9f\n", (double)answer);
         fprintf(stderr, "%d/%d cases done!\n", T, NT);
     }
     return 0;
 }
