#include <cstdio>
 #include <cstring>
 #include <string>
 #include <map>
 
 using namespace std;
 
 const int MAXN = 210;
 const int MAXM = 1100;
 
 int num;
 int n;
 int a[MAXN][MAXM];
 int b[MAXN];
 int f[5000];
 char s[200000];
 map<string, int> hash;
 int ans;
 
 int get(string s)
 {
    if (hash[s] == 0) {/*printf("[%s]\n",s.c_str());*/ return hash[s] = ++num;}
    else {/*printf("[%s]:%d\n",s.c_str(), hash[s]); */return hash[s];}
 }
 
 void init()
 {
    hash.clear();
    num = 0;
    scanf("%d\n", &n);
    string wd;
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; ++i)
    {
       gets(s);
       int len = strlen(s);
       wd = "";
       for (int j = 0; j < len; ++j)
       if (s[j] == ' ')
       {
          a[i][++a[i][0]] = get(wd);
          wd = "";
       }
       else wd = wd + s[j];
       a[i][++a[i][0]] = get(wd);
    }
 }
 
 
 void dfs(int dep)
 {
    if (dep > n)
    {
       int t = 0;
       memset(f, 0, sizeof(f));
       for (int i = 1; i <= n; ++i)
       for (int j = 1; j <= a[i][0]; ++j)
       {
          int d = (1 << b[i]);
          if ((f[a[i][j]] & d) == 0)
          {
             f[a[i][j]] += d;
             if (f[a[i][j]] == 3) ++t;
          }
       }
       if (t < ans) ans = t;
       return;
    }
    b[dep] = 0;
    dfs(dep + 1);
    b[dep] = 1;
    dfs(dep + 1);
 }
 
 void solve()
 {
    /*for (int i = 1; i <= n; ++i)
    {
       printf("%d: ", a[i][0]);
       for (int j = 1; j <= a[i][0]; ++j)
          printf("%d ", a[i][j]);
       printf("\n");
    }*/
    fflush(stdout);
    b[1] = 0;
    b[2] = 1;
    ans = 2100000000;
    dfs(3);
    printf("%d\n", ans);
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
