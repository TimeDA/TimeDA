#include <vector>
 #include <list>
 #include <map>
 #include <set>
 #include <queue>
 #include <deque>
 #include <stack>
 #include <algorithm>
 #include <sstream>
 #include <iostream>
 #include <iomanip>
 #include <cstdio>
 #include <cmath>
 #include <cstdlib>
 #include <ctime>
 #include <memory.h>
 
 #define ABS(a) ((a>0)?a:-(a))
 #define MIN(a,b) ((a<b)?(a):(b))
 #define MAX(a,b) ((a<b)?(b):(a))
 #define FOR(i,a,n) for (int i=(a);i<(n);++i)
 #define FI(i,n) for (int i=0; i<(n); ++i)
 #define pnt pair <int, int>
 #define mp make_pair
 #define PI 3.14159265358979
 #define MEMS(a,b) memset(a,b,sizeof(a))
 #define LL long long
 #define U unsigned
 
 using namespace std;
 stringstream tmp;
 string s;
 string s1,s2;
 set <pnt > q;
 int main()
 {
 	freopen("in.txt","r",stdin);
 	freopen("out.txt","w",stdout);
 	int t;
 	scanf("%d",&t);
 	FOR(test,1,t+1)
 	{
 		int a,b;
 		scanf("%d%d",&a,&b);
 		int res=0;
 		FOR(i,a,b+1)
 		{
 			tmp.clear();
 			tmp<<i;
 			tmp>>s;
 			q.clear();
 			FOR(j,1,s.size())
 			{
 				string s1=s.substr(0,j);
 				string s2=s.substr(j,s.size()-j);
 				s1=s2+s1;
 				while (s1[0]=='0')
 					s1=s1.substr(1,s1.size()-1);
 				if (s1.size()!=s.size())
 					continue;
 				tmp.clear();
 				tmp<<s1;
 				int v;
 				tmp>>v;
 				if ((v>=a) && (v<=b) && (v<i))
 					q.insert(mp(v,i));
 			}
 			res+=q.size();
 		}
 		printf("Case #%d: %d\n",test,res);
 	}
 	return 0;
 }
