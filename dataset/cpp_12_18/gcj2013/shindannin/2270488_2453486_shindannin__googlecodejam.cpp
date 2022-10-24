// topcoder.cpp : R\[ AvP[ṼGg |Cg`܂B
 //
 
 #include <stdio.h>
 #include <cstdio>
 #include <cstdlib>
 #include <cmath>
 #include <climits>
 #include <cfloat>
 #include <map>
 #include <utility>
 #include <set>
 #include <iostream>
 #include <memory>
 #include <string>
 #include <vector>
 #include <algorithm>
 #include <functional>
 #include <sstream>
 #include <complex>
 #include <stack>
 #include <queue>
 #include <numeric>
 
 using namespace std;
 static const double EPS = 1e-9;
 int ROUND(double x) { return (int)(x+0.5); }
 bool ISINT(double x) { return fabs(ROUND(x)-x)<=EPS; }
 bool ISEQUAL(double x,double y) { return fabs(x-y)<=EPS*max(1.0,max(fabs(x),fabs(y))); }
 double SQSUM(double x,double y) { return x*x+y*y; }
 template<class T> bool INRANGE(T x,T a,T b) { return a<=x&&x<=b; }
 #define PI	(3.14159265358979323846)
 #define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
 #define NG (-1)
 #define BIG (987654321)
 #define SZ(a) ((int)a.size())
 typedef long long ll;
 
 #define FOR(v,i) for(__typeof((v).begin())i=(v).begin();i!=(v).end();++i)
 // BEGIN CUT HERE
 #undef FOR
 #define FOR(v,i) for(auto i=(v).begin();i!=(v).end();++i)
 // END CUT HERE
 
 
 int main(){
 
 	freopen("_google_code_jam_input.txt","r",stdin);
 	freopen("_google_code_jam_output.txt","w",stdout);
 
 	char str[10000];
 	int T;
 	scanf("%d",&T);
 
 
 	for (int testcase = 0; testcase < T; testcase++)
 	{
 		vector <string> field;
 
 		for (int y = 0; y < 4; y++)
 		{
 			scanf("%s",str);
 			field.push_back(string(str));
 		}
 
 		bool isGameCompleted = true;
 		for (int y = 0; y < SZ(field); y++)
 		{
 			for (int x = 0; x < SZ(field[y]); x++)
 			{
 				const static int dy[] = {-1, 0, 1, 0, -1, -1, 1, 1}; // U,R,D,L
 				const static int dx[] = { 0, 1, 0,-1,  1, -1, 1,-1};
 
 				if(field[y][x]=='.')
 				{
 					isGameCompleted = false;
 				}
 
 				for(int d = 0; d < 8; d++)
 				{
 					bool isXwon = true;
 					bool isOwon = true;
 
 					for(int len=0;len<4;len++)
 					{
 						const int ny = y+dy[d]*len; 
 						const int nx = x+dx[d]*len;
 						if(!(INRANGE(ny,0,SZ(field)-1)&&INRANGE(nx,0,SZ(field[y])-1)&&(field[ny][nx]=='X'||field[ny][nx]=='T')) )
 						{
 							isXwon = false;
 						}
 						if(!(INRANGE(ny,0,SZ(field)-1)&&INRANGE(nx,0,SZ(field[y])-1)&&(field[ny][nx]=='O'||field[ny][nx]=='T')) )
 						{
 							isOwon = false;
 						}
 					}
 
 					if(isXwon)
 					{
 						printf("Case #%d: X won\n",testcase+1);
 						goto NUKE;
 					}
 					else if (isOwon)
 					{
 						printf("Case #%d: O won\n",testcase+1);
 						goto NUKE;
 					}
 				}
 
 
 			}
 		}
 
 		if(isGameCompleted)
 		{
 			printf("Case #%d: Draw\n",testcase+1);
 		}
 		else
 		{
 			printf("Case #%d: Game has not completed\n",testcase+1);
 		}
 
 		NUKE:;
 	}
 }
