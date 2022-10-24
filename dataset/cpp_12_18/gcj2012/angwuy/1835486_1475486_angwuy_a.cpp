#include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <utility>
 
 using namespace std;
 
 const int MAXN = 1100;
 
 struct Tnum{
    int l, p, num;
 };
 
 int n;
 Tnum a[MAXN];
 
 bool cmp(Tnum a, Tnum b)
 {
    if (a.l * b.p == b.l * a.p) return a.num < b.num;
    else return a.l * b.p < b.l * a.p;
 }
 
 void solve()
 {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
       scanf("%d", &a[i].l);
    for (int i = 1; i <= n; ++i)
       scanf("%d", &a[i].p);
    for (int i = 1; i <= n; ++i)
       a[i].num = i - 1;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; ++i)
       printf(" %d", a[i].num);
    printf("\n");
 }
 
 int main()
 {
    int tt;
    scanf("%d", &tt);
    for (int ii = 1; ii <= tt; ++ii)
    {
       printf("Case #%d:", ii);
       solve();
    }
    return 0;
 }
 
 
