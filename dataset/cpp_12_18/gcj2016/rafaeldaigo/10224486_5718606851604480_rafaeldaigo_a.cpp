#include<cstdio>
 #include<cstring>
 #include<string>
 #include<queue>
 #include<utility>
 #include<vector>
 #include<algorithm>
 #include<iostream>
 
 using namespace std;
 
 string best[13][3];
 int bestr[13][3];
 int bestp[13][3];
 
 int main()
 {
 	int t, teste;
 	scanf("%d\n", &teste);
 
 	best[0][0] = "R";
 	bestr[0][0] = 1;
 	bestp[0][0] = 0;
 	best[0][1] = "P";
 	bestr[0][1] = 0;
 	bestp[0][1] = 1;
 	best[0][2] = "S";
 	bestr[0][2] = 0;
 	bestp[0][2] = 0;
 
 	for (int a = 1; a <= 12; a++)
 	{
 		best[a][0] = (best[a-1][0] < best[a-1][2]) ? best[a-1][0] + best[a-1][2] : best[a-1][2] + best[a-1][0];
 		bestr[a][0] = bestr[a-1][0] + bestr[a-1][2];
 		bestp[a][0] = bestp[a-1][0] + bestp[a-1][2];
 		best[a][1] = (best[a-1][1] < best[a-1][0]) ? best[a-1][1] + best[a-1][0] : best[a-1][0] + best[a-1][1];
 		bestr[a][1] = bestr[a-1][1] + bestr[a-1][0];
 		bestp[a][1] = bestp[a-1][1] + bestp[a-1][0];
 		best[a][2] = (best[a-1][2] < best[a-1][1]) ? best[a-1][2] + best[a-1][1] : best[a-1][1] + best[a-1][2];
 		bestr[a][2] = bestr[a-1][2] + bestr[a-1][1];
 		bestp[a][2] = bestp[a-1][2] + bestp[a-1][1];
 	}
 
 	for (int t = 0; t < teste; t++)
 	{
 		int n, r, p, s;
 		scanf("%d %d %d %d\n", &n, &r, &p, &s);
 
 		string resp = "";
 		if (bestr[n][0] == r && bestp[n][0] == p)
 			resp = best[n][0];
 		if (bestr[n][1] == r && bestp[n][1] == p)
 			resp = best[n][1];
 		if (bestr[n][2] == r && bestp[n][2] == p)
 			resp = best[n][2];
 
 		if (resp != "")
 			printf("Case #%d: %s\n", t + 1, resp.c_str());
 		else
 			printf("Case #%d: IMPOSSIBLE\n", t + 1);
 	}
 	return 0;
 }
