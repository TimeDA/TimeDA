#include <cstdio>
 #include <cstring>
 #include <string>
 
 using namespace std;
 
 const int MAXN = 13;
 string a[3][MAXN];
 
 
 void init_all()
 {
 	a[0][0] = "R";
 	a[1][0] = "P";
 	a[2][0] = "S";
 	for (int i = 1; i <= 12; ++i)
 	for (int j = 0; j <= 2; ++j)
 	{
 		int k = (j + 2) % 3;
 		if (a[k][i - 1] < a[j][i - 1])
 			a[j][i] = a[k][i - 1] + a[j][i - 1];
 		else
 			a[j][i] = a[j][i - 1] + a[k][i - 1];
 	}
 }
 
 void solve()
 {
 	int n, r, p, s;      
 	scanf("%d %d %d %d", &n, &r, &p, &s);
 	string ans = "";
 	for (int i = 0; i < 3; ++i)
 	{
 //printf("[%s]\n", a[i][n].c_str());
 		int tr = 0, tp = 0, ts = 0;
 		for (int j = 0; j < a[i][n].size(); ++j)
 		{
 			if (a[i][n][j] == 'R') ++tr;
 			if (a[i][n][j] == 'P') ++tp;
 			if (a[i][n][j] == 'S') ++ts;
 		}
 		if (tr == r && tp == p && ts == s)
 		{
 			if (ans == "" || a[i][n] < ans)
 				ans = a[i][n];
 		}
 	}
 	if (ans == "")
 		printf("IMPOSSIBLE\n");
 	else
 		printf("%s\n", ans.c_str());
 }
 
 int main()
 {
 	init_all();      
 	int tt, ii;
 	scanf("%d", &tt);
 	for (ii = 1; ii <= tt; ++ii)
 	{
 		printf("Case #%d: ", ii);
 		solve();
 	}
 	return 0;
 }
 
 
 
 
