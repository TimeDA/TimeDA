#include <vector>
 #include <list>
 #include <map>
 #include <set>
 #include <deque>
 #include <stack>
 #include <bitset>
 #include <algorithm>
 #include <functional>
 #include <numeric>
 #include <utility>
 #include <sstream>
 #include <iostream>
 #include <iomanip>
 #include <cstdio>
 #include <cmath>
 #include <cstdlib>
 #include <ctime>
 #include <cstring>
 #include <string>
 #include <cstdarg>
 
 #pragma comment(linker, "/STACK:64000000")
 
 #define DBG2 1
 
 void dbg(const char * fmt, ...)
 {
 #ifdef DBG1
 #if DBG2
 	va_list args;
 	va_start(args, fmt);
 	vfprintf(stderr, fmt, args);
 	va_end(args);
 
 	fflush(stderr);
 #endif
 #endif
 }
 
 using namespace std;
 
 #define clr(a) memset(a, 0, sizeof(a))
 #define fill(a, b) memset(a, b, sizeof(a))
 
 typedef long long ll;
 typedef unsigned long long ull;
 typedef std::pair<int, int> pii;
 
 bool win(char s[5][5], char ch1, char ch2)
 {
 	bool res = false;
 	for (int i = 0; i < 4; ++i)
 	{
 		bool ok = true;
 		for (int j = 0; j < 4; ++j)
 			ok &= (s[i][j] == ch1 || s[i][j] == ch2);
 		res |= ok;
 	}
 
 	for (int i = 0; i < 4; ++i)
 	{
 		bool ok = true;
 		for (int j = 0; j < 4; ++j)
 			ok &= (s[j][i] == ch1 || s[j][i] == ch2);
 		res |= ok;
 	}
 	{
 		bool ok = true;
 		for (int i = 0; i < 4; ++i)
 			ok &= (s[i][i] == ch1 || s[i][i] == ch2);
 		res |= ok;
 	}
 	{
 		bool ok = true;
 		for (int i = 0; i < 4; ++i)
 			ok &= (s[i][3 - i] == ch1 || s[i][3 - i] == ch2);
 		res |= ok;
 	}
 
 	return res;
 }
 
 int main()
 {
 #ifdef DBG1
 	freopen(".in", "r", stdin);
 	freopen(".out", "w", stdout);
 	freopen(".err", "w", stderr);
 #endif
 
 	char s[5][5];
 	int tt;
 	scanf("%d", &tt);
 	for (int ii = 0; ii < tt; ++ii)
 	{
 		for (int i = 0; i < 4; ++i)
 			scanf("%s", s[i]);
 
 		printf("Case #%d: ", ii + 1);
 		if (win(s, 'X', 'T'))
 			printf("X won\n");
 		else if (win(s, 'O', 'T'))
 			printf("O won\n");
 		else
 		{
 			bool isNotDraw = false;
 			for (int i = 0; i < 4; ++i)
 				for (int j = 0; j < 4; ++j)
 					if (s[i][j] == '.')
 						isNotDraw = true;
 			printf("%s\n", isNotDraw ? "Game has not completed" : "Draw");
 		}		
 	}
 
 	return 0;
 }