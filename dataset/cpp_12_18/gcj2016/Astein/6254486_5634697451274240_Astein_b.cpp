#include <cstdio>
 #include <iostream>
 #include <string>
 
 using namespace std;
 
 int main()
 {
   int T;
   cin >> T;
   for (int cn = 1; cn <= T; ++cn)
   {
 		string s;
 		cin >> s;
 		int ret = 0;
 
 		char f = '-';
 		for (int i = s.size() - 1; i >= 0; --i)
 		{
 		  if (s[i] == f)
 		  {
 		    ret++;
 		    if (f == '-') f = '+'; else f = '-'; // flip
 		  }
 		}
 		printf("Case #%d: %d\n", cn, ret);
   }
 }
