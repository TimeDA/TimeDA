#include <iostream>
 #include <cassert>
 #include <algorithm>
 #include <cmath>
 #include <cstring>
 #include <string>
 #include <vector>
 #include <cstdio>
 
 using namespace std;
 
 typedef long long ll;
 typedef long double ld;
 
 #ifdef WIN32
 	#define LLD "%I64d"
 #else
 	#define LLD "%lld"
 #endif
 
 char a[256];
 FILE *ssin,*ssout;
 
 int main()
 {
 // 	cerr << "SAdgdf" << endl;
 	ssin=fopen("sample.in","r"); //freopen("sample.in","r",ssin);
 // 	cerr << "open" << endl;
 	ssout=fopen("sample.out","r"); 
 // 	cerr << "open" << endl;
 	int NT;
 	fscanf(ssin,"%d\n",&NT);
 	memset(a,0,sizeof(a));
 	char c1,c2;
 	fscanf(ssin,"%c",&c1);
 	fscanf(ssout,"%c",&c2);
 	for (int i=0;i<NT;i++)
 	{
 		while ((c1>='a' && c1<='z')||(c1==' '))
 		{
 			if (c1!=' ') a[c1]=c2;
 			fscanf(ssin,"%c",&c1);
 			fscanf(ssout,"%c",&c2);
 		}
 		while (c1<'a' || c2>'z')
 		{
 			if (!(fscanf(ssin,"%c",&c1)==1)) break;
 			fscanf(ssout,"%c",&c2);
 		}
 	}
 	a['q']='z';
 	a['z']='q';
 	scanf("%d\n",&NT);
 	scanf("%c",&c1);
 	for (int i=0;i<NT;i++)
 	{
 		printf("Case #%d: ",i+1);
 		while ((c1>='a' && c1<='z')||(c1==' '))
 		{
 			if (c1!=' ') c1=a[c1];
 			printf("%c",c1);
 			scanf("%c",&c1);
 		}
 		while (c1<'a' || c1>'z')
 		{
 			if (!(scanf("%c",&c1)==1)) break;
 		}
 		printf("\n");
 	}
 	return 0;
 }
