#include <cstdio>
 #include <cstring>
 
 const int INF = 0x7F7F7F7F;
 
 int Hd, Ad, Hk, Ak, B, D;
 
 int f[110][110][110];
 
 void init()
 {
 	scanf("%d %d %d %d %d %d", &Hd, &Ad, &Hk, &Ak, &B, &D);
 }
 
 int geta()
 {
 	int ret = (Hk - 1) / Ad + 1;
 	if (B == 0) return ret;
 	int b = 0;
 	while (1)
 	{
 		Ad += B;
 		++b;
 		int nret = (Hk - 1) / Ad + 1 + b;
 		if (nret < ret) ret = nret;
 		else break;
 	}
 	return ret;
 }
 
 int min(int x, int y) {return x < y ? x : y;}
 int max(int x, int y) {return x > y ? x : y;}
 
 
 int find(int Ak, int H, int R)
 {
 	if (R == 0) f[Ak][H][R] = 0;
 	if (R == 1) f[Ak][H][R] = 1;
 	if (f[Ak][H][R] < INF) return f[Ak][H][R];
 	f[Ak][H][R] = INF - 1;
 	//A
 	if (Ak < H)
 		f[Ak][H][R] = min(f[Ak][H][R], find(Ak, H - Ak, R - 1) + 1);
 	//D
 	if (Ak - D < H)
 	{
 		int nAk = max(0, Ak - D);
 		f[Ak][H][R] = min(f[Ak][H][R], find(nAk, H - nAk, R) + 1);
 	}
 	//R
 	if (Ak < Hd)
 		f[Ak][H][R] = min(f[Ak][H][R], find(Ak, Hd - Ak, R) + 1);
 	return f[Ak][H][R];
 }
 
 void solve()
 {
 	int a = geta();
 	memset(f, 0x7F, sizeof(f));
 	int ret = find(Ak, Hd, a);
 	if (ret < INF / 2) printf("%d\n", ret);
 	else printf("IMPOSSIBLE\n");
 }
 
 
 
 
 
 int main()
 {
 	//freopen("c.in", "r", stdin);
 	int tt;
 	scanf("%d", &tt);
 	for (int ii = 1; ii <= tt; ++ii)
 	{
 		init();
 		printf("Case #%d: ", ii);
 		solve();
 	}
 	return 0;
 }
 
