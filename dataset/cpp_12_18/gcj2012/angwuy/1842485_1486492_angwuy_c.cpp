#include <cstdio>
 #include <cstring>
 
 const int MAXN = 2010;
 
 int n;
 int a[MAXN];
 int h[MAXN];
 double hh[MAXN];
 
 bool mul(int i1, int i2, int i3)
 {
 	return (long long)(i2 - i1) * (long long)(h[i3] - h[i1]) - (long long)(i3 - i1) * (long long)(h[i2] - h[i1]) > 0;
 }
 
 void init()
 {
 	scanf("%d", &n);
 	for (int i = 1; i < n; ++i)
 		scanf("%d", &a[i]);
 }
 
 int getl(int l, int r, int hl, int hr, int m)
 {
 	double mh = hl + double(hr - hl) / (r - l) * (m - l);
 	return (int)(mh - 0.01);
 }
 
 int geth(int l, int r, int hl, int hr, int m)
 {
 	double mh = hl + double(hr - hl) / (r - l) * (m - l);
 	return (int)(mh + 0.01) + 1;
 }
 
 double get(int l, int r, double hl, double hr, int m)
 {
 	return hl + double(hr - hl) / (r - l) * (m - l);
 //	return (int)(mh + 0.01) + 1;
 }
 
 void make(int st, int ed, int h1, int h2)
 {
 	h[st] = h1;
 	h[ed] = h2;
 	if (ed - st <= 1) return;
 	if (a[st] < ed)
 	{
 		int h = geth(st, ed, h1, h2, a[st]);
 		make(st, a[st], h1, h);
 		make(a[st], ed, h, h2);
 	}
 	else
 	{
 		//int h = getl(st, ed, h1, h2, a[st]) - 1;
 		int h = 1000000;
 		make(st, st + 1, h1, h);
 		make(st + 1, ed, h, h2);
 	}
 }
 /*
 void make2(int st, int ed, double h1, double h2)
 {
 	hh[st] = h1;
 	hh[ed] = h2;
 	if (ed - st <= 1) return;
 	if (a[st] < ed)
 	{
 		double h = get(st, ed, h1, h2, a[st]);
 		make2(st, a[st], h1, h);
 		make2(a[st], ed, h, h2);
 	}
 	else
 	{
 		double h = get(st, ed, h1, h2, st + 1) - 1e-6;
 		make2(st, st + 1, h1, h);
 		make2(st + 1, ed, h, h2);
 	}
 }*/
 bool check(int &res1, int &res2, int &res3)
 {
 
 	int i, j, k;
 	for (i = 1; i <= n; ++i)
 	if (h[i] >= 1000000000)
 	{
 		printf("H[%d] to large : %d, ", i, h[i]);
 		res1 = res2 = res3 = -1;
 		return false;
 	}
 	for (i = n - 1; i >= 1; --i)
 	{
 		k = i + 1;
 		for (j = i + 2; j <= n; ++j)
 		if (mul(i, k, j))
 			k = j;
 		if (k != a[i])
 		{
 			res1 = i;
 			res2 = k;
 			res3 = a[i];
 			//printf("%d %d %d, ", i, k, a[i]);
 			return false;
 		}
 	}
 	return true;
 }
 
 /*void solve()
 {
 	int i, j;
 	for (i = 1; i < n; ++i)
 	for (j = i + 1; j < a[i]; ++j)
 	if (a[i] < a[j])
 	{
 		printf(" Impossible\n");
 		return;
 	}
 	//make(1, n, 1000000000, 1000000000);
 	make(1, n, 900000000, 900000000);
 	/*make2(1, n, 1, 1);
 	for (i = 1; i <= n; ++i)
 		h[i] = (int)(hh[i] * 100000000);*/
 /*	for (i = 1; i <= n; ++i)
 		printf(" %d", h[i]);
 	printf("\n");
 	if (!check()) printf("FUCK!\n");
 }*/
 
 void solve()
 {
 	int i, j;
 	for (i = 1; i < n; ++i)
 	for (j = i + 1; j < a[i]; ++j)
 	if (a[i] < a[j])
 	{
 		printf(" Impossible\n");
 		return;
 	}
 	int res1, res2, res3;
 	make(1, n, 100000000, 900000000);
 	while (!check(res1, res2, res3))
 	{
 		h[res2] = getl(res1, res3, h[res1], h[res3], res2);
 	}
 	for (i = 1; i <= n; ++i)
 		printf(" %d", h[i]);
 	printf("\n");
 }
 
 
 int main()
 {
 	freopen("c.in", "r", stdin);
 	int ii, tt;
 	scanf("%d", &tt);
 	for (ii = 1; ii <= tt; ++ii)
 	{
 		printf("Case #%d:", ii);
 		init();
 		solve();
 	}
 	return 0;
 }
