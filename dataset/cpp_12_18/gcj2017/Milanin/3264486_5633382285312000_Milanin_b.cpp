#pragma comment(linker, "/STACK:100000000")
 #include <cmath>
 #include <cstdio>
 #include <vector>
 #include <iostream>
 #include <algorithm>
 #include <set>
 #include <map>
 #include <ctime>
 using namespace std;
 const int N=25;
 char s[N];
 int main()
 {
     int ts;
     scanf("%d", &ts);
     for(int t=1; t<=ts; t++)
     {
         printf("Case #%d: ", t);
         scanf("%s", s);
         int n=strlen(s);
         int i, j;
         for(; ; )
         {
             for(i=0; i+1<n; i++)
                 if(s[i]>s[i+1]) break;
             if(i+1<n)
             {
                 s[i]--;
                 for(i++; i<n; s[i]='9', i++);
             }
             else break;
         }
         if(s[0]=='0') printf("%s\n", s+1);
         else printf("%s\n", s);
     }
 	return 0;
 }