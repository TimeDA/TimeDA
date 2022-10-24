#include <stdio.h>
 #include <algorithm>
 #include <set>
 #include <map>
 #include <string>
 #include <string.h>
 #include <cstring>
 #include <vector>
 #include <queue>
 
 using namespace std;
 
 int k;
 int n;
 char dat[1024];
 set<string> s;
 map<char,char> alt;
 int indeg[256];
 int outdeg[256];
 int matrx[256][256];
 
 int main()
 {
 	int T;
 	scanf("%d",&T);
 	alt[ 'o' ]= '0';
 	alt[ 'i' ]= '1';
 	alt[ 'e' ]= '3';
 	alt[ 'a' ]= '4';
 	alt[ 's' ]= '5';
 	alt[ 't' ]= '7';
 	alt[ 'b' ]= '8';
 	alt[ 'g' ]= '9';
 	for(int testcase = 1; testcase <= T; testcase ++)
 	{
 		memset(indeg, 0, sizeof(indeg));
 		memset(outdeg, 0, sizeof(outdeg));
 		memset(matrx, 0, sizeof(matrx));
 		scanf("%d",&k);
 		scanf("%s",dat);
 		int n = strlen(dat);
 		for(int i = 0;i+1 < n; i ++)
 		{
 			string cur(dat+i,dat+i+2);
 			s.insert(cur);
 			if(alt.count(cur[0]) && alt.count(cur[1]))
 			{
 				string ns;
 				ns.push_back(alt[cur[0]]);
 				ns.push_back(alt[cur[1]]);
 				s.insert(ns);
 			}
 			if(alt.count(cur[0]))
 			{
 				string ns;
 				ns.push_back(alt[cur[0]]);
 				ns.push_back(cur[1]);
 				s.insert(ns);
 			}
 			if(alt.count(cur[1]))
 			{
 				string ns;
 				ns.push_back(cur[0]);
 				ns.push_back(alt[cur[1]]);
 				s.insert(ns);
 			}
 		}
 		int ans = 0;
 		for(auto I = s.begin(); I != s.end(); I ++)
 		{
 			string s = *I;
 			indeg[s[0]] ++;
 			outdeg[s[1]] ++;
 			matrx[s[0]][s[1]] = 1;
 			ans += 2;
 		}
 		int cnt = 0;
 		for(int i = 0;i < 256; i ++)
 		{
 			cnt += min(indeg[i],outdeg[i]);
 		}
 		if(cnt * 2 == ans) ans ++;
 		ans -= cnt;
 		printf("Case #%d: %d\n", testcase, ans);
 		s.clear();
 	}
 	return 0;
 }
