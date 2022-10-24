#include <algorithm>
 #include <iostream>
 #include <sstream>
 #include <string>
 #include <vector>
 #include <queue>
 #include <set>
 #include <map>
 #include <cstdio>
 #include <cstdlib>
 #include <cctype>
 #include <cmath>
 #include <numeric>
 #include <cstring>
 
 typedef long long i64d;
 
 using namespace std;
 
 string de(string s)
 {
     if (s.length() == 1) return s;
     string s1 = s.substr(0 , s.length()/2);
     string s2 = s.substr(s.length()/2);
     s1 = de(s1);
     s2 = de(s2);
     if (s1.compare(s2) < 0) return s1 + s2;
     return s2 + s1;
 }
 
 int main()
 {
 	freopen("A-small-attempt1.in" , "r" , stdin);
 	freopen("A-small-attempt1.out" , "w" , stdout);
 	//freopen("B-large.in" , "r" , stdin);
 	//freopen("B-large.out" , "w" , stdout);
 	int cas;
 	scanf("%d" , &cas);
 	for (int ca = 1; ca <= cas; ca ++)
 	{
 		printf("Case #%d: " , ca);
         int n , r , p , s;
         int pe[15] = {1};
         scanf("%d %d %d %d" , &n , &r , &p , &s);
         int done = 0;
         vector<string > x;
         string fin;
         for (int win = 0; win < 3; win ++)
         {
             int a[3] = {0};
             vector<int> res;
             res.push_back(win);
             for (int i = 0; i < n; i ++)
             {
                 vector<int> tmp;
                 for (int j = 0; j < res.size(); j ++)
                     if (res[j] == 0) {tmp.push_back(0); tmp.push_back(1);}
                     else if (res[j] == 1) {tmp.push_back(1); tmp.push_back(2);}
                     else {tmp.push_back(0); tmp.push_back(2);}
                 res = tmp;
             }
             for (int i = 0; i < res.size(); i ++)
                 a[res[i]] ++;
             if (a[0] == p && a[1] == r && a[2] == s)
             {
                 for (int i = 0; i < res.size(); i += 2)
                 {
                     if (res[i] == 0 && res[i+1] == 1)
                         x.push_back("PR");
                     else if (res[i] == 0 && res[i+1] == 2)
                         x.push_back("PS");
                     else x.push_back("RS");
                 }
                 string ss = "";
                 for (int i = 0; i < x.size(); i ++)
                     ss += x[i];
                 if (done == 0) fin = ss;
                 else if (fin.compare(ss) > 0) fin = ss;
                 done = 1;
             }
         }
         if (done)
         {
             fin = de(fin);
             printf("%s\n" , fin.c_str());
         }
         else printf("IMPOSSIBLE\n");
 
     }
     return 0;
 }