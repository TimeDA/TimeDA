#include <cstdio>
 #include <cstring>
 
 const int MAXN = 5010;
 
 int n, k, ans;
 bool a[500][500];
 int ind[500], outd[500];
 char s[MAXN];
 
 
 void create(char ch, int a[], int &len)
 {
    len = 1;
    a[1] = ch;
    if (ch == 'o') a[++len] = '0';
    if (ch == 'i') a[++len] = '1';
    if (ch == 'e') a[++len] = '3';
    if (ch == 'a') a[++len] = '4';
    if (ch == 's') a[++len] = '5';
    if (ch == 't') a[++len] = '7';
    if (ch == 'b') a[++len] = '8';
    if (ch == 'g') a[++len] = '9';
 }
 
 void init()
 {
    scanf("%d", &k);
    scanf("%s", s);
    n = strlen(s);
    memset(a, 0, sizeof(a));
    ans = 0;
    int a1[10], a2[10], l1, l2;
    int i1, i2;
    for (int i = 1; i < n; ++i)
    {
       create(s[i - 1], a1, l1);
       create(s[i], a2, l2);
       for (i1 = 1; i1 <= l1; ++i1)
       for (i2 = 1; i2 <= l2; ++i2)
       if (!a[a1[i1]][a2[i2]])
       {
          a[a1[i1]][a2[i2]] = true;
          ++ans;
       }
    }
 }
 
 void solve()
 {
    int i, j;
    memset(ind, 0, sizeof(ind));
    memset(outd, 0, sizeof(outd));
    for (i = 1; i <= 300; ++i)
    for (j = 1; j <= 300; ++j)
    if (a[i][j])
    {
       ++outd[i];
       ++ind[j];
    }
    //printf("%d\n", ans);
    int t = 0;
    for (i = 1; i <= 300; ++i)
       if (ind[i] < outd[i])
          t += outd[i] - ind[i];
    if (t == 0) printf("%d\n", ans + 1);
    else printf("%d\n", ans + t);
 }
 
 int main()
 {
    int tt;
    scanf("%d", &tt);
    for (int ii = 1; ii <= tt; ++ii)
    {
       printf("Case #%d: ",ii);
       init();
       solve();
    }
    return 0;
 }