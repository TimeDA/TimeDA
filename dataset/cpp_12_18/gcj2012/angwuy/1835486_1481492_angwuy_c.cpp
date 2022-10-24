#include <cstdio>
 #include <cstring>
 #include <algorithm>
 
 using namespace std;
 
 const int MAXN = 250;
 const int MAXM = 2000010;
 
 struct Tfood{
    long long m, t, c;
 };
 
 bool cmp(Tfood a, Tfood b)
 {
    if (a.m == b.m) return a.t > b.t;
    else return a.m < b.m;
 }
 
 int n;
 long long m, ff;
 Tfood a[MAXN];
 long long f[MAXM], g[MAXM];
 
 void init()
 {
    scanf("%I64d %I64d %d", &m, &ff, &n);
    //printf("%I64d %I64d %d", m, ff, n);
    fflush(stdout);
    for (int i = 1; i <= n; ++i)
    {
       scanf("%I64d %I64d", &a[i].m, &a[i].t);
       ++a[i].t;
    }
    sort(a + 1, a + n + 1, cmp);
    int n1 = 1;
    for (int i = 2; i <= n; ++i)
       if (a[i].t > a[n1].t) a[++n1] = a[i];
    n = n1;
 }
 
 void solve()
 {
    int i;
    long long cost, time;
    a[0].c = ff;
    a[1].c = ff + a[1].m * a[1].t;
    for (i = 2; i <= n; ++i)
       a[i].c = a[i - 1].c + a[i].m * (a[i].t - a[i - 1].t);
    memset(f, 0, sizeof(f));
    for (i = 1; i <= n; ++i)
    {
       cost = 0, time = 0;
       while (cost <= m)
       {
          f[cost] = max(f[cost], time);
          cost += a[i].c;
          time += a[i].t;
       }
    }
    for (i = 1; i <= m; ++i)
       f[i] = max(f[i], f[i - 1]);
    //for (i = 1; i <= m; ++i)
    //   printf("%I64d\n", f[i]);
    i = 1, cost = ff, time = 0;
    while (i <= n && cost <= m)
    {
       //printf("%I64d %I64d\n", cost, time);
       f[m] = max(f[m], f[m - cost] + time);
       ++time;
       while (i <= n && time > a[i].t) ++i;
       cost += a[i].m;
    }
    printf("%I64d\n", f[m]);
    fflush(stdout);
 }
 
 long long get(int y)
 {
    int l, r, m1, m2;
    l = 1;
    r = y;
    while (l + 20 < r)
    {
       m1 = l + (r - l) / 2;
       m2 = r - (r - l) / 2;
       if (f[m1] + f[y - m1] > f[m2] + f[y - m2])
          r = m2;
       else
          l = m1;
    }
    long long ret = 0;
    for (int i = l; i <= r; ++i)
    if (f[i] + f[y - i] > ret)
       ret = f[i] + f[y - i];
    return ret;
 }
 
 void solve2()
 {
    int i, l, r;
    long long cost, time;
    a[0].c = ff;
    a[1].c = ff + a[1].m * a[1].t;
    for (i = 2; i <= n; ++i)
       a[i].c = a[i - 1].c + a[i].m * (a[i].t - a[i - 1].t);
    memset(f, 0, sizeof(f));
    i = 1, cost = ff + a[1].m, time = 1;
    while (i <= n && cost <= m)
    {
       f[cost] = time;
       ++time;
       while (i <= n && time > a[i].t) ++i;
       cost += a[i].m;
    }
    for (i = 1; i <= m; ++i)
    {
       f[i] = max(f[i], f[i - 1]);
      // for (l = 0, r = i; l <= r; ++l, --r)
      //    f[i] = max(f[i], f[l] + f[r]);
       f[i] = max(f[i], get(i));
    }
    printf("%I64d\n", f[m]);
    fflush(stdout);
 }
 
 int main()
 {
    //freopen("c.in", "r", stdin);
    int tt;
    scanf("%d", &tt);
    for (int ii = 1; ii <= tt; ++ii)
    {
       printf("Case #%d: ", ii);
       init();
       solve2();
    }
 }