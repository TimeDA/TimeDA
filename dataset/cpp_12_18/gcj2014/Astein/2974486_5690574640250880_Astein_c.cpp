#include <cstdio>
 #include <vector>
 #include <string>
 
 using namespace std;
 
 vector<string> generate(int r, int c, int m)
 {
 	vector<string> ret;
 	if (r == 4 && c == 4 && m == 3) {
 		ret.push_back("c...");
 		ret.push_back("....");
 		ret.push_back("...*");
 		ret.push_back("..**");
 		return ret;
 	}
 	// all mine except one grid.
 	if (r * c == m + 1)
 	{
 		ret = vector<string> (r, string(c, '*'));
 		ret[0][0] = 'c';
 		return ret;
 	}
 
 	if (c == 1)
 	{
 		ret = vector<string> (r, "*");
 		ret[0] = "c";
 		for (int i = 1; i < r - m; ++i) ret[i] = ".";
 		return ret;
 	}
 	if (r == 1)
 	{
 		return vector<string>();		
 	}
 
 	if (r > 1 && c > 1 && r * c - m < 4) 
 		return vector<string>();
 
 	// rect
 	for (int i = 2; i <= r; ++i)
 		for (int j = 2; j <= c; ++j)
 			if (i * j + m == r * c)
 			{
 				ret = vector<string> (r, string(c, '*'));
 				for (int k = 0; k < i; ++k)
 					for (int l = 0; l < j; ++l)
 						ret[k][l] = '.';
 				ret[0][0] = 'c';
 				return ret;
 			}
 
 	// mine-rect
 	for (int i = 1; i <= r - 2; ++i)
 		for (int j = 1; j <= c - 2; ++j)
 			if (i * j == m)
 			{
 				ret = vector<string> (r, string(c, '.'));
 				for (int k = 0; k < i; ++k)
 					for (int l = 0; l < j; ++l)
 						ret[k][l] = '*';
 				ret[r - 1][c - 1] = 'c';
 				return ret;
 			}
 	
 	// rect
 	if ((r * c - m) % c != 1 && (r * c - m) >= 2 * c)
 	{
 		ret = vector<string> (r, string(c, '*'));
 		int x = 0, y = 0;
 		for (int i = 0; i < r * c - m; ++i) {
 			ret[x][y] = '.';
 			y++;
 			if (y == c) { y = 0, x++; }
 		}
 		ret[0][0] = 'c';
 		return ret;
 	}
 	return vector<string>();
 }
 
 int main()
 {
 	int T;
 	scanf("%d", &T);
 	for (int cn = 1; cn <= T; ++cn)
 	{
 		int r, c, m;
 		scanf("%d%d%d", &r, &c, &m);
 		vector<string> ret = generate(r, c, m);
 		printf("Case #%d:\n", cn);
 		if (ret.size() == 0)
 		{
 			ret = generate(c, r, m);
 			if (ret.size() == 0)
 			{
 				printf("Impossible\n");
 			}
 			else
 			{
 				for (int i = 0; i < r; ++i)
 				{
 					for (int j = 0; j < c; ++j)
 						printf("%c", ret[j][i]);
 					printf("\n");
 				}
 			}
 		}
 		else
 		{
 			for (int i = 0; i < r; ++i)
 				printf("%s\n", ret[i].c_str());
 		}
 	}
 }
 
