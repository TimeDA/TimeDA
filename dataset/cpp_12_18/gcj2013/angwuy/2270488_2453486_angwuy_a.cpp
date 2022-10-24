#include <cstdio>
 #include <cstring>
 
 const int MAXN = 4;
 
 char a[MAXN][MAXN + 5];
 
 bool checkX()
 {
 	int i, j, k;
 	bool ok = true;
 	for (i = 0; i < 4; ++i)
 	{
 		ok = true;
 		for (j = 0; j < 4; ++j)
 		if (a[i][j] == 'O' || a[i][j] == '.')
 		{
 			ok = false;
 			break;
 		}
 		if (ok) return true;
 		ok = true;
 		for (j = 0; j < 4; ++j)
 		if (a[j][i] == 'O' || a[j][i] == '.')
 		{
 			ok = false;
 			break;
 		}
 		if (ok) return true;
 	}
 	ok = true;
 	for (i = 0; i < 4; ++i)
 	if (a[i][i] == 'O' || a[i][i] == '.')
 	{
 		ok = false;
 		break;
 	}
 	if (ok) return true;
 	ok = true;
 	for (i = 0; i < 4; ++i)
 	if (a[i][3-i] == 'O' || a[i][3-i] == '.')
 	{
 		ok = false;
 		break;
 	}
 	if (ok) return true;
 	return 0;
 }
 
 bool checkO()
 {
 	int i, j, k;
 	bool ok = true;
 	for (i = 0; i < 4; ++i)
 	{
 		ok = true;
 		for (j = 0; j < 4; ++j)
 		if (a[i][j] == 'X' || a[i][j] == '.')
 		{
 			ok = false;
 			break;
 		}
 		if (ok) return true;
 		ok = true;
 		for (j = 0; j < 4; ++j)
 		if (a[j][i] == 'X' || a[j][i] == '.')
 		{
 			ok = false;
 			break;
 		}
 		if (ok) return true;
 	}
 	ok = true;
 	for (i = 0; i < 4; ++i)
 	if (a[i][i] == 'X' || a[i][i] == '.')
 	{
 		ok = false;
 		break;
 	}
 	if (ok) return true;
 	ok = true;
 	for (i = 0; i < 4; ++i)
 	if (a[i][3-i] == 'X' || a[i][3-i] == '.')
 	{
 		ok = false;
 		break;
 	}
 	if (ok) return true;
 	return 0;
 }
 
 bool checkDraw()
 {
 	for (int i = 0; i < 4; ++i)
 	for (int j = 0; j < 4; ++j)
 	if (a[i][j] == '.') return false;
 	return true;
 }
 
 void solve()
 {
 	memset(a, 0, sizeof(a));
 	for (int i = 0; i < 4; ++i)
 	{
 		do{
 			gets(a[i]);
 		}while (a[i][0] == '\0');
 	}
 	
 	//for (int i = 0; i < 4; ++i) printf("%s\n", a[i]);
 	if (checkX()) printf("X won\n");
 	else if (checkO()) printf("O won\n");
 	else if (checkDraw()) printf("Draw\n");
 	else printf("Game has not completed\n");
 }
 
 int main()
 {
 	freopen("a.in", "r", stdin);
 	//freopen("a.out", "w", stdout);
 	int t;
 	scanf("%d", &t);
 	for (int i = 1; i <= t; ++i)
 	{
 		printf("Case #%d: ", i);
 		solve();
 	}
 	return 0;
 }