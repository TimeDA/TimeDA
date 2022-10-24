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
 
 
 #if 1
 
 int main(){
 
 	freopen("_google_code_jam_input.txt","r",stdin);
 	freopen("_google_code_jam_output.txt","w",stdout);
 
 	int T;
 	scanf("%d ",&T);
 
 	for (int testcase = 0; testcase < T; testcase++)
 	{
 		int H,W;
 		scanf("%d %d ",&H,&W);
 		vector < vector <int> > field(H, vector <int> (W,0) );
 
 		bool ok = true;
 		for (int y = 0; y < H; y++)
 		{
 			for (int x = 0; x < W; x++)
 			{
 				scanf("%d ",&field[y][x]);
 			}
 		}
 
 		for (int y = 0; y < H; y++)
 		{
 			for (int x = 0; x < W; x++)
 			{
 
 				bool check1 = true;
 				for(int d=0;d<H;d++)
 				{
 					if(field[y][x]<field[d][x])
 					{
 						check1 = false;
 					}
 				}
 
 				bool check2 = true;
 				for(int d=0;d<W;d++)
 				{
 					if(field[y][x]<field[y][d])
 					{
 						check2 = false;
 					}
 				}
 
 				if(!check1 && !check2)
 				{
 					ok = false;
 				}
 
 			}
 		}
 
 		if(ok)
 		{
 			printf("Case #%d: YES\n",testcase+1);
 		}
 		else
 		{
 			printf("Case #%d: NO\n",testcase+1);
 		}
 	}
 }
 
 #elif 0
 
 int K,N;
 vector <int> firstKeys;
 vector <int> openChest;
 vector < vector <int> > keyInside;
 
 bool isOK( const vector <int>& order )
 {
 	const int N = SZ(order);
 	vector <int> numKeys(N);
 	numKeys[firstKey]++;
 
 	for (int i = 0; i < SZ(order); i++)
 	{
 	}
 }
 
 
 
 int main(){
 
 	freopen("_google_code_jam_input.txt","r",stdin);
 	freopen("_google_code_jam_output.txt","w",stdout);
 
 	int T;
 	cin >> T;
 
 	for (int testcase = 0; testcase < T; testcase++)
 	{
 		cin >> K >> N;
 
 		firstKeys.clear();
 		openChest.clear();
 		keyInside.clear();
 
 		firstKeys.resize(K);
 		for (int i = 0; i < K; i++)
 		{
 			cin >> firstKeys[i];
 			firstKeys[i]--;
 		}
 
 		openChest.resize(N);
 		keyInside.resize(N);
 		for (int i = 0; i < N; i++)
 		{
 			cin >> openChest[i];
 			openChest[i]--;
 
 			int numInside;
 			cin >> numInside;
 
 			keyInside[i].resize(numInside);
 			for (int k = 0; k < numInside; k++)
 			{
 				cin >> keyInside[i][k];
 				keyInside[i][k]--;
 			}
 		}
 
 
 
 
 
 
 		printf("Case #%d: %d\n",testcase+1,ans);
 	}
 
 
 
 }
 
 
 
 
 #elif 0
 
 char str[10000];
 bool isPalin(ll x)
 {
 	sprintf(str,"%lld",x);
 	int n = strlen(str);
 
 	bool ret = true;
 	for (int i = 0; i < n/2; i++)
 	{
 		if(str[i]!=str[n-1-i])
 		{
 			ret = false;
 			break;
 			
 		}
 	}
 
 	return ret;
 }
 
 ll test[] =
 {
 	0,
 	1,
 	4,
 	9,
 	121,
 	484,
 	10201,
 	12321,
 	14641,
 	40804,
 	44944,
 	1002001,
 	1234321,
 	4008004,
 	100020001,
 	102030201,
 	104060401,
 	121242121,
 	123454321,
 	125686521,
 	400080004,
 	404090404,
 	10000200001,
 	10221412201,
 	12102420121,
 	12345654321,
 	40000800004,
 	1000002000001,
 	1002003002001,
 	1004006004001,
 	1020304030201,
 	1022325232201,
 	1024348434201,
 	1210024200121,
 	1212225222121,
 	1214428244121,
 	1232346432321,
 	1234567654321,
 	4000008000004,
 	4004009004004,
 	100000020000001,
 	100220141022001,
 	102012040210201,
 	102234363432201,
 	121000242000121,
 	121242363242121,
 	123212464212321,
 	123456787654321,
 	400000080000004,
 	10000000200000001,
 	10002000300020001,
 	10004000600040001,
 	10020210401202001,
 	10022212521222001,
 	10024214841242001,
 	10201020402010201,
 	10203040504030201,
 	10205060806050201,
 	10221432623412201,
 	10223454745432201,
 	12100002420000121,
 	12102202520220121,
 	12104402820440121,
 	12122232623222121,
 	12124434743442121,
 	12321024642012321,
 	12323244744232321,
 	12343456865434321,
 	12345678987654321,
 	40000000800000004,
 	40004000900040004,
 };
 
 
 int main(){
 
 	freopen("_google_code_jam_input.txt","r",stdin);
 	freopen("_google_code_jam_output.txt","w",stdout);
 
 	int T;
 	cin >> T;
 
 	int n = 0;
 	vector <ll> oks;
 
 	for (ll i = 0; i <= 20000000; i++)
 	{
 		if(isPalin(i))
 		{
 			ll k = i*i;
 			if(isPalin(k))
 			{
 				oks.push_back(k);
 			}
 		}
 	}
 
 	for (int testcase = 0; testcase < T; testcase++)
 	{
 		ll A,B;
 		cin >> A >> B;
 
 		int numB = upper_bound(oks.begin(),oks.end(),B)-oks.begin();
 		int numA = lower_bound(oks.begin(),oks.end(),A)-oks.begin();
 		int ans = numB-numA;
 
 		printf("Case #%d: %d\n",testcase+1,ans);
 	}
 }
 
 
 
 
 
 
 #elif 1
 
 int main(){
 
 	freopen("_google_code_jam_input.txt","r",stdin);
 	freopen("_google_code_jam_output.txt","w",stdout);
 
 	char str[10000];
 	int T;
 	scanf("%d",&T);
 
 
 	for (int testcase = 0; testcase < T; testcase++)
 	{
 		int H,W;
 		scanf("%d %d ",&H,&W);
 		vector <string> field;
 
 		for (int y = 0; y < H; y++)
 		{
 			scanf("%s",str);
 			field.push_back(string(str));
 		}
 
 		for (int y = 0; y < length; y++)
 		{
 
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
 
 
 #else
 
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
 
 #endif