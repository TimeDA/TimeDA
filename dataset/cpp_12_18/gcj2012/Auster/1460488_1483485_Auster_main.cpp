#include <cstdio>
 #include <vector>
 #include <string>
 #include <sstream>
 #include <set>
 #include <iostream>
 
 using namespace std;
 
 typedef long long LL;
 
 const string abc = "ynficwlbkuomxsevzpdrjgthaq";
 
 int n;
 char buf[1 << 7];
 
 int main()
 {
 	freopen("A.in", "r", stdin);
 	freopen("output.txt", "w", stdout);
 	scanf("%d\n", &n);
 	for(int i = 0; i < n; ++i)
 	{
 		gets(buf);
 		for(int j = 0; buf[j]; ++j)
 		{
 			for(int k = 0; k < 26; ++k)
 			{
 				if (buf[j] == abc[k])
 				{
 					buf[j] = 'a' + k;
 					break;
 				}
 			}
 		}
 		printf("Case #%d: %s\n", i + 1, buf);
 	}
 	return 0;
 }