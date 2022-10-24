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
 int a[30];
 int is[30];
 string s;
 int main()
 {
 	MEMS(a,-1);
 	freopen("in.txt","r",stdin);
 	freopen("out.txt","w",stdout);
 	string s1="ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
 	string s2="our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
 	FOR(i,0,s1.size())
 		if (s1[i]!=' ')
 			a[s1[i]-'a']=s2[i]-'a';
 	a[25]=16;
 	a[16]=25;
 	int test;
 	scanf("%d",&test);
 	getline(cin,s);
 	FOR(it,0,test)
 	{
 		getline(cin,s);
 		printf("Case #%d: ",it+1);
 		FOR(i,0,s.size())
 			if (s[i]!=' ')
 				printf("%c",a[s[i]-'a']+'a');
 			else
 				printf(" ");
 		printf("\n");
 	}
 	return 0;
 }
